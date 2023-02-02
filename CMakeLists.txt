cmake_minimum_required(VERSION 3.16)
project(imgui-sfml-starter)

set(CMAKE_CXX_STANDARD 17)
# In CMake 3.12+ this policy will automatically take the ImGui_ROOT and SFML_ROOT environment variables
# into account as hints for the find_package calls.
if(POLICY CMP0074)
    cmake_policy(SET CMP0074 NEW)
endif()
# In CMake 3.13+ this policy enables you to define normal variables with option names as if you defined
# these options. Useful for add_subdirectory(ImGui-SFML)
if(POLICY CMP0077)
    cmake_policy(SET CMP0077 NEW)
endif()

#find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# 3rd party dependencies
add_subdirectory(lib)

add_executable(${PROJECT_NAME}
        src/main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE ImGui-SFML::ImGui-SFML sfml-graphics sfml-system docopt fmt::fmt-header-only spdlog nlohmann_json)

