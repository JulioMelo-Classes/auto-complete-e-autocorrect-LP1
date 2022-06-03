cmake_minimum_required(VERSION 3.0)
project(Autocomplete)
include_directories(./include)
add_executable(
    words_complete_correct
    ./src/main.cpp
    ./src/LoadBase.cpp
    ./src/AutoComplete.cpp
    ./src/AutoCorrect.cpp
)

