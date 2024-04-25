#ifndef CLIST_H_

#include <stddef.h>
#include <stdlib.h>

#define CLIST_H_
#define container_of(ptr, type, member) (type*)((char*)(ptr) - offsetof(type, member))

typedef struct intrusive_node intrusive_node_t;
typedef struct intrusive_list intrusive_list_t;

struct intrusive_node {
    struct intrusive_node* next;
    struct intrusive_node* prev;
};
  
struct intrusive_list {
    intrusive_node_t* head;
};

void init_list(intrusive_list_t* node_list);
void add_node(intrusive_list_t* node_list, intrusive_node_t* node);
void remove_node(intrusive_node_t* node);

int get_length(intrusive_list_t* node_list);

#endif
