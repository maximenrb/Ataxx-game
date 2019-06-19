cmake_minimum_required(VERSION 3.7)
project(Mini_Project)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
find_package(Qt5Widgets CONFIG REQUIRED)

add_executable(Mini_Project main.cpp src/Model/Grid_Model.h src/Controller/Game_Controller.cpp src/Controller/Game_Controller.h tools/ParseArgs/ParseArgs.cpp tools/ParseArgs/ParseArgs.h tools/Observer/Observer.h src/View/Console_View.h src/Controller/ObservableGame_Controller.h tools/Observer/Subject.h tools/ParseArgs/getoptpp/getopt_pp.cpp tools/ParseArgs/getoptpp/getopt_pp.h src/View/Qt_View.h src/View/Console_View.cpp src/Controller/ObservableGame_Controller.cpp src/View/Qt_View.cpp)
target_link_libraries(Mini_Project Qt5::Widgets)