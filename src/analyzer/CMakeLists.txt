add_subdirectory(core)
add_subdirectory(processing)

add_executable(analyzer main.c)

target_link_libraries(analyzer Core Processing)
