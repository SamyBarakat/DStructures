#include <stdlib.h>
#include <stdio.h>

// Linked List: Insert a node at nth position

struct Node {
    int data;
    struct Node *next;
};

struct Node *head; // global head variable

void Print() {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void Insert(int data, int n) {
    // temp1 is empty node (or pointer to one)
    // Node *temp1 = new Node(); --> in C++
    struct Node *temp1 = (struct Node*)malloc(sizeof(struct  Node*));
    temp1->data = data;
    temp1->next = NULL;
    if (n == 1) {
        temp1->next = head;
        head = temp1;
        return;
    }
    struct Node *temp2 = head;
    for(int i = 0; i<n-2;i++) {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next; // temp1.next takes the value of temp2->next
    temp2->next = temp1;
}

int main() {
    head = NULL; // empty list
    Insert(2, 1); // 2
    Insert(3, 2); // 2,3
    Insert(4, 1); // 4,2,3
    Insert(5, 2); // 4,5,2,3
    Print();
}