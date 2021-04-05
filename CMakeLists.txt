cmake_minimum_required(VERSION 3.13)
project(cmake_testapp)
set(CMAKE_CXX_STANDARD 17)
add_executable(cmake_testapp src/main.c src/struct.h src/nieghbors.h src/nieghbors.c src/alloc.h src/alloc.c src/evolve.h src/evolve.c
        src/generator.h src/generator.c src/tester.h src/tester.c src/gifenc.c src/gifenc.h src/solver.c
        src/solver.h src/game.c src/game.h)