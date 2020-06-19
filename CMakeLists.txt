cmake_minimum_required(VERSION 2.6)
project( solarTracker )

include_directories(include)
file(GLOB SOURCES "src/*.cpp")


add_executable( solarTracker ${SOURCES})

find_package( OpenCV REQUIRED )
target_link_libraries( solarTracker ${OpenCV_LIBS} )