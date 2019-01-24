#include "merge.h"
#include <stdlib.h>

Node *merge(Node *list[], int K) {
    Node *head = (Node*)malloc(sizeof(Node));
    Node *tail = head;
    int rest = K, swi = 1;
    for ( int i = 0; i < K; i++)
        if ( list[i] == NULL )
            rest--;
    while ( rest > 1 ) {
        if ( swi ) {
            for ( int i = 0; i < K; i++) {
                if ( list[i] != NULL ) {
                    tail->next = list[i];
                    list[i] = list[i]->next;
                    if ( list[i] == NULL )
                        rest--;
                    tail = tail->next;
                }
            }
        } else {
            for ( int i = K - 1; i >= 0; i--) {
                if ( list[i] != NULL ) {
                    tail->next = list[i];
                    list[i] = list[i]->next;
                    if ( list[i] == NULL )
                        rest--;
                    tail = tail->next;
                }
            }
        }
        swi = !swi;
    }
    for ( int i = 0; i < K; i++)
        if ( list[i] != NULL )
            tail->next = list[i];
    return head->next;
}