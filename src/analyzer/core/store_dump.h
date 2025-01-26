#ifndef CORE_STORE_DUMP_H
#define CORE_STORE_DUMP_H

#include <stdio.h>

#include "list.h"

/*
@brief сохранение массива StatData в файл
@param data список объектов StatData
@param stream файловы поток для вывода
*/
void store_dump(List *data, FILE *stream);

#endif
