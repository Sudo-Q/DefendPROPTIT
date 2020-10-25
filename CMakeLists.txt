cmake_minimum_required(VERSION 3.17)
project(defenderPro)

set(CMAKE_CXX_STANDARD 20)
find_package(SFML 2.5 COMPONENTS window system graphics)

add_executable(defenderPro main.cpp Animation.cpp Animation.h Bug.cpp Bug.h Bullet.cpp Bullet.h Shooter.cpp Shooter.h Intro.cpp Intro.h Map.cpp Map.h Data.cpp Data.h)

target_link_libraries(defenderPro sfml-system sfml-window sfml-graphics sfml-audio)