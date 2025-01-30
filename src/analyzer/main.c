#include <stdio.h>

#include "core/cmd_parser.h"
#include "core/dump.h"
#include "core/list.h"
#include "core/utils.h"
#include "processing/processing.h"

int main(int argc, char *argv[]) {
  CMDParseApi cmd_api = get_cmd_parse_api();
  CMDParseResult *parse_result = cmd_api.parse_cmd(argc, argv);
  cmd_api.raise_from_result(parse_result);

  FILE *f;
  DumpApi dump_api = get_dump_api();
  ProcessingApi processing_api = get_processing_api();
  List *dump1;
  List *dump2;

  if (!(f = fopen(parse_result->file1, "r"))) {
    err_exit("Ошибка чтения файла");
  }
  dump1 = dump_api.load_dump(f);

  if (!(f = fopen(parse_result->file2, "r"))) {
    err_exit("Ошибка чтения файла");
  }
  dump2 = dump_api.load_dump(f);

  List *joined_list = processing_api.join_dump(dump1, dump2);
  processing_api.sort_dump(joined_list);

  f = fopen(parse_result->result_file, "w");
  dump_api.store_dump(joined_list, f);
  fclose(f);

  return 0;
}