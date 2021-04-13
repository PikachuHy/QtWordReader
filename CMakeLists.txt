cmake_minimum_required(VERSION 3.5)

project(QtWordReader LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
if(MSVC)
    add_compile_options("/utf-8")
endif()
find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Gui REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS
        Core Gui
        REQUIRED)


set(PROJECT_SOURCES
        WordReader.cpp WordReader.h
        )

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    add_library(QtWordReader ${PROJECT_SOURCES})
else()
    if(ANDROID)
        add_library(MyNotes SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_library(QtWordReader ${PROJECT_SOURCES})
    endif()

endif()
target_include_directories(QtWordReader INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(QtWordReader PRIVATE
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::GuiPrivate
        )
add_executable(WordReader main.cpp)
target_link_libraries(WordReader PRIVATE
        Qt${QT_VERSION_MAJOR}::Core
        QtWordReader)