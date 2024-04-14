cmake_minimum_required(VERSION 3.22)
set(BOARD nucleo_h723zg)

find_package(Zephyr)
project(zephyr_ssd1306)

target_sources(app PRIVATE src/main.c)
