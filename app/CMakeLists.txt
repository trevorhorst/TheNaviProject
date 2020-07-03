cmake_minimum_required( VERSION 3.5 )
project(controld)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(
    ${PROJECT_NAME}
    ${CONTROL_PROJECT}
    example
    pthread
    )

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CONTROL_BIN_DIR})
