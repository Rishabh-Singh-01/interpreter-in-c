#include "int_auto_list.h"

#define AUTO_LIST_INITIAL_SIZE 16
#define AUTO_LIST_MULTIPLIER_FACTOR 2

int_auto_list* initialize_int_auto_list() {
    int_auto_list *p_auto_list = (int_auto_list*) malloc(sizeof(int_auto_list));

    if (!p_auto_list) {
        printf("Error: Unable to malloc during struct initialization of init_auto_list.");
        exit(EXIT_FAILURE);
    }

    int *p_malloc_list = (int *) malloc(AUTO_LIST_INITIAL_SIZE * sizeof(int));

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

void insert_int_auto_list(int_auto_list *p_auto_list, int data) {
    printf("Iside method: %d\n", data);

    assert(p_auto_list -> len <= p_auto_list -> size, "Length of the auto list is greater than its current size");

    if (p_auto_list -> len != p_auto_list -> size) {
        (p_auto_list -> p_list)[p_auto_list -> len] = data;
        (p_auto_list -> len)++;
        return;
    }

    p_auto_list -> size = (p_auto_list -> size) * AUTO_LIST_MULTIPLIER_FACTOR;

    int *p_realloc_list = (int *) realloc(p_auto_list -> p_list, p_auto_list -> size);

    if (!p_realloc_list) {
        printf("Error: Unable to realloc during list initialization of insert_int_auto_list.");
        free(p_auto_list -> p_list);
        free(p_auto_list);
        exit(EXIT_FAILURE);
    }
   
    p_auto_list -> p_list = p_realloc_list;
    (p_auto_list -> p_list)[p_auto_list -> len] = data;
    (p_auto_list -> len)++;
}

void free_int_auto_list(int_auto_list *p_auto_list) {
    free(p_auto_list -> p_list);
    free(p_auto_list);
}


