#ifndef CORE_OPTIONAL_H
#define CORE_OPTIONAL_H

#include <stdbool.h>

/**
 * @brief аналог std::optional из C++
 * @param T тип значения
 */
#define OPTIONAL(T)    \
  struct Optional##T { \
    T value;           \
    bool has_value;    \
  }

#endif
