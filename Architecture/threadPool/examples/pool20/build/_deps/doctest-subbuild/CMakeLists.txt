# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.14.5)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(doctest-populate NONE)

include(ExternalProject)
ExternalProject_Add(doctest-populate
                     "UPDATE_DISCONNECTED" "False" "GIT_REPOSITORY" "https://github.com/onqtam/doctest.git" "GIT_TAG" "2.4.5"
                    SOURCE_DIR          "/home/hungtran/Workspace/cpp/designPattern/Architecture/threadPool/examples/pool20/build/_deps/doctest-src"
                    BINARY_DIR          "/home/hungtran/Workspace/cpp/designPattern/Architecture/threadPool/examples/pool20/build/_deps/doctest-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
)
