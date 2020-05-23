project(mediatorD3)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} $ENV{CXXFLAGS} $ENV{CPPFLAGS}")
set(CMAKE_CXX_STANDARD 17) # -std=c++17
option(BUILD_EXAMPLE "Build example code" ON)

include_directories(./)

file(GLOB CPP_FILES mediator/*/*.cpp mediator/*.cpp)
file(GLOB HPP_FILES mediator/*/*.h mediator/*.h)
add_library(${PROJECT_NAME} ${CPP_FILES} ${HPP_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC ./)

if(BUILD_EXAMPLE)
  add_subdirectory(exemplo)
endif()

if( CMAKE_COMPILER_IS_MINGW )
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Og -Wa,-mbig-obj")
elseif( MSVC )
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")
endif()

install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(FILES ${HPP_FILES} DESTINATION include/${PROJECT_NAME})
