#include "pangfeng.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int od[128];

int cmp(const void *a, const void *b)
{
    Td *x = *(Td **)a;
    Td *y = *(Td **)b;
    for ( int i = 0; od[i] >= 0; i++) {
        if ( x->grade[od[i]] != y->grade[od[i]] ) {
            return y->grade[od[i]] - x->grade[od[i]];
        }
    }
    return strcmp(x->name, y->name);
}

void init(ExamTable *self, int n)
{
    self->dim_n = n;
    self->count = 0;
    for ( int i = 0; i < 256; i++)
        self->tr[i] = NULL;
}

void addrow(ExamTable *self, char *name, int score[])
{
    int n = self->dim_n, c = self->count++;
    self->tr[c] = (Td *)malloc(sizeof(Td));
    strcpy(self->tr[c]->name, name);
    self->tr[c]->grade = (int *)malloc(sizeof(int) * n);
    for ( int i = 0; i < n; i++)
        self->tr[c]->grade[i] = score[i];
}

void print(ExamTable *self, int order[])
{
    printf("----- table begin -----\n");
    memcpy(od, order, sizeof(int) * self->dim_n);
    od[self->dim_n] = -1;
    qsort(self->tr, self->count, sizeof(Td *), cmp);
    for ( int i = 0; i < self->count; i++) {
        printf("%s, ", self->tr[i]->name);
        for ( int j = 0; j < self->dim_n; j++) {
            printf("%d%s", self->tr[i]->grade[j], j == self->dim_n - 1 ? "\n" : ", ");
        }
    }
    printf("----- end         -----\n");
}