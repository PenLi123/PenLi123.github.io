#include "calendarplannerwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);           // Initialize Qt application
    CalendarPlannerWindow window;           // Create main window
    window.show();                          // Display the window
    return app.exec();                      // Start the event loop
}
