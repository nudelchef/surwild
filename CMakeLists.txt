cmake_minimum_required(VERSION 3.7)

set(CMAKE_CXX_STANDARD 14)
set("${CMAKE_CXX_FLAGS} -pthread")

project(surwild)

find_package(SDL2 REQUIRED)

set(SOURCES
        include/Camera.h
        include/Direction.h
        include/Entity.h
        include/Game.h
        include/Map.h
        include/Player.h
        include/StringUtils.h
        include/TextureManager.h
        src/Camera.cpp
        src/Entity.cpp
        src/Game.cpp
        src/main.cpp
        src/Map.cpp
        src/Player.cpp
        src/StringUtils.cpp
        src/TextureManager.cpp
        )

add_executable(${PROJECT_NAME} ${SOURCES})

include_directories(include)
include_directories(src)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})