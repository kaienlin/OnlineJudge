#include "node.h"
#include <stdlib.h>

struct node *map[1 << 18];

// 0 1 2 3 4 5 ... cnt-1
//             ...  0

struct node *getNode(struct node *head, unsigned int i)
{
    unsigned int cnt = 0;
    while ( head != NULL ) {
        map[cnt++] = head;
        head = head->next;
    }
    if ( i > cnt-1 ) {return NULL;}
    else {return map[cnt - i - 1];}
}