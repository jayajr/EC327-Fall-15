cmake_minimum_required(VERSION 3.3)
project(Q1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES pa3.cpp CartPoint.cpp CartPoint.h CartVector.cpp CartVector.h GameObject.cpp GameObject.h Port.cpp Port.h Dock.cpp Dock.h Dock.cpp Dock.h Sailor.cpp Sailor.h Model.cpp Model.h View.cpp View.h GameCommand.cpp GameCommand.h)
add_executable(Q1 ${SOURCE_FILES})