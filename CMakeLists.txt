cmake_minimum_required(VERSION 3.10)
project(4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавление опций компиляции
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=maybe-uninitialized")

# Установка Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.0
  TLS_VERIFY false
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Создаем библиотеку (только заголовки - INTERFACE)
add_library(${CMAKE_PROJECT_NAME}_lib INTERFACE)

# Указываем include директории для библиотеки
target_include_directories(${CMAKE_PROJECT_NAME}_lib INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Создаем исполняемый файл основной программы
add_executable(${CMAKE_PROJECT_NAME}_exe main.cpp)

# Связываем библиотеку с исполняемым файлом
target_link_libraries(${CMAKE_PROJECT_NAME}_exe PRIVATE ${CMAKE_PROJECT_NAME}_lib)

# Указываем include директории для исполняемого файла
target_include_directories(${CMAKE_PROJECT_NAME}_exe PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Добавление тестов
enable_testing()

add_executable(tests test/test_figures.cpp)
target_link_libraries(tests ${CMAKE_PROJECT_NAME}_lib gtest_main)

# Указываем include директории для тестов
target_include_directories(tests PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Добавление тестов в тестовый набор
add_test(NAME GeometryFiguresTests COMMAND tests)