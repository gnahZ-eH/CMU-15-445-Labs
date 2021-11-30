cmake_minimum_required(VERSION 3.0)
project(CMU_15_445_Labs)

set(CMAKE_CXX_STANDARD 14)

add_executable(CMU_15_445_Labs courses/database/cmu-15-445/src/include/storage/disk/disk_manager.h courses/database/cmu-15-445/src/include/hash/hash_table.h courses/database/cmu-15-445/src/include/hash/extendible_hash.h courses/database/cmu-15-445/src/hash/extendible_hash.cpp courses/database/cmu-15-445/src/hash/extendible_hash.h)
