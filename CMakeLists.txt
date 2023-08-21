cmake_minimum_required(VERSION 3.18)
project(HW_29_7 LANGUAGES CXX C)

add_executable(HW_29_7 main.cpp ./list/list.cpp)
set_target_properties(HW_29_7
    PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS YES
        C_STANDARD 11
        C_STANDARD_REQUIRED YES
        C_EXTENSIONS YES
)         