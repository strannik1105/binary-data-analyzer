#include "core/stat_data.h"

#include <stdio.h>

int main()
{
    FILE *f;
    f = fopen("t.txt", "w");
    StatData obj;
    obj.id = 1;
    obj.count = 2;
    obj.cost = 3.3;
    obj.primary = 0;
    obj.mode = 1;
    serialize(obj, f);
    fclose(f);
    printf("success serialize\n");

    f = fopen("t.txt", "r");
    struct OptionalStatData deserialized = deserialize(f);
    printf("%ld;%d;%f;%u;%u;\n", obj.id, obj.count, obj.cost, obj.primary, obj.mode);

    fclose(f);
    return 0;
}