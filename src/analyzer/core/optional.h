#ifndef CORE_OPTIONAL_H
#define CORE_OPTIONAL_H

#include <stdbool.h>

#define OPTIONAL(T)     \
struct Optional##T      \
{                       \
    bool has_value;     \
    T value;            \
}                       \

#endif
