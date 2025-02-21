cmake_minimum_required(VERSION 3.14..3.31 FATAL_ERROR)

project(Hotwire
	VERSION 1
	LANGUAGES C)

add_library(hotwire src/dlopen.c)
add_library(hotwire::Hotwire ALIAS hotwire)

target_include_directories(hotwire PUBLIC include)
