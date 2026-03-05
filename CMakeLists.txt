cmake_minimum_required(VERSION 3.10)

project(COP4533-PA2-GreedyAlgorithms)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(src)

set(SOURCES
        src/main.cpp
        src/input_handler.cpp
        src/fifo.cpp
        src/lru.cpp
        src/optff.cpp
        src/input_handler.h
        src/fifo.h
        src/lru.h
        src/optff.h

)

add_executable(cache_evictions ${SOURCES})
set_target_properties(cache_evictions PROPERTIES SUFFIX ".exe")

add_custom_command(TARGET cache_evictions POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/data
        ${CMAKE_CURRENT_BINARY_DIR}/data
        COMMENT "Copying data folder to build directory..."
)

add_custom_command(TARGET cache_evictions POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:cache_evictions>
        ${CMAKE_BINARY_DIR}/cache_evictions.exe
        COMMENT "Copying executable to build directory..."
)