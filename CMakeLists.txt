cmake_minimum_required(VERSION 3.30)
project(btn_lab5)

set(CMAKE_CXX_STANDARD 20)

# executables
add_executable(btn_lab5 main.cpp)
add_executable(server MenuDisplayServer.cpp
        inventory.cpp
        inventory.h
        product.h)
add_executable(client MenuDisplayClient.cpp
        inventory.cpp
        inventory.h
        product.h)

# link libraries
target_link_libraries(client ws2_32)
target_link_libraries(server ws2_32)
