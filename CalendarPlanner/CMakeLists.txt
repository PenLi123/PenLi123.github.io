cmake_minimum_required(VERSION 3.16)

project(CalendarPlanner LANGUAGES CXX)

# Use C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Path to Qt6 installed via Homebrew (macOS)
set(CMAKE_PREFIX_PATH "/opt/homebrew/opt/qt@6/lib/cmake")

# Find required Qt6 modules
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Network)

qt_standard_project_setup()

# Define the executable and source files
qt_add_executable(CalendarPlanner
    main.cpp
    calendarplannerwindow.cpp
    calendarplannerwindow.h
    calendarplannerwindow.ui
)

# Link against Qt6 libraries
target_link_libraries(CalendarPlanner PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Network
)
