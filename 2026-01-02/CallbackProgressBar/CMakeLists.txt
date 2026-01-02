cmake_minimum_required(VERSION 3.25.0)

# Configure for x86 (32-bit) build:
#   cmake .. -A Win32

#-----------------------------------------------------
# Edit project-specific information
#-----------------------------------------------------

set(EXECUTABLE prog)

#-----------------------------------------------------
# Usually leave the rest untouched
#-----------------------------------------------------

project(${EXECUTABLE} VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Use stricter compiler warnings
if(MSVC)
    # Microsoft Visual C++
    add_compile_options(/EHsc /W4 /Za) 
    include_directories(/VC_Extra/include)
    link_directories(C:/VC_Extra/lib)
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${EXECUTABLE})
else()
    # GCC and Clang
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

file(GLOB SRCS_LIST "*.cpp" "*.h")

add_executable(${EXECUTABLE} ${SRCS_LIST})

if(MSVC)
    # Microsoft Visual C++
    target_link_libraries(${EXECUTABLE} glut32.lib)
    # Copy the glut32.dll to the executable folder
    ADD_CUSTOM_COMMAND(TARGET ${EXECUTABLE}
                       POST_BUILD
                       COMMAND ${CMAKE_COMMAND} -E 
                              copy c:/VC_Extra/bin/glut32.dll 
                                   ${PROJECT_BINARY_DIR}/Debug/.
    )
elseif(MINGW)
    # MSYS2
    target_link_libraries(${EXECUTABLE} freeglut.lib opengl32.lib glu32.lib)
else()
    # GCC and Clang
    target_link_libraries(${EXECUTABLE} glut GL GLU)
endif()


