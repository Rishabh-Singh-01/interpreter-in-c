#include "../linked_lists/singly_linked_list.h"
#include "vector.h"

const size_t STATIC_ARRAY_SIZE = 255;
const char VECTOR_END_CHAR = '\0';

// TODO: think of a way to return more generic ptr instead of singly_linked_list_node* or void*
void* initialize_char_vector() {
    // TODO: handle any errors due to malloc
    char *p_arr = (char*) malloc(sizeof(char) * STATIC_ARRAY_SIZE);

    singly_linked_list_node *p_head = initialize_node_singly_linked_list();
    add_data_node_singly_linked_list(p_head, p_arr);

    return (void *) p_head; 
}

void* traverse_to_last_elem_char_vector(void *p_vector) {
    singly_linked_list_node *p_sll_temp = (singly_linked_list_node*) p_vector;
    size_t static_array_size = STATIC_ARRAY_SIZE;

    while (p_sll_temp != NULL) {
        char *p_arr = p_sll_temp -> p_data;

        while ((*p_arr != VECTOR_END_CHAR) || (static_array_size != 0)) {
            p_arr++;
        }

        if (*p_arr == VECTOR_END_CHAR)
            return (void*) p_arr;

        static_array_size = STATIC_ARRAY_SIZE;
        p_sll_temp = p_sll_temp -> p_next;
    }

    exit(EXIT_FAILURE);
}

void add_nth_char_vector(void *p_vector, char c, size_t nth_pos) {
    size_t sll_node_num = nth_pos / STATIC_ARRAY_SIZE;
    size_t arr_num = nth_pos % STATIC_ARRAY_SIZE;

    singly_linked_list_node *sll_node_temp = (singly_linked_list_node*) p_vector;
    while (sll_node_num != 0) {
        if (sll_node_temp -> p_next == NULL) {
            singly_linked_list_node *sll_node_next = initialize_node_singly_linked_list();

            sll_node_temp -> p_next = sll_node_next;
        }

        sll_node_temp = sll_node_temp -> next;
    }

    char *p_arr = NULL;

    if (sll_node_temp -> p_data == NULL) {
        *p_arr = (char*) malloc(sizeof(char) * STATIC_ARRAY_SIZE);
        add_data_node_singly_linked_list(sll_node_temp, p_arr);
    }

    *(p_arr + arr_num) = c;
}
