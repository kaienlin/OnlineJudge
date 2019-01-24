#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXNAME 64
#define MAXN 100000

int hasEOF = 0;
int readchar() {
    static int N = 1<<20;
    static char buf[1<<20];
    static char *p = buf, *end = buf;
    if(p == end) {
        if((end = buf + fread(buf, 1, N, stdin)) == buf) {
            hasEOF = 1;
            return EOF;   
        }
        p = buf;
    }
    return *p++;
}
int ReadInt(int *x) {
    char c, neg;
    while((c = readchar()) < '-')    {if(c == EOF) return 0;}
    neg = (c == '-') ? -1 : 1;
    *x = (neg == 1) ? c-'0' : 0;
    while((c = readchar()) >= '0')
        *x = (*x << 3) + (*x << 1) + c-'0';
    *x *= neg;
    return 1;
}
int ReadStr(char *s) {
    while ( !isgraph(*s = readchar()) )    {if(*s == EOF) return 0;}
    s++;
    while ( isgraph(*(s++) = readchar()) ) ;
    *(--s) = '\0';
    return 1;
}

typedef struct data {
    int h, w;
    double BMI;
    char name[MAXNAME];
} Data;

Data students[MAXN];
Data *sort[MAXN];

int cmp(const void *a, const void *b) {
    Data *x = *(Data**)a, *y = *(Data**)b;
    if ( x->BMI != y->BMI )
        return (x->BMI > y->BMI) - (y->BMI > x->BMI);
    if ( x->w != y->w )
        return (x->w > y->w) - (y->w > x->w);
    if ( x->h != y->h )
        return (x->h > y->h) - (y->h > x->h);
    return strcmp(x->name, y->name);
}

double sq(double x) {
    return (double)x * x;
}

int main()
{
    int N;
    ReadInt(&N);
    for ( int i = 0; i < N; i++) {
        ReadStr(students[i].name);
        ReadInt(&students[i].h);
        ReadInt(&students[i].w);
        students[i].BMI = students[i].w / sq(students[i].h / 100.0);
        sort[i] = &students[i];
    }
    qsort(sort, N, sizeof(Data*), cmp);
    for ( int i = 0; i < N; i++)
        printf("%s %d %d\n", sort[i]->name, sort[i]->h, sort[i]->w);
    return 0;
}