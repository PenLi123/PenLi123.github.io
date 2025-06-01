#include "calendarplannerwindow.h"
#include "ui_calendarplannerwindow.h"

#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include <QTextCharFormat>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>

// Constructor
CalendarPlannerWindow::CalendarPlannerWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::CalendarPlannerWindow)
{
    ui->setupUi(this);
    networkManager = new QNetworkAccessManager(this);

    // Setup UI formatting
    ui->calendarWidget->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);

    // Initialize with current date
    updateTaskListForDate(ui->calendarWidget->selectedDate());
    updateCalendarHighlights();

    setupConnections();
}

// Destructor
CalendarPlannerWindow::~CalendarPlannerWindow()
{
    delete ui;
}

// ----------------------------
// Connection Setup
// ----------------------------

void CalendarPlannerWindow::setupConnections()
{
    connect(ui->taskListView, &QListWidget::itemChanged,
            this, &CalendarPlannerWindow::toggleStrikethrough);

    connect(ui->calendarWidget, &QCalendarWidget::selectionChanged, this, [this]() {
        updateTaskListForDate(ui->calendarWidget->selectedDate());
    });

    connect(ui->addTaskBtn, &QPushButton::clicked, this, &CalendarPlannerWindow::addTask);
    connect(ui->deleteTaskBtn, &QPushButton::clicked, this, &CalendarPlannerWindow::deleteSelectedTask);
}

// ----------------------------
// Task & UI Logic
// ----------------------------

void CalendarPlannerWindow::toggleStrikethrough(QListWidgetItem* item)
{
    QFont font = item->font();
    font.setStrikeOut(item->checkState() == Qt::Checked);
    item->setFont(font);
}

void CalendarPlannerWindow::addTask()
{
    QString taskText = ui->taskInputField->text().trimmed();
    if (taskText.isEmpty()) return;

    QDate selectedDate = ui->calendarWidget->selectedDate();
    QString dateString = selectedDate.toString("yyyy-MM-dd");

    // Prepare JSON payload for backend
    QJsonObject json;
    json["text"] = taskText;
    QJsonDocument doc(json);
    QByteArray data = doc.toJson();

    QUrl url("http://127.0.0.1:5000/tasks/" + dateString);
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    networkManager->post(request, data);

    // Update local task map
    dailyTasksMap[selectedDate].append(taskText);
    ui->taskInputField->clear();

    updateTaskListForDate(selectedDate);
    updateCalendarHighlights();
}

void CalendarPlannerWindow::deleteSelectedTask()
{
    QListWidgetItem* selectedItem = ui->taskListView->currentItem();
    if (!selectedItem) return;

    QString taskText = selectedItem->text();
    QDate selectedDate = ui->calendarWidget->selectedDate();

    QStringList& tasks = dailyTasksMap[selectedDate];
    tasks.removeAll(taskText);

    delete selectedItem;
    updateCalendarHighlights();
}

// ----------------------------
// Task Display
// ----------------------------

void CalendarPlannerWindow::updateTaskListForDate(const QDate& date)
{
    ui->taskListView->clear();
    const QStringList& tasks = dailyTasksMap[date];

    for (const QString& task : tasks) {
        QListWidgetItem* item = new QListWidgetItem(task);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        item->setCheckState(Qt::Unchecked);
        ui->taskListView->addItem(item);
    }
}

// ----------------------------
// Calendar Highlighting
// ----------------------------

void CalendarPlannerWindow::updateCalendarHighlights()
{
    QTextCharFormat defaultFormat;

    for (const QDate& date : dailyTasksMap.keys()) {
        ui->calendarWidget->setDateTextFormat(date, defaultFormat);
    }

    for (const QDate& date : dailyTasksMap.keys()) {
        if (!dailyTasksMap[date].isEmpty()) {
            QTextCharFormat format;
            format.setFontWeight(QFont::Bold);
            format.setForeground(QColor("#00AA88"));
            ui->calendarWidget->setDateTextFormat(date, format);
        }
    }
}
