#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

Node* create_node(int value) {
    Node* n = (Node*) malloc(sizeof(Node));
    n->value = value;
    n->next = NULL;
    return n;
}

Stack* create_stack() {
    Stack* s = (Stack*) malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

void push(Stack* s, int value) {
    Node* n = create_node(value);
    n->next = s->top;
    s->top = n;
}

void pop(Stack* s) {
    Node* n = s->top;
    s->top = n->next;
    free(n);
}

int peek(Stack s) {
    return s.top->value;
}

int length(Stack s) {
    Node* n = s.top;
    int i = 1;
    while (n->next != NULL) {
        n = n->next;
        i++;
    }
    return i;
}

int main() {
    Stack* s = create_stack();
    push(s, 8);
    push(s, 9);
    push(s, 1);
    push(s, 2);
    printf("Length: %d\n", length(*s));
    pop(s);
    printf("Length: %d\n", length(*s));
    printf("Top: %d\n", peek(*s));
}