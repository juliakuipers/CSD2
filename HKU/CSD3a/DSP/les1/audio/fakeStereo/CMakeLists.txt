add_library(FakeStereo STATIC fakeStereo.cpp)
target_compile_features(FakeStereo PRIVATE cxx_std_20)
target_include_directories(FakeStereo PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(FakeStereo CircularBuffer AllPassFilter)
