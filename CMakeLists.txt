cmake_minimum_required(VERSION 3.16)
project(surwild)

set(CMAKE_CXX_STANDARD 14)
set("${CMAKE_CXX_FLAGS} -pthread")

include_directories(include)
include_directories(src)

add_executable(surwild
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
        src/TextureManager.cpp)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})
