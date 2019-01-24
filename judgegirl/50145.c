#include "sub.h"
#include <stdio.h>
 
void substring(Node* text, Node* pattern) {
    int sum = 0, idx = 0;
    for ( Node *cur = pattern; cur; text = text->next, idx++) {
        if ( text->c == cur->c ) {
            sum += idx;
            cur = cur->next;
        } else {
            sum = 0;
            cur = pattern;
            if ( text->c == cur->c ) {
                sum += idx;
                cur = cur->next;
            }
        }
    }
    printf("%d\n", sum);
}
void subsequence(Node* text, Node* pattern) {
    int sum = 0;
    for (int idx = 0; pattern; text = text->next, idx++) {
        if ( text->c == pattern->c ) {
            sum += idx;
            pattern = pattern->next;
        }
    }
    printf("%d\n", sum);
}