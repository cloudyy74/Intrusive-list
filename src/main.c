#include "clist.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct point point_t;

struct point {
    int x, y;
    intrusive_node_t node;
};

void add_point(intrusive_list_t* node_list, int x, int y) {
    point_t* point = malloc(sizeof(point_t));
    point->x = x;
    point->y = y;
    add_node(node_list, &(point->node));
}

void remove_point(intrusive_list_t* node_list, int x, int y) { // removes all (x, y) pairs
    intrusive_node_t* previous = node_list->head;
    while (previous->next != NULL) {
        intrusive_node_t* current = previous->next;
        point_t* point = container_of(current, point_t, node);
        if (point->x == x && point->y == y) {
            remove_node(current);
            free(point);
        }
        else {
            previous = previous->next; 
        }
    }
}

void show_point(point_t* point) {
    printf("(%d %d)", point->x, point->y);
}

void show_all_points(intrusive_list_t* node_list) {
    intrusive_node_t* current = node_list->head;
    while (current->next != NULL)
    {
        current = current->next;
        point_t* point = container_of(current, point_t, node);
        show_point(point);
        if (current->next != NULL)
            printf(" ");
    }
    printf("\n");
}

void remove_all_points(intrusive_list_t* node_list) {
    intrusive_node_t* previous = node_list->head;
    while (previous->next != NULL) {
        intrusive_node_t* current = previous->next;
        point_t* point = container_of(current, point_t, node);
        remove_node(current);
        free(point);
    }
}

int main() {
    intrusive_list_t node_list;
    init_list(&node_list);

    char command[239];

    while (true) {
        scanf("%239s", command);

        if (strcmp(command, "add") == 0) {
            int x, y;
            scanf("%d %d", &x, &y);
            add_point(&node_list, x, y);
        }

        else if (strcmp(command, "rm") == 0) {
            int x, y;
            scanf("%d %d", &x, &y);
            remove_point(&node_list, x, y);
        }

        else if (strcmp(command, "rma") == 0) {
            remove_all_points(&node_list);
        }

        else if (strcmp(command, "print") == 0) {
            show_all_points(&node_list);
        }

        else if (strcmp(command, "len") == 0) {
            printf("%d\n", get_length(&node_list));
        }

        else if (strcmp(command, "exit") == 0) {
            remove_all_points(&node_list);
            free(node_list.head);
            break;
        }

        else {
            printf("Unknown command\n");
        }
    }
}
