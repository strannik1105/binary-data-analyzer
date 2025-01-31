
#include <stdio.h>

#include "core/dump.h"
#include "core/list.h"
#include "core/stat_data.h"
#include "processing/processing.h"
#include "test_helper.h"

void run_cases() {
    #include "cases.txt"

    ProcessingApi api = get_processing_api();
    List *dump1_lst = to_list(data1, 2);
    List *dump2_lst = to_list(data2, 2);
    StatData* cur = get_list_api().pop(dump1_lst);
    while (cur != NULL) {
        printf(" %ld %f %i\n", cur->id, cur->cost, cur->count);
        cur = get_list_api().pop(dump1_lst);
    }
    List *result = api.join_dump(dump1_lst, dump2_lst);

    api.sort_dump(result);
    FILE *f = fopen("test.txt", "w");
    get_dump_api().store_dump(result, f);
    fclose(f);
}

int main() { 
    run_cases();
}
