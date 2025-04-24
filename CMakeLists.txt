cmake_minimum_required(VERSION 3.5)
project(SmartPointers)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include_directories(
        "C:\\Qt\\6.9.0\\mingw_64\\include\\QtWidgets"
        "C:\\Qt\\6.9.0\\mingw_64\\include\\QtCore"
        "C:\\Qt\\6.9.0\\mingw_64\\include\\QtGui"
        "C:\\Qt\\6.9.0\\mingw_64\\include")

link_directories("C:\\Qt\\6.9.0\\mingw_64\\lib")

set(Qt6Widgets_DIR "C:\\Qt\\6.9.0\\mingw_64\\lib\\cmake\\Qt6Widgets")
find_package(Qt6Widgets REQUIRED)
set(Qt6Core_DIR "C:\\Qt\\6.9.0\\mingw_64\\lib\\cmake\\Qt6Core")
find_package(Qt6Core REQUIRED)
set(Qt6Gui_DIR "C:\\Qt\\6.9.0\\mingw_64\\lib\\cmake\\Qt6Gui")
find_package(Qt6Gui REQUIRED)

add_executable(SmartPointers
        main.cpp
        mainwindow.cpp
        mainwindow.ui
        classes/Library.cpp
        classes/Book.cpp
        classes/User.cpp
        source/bookdialog.h
        source/bookdialog.cpp
        source/BookModel.h
        source/BookModel.cpp
        source/UserModel.cpp
        source/UserModel.h
)

target_link_libraries(SmartPointers PRIVATE Qt6Core Qt6Gui Qt6Widgets)
