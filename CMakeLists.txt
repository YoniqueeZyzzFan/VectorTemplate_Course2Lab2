# CMakeList.txt : CMake project for Lab2, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Lab2")

# Add source to this project's executable.
add_executable (main "VectorTemplate/main.cpp" "VectorTemplate/Vector.h" "VectorTemplate/Vector.cpp")

# Включение высокого уровня предупреждений
if(MSVC) # Компилятор MSVC /W3
    if(CMAKE_C_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
    else()
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /W4")
    endif()
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
    add_compile_options(/experimental:external /external:anglebrackets /external:W0)
elseif(CMAKE_COMPILER_IS_GNUCC) # Компилятор GCC    
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wconversion -Wextra -Wpedantic")
endif()
