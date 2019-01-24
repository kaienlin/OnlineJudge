#include "merge.h"

Node *merge(Node *list[], int K) {
    Node head;
    Node *prev = &head;
    int swi = 1, rest = K;
    for ( int i = 0; i < K; i++)
        if (!list[i])
            rest--;
    #ifdef BOTTOMUP
    swi = 0;
    #endif
    while ( rest > 1 ) {
        if ( swi ) {
            for ( int i = 0; i < K; i++) {
                if ( list[i] ) {
                    prev->next = list[i];
                    prev = prev->next;
                    list[i] = list[i]->next;
                    if ( !list[i] ) rest--;
                }
            }
        } else {
            for ( int i = K - 1; i >= 0; i--) {
                if ( list[i] ) {
                    prev->next = list[i];
                    prev = prev->next;
                    list[i] = list[i]->next;
                    if ( !list[i] ) rest--;
                }
            }
        }
        #ifdef ZIGZAG
        swi = !swi;
        #endif
    }
    for ( int i = 0; i < K; i++)
        if ( list[i] )
            prev->next = list[i];
    return head.next;
}