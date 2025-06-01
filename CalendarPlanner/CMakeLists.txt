# ------------------------------------------------------------------------------
# CalendarPlanner – CMake Build Configuration
#
# A cross-platform personal task and calendar manager
# built with C++17, Qt6, and modern UI design principles.
# ------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.14)

# Project metadata
project(CalendarPlanner LANGUAGES CXX)

# Use modern C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Path to Qt6 (Homebrew on macOS)
set(CMAKE_PREFIX_PATH "/opt/homebrew/opt/qt@6/lib/cmake")

# Required Qt modules
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Network)

# -------------------------------------------------------------
# Source Groupings – keeping the build setup clean and scalable
# -------------------------------------------------------------

# Application source files
set(SOURCES
    main.cpp
    calendarplannerwindow.cpp
)

# Header files
set(HEADERS
    calendarplannerwindow.h
)

# UI design files (from Qt Designer)
set(UIS
    calendarplannerwindow.ui
)

# ----------------------------------
# Build the executable with Qt support
# ----------------------------------

qt_add_executable(CalendarPlanner
    ${SOURCES}
    ${HEADERS}
    ${UIS}
)

# Link against required Qt modules
target_link_libraries(CalendarPlanner PRIVATE
    Qt6::Core
    Qt6::Widgets
    Qt6::Network
)
