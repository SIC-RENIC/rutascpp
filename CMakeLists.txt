cmake_minimum_required(VERSION 3.15)
project(rutascpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(rutascpp src/main.cpp src/rutascpp.h src/LectorLocs.cpp src/LectorLocs.h src/LectorRutas.cpp src/LectorRutas.h src/Algoritmo.cpp src/Algoritmo.h src/Localidad.h src/LocalidadE.cpp src/Salida.cpp src/Salida.h)