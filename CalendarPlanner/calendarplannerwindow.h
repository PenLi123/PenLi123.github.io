#ifndef CALENDARPLANNERWINDOW_H
#define CALENDARPLANNERWINDOW_H

#include <QMainWindow>
#include <QDate>
#include <QMap>
#include <QtNetwork/QNetworkAccessManager>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class CalendarPlannerWindow; }
QT_END_NAMESPACE

class CalendarPlannerWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit CalendarPlannerWindow(QWidget *parent = nullptr);
    ~CalendarPlannerWindow();

private:
    Ui::CalendarPlannerWindow *ui;

    // Stores tasks associated with each date
    QMap<QDate, QStringList> dailyTasksMap;

    // Handles HTTP requests to the Flask backend
    QNetworkAccessManager* networkManager;

    void setupConnections();                         // Connects signals and slots
    void toggleStrikethrough(QListWidgetItem* item); // Strikes through checked tasks
    void addTask();                                  // Adds a task for the selected date
    void deleteSelectedTask();                       // Deletes the selected task
    void updateTaskListForDate(const QDate& date);   // Updates the task list display
    void updateCalendarHighlights();                 // Highlights dates that have tasks
};

#endif // CALENDARPLANNERWINDOW_H
