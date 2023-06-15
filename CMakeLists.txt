cmake_minimum_required(VERSION 3.24)
project(ucc_2023_trabajo_final)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(trabajo_final main.cpp  Transaccion.h Cliente.h transaccion.txt cliente.txt Cliente.cpp Transaccion.cpp Base_de_Datos.cpp Base_de_Datos.h)
