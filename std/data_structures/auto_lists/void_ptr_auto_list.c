#include <stdio.h>
#include <stdlib.h>

#include "void_ptr_auto_list.h"

#define AUTO_LIST_INITIAL_SIZE 16
#define AUTO_LIST_MULTIPLIER_FACTOR 2

void_ptr_auto_list* initialize_void_ptr_auto_list() {
    void_ptr_auto_list *p_auto_list = (void_ptr_auto_list*) malloc(sizeof(void_ptr_auto_list));

    if (!p_auto_list) {
        printf("Error: Unable to malloc during struct initialization of void_ptr_auto_list.");
        exit(EXIT_FAILURE);
    }

    void** p_malloc_list = (void**) malloc(AUTO_LIST_INITIAL_SIZE * sizeof(void*));

    if (!p_malloc_list) {
        printf("Error: Unable to malloc during list initialization of init_auto_list.");
        free(p_auto_list);
        exit(EXIT_FAILURE);
    }

    p_auto_list -> p_list = p_malloc_list;
    p_auto_list -> len = 0;
    p_auto_list -> size = AUTO_LIST_INITIAL_SIZE;

    return p_auto_list;
}

void insert_void_ptr_auto_list(void_ptr_auto_list *p_auto_list, void* data) {

    assert(p_auto_list -> len <= p_auto_list -> size, "Length of the auto list is greater than its current size");

    if (p_auto_list -> len != p_auto_list -> size) {
        (p_auto_list -> len)++;
        void* p_temp = (p_auto_list -> p_list) + p_auto_list -> len;
        p_temp = data;
        return;
    }

    p_auto_list -> size = (p_auto_list -> size) * AUTO_LIST_MULTIPLIER_FACTOR;

    void** p_realloc_list = (void**) realloc(p_auto_list -> p_list, p_auto_list -> size);

    if (!p_realloc_list) {
        printf("Error: Unable to realloc during list initialization of insert_void_ptr_auto_list.");
        free(p_auto_list -> p_list);
        free(p_auto_list);
        exit(EXIT_FAILURE);
    }
}

void free_void_ptr_auto_list(void_ptr_auto_list *p_auto_list) {
    free(p_auto_list -> p_list);
    free(p_auto_list);
}
