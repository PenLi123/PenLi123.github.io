#ifndef CALENDARPLANNERWINDOW_H
#define CALENDARPLANNERWINDOW_H

#include <QMainWindow>
#include <QDate>
#include <QMap>
#include <QtNetwork/QNetworkAccessManager>
#include <QListWidgetItem>

// Forward declaration of the auto-generated UI class
QT_BEGIN_NAMESPACE
namespace Ui { class CalendarPlannerWindow; }
QT_END_NAMESPACE

/**
 * @brief Main window class for the CalendarPlanner application.
 * 
 * Manages the user interface, task data, and calendar interactions.
 */
class CalendarPlannerWindow : public QMainWindow {
    Q_OBJECT

public:
    // ----- Constructor & Destructor -----
    explicit CalendarPlannerWindow(QWidget *parent = nullptr);
    ~CalendarPlannerWindow();

private:
    // ----- UI Layer -----
    Ui::CalendarPlannerWindow *ui;  // Pointer to auto-generated UI layout

    // ----- Task Data -----
    QMap<QDate, QStringList> dailyTasksMap;  // Maps dates to their respective task lists

    // ----- Network -----
    QNetworkAccessManager* networkManager;  // Handles API communication if needed (e.g., sync)

    // ----- Core Logic -----
    void refreshTaskList(const QDate& date);       // Updates the task list display for the selected date
    void refreshCalendarIndicators();              // Highlights dates with scheduled tasks in the calendar
    void setupConnections();                       // Connects UI signals to corresponding slots
    void toggleStrikethrough(QListWidgetItem* item); // Applies strikethrough to completed tasks
    void addTask();                                // Adds a new task to the selected date
    void deleteSelectedTask();                     // Deletes the currently selected task
};

#endif // CALENDARPLANNERWINDOW_H
