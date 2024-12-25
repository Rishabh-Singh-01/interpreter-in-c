#ifndef STD_DS_AUTO_LISTS_VOID_PTR_AUTO_LIST
#define STD_DS_AUTO_LISTS_VOID_PTR_AUTO_LIST

#include "./../../assertions/assert_conditions.h"

typedef struct VoidPtrAutoList {
    void* p_list;
    size_t len;
    size_t size;
} void_ptr_auto_list;

void_ptr_auto_list* initialize_void_ptr_auto_list();
void insert_void_ptr_auto_list(void_ptr_auto_list *p_auto_list, void* data);
void free_void_ptr_auto_list(void_ptr_auto_list *p_auto_list);

#endif
