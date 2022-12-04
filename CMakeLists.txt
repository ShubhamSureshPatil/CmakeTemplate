cmake_minimum_required(VERSION 3.16.0)
set(BOOST_ROOT /usr/local/boost)
include_directories(include)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_OSX_ARCHITECTURES "x86_64")
set(CMAKE_BUILD_TYPE debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

message(STATUS "CMake version: ${CMAKE_VERSION}")

project(learn_cmake)

option(USE_CUDA "Use CUDA" ON)

file(GLOB cpu_source_files "${CMAKE_SOURCE_DIR}/src/*.cc")
file(GLOB gpu_source_files "${CMAKE_SOURCE_DIR}/src/*.cu")

set(Torch_DIR  ~/Packages/libtorch/share/cmake/Torch)
find_package(Torch PATHS ${Torch_DIR} NO_DEFAULT REQUIRED)
find_package(Torch REQUIRED)
if (Torch_FOUND)
    message(STATUS "Torch library found!")
    message(STATUS "    include path: ${TORCH_INCLUDE_DIRS}" \n)
else ()
    message(FATAL_ERROR "Could not locate Torch" \n)
endif()


if(USE_CUDA)
    enable_language("CUDA")
    add_executable(learn_cmake ${cpu_source_files} ${gpu_source_files})
else(USE_CUDA)
    add_executable(learn_cmake ${cpu_source_files})
endif()

message(STATUS "USE_CUDA: ${USE_CUDA}")
if(USE_CUDA)
    add_definitions(-DUSE_CUDA)
endif()

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

target_link_libraries(learn_cmake "${TORCH_LIBRARIES}"
                                  "${OpenCV_LIBS}"
                     )

# target_link_libraries (
#         ${CMAKE_PROJECT_NAME}
#         ${OpenCV_LIBS}
#         ${TORCH_LIBRARIES}
# )
