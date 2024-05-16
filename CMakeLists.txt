cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)

project(PrototypePattern)

set(SOURCE_FILES flyweight/Flyweight.cpp)

add_executable(PrototypePattern ${SOURCE_FILES})

enable_testing()

# Подключение библиотеки Google Test
add_subdirectory(third-party/gtest)
include_directories(third-party/gtest/googletest/include)

# Добавление исполняемого файла для теста
add_executable(flyweighttest tests/FlyweightTest.cpp)
target_link_libraries(flyweighttest gtest gtest_main)
add_test(NAME flyweighttest COMMAND flyweighttest)
