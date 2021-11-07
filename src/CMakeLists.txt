cmake_minimum_required(VERSION 2.6)
project(timeserver)

add_executable(timeserver main.c)

INSTALL(TARGETS timeserver RUNTIME DESTINATION /usr/bin/)
