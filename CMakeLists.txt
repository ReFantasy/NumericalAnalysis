cmake_minimum_required(VERSION 3.0)

project(NumericalAnalysis)

# 库文件输出目录
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
# 可执行文件输出目录
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


# 第三方库
IF (WIN32)
        MESSAGE(STATUS "Now is windows")
	
ELSEIF (APPLE)
        MESSAGE(STATUS "Now is Apple systens.")
        
ELSEIF (UNIX)
        MESSAGE(STATUS "Now is UNIX-like OS's.")
ENDIF ()

add_executable(numerical main.cpp equation.h equation.cpp easylogging++.cc easylogging++.h
               global.h global.cpp)

