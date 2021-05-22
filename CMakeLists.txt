cmake_minimum_required(VERSION 3.5)

project(QtWordReader LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
if (MSVC)
    add_compile_options("/utf-8")
endif ()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Gui REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS
        Core Gui
        REQUIRED)

add_library(QtWordReader SHARED
        WordReader.cpp WordReader.h
        )
target_compile_definitions(QtWordReader PRIVATE -DQtWordReader_LIBRARY)
target_include_directories(QtWordReader INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(QtWordReader PUBLIC
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::GuiPrivate
        )
    if (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_LIST_DIR})
        if (ANDROID)
            set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/android-build/libs/${CMAKE_ANDROID_ARCH_ABI}/)
            set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/android-build/libs/${CMAKE_ANDROID_ARCH_ABI}/)
        endif ()
qt_add_executable(WordReader
        MANUAL_FINALIZATION
        main.cpp
        )
target_link_libraries(WordReader PRIVATE
        QtWordReader
        )
if (QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(WordReader)
endif ()
endif()
