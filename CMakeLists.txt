cmake_minimum_required(VERSION 3.10)
project(ray_tracer)

find_package(Armadillo REQUIRED)
include_directories(${ARMADILLO_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 14)

add_executable(ray_tracer main.cpp engine/Renderer.cpp engine/Renderer.h world/World.cpp world/World.h engine/Ray.cpp engine/Ray.h world/LightSource.cpp world/LightSource.h world/Thing.cpp world/Thing.h things/Sphere.cpp things/Sphere.h)
target_link_libraries(ray_tracer ${ARMADILLO_LIBRARIES})