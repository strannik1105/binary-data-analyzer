add_subdirectory(core)

add_executable(analyzer main.c)

target_link_libraries(analyzer core)
