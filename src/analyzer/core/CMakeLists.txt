add_library(Core SHARED
    cmd_parser.c
    dump.c
    list.c
    map.c
    stat_data.c
    )

target_link_libraries(Core)