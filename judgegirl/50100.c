#include "compute.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 1024

typedef struct {
    char name[64];
    int cited, paper_n;
} journal;

int record(char *name, journal journals[], int *journal_n) {
    for ( int i = 0; i < *journal_n; i++)
        if ( !strcmp(name, journals[i].name) ) {
            journals[i].paper_n++;
            return i;
        }
    strcpy(journals[*journal_n].name, name);
    journals[*journal_n].paper_n = 1;
    journals[*journal_n].cited = 0;
    return (*journal_n)++;
}
int cmp(const void *a, const void *b) {
    journal *x = (journal*)a, *y = (journal*)b;
    return strcmp(x->name, y->name);
}
void compute(paper P[], int N)
{
    journal journals[MAXN];
    int journal_idx[MAXN], journal_n = 0;
    for ( int i = 0; i < N; i++)
        journal_idx[i] = record(P[i].journalName, journals, &journal_n);
    for ( int i = 0; i < N; i++)
        for ( int j = 0; j < P[i].numCitedPaper; j++)
            journals[journal_idx[P[i].citedPaperIndex[j]]].cited++;
    qsort(journals, journal_n, sizeof(journal), cmp);
    for ( int i = 0; i < journal_n; i++)
        printf("%s %d/%d\n", journals[i].name, journals[i].cited, journals[i].paper_n);
}