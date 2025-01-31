add_executable(tests 
    main.c
    test_helper.c
)

target_link_libraries(tests Core Processing)
