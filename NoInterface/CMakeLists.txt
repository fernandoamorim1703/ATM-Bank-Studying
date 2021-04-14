cmake_minimum_required(VERSION 3.5)

project(ATMBankStudy LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    main.cpp
    optionsaccount.cpp
    optionsaccount.h
    personaccount.h
    )

add_executable(ATMBankStudy ${SOURCES})

