cmake_minimum_required(VERSION 3.21)
project(musicEloTesting)
set(CMAKE_CXX_STANDARD 14)

find_package(Threads REQUIRED) #needed to build google test
include(FetchContent) #so we can pull in google test
FetchContent_Declare( #declare information about google test
        googletest #its variable name
        #its location on the internet
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main #what branch we want
        )

#download google test
FetchContent_GetProperties(googletest)
if (NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
endif ()
#add this to the cmake command line -DINSTALL_GTEST=OFF
add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})

add_executable(musicEloTests
            unitTests.cpp
        )



target_link_libraries(musicEloTests
        PRIVATE
        musicEloSrc
        gtest #link in google test
        gmock #link in google mock
        gtest_main #add this one if you want to use google's basic main
        )

target_compile_options(musicEloTests PRIVATE -Wall -Werror)

