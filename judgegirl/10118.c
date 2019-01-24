#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
 
Node* mk_list(int n) {
    Node *head = NULL, *prev = NULL;
    for (int i = 0; i < n; i++) {
        Node *u = (Node*)malloc(sizeof(Node));
        u->v = sp_rand(), u->next = NULL;
        if ( head == NULL ) {
            head = u;
            prev = u;
        } else {
            prev->next = u;
            prev = u;
        }
    }
    return head;
}
void rm_list(Node *head) {
    while (head != NULL) {
        Node *tmp = head->next;
        free(head);
        head = tmp;
    }
}