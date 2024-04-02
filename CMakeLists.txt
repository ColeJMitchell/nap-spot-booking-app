cmake_minimum_required(VERSION 3.22)
project(gold)
find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)
include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

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
        frontend/gui.cpp
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
add_executable(frontend frontend/gui.cpp
        dbtools/Insert.cpp
        dbtools/Insert.h
        dbtools/Delete.cpp
        dbtools/Delete.h
        dbtools/Update.cpp
        dbtools/Update.h
        dbtools/Select.cpp
        dbtools/Select.h
        frontend/gui.cpp
        frontend/Button.cpp
        frontend/Button.h
)
target_link_libraries(tests sqlite3)
target_link_libraries(frontend ${GTKMM_LIBRARIES})
target_link_libraries(frontend sqlite3)