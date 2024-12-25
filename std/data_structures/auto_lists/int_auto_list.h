#ifndef STD_DS_AUTO_LISTS_INT_AUTO_LIST
#define STD_DS_AUTO_LISTS_INT_AUTO_LIST

#include <stdio.h>
#include <stdlib.h>
#include "./../../loggers/log.h"
#include "./../../assertions/assert_conditions.h"

typedef struct IntAutoList {
    int* p_list;
    size_t len;
    size_t size;
} int_auto_list;


int_auto_list* initialize_int_auto_list();
void insert_int_auto_list(int_auto_list *p_auto_list, int data);
void free_int_auto_list(int_auto_list *p_auto_list);

#endif
