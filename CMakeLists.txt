cmake_minimum_required(VERSION 3.6)
project(Homework5)

#define EXECUTABLE NAME HERE
set(EXECUTABLE_NAME "h5")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
include_directories(${SFML_INCLUDE_DIR})

set(SOURCE_FILES
        main.cpp
        Game.cpp Game.h GameObject.cpp GameObject.h RegularGameObject.h RegularGameObject.cpp AnimatedGameObject.h AnimatedGameObject.cpp Menu.cpp Menu.h GameOver.cpp GameOver.h Screen.h Story.cpp Story.h Bug.cpp Bug.h Gardener.cpp Gardener.h Tomato.cpp Tomato.h)

#copy file to where my executable is
file(COPY "content/bug sprite.png" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "content/farmer sprite.png" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "content/newtomato.png" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "content/grass texture.jpg" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "content/ARCADECLASSIC.TTF" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "content/Story.png" DESTINATION "${CMAKE_BINARY_DIR}")


add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})