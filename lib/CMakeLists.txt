include(FetchContent)

FetchContent_Declare(
  sfml
  GIT_REPOSITORY "https://github.com/SFML/SFML"
  GIT_TAG 2.5.1
)
add_subdirectory(sfml)

FetchContent_Declare(
  imgui
  GIT_REPOSITORY https://github.com/ocornut/imgui
  GIT_TAG v1.89.2  #docking
#  GIT_TAG 35b1148efb839381b84de9290d9caf0b66ad7d03
)
message(STATUS "Fetching IMGUI...")
FetchContent_MakeAvailable(imgui)

FetchContent_Declare(
  imgui-sfml
  GIT_REPOSITORY https://github.com/eliasdaler/imgui-sfml
)
add_subdirectory(imgui-sfml)

FetchContent_Declare(
  fmtlib
  GIT_REPOSITORY https://github.com/fmtlib/fmt
  GIT_TAG 9.1.0
)
message(STATUS "Fetching FMT lib...")
FetchContent_MakeAvailable(fmtlib)

FetchContent_Declare(
  docopt
  GIT_REPOSITORY https://github.com/docopt/docopt.cpp
  GIT_TAG v0.6.3
)
message(STATUS "Fetching docopt...")
FetchContent_MakeAvailable(docopt)

FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog
  GIT_TAG v1.11.0
)
message(STATUS "Fetching spdlog...")
#set(SPDLOG_FMT_EXTERNAL_HO, TRUE)
FetchContent_MakeAvailable(spdlog)
FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.11.2
)
message(STATUS "Fetching nlohmann/json...")
FetchContent_MakeAvailable(json)