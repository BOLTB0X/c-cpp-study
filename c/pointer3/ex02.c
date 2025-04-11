#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void insert(Node **head, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void print(Node *head) {
    while(head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main(void) {
    Node *head = NULL;

    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);

    print(head);  // 30 -> 20 -> 10 -> NULL

    return 0;
}