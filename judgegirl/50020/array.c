#include "array.h"
#include <stdio.h>
#include <stdlib.h>

Node *new_node(int idx, int data) {
    Node *ret = (Node*)malloc(sizeof(Node));
    ret->idx = idx;
    ret->data = data;
    ret->next = NULL;
    return ret;
}
Node* insert(Node *head, int idx, int value) {
    if ( head == NULL ) {
        Node *ret = new_node(idx, value);
        ret->next = NULL;
        return ret;
    }
    Node *last = NULL, *current = head;
    while ( current != NULL && current->idx < idx ) {
        last = current;
        current = current->next;
    }
    if ( current != NULL && current->idx == idx ) {
        current->data = value;
        return head;
    } // element may be set multiple times
    if ( last == NULL ) {
        Node *ret = new_node(idx, value);
        ret->next = head;
        return ret;
    }
    Node *ret = new_node(idx, value);
    ret->next = current;
    last->next = ret;
    return head;
}
Node *seek(Node *head, int idx) {
    while ( head != NULL && head->idx != idx )
        head = head->next;
    return head;
}
void init(ARRAY *a,  int left, int right) {
    a->start = left;
    a->end = right;
    a->head = NULL;
}
int set(ARRAY *a, int index, int value) {
    if ( index < a->start || index > a->end )
        return -2147483648;
    a->head = insert(a->head, index, value);
    return 1;
}
int get(ARRAY *a, int index) {
    if ( index < a->start || index > a->end )
        return -2147483648;
    Node *result = seek(a->head, index);
    if ( result == NULL )
        return -2147483647;
    return result->data;
}
void print(ARRAY *a) {
    int idx = a->start, end = a->end;
    Node *head = a->head;
    while ( idx <= end ) {
        if ( head == NULL ) {
            for ( int i = idx; i <= end; i++)
                puts("No value");
            break;
        }
        if ( head->idx == idx ) {
            printf("%d\n", head->data);
            head = head->next;
        } else
            puts("No value");
        idx++;
    }
}
int numofelems(Node *head) {
    int cnt = 0;
    while (head != NULL) {
        cnt++;
        head = head->next;
    }
    return cnt;
}
int cmp(const void *a, const void *b) {
    return *(int*)b - *(int*)a;
}
void free_list(Node *list) {
    if ( list != NULL ) {
        free_list(list->next);
        free(list);
    }
}
void sort(ARRAY *a) {
    int num = numofelems(a->head), cnt = 0;
    if ( num == 0 )
        return;
    int array[num];
    Node *current = a->head;
    while ( current != NULL ) {
        array[cnt++] = current->data;
        current = current->next;
    }
    qsort(array, num, sizeof(int), cmp);
    free_list(a->head);
    a->head = NULL;
    for ( int i = 0; i < num; i++) {
        a->head = insert(a->head, a->end - i, array[i]);
    }
}