cmake_minimum_required(VERSION 3.0.0)
project(HW10_20_22 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(HW10_20_22 main.cpp log.cpp log_list.cpp)

set(CMAKE_CXX_STANDARD 17)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
