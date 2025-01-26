#ifndef CORE_STAT_DATA_H
#define CORE_STAT_DATA_H

#include <stdio.h>

#include "optional.h"

typedef struct StatData {
  long id;
  int count;
  float cost;
  unsigned int primary : 1;
  unsigned int mode : 3;
} StatData;

/*
@brief сериализация StatData
@param obj объект StatData
@param stream файловый поток в который будет записан объект
*/
void serialize(const StatData obj, FILE *stream);

/*
@brief десериализация StatData
@param stream файловый поток из которого будет создан объект
@return объект StatDatas
*/
OPTIONAL(StatData) deserialize(FILE *stream);

#endif
