
#include <stdio.h>
#include <stdlib.h>

#include "cases.h"
#include "core/dump.h"
#include "core/list.h"
#include "core/stat_data.h"
#include "processing/processing.h"
#include "test_helper.h"

void run_case(const StatData *in1, const StatData *in2, const StatData *out) {
    ProcessingApi api = get_processing_api();
    List *dump1_lst = to_list(in1, 2);
    List *dump2_lst = to_list(in2, 2);
    List *expected  = to_list(out, 3);
    FILE *f;

    f = fopen("test1.txt", "w");
    get_dump_api().store_dump(dump1_lst, f);
    fclose(f);

    f = fopen("test2.txt", "w");
    get_dump_api().store_dump(dump2_lst, f);
    fclose(f);

    system("build/analyzer/analyzer test1.txt test2.txt test_result.txt");

    f = fopen("test_result.txt", "r");
    List *after_exec = get_dump_api().load_dump(f);
    fclose(f);

    system("rm test1.txt test2.txt test_result.txt");

    printf("result %d\n", get_list_api().compare(after_exec, expected, eq));
}

#define RUN_CASE(case)  run_case(case##_in_a, case##_in_b, case##_out)

int main() { 
    RUN_CASE(case1);
}
