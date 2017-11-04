project(sfml-packman)
cmake_minimum_required(VERSION 3.8)

# Ищем статическую версию библиотек SFML и её зависимостей
set(SFML_STATIC_LIBRARIES TRUE)
find_package(Freetype REQUIRED)
find_package(JPEG REQUIRED)
find_package(SFML 2 COMPONENTS window graphics system REQUIRED)

# Функция add_sample добавляет подкаталог с примером и подключает SFML
# Имя подкаталога становится именем цели сборки (и исполняемого файла)
function(add_sample NAME)
    # Собираем файлы с указанных каталогов
    foreach(DIR ${ARGN})
        file(GLOB TARGET_SRC_PART "${CMAKE_CURRENT_SOURCE_DIR}/${DIR}/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/${DIR}/*.h")
        list(APPEND TARGET_SRC ${TARGET_SRC_PART})
    endforeach()
    add_executable(${NAME} ${TARGET_SRC})
    target_include_directories(${NAME} PRIVATE ${SFML_INCLUDE_DIR} ${JPEG_INCLUDE_DIR} ${FREETYPE_INCLUDE_DIRS})
    target_compile_features(${NAME} PUBLIC cxx_std_17)
    target_compile_definitions(${NAME} PRIVATE SFML_STATIC)
    target_link_libraries(${NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} ${JPEG_LIBRARIES} ${FREETYPE_LIBRARIES})
    if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
        target_compile_options(${NAME} PUBLIC "-Wall" "-Wextra" "-Wno-implicit-fallthrough")
    endif()
endfunction()

add_sample(sfml_tmx_demo src lib/tinyxml2)
