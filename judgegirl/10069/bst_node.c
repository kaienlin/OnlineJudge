#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
 
bstNode* bstNode_getLson(bstNode *self) {
    return self->lson;
} 
bstNode* bstNode_getRson(bstNode *self) {
    return self->rson;
}
void bstNode_setLson(bstNode *self, bstNode *u) {
    self->lson = u;
} 
void bstNode_setRson(bstNode *self, bstNode *u) {
    self->rson = u;
}
void bstNode_print(bstNode *self) {
    printf("%d ", *(int *)(self->extra));
}
 
int bstNode_init(bstNode *obj) {
    obj->getLson = bstNode_getLson;
    obj->getRson = bstNode_getRson;
    obj->setLson = bstNode_setLson;
    obj->setRson = bstNode_setRson;
    obj->print = bstNode_print;
    obj->extra = (void *) malloc(sizeof(int));
    return 1;
}
void bstNode_destroy(bstNode *obj) {
    free(obj->extra);
}
 
Object bstNodeProto = {
    .init = bstNode_init,
    .destroy = bstNode_destroy
};

void insert(int data, bstNode *root)
{
    if ( data < *((int*)root->extra) ) {
        if ( root->lson == NULL ) {
            root->lson = (bstNode*)malloc(sizeof(bstNode));
            bstNodeProto.init(root->lson);
            *((int*)root->lson->extra) = data;
            root->lson->lson = root->lson->rson = NULL;
            return;
        } else {
            insert(data, root->lson);
        }
    } else {
        if ( root->rson == NULL ) {
            root->rson = (bstNode*)malloc(sizeof(bstNode));
            bstNodeProto.init(root->rson);
            *((int*)root->rson->extra) = data;
            root->rson->lson = root->rson->rson = NULL;
            return;
        } else {
            insert(data, root->rson);
        }
    }
}
 
bstNode* buildBST(int A[], int n) {
    bstNode *root = (bstNode*)malloc(sizeof(bstNode));
    bstNode_init(root);
    *((int*)root->extra) = A[0];
    root->lson = root->rson = NULL;
    for ( int i = 1; i < n; i++)
        insert(A[i], root);
    return root;
}