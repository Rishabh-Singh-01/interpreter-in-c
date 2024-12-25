#include <stddef.h>
#include <stdlib.h>

#include "singly_linked_list.h"

singly_linked_list_node* initialize_node_singly_linked_list() {
    singly_linked_list_node *p_sll_node = (singly_linked_list_node*) malloc(sizeof(singly_linked_list_node));
    p_sll_node -> p_data = NULL;
    p_sll_node -> p_next = NULL;
    return p_sll_node;
}

void add_data_node_singly_linked_list(singly_linked_list_node *p_sll_node, void *p_data) {
    p_sll_node -> p_data = p_data;
}

void point_to_next_node_singly_linked_list(singly_linked_list_node *p_sll_node, singly_linked_list_node *p_next_sll_node) {
    p_sll_node -> p_next = p_next_sll_node;
}

singly_linked_list_node* add_tail_node_singly_linked_list(singly_linked_list_node* p_prev_sll_node, void *p_data) {
    singly_linked_list_node *p_cur_sll_node = initialize_node_singly_linked_list();
    add_data_node_singly_linked_list(p_cur_sll_node, p_data);
    point_to_next_node_singly_linked_list(p_prev_sll_node, p_cur_sll_node);
    return p_cur_sll_node;
}

void free_singly_linked_list(singly_linked_list_node *p_head_sll) {
    singly_linked_list_node *temp = p_head_sll;
    singly_linked_list_node *next = NULL;

    while (temp != NULL) {
        next = temp -> p_next;
        free(temp);
        temp = next;
    }
}
