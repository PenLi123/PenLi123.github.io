/********************************************************************************
** Form generated from reading UI file 'calendarplannerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALENDARPLANNERWINDOW_H
#define UI_CALENDARPLANNERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CalendarPlannerWindow
{
public:
    QWidget *centralwidget;
    QCalendarWidget *calendarWidget;
    QLineEdit *taskInputField;
    QPushButton *addTaskBtn;
    QListWidget *taskListView;
    QPushButton *deleteTaskBtn;

    void setupUi(QMainWindow *CalendarPlannerWindow)
    {
        if (CalendarPlannerWindow->objectName().isEmpty())
            CalendarPlannerWindow->setObjectName("CalendarPlannerWindow");
        CalendarPlannerWindow->resize(820, 620);
        centralwidget = new QWidget(CalendarPlannerWindow);
        centralwidget->setObjectName("centralwidget");
        calendarWidget = new QCalendarWidget(centralwidget);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setGeometry(QRect(10, 10, 660, 280));
        taskInputField = new QLineEdit(centralwidget);
        taskInputField->setObjectName("taskInputField");
        taskInputField->setGeometry(QRect(10, 500, 530, 60));
        addTaskBtn = new QPushButton(centralwidget);
        addTaskBtn->setObjectName("addTaskBtn");
        addTaskBtn->setGeometry(QRect(550, 500, 120, 32));
        taskListView = new QListWidget(centralwidget);
        taskListView->setObjectName("taskListView");
        taskListView->setGeometry(QRect(10, 300, 530, 190));
        deleteTaskBtn = new QPushButton(centralwidget);
        deleteTaskBtn->setObjectName("deleteTaskBtn");
        deleteTaskBtn->setGeometry(QRect(550, 540, 120, 32));
        CalendarPlannerWindow->setCentralWidget(centralwidget);

        retranslateUi(CalendarPlannerWindow);

        QMetaObject::connectSlotsByName(CalendarPlannerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CalendarPlannerWindow)
    {
        CalendarPlannerWindow->setWindowTitle(QCoreApplication::translate("CalendarPlannerWindow", "CalendarPlanner", nullptr));
        addTaskBtn->setText(QCoreApplication::translate("CalendarPlannerWindow", "Add New Task", nullptr));
        deleteTaskBtn->setText(QCoreApplication::translate("CalendarPlannerWindow", "Delete Selected", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CalendarPlannerWindow: public Ui_CalendarPlannerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALENDARPLANNERWINDOW_H
