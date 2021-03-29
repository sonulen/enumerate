add_executable(enumerate-unit-tests main.cpp)

target_link_libraries(
    enumerate-unit-tests
    PRIVATE enumerate
)

add_custom_target(check ALL COMMAND enumerate-unit-tests)