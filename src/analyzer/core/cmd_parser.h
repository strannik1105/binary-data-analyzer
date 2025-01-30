#ifndef CORE_PARSER_H
#define CORE_PARSER_H

#include <stdio.h>
#include <stdlib.h>

enum ParseStatus {
  CMD_SUCCESS,
  CMD_TOO_FEW_ARGS,
  CMD_TOO_MANY_ARGS,
  CMD_INCORRECT_ARGS
};

typedef struct {
  enum ParseStatus status;
  char *file1;
  char *file2;
  char *result_file;
} CMDParseResult;

typedef struct CMDParseApi {
  CMDParseResult *(*make_cmd_parse_result)(enum ParseStatus status, char *f1,
                                           char *f2, char *result_file);
  CMDParseResult *(*parse_cmd)(int argc, char *argv[]);
  void (*raise_from_result)(CMDParseResult *result);
} CMDParseApi;

CMDParseApi get_cmd_parse_api();

#endif
