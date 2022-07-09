cmake_minimum_required(VERSION 3.7)

set(CMAKE_CXX_STANDARD 14)
set("${CMAKE_CXX_FLAGS} -pthread")

project(surwild)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

file(GLOB SOURCES
        "include/*.h"
        "src/*.cpp"
        )

add_executable(${PROJECT_NAME} ${SOURCES})

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

include_directories(include)
include_directories(src)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})