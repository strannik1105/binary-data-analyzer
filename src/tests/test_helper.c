#include "test_helper.h"

#include "core/list.h"
#include "core/stat_data.h"

List *to_list(const StatData *data, size_t size) {
  List *lst = get_list_api().make_list();
  for (int i = 0; i < size; i++) {
    get_list_api().append(lst, (void *)&data[i]);
  }
  return lst;
}

bool run_case(const StatData *in1, size_t in1_size, const StatData *in2,
              size_t in2_size, const StatData *out, size_t out_size) {
  ProcessingApi api = get_processing_api();
  List *dump1_lst = to_list(in1, in1_size);
  List *dump2_lst = to_list(in2, in2_size);
  List *expected = to_list(out, out_size);
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

  return get_list_api().compare(after_exec, expected, eq);
}
