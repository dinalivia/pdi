cmake_minimum_required(VERSION 3.6)

project(DigitalImageProcessing)
 
find_package(OpenCV REQUIRED)

set(PDI_INCLUDE_DIRS
    ${CMAKE_SOURCE_DIR}
    ${OpenCV_INCLUDE_DIRS}
)

set(PDI_LIBRARIES
    ${OpenCV_LIBS}
)

# The list of examples to be compiled goes here.
set(PDI_EXAMPLES_SOURCES
    example.cpp
    negative.cpp
    troca_regioes.cpp
    bolhas.cpp
    histogram.cpp
    equalize.cpp
    motiondetector.cpp
    laplgauss.cpp
    filtroespacial.cpp
    tiltyshift.cpp
    addweighted.cpp
    tiltyshiftvideo.cpp
    dft.cpp
    homomorphic.cpp
    canny.cpp
    pointillism-sample.cpp
    pointillism.cpp
    k-means.cpp
    autocorrection.cpp
    gabarito.cpp


)

foreach(_source IN ITEMS ${PDI_EXAMPLES_SOURCES})
    # Extract name from filename without suffix and directory.
    # E.g. test/example.cpp -> example
    #      _source          -> _target
    get_filename_component(_target ${_source} NAME_WE)

    # The process of adding an executable.
    add_executable(${_target} ${_source})
    target_include_directories(${_target} PUBLIC ${PDI_INCLUDE_DIRS})
    target_link_libraries(${_target} PUBLIC ${PDI_LIBRARIES})
endforeach()