cmake_minimum_required(VERSION 3.5)

project(NumericalAnalysis)

# 库文件输出目录
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
# 可执行文件输出目录
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)


set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 第三方库
IF (WIN32)
        MESSAGE(STATUS "Now is windows")
		include_directories(${PROJECT_BINARYs_DIR}/eigen)

ELSEIF (APPLE)
        MESSAGE(STATUS "Now is Apple systens.")
        
ELSEIF (UNIX)
        MESSAGE(STATUS "Now is UNIX-like OS's.")
ENDIF ()

add_executable(na main.cpp nonlinear_equation.h nonlinear_equation.cpp)

