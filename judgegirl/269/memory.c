#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "memory.h"

void initMemory(Memory *memory, int length)
{
    memory->start = 0;
    memory->len = length;
    memory->status = 0;
    memory->next = NULL;
}
void printMemory(Memory *memory)
{
    puts("==========");
    while (memory != NULL) {
        if ( !memory->status )
            printf("start %d, length %d\n", memory->start, memory->len);
        memory = memory->next;
    }
}
Memory *newBlock(int start, int len, int status)
{
    Memory *new = (Memory*)malloc(sizeof(Memory));
    new->start = start;
    new->len = len;
    new->status = status;
    return new;
}
void allocateMemory(Memory *memory, int start, int length)
{
    Memory *prev = NULL;
    while (1) {
        if ( memory == NULL ) {
            if ( prev->status == 1 ) {break;}
            if ( start + length == prev->start + prev->len ) {
                Memory *new = newBlock(start, length, 1);
                prev->next = new;
                prev->len -= length;
                new->next = NULL;
            } else {
                Memory *new = newBlock(start, length, 1);
                Memory *post = newBlock(start + length, prev->len - length - start + prev->start, 0);
                prev->next = new;
                new->next = post;
                post->next = NULL;
                prev->len = start - prev->start;
            }
            break;
        } else if ( memory->start > start ) {
            if ( prev->status == 1 ) {break;}
            if ( start + length == memory->start ) {
                if ( memory->status == 1 ) {
                    memory->len += length;
                    prev->len -= length;
                    memory->start -= length;
                } else {
                    Memory *new = newBlock(start, length, 1);
                    new->next = memory;
                    prev->next = new;
                    prev->len -= length;
                }
            } else {
                Memory *new = newBlock(start, length, 1);
                Memory *post = newBlock(start + length, memory->start - start - length, 0);
                prev->next = new;
                new->next = post;
                post->next = memory;
                prev->len = start - prev->start;
            }
            break;
        } else if ( memory->start == start ) {
            if ( memory->len == length ) {
                if ( prev == NULL && memory->next == NULL ) {
                    memory->status = 1;
                } else if ( prev == NULL ) {
                    memory->status = 1;
                    memory->len += memory->next->len;
                    Memory *toFree = memory->next;
                    memory->next = memory->next->next;
                    free(toFree);
                } else if ( memory->next == NULL ) {
                    prev->len += memory->len;
                    free(memory);
                    prev->next = NULL;
                } else {
                    prev->len += length + memory->next->len;
                    prev->next = memory->next;
                    free(memory);
                }
            } else {
                if ( prev == NULL ) {
                    Memory *new = newBlock(start + length, memory->len - length, 0);
                    new->next = memory->next;
                    memory->status = 1;
                    memory->len = length;
                    memory->next = new;
                } else {
                    if ( prev->status == 1 ) {
                        prev->len += length;
                        memory->len -= length;
                        memory->start = start + length;
                    } else {
                        Memory *new = newBlock(start, length, 1);
                        prev->next = new;
                        new->next = memory;
                        memory->len -= length;
                    }
                }
            }
            break;
        } else if ( memory->start < start ) {
            prev = memory;
            memory = memory->next;
        }
    }
}

void freeMemory(Memory *memory, int start, int length)
{
    Memory *prev = NULL, *blank = NULL;
    while (memory != NULL && memory->start < start) {
        prev = memory;
        memory = memory->next;
    }
    if ( memory == NULL ) {
        if ( prev->status == 0 ) {return;}
        if ( start + length == prev->start + prev->len ) {
            blank = newBlock(start, length, 0);
            blank->next = NULL;
            prev->len -= length;
            prev->next = blank;
            return;
        } else {
            blank = newBlock(start, length, 0);
            Memory *post = newBlock(start + length, prev->len - length - start + prev->start, 1);
            prev->len = start - prev->start;
            prev->next = blank;
            blank->next = post;
            post->next = NULL;
            return;
        }
    } else if ( memory->start > start ) {
        if ( prev == NULL ) {
            if ( memory->status == 1 ) { // memory->next->status == 0
                if ( start + length < memory->start + memory->len ) {
                    blank = newBlock(start, length, 0);
                    Memory *post = newBlock(start + length, memory->len - length - start + memory->start, 1);
                    memory->len = start - memory->start;
                    post->next = memory->next;
                    memory->next = blank;
                    blank->next = post;
                    return;
                } else if ( start + length == memory->start + memory->len ) {
                    blank = newBlock(start, length, 0);
                    blank->next = memory->next;
                    memory->next = blank;
                    return;
                } else {
                    blank = newBlock(start, length, 0);
                    memory->len = start - memory->start;
                }
            } else {
                blank = memory;
            }
        } else {
            if ( prev->status == 0 ) {
                blank = prev;
                prev->len = start + length - prev->start; // to connect
            } else {
                blank = newBlock(start, length, 0);
                Memory *post = NULL;
                if ( start + length < prev->start + prev->len ) {
                    post = newBlock(start + length, prev->len - length - start + prev->start, 1);
                    post->next = memory;
                    blank->next = post;
                }
                prev->next = blank;
                prev->len = start - prev->start; // to connect
                if ( post != NULL ) {return;}
            }
        }
    } else if ( memory->start == start ) {
        if ( prev == NULL ) {
            if ( memory->status == 1 ) { // memory->next->status == 0
                if ( length < memory->len ) {
                    memory->len = length;
                    memory->status = 0;
                    Memory *new = newBlock(start + length, memory->next->start, 1);
                    new->next = memory->next;
                    memory->next = new;
                    return;
                } else if ( length == memory->len ) {
                    memory->status = 0;
                    memory->len += memory->next->len;
                    memory->next = memory->next->next;
                    return;
                } else {
                    blank = memory;
                    memory->len = length;
                }
            } else {
                if ( length <= memory->len ) {
                    return;
                } else {
                    blank = memory;
                    memory->len = length; // to connect
                }
            }
        } else {
            if ( prev->status == 0 ) { // memory->status == 1
                blank = prev;
                prev->len = start + length - prev->start;
                if ( length < memory->len ) {
                    memory->start = start + length;
                    memory->len -= length;
                    return;
                } else if ( length == memory->len ) {
                    if ( memory->next != NULL ) {
                        prev->len += memory->next->len;
                        prev->next = memory->next->next;
                    } else {
                        prev->next = NULL;
                    }
                    return;
                } // to connect if length > memory->len
            } else { // memory->status == 0
                if ( length <= memory->len ) {return;}
                else {
                    blank = memory;
                    memory->len = length; // to connect
                }
            }
        }
    }
    int end = start + length;
    while (memory != NULL && memory->start < end ) {
        prev = memory;
        memory = memory->next;
    }
    if ( memory == NULL || memory->start > end ) {
        if ( prev->status == 0 ) {
            blank->len = prev->start + prev->len - blank->start;
            blank->next = memory;
            return;
        } else {
            blank->next = prev;
            prev->start = start + length;
            prev->len = prev->len - prev->start;
            return;
        }
    } else if ( memory->start == end ) {
        if ( memory->status == 0 ) {
            blank->len += memory->len;
            blank->next = memory->next; // miss this statement !!!
            return;
        } else {
            blank->next = memory;
            return;
        }
    }
}
