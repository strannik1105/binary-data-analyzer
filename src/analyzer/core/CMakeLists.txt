add_library(Core SHARED
    dump.c
    list.c
    map.c
    stat_data.c
    )

target_link_libraries(Core)