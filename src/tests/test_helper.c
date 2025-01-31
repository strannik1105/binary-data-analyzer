#include "test_helper.h"

#include "core/list.h"
#include "core/stat_data.h"


List *to_list(const StatData *data, size_t size) {
    List *lst = get_list_api().make_list();
    for (int i = 0; i < size; i++) {
        get_list_api().append(lst, (void *)&data[i]);
    }
    return lst;
}
