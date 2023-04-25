include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

include(GoogleTest)

foreach(class ${CLASS_NAMES})
if (NOT ${class} IN_LIST HEADER_CLASS_NAMES)
set(NEED_HEADER, ${HEADER_CLASS_NAMES})
else()
set(NEED_HEADER, " ")
endif()
add_executable(${class}_test
                ${class}_test.cpp)
target_link_libraries(${class}_test
                        ${class}
                        ${NEED_HEADER}
                        gtest_main)
gtest_discover_tests(${class}_test)
endforeach()

