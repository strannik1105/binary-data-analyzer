#ifndef CORE_UTILS_H
#define CORE_UTILS_H

#include <stdio.h>
#include <stdlib.h>

// TODO: вынести в отдельный модуль, сделать структуру для ошибок и маппер
void err_exit(char* message) {
  printf("%s\n", message);
  exit(1);
}

#endif
