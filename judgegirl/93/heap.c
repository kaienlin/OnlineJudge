#include <string.h>
#include "heap.h"

void initialize(struct Heap *heap)
{
    heap->num = 0;
    memset(heap->ary, 0, sizeof(heap->ary));
}
int removeMin(struct Heap *heap)
{
    int ret = heap->ary[0];
    memmove(heap->ary, heap->ary + 1, sizeof(int) * (heap->num - 1));
    heap->num--;
    return ret;
}
void add(struct Heap *heap, int i)
{
    int N = heap->num++;
    if ( N == 0 ) {
        heap->ary[0] = i;
        return;
    }
    for ( int j = 0; j < N; j++) {
        if ( i <= heap->ary[j] ) {
            memmove(&heap->ary[j + 1], &heap->ary[j], sizeof(int) * (N - j));
            heap->ary[j] = i;
            return;
        }
    }
    heap->ary[N] = i; // If i greater than all the data in heap !!!
}
int isFull(struct Heap *heap)
{
    return heap->num == MAXHEAP;
}
int isEmpty(struct Heap *heap)
{
    return heap->num == 0;
}