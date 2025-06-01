#include "calendarplannerwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    CalendarPlannerWindow window;
    window.show();
    return app.exec();
}
