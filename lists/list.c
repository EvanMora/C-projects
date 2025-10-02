#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} List;

Node* create_node(int value) {
    Node* n = (Node*) malloc(sizeof(Node));
    n->value = value;
    n->next = NULL;
    return n;
}

List* create_list() {
    List* l = (List*) malloc(sizeof(List));
    l->head = NULL;
    return l;
}

void add_element(List* list, int value) {
    Node* base = create_node(value);
    if (list->head == NULL) {
        list->head = base;
        return;
    }

    Node* n = list->head;
    while (n->next != NULL) {
        n = n->next;
    }
    n->next = base;
}

void insert_element(List* list, int value, int index) {
    Node* base = create_node(value);
    if (index == 0) {
        Node* old_head = list->head;
        list->head = base;
        base->next = old_head;
        return;
    }

    Node* prev = list->head;
    Node* actual = list->head->next;
    for (int i = 0; i < index - 1; i++) {
        if (actual == NULL) {
            printf("Index out of the bounds");
            exit(1);
        }
        prev = prev->next;
        actual = actual->next;
    }
    prev->next = base;
    base->next = actual;
}

void remove_element(List* list, int index) {
    if (index == 0) {
        Node* n = list->head->next;
        Node* delete = list->head;
        list->head = n;
        free(delete);
        return;
    }

    Node* prev = list->head;
    Node* actual = list->head->next;
    for (int i = 0; i < index - 1; i++) {
        if (actual == NULL) {
            printf("Index out of the bounds");
            exit(1);
        } 
        prev = prev->next;
        actual = actual->next;
    }
    actual = actual->next;
    free(prev->next);
    prev->next = actual;
}

int get(List list, int index) {
    Node* n = list.head;
    for (int i = 0; i < index; i++) {
        n = n->next;
    }

    if (n == NULL) {
        printf("Index out of bounds");
        exit(1);
    }

    return n->value;
}

void print_list(List list) {
    if (list.head == NULL) {
        printf("Empty list\n");
    }

    Node* n = list.head;
    while (n != NULL) {
        printf("%d ", n->value);
        n = n->next;
    }
}


int main() {
    List* l = create_list();
    add_element(l, 8);
    add_element(l, 9);
    add_element(l, 10);
    insert_element(l, 2, 7);
    print_list(*l);
}
