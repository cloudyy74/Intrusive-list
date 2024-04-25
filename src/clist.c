#include "clist.h"

void init_list(intrusive_list_t* node_list) {
	node_list->head = malloc(sizeof(intrusive_node_t));
	(node_list->head)->prev = NULL;
	(node_list->head)->next = NULL;
}

void add_node(intrusive_list_t* node_list, intrusive_node_t* node) {
	intrusive_node_t* head = node_list->head;
    if (head->next != NULL)
    {
    	node->prev = head;
    	node->next = head->next;
        (head->next)->prev = node;
        head->next = node;
    }
    else
    {
        node->prev = head;
        node->next = NULL;
        head->next = node;
    }
}

void remove_node(intrusive_node_t* node) {
	if (!node->prev) {
		(node->next)->prev = NULL;
	}
	else if (!node->next) {
		(node->prev)->next = NULL;
 	}
 	else {
 		(node->prev)->next = node->next;
 		(node->next)->prev = node->prev;
 	}
}

int get_length(intrusive_list_t* node_list) {
	int length = 0;
	intrusive_node_t* current = node_list->head;
	while (current->next != NULL) {
		length++;
		current = current->next;
	}
	return length;
}