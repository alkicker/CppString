cmake_minimum_required(VERSION 3.5)

project(CppStrings LANGUAGES CXX)

add_executable(CppStrings main.cpp

                          inputdatahandler.h
                          outputdatahandler.h
                          commandlineprocessor.h
                          stringlistprocessor.h

                          inputdatahandler.cpp
                          outputdatahandler.cpp
                          commandlineprocessor.cpp
                          stringlistprocessor.cpp
               )

set_property(TARGET CppStrings PROPERTY CXX_STANDARD 17)

#get cxxopts library from github
include(FetchContent)

FetchContent_Declare(
    cxxopts
    GIT_REPOSITORY https://github.com/jarro2783/cxxopts.git
    GIT_TAG v3.1.1
)

FetchContent_GetProperties(cxxopts)
if(NOT cxxopts_POPULATED)
    FetchContent_Populate(cxxopts)
    add_subdirectory(${cxxopts_SOURCE_DIR} ${cxxopts_BINARY_DIR})
endif()

target_include_directories(CppStrings PRIVATE ${cxxopts_SOURCE_DIR}/include)
target_link_libraries(CppStrings cxxopts)

install(TARGETS CppStrings
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /WX")
endif()



