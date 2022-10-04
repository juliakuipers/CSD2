add_library(Oscillators STATIC 1dFastNoise.cpp oscillator.cpp )
target_compile_features(Oscillators PRIVATE cxx_std_20)
target_include_directories(Oscillators PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# target_link_libraries(Oscillators samplebasedfilters utilities circbuffer)
