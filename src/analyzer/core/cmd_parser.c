#include "cmd_parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

CMDParseResult *make_cmd_parse_result(enum ParseStatus status, char *f1,
                                      char *f2, char *result_file) {
  CMDParseResult *ptr = malloc(sizeof(CMDParseResult));
  ptr->status = status;
  ptr->file1 = f1;
  ptr->file2 = f2;
  ptr->result_file = result_file;

  return ptr;
}

CMDParseResult *parse_cmd(int argc, char *argv[]) {
  // По хорошему загонять их в маппу, но для экономии времени так
  const char *eq_type = argv[1];
  enum ParseStatus status = CMD_SUCCESS;
  char *file1 = NULL;
  char *file2 = NULL;
  char *result_file = NULL;

  if (strcmp(eq_type, "-h") == 0) {
    printf("Params: \n");
    printf("\t<file1> <file2> <result_file>\n");
    printf("\n");
    printf("Ex: ./binary-analyzer dump1.txt dump2.txt result.txt\n");
    status = CMD_SUCCESS;
  } else {
    if (argc < 4) {
      status = CMD_TOO_FEW_ARGS;
    } else if (argc > 4) {
      status = CMD_TOO_MANY_ARGS;
    } else {
      char *file1 = argv[1];
      char *file2 = argv[2];
      char *result_file = argv[3];
      return make_cmd_parse_result(status, file1, file2, result_file);
    }
  }
  return make_cmd_parse_result(status, file1, file2, result_file);
}

void raise_from_result(CMDParseResult *result) {
  switch (result->status) {
    case CMD_SUCCESS:
      if ((result->file1 == NULL) || (result->file2 == NULL) ||
          (result->result_file == NULL))
        exit(0);
      break;
    case CMD_INCORRECT_ARGS:
      err_exit("Некорректное число параметров");
    case CMD_TOO_FEW_ARGS:
      err_exit("Слишком мало параметров");
    case CMD_TOO_MANY_ARGS:
      err_exit("Слишком много параметров");
  }
}

CMDParseApi get_cmd_parse_api() {
  CMDParseApi api;
  api.make_cmd_parse_result = make_cmd_parse_result;
  api.parse_cmd = parse_cmd;
  api.raise_from_result = raise_from_result;

  return api;
}
