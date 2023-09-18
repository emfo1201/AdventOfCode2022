cmake_minimum_required(VERSION 3.0)

project(AdventOfCode2022)

# Loopa igenom deluppgiftsmapparna
file(GLOB subdirectories RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*)

foreach(subdir ${subdirectories})
    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${subdir})
        file(GLOB sources ${CMAKE_CURRENT_SOURCE_DIR}/${subdir}/*.cpp)
        if(sources)
            # Skapa en exekverbar fil för varje deluppgift
            add_executable(${subdir} ${sources})
        endif()
    endif()
endforeach()

