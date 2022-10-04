add_library(CircularBuffer STATIC CircularBuffer.cpp)
target_compile_features(CircularBuffer PRIVATE cxx_std_20)
target_include_directories(CircularBuffer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# target_link_libraries(CircularBuffer FakeStereo AllPassFilter)
