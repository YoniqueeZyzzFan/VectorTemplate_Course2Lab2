cmake_minimum_required (VERSION 3.8)
add_executable (VectorTemplateTest "GoogleTest.cpp" "../VectorTemplate/Vector.h" "../VectorTemplate/Vector.inl")
target_link_libraries(VectorTemplateTest "gmock_main")