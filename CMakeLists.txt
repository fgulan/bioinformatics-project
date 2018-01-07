cmake_minimum_required(VERSION 3.9)
project(bioinformatics_project)

set(CMAKE_CXX_STANDARD 17)


add_library(wavelet_lib
        src/shared/common.h
        src/rrr/RRRTable.cpp
        src/rrr/RRRTable.h
        src/rrr/RRRSequence.cpp
        src/rrr/RRRSequence.h
        src/wavelet/WaveletNode.cpp
        src/wavelet/WaveletNode.h
        src/wavelet/WaveletTree.cpp
        src/wavelet/WaveletTree.h
        src/utility/bioinf_utility.cpp
        src/utility/bioinf_utility.h)


add_executable(run_tests
        tests/catch.h
        tests/rrr_sequence_tests.cpp)

target_link_libraries(run_tests
        wavelet_lib)


add_executable(bioinformatics_project
        src/main.cpp)

target_link_libraries(bioinformatics_project
        wavelet_lib)
