#include <QApplication>
#include "calendarplannerwindow.h"

int main(int argc, char *argv[]) {
    // Create the application object (required by all Qt apps)
    QApplication calendarApp(argc, argv);

    // Create and configure the main application window
    CalendarPlannerWindow mainWindow;
    mainWindow.setWindowTitle("CalendarPlanner");  // Set custom window title
    mainWindow.show();                             // Display the main window

    // Run the Qt event loop
    return calendarApp.exec();
}
