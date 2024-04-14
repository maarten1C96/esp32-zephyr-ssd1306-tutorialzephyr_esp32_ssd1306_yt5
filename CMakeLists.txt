cmake_minimum_required(VERSION 3.22)
set(BOARD nucleo_h723zg)

find_package(Zephyr)
project(zephyr_ssd1306)

target_sources(app PRIVATE src/main.c)

# set(-DCOMPILE_DATE "\"$(date +'%Y-%m-%d')\"")
# set(-DCOMPILE_TIME "\"$(date +'%H:%M:%S')\"")

# Define compile-time constants
string(TIMESTAMP COMPILE_DATE "%Y-%m-%d")
string(TIMESTAMP COMPILE_TIME "%H:%M:%S")

# Pass these definitions to the compiler
add_definitions(-DCOMPILE_DATE="${COMPILE_DATE}")
add_definitions(-DCOMPILE_TIME="${COMPILE_TIME}")