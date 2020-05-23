cmake_minimum_required(VERSION 2.8)

project(exemplo_mediatorD3)

add_executable(${PROJECT_NAME} exemplo.cpp serviceA.cpp serviceB.cpp serviceC.cpp)
target_link_libraries(${PROJECT_NAME} mediatorD3)
