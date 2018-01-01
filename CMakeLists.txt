cmake_minimum_required(VERSION 3.9)
project(bioinformatics_project)

set(CMAKE_CXX_STANDARD 17)

add_executable(bioinformatics_project src/main.cpp src/shared/common.h src/rrr/RRRTable.cpp src/rrr/RRRTable.h src/rrr/RRRSequence.cpp src/rrr/RRRSequence.h src/wavelet/WaveletNode.cpp src/wavelet/WaveletNode.h)
