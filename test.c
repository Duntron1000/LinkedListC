#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
} node;

typedef struct linkedList {
    node* head;
    int len;
} linkedList;

linkedList* newList() {
    linkedList* list = malloc(sizeof(linkedList));
    list->head = NULL;
    list->len = 0;
    return list;
}

node* newNode(int v) {
    node* newNode = malloc(sizeof(node));
    newNode->next = NULL;
    newNode->value = v;
    return newNode;
}

void addNode(linkedList* l, int value) {
    node* n = newNode(value);
    if (l->head == NULL) {
        l->head = n;
    }
    n->next = l->head;
    l->head = n;
    l->len++;
}

void printList(linkedList* l) {
    node* cursor = l->head;
    for (int i = 0; i < l->len; i++){
        printf("%d->", cursor->value);
        cursor = cursor->next;
    }
    puts("\n");
}

int listPop(linkedList* l) {
    int ret = l->head->value;
    node * newHead = l->head->next;
    free(l->head);
    l->len--;
    l->head = newHead;
    return ret;
}

void linkedListDel(linkedList* l) {
    node* cursor = l->head;
    for (int i = 0; i < l->len; i++) {
        node* temp = cursor->next;
        free(cursor);
        cursor = temp;
    }
    free(l);
}

int main(int argc, char** argv) {
    puts("start");
    linkedList* list = newList();
    for (int i = 0; i < 10; i++){
        addNode(list, i);
    }
    printList(list);
    for (int i = 0; i < 5; i++){
        printf("poped: %d\n", listPop(list));
        printList(list);
    }
    linkedListDel(list);
    return 0;
}
