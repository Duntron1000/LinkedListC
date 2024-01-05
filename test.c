#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node {
    int value;
    struct node* next;
    struct node* last;
} node;

typedef struct linkedList {
    node* head;
    node* tail;
    int len;
} linkedList;

linkedList* newList() {
    linkedList* list = malloc(sizeof(linkedList));
    list->head = NULL;
    list->tail = NULL;
    list->len = 0;
    return list;
}

node* newNode(int v) {
    node* newNode = malloc(sizeof(node));
    newNode->next = NULL;
    newNode->last = NULL;
    newNode->value = v;
    return newNode;
}

void addFirstNode(linkedList* l, int value) {
    node* n = newNode(value);
    if (l->head == NULL) {
        l->head = n;
        l->tail = n;
    }
    n->next = l->head;
    l->head->last = n;
    l->head = n;
    l->len++;
}

void printList(linkedList* l) {
    node* cursor = l->head;
    for (int i = 0; i < l->len; i++){
        printf("%d<->", cursor->value);
        cursor = cursor->next;
    }
    puts("\n");
}

int listPopFirst(linkedList* l) {
    assert(l->head != NULL);
    int ret = l->head->value;
    l->head->next->last = NULL;
    node * newHead = l->head->next;
    free(l->head);
    l->len--;
    l->head = newHead;
    return ret;
}

int listPopLast(linkedList* l) {
    assert(l->tail != NULL);
    int ret = l->tail->value;
    l->tail->last->next = NULL;
    node * newTail = l->tail->last;
    free(l->tail);
    l->len--;
    l->tail = newTail;
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
    linkedList* list = newList();
    for (int i = 0; i < 10; i++){
        addFirstNode(list, i);
    }
    printList(list);
    for (int i = 0; i < 5; i++){
        printf("popedLast: %d\n", listPopLast(list));
        printList(list);
        printf("popedFirst: %d\n", listPopFirst(list));
        printList(list);
    }
    linkedListDel(list);
    return 0;
}
