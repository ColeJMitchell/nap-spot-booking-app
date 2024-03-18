cmake_minimum_required(VERSION 3.22)
project(gold)

set(CMAKE_CXX_STANDARD 17)

include_directories(dbtools)
add_executable(gold main.cpp
        dbtools/Insert.cpp
        dbtools/Insert.h
        dbtools/Delete.cpp
        dbtools/Delete.h
        dbtools/Update.cpp
        dbtools/Update.h
        dbtools/Select.cpp
        dbtools/Select.h
)
target_link_libraries(gold sqlite3)

include_directories(test)
include_directories(googletest googletest/include googletest/include/gtest)
add_executable(tests googletest/src/gtest-all.cc
        test/unittest.cpp
        dbtools/Insert.cpp
        dbtools/Insert.h
        dbtools/Delete.cpp
        dbtools/Delete.h
        dbtools/Update.cpp
        dbtools/Update.h
        dbtools/Select.cpp
        dbtools/Select.h
)
target_link_libraries(tests sqlite3)