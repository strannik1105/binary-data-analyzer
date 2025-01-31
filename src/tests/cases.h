#ifndef CASES_H
#define CASES_H

#include "core/stat_data.h"
#include "test_helper.h"

const StatData case1_in_a[2] = {
    {.id = 90889, .count = 13, .cost = 3.567, .primary = 0, .mode=3},
    {.id = 90089, .count = 1, .cost = 88.90, .primary = 1, .mode=0},
};
const StatData case1_in_b[2] = {
    {.id = 90889, .count = 13, .cost = 0.011, .primary = 0, .mode=2},
    {.id = 90189, .count = 1000, .cost = 1.00003, .primary = 1, .mode=2},
};

const StatData case1_out[3] = {
    {90189, 1000, 1.000030, 1, 2},
    {90889, 13, 3.578000, 0, 3},
    {90089, 1, 88.900002, 1, 0},
};

// const StatData case1_in_a[2] = {
//     {2, 2, 2.200000, 0, 1},
//     {4, 1, 1.100000, 0,1},
// };
// const StatData case1_in_b[2] = {
//     {2, 2, 2.200000, 0, 1},
//     {3, 1, 3.300000, 0,1},
// };

#endif
