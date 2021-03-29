cmake_minimum_required(VERSION 3.1...3.19)

project(enumerate VERSION "1.0" LANGUAGES CXX)

get_directory_property(IS_SUBPROJECT PARENT_DIRECTORY)

# Establish the project options
option(ENUMERATE_BUILD_EXAMPLES "Set to ON to build examples" ON)
option(ENUMERATE_BUILD_TESTS "Set to ON to build tests" ON)

# Включение 17 стандарта.
set(CMAKE_CXX_STANDARD 17)

################################################################################
##
##      Опции компиляции
##
################################################################################

add_compile_options(
    -Werror

    -Wall
    -Wextra
    -Wpedantic

    -Wcast-align
    -Wcast-qual
    -Wconversion
    -Wctor-dtor-privacy
    -Wenum-compare
    -Wfloat-equal
    -Wnon-virtual-dtor
    -Wold-style-cast
    -Woverloaded-virtual
    -Wredundant-decls
    -Wsign-conversion
    -Wsign-promo
)

if(NOT CMAKE_CXX_EXTENSIONS)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif()

################################################################################
##
##      Заголовочная библиотека
##
################################################################################

add_library(enumerate INTERFACE)

target_include_directories(enumerate INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_compile_features(enumerate INTERFACE cxx_std_17)

add_library(mtl::enumerate ALIAS enumerate)

################################################################################
##
##      Пример использования
##
################################################################################

if (NOT ENUMERATE_BUILD_EXAMPLES)
    message(STATUS "Сборка примеров использования enumerate выключена")
elseif(IS_SUBPROJECT)
    message(STATUS "enumerate примеры не собираются в режиме подмодуля")
else()
    add_subdirectory(src)
endif()

################################################################################
##
##      Тесты
##
################################################################################

if(NOT ENUMERATE_BUILD_TESTS)
    message(STATUS "Тестирование проекта enumerate выключено")
elseif(IS_SUBPROJECT)
    message(STATUS "enumerate не тестируется в режиме подмодуля")
else()
    add_subdirectory(test)
endif()


