#include "trace.h"
#include <stdlib.h>

void traverse_node(Node *root, Answer *ans, int d);

void traverse_list(ChildList *head, Answer *ans, int d, int b) {
    if ( head == NULL ) return;
    traverse_node(head->node, ans, d + 1);
    if ( b > ans->MaxBranchFactor )
        ans->MaxBranchFactor = b;
    traverse_list(head->next, ans, d, b + 1);
}

void traverse_node(Node *root, Answer *ans, int d) {
    if ( d > ans->Depth )
        ans->Depth = d;
    if ( root->list == NULL ) {
        ans->Leaf++;
        return;
    }
    ans->InternalNode++;
    traverse_list(root->list, ans, d, 1);
}

void trace(Node *root, Answer *ans) {
    traverse_node(root, ans, 0);
}