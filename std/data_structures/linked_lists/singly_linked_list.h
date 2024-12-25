typedef struct SinglyLinkedListNode {
    void *p_data;
    struct SinglyLinkedListNode *p_next;
} singly_linked_list_node;

singly_linked_list_node* new_node_singly_linked_list_node();
singly_linked_list_node* add_tail_node_singly_linked_list_node();

