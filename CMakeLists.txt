cmake_minimum_required(VERSION 3.5)

project(BankOfStudy LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(SOURCES
    main.cpp
    optionsaccounts.cpp
    optionsaccounts.h
    personaccount.h
)

add_executable(BankOfStudy ${SOURCES})
