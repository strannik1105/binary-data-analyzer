add_library(Processing SHARED
    processing.c
    )

target_link_libraries(Processing PRIVATE Core)

target_include_directories(Processing PUBLIC ${CMAKE_SOURCE_DIR}/analyzer)
