#ifndef CORE_LIST_H
#define CORE_LIST_H

#define DEFINE_LIST(T)              \
struct __Node##T                   \
{                                   \
    T value;                        \
    struct __Node##T *next;        \
};                                  \
                                    \
struct __List##T                   \
{                                   \
    struct __Node##T *root;        \
}                                   \

#define LIST(T) struct __List##T

#endif