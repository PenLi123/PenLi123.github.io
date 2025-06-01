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
    QMap<QDate, QStringList> dailyTasksMap;
    QNetworkAccessManager* networkManager;

    void setupConnections();
    void toggleStrikethrough(QListWidgetItem* item);
    void addTask();
    void deleteSelectedTask();
    void updateTaskListForDate(const QDate& date);
    void updateCalendarHighlights();
};

#endif // CALENDARPLANNERWINDOW_H
