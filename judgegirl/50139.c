#include "GPA_calculation.h"
#include <stdio.h>
#include <stdlib.h>
 
typedef struct Student Stu;
typedef struct Class Cls;
 
int cmp(const void *a, const void *b) {
    Stu *x = *(Stu**)a, *y = *(Stu**)b;
    return (x->GPA < y->GPA) - (y->GPA < x->GPA);
}
double plus(char c) {
    switch ( c ) {
        case '+': return 0.3;
        case '-': return -0.3;
        default: return 0.0;
    }
}
double convert(char *scale) {
    for ( int i = 0; i < 3; i++)
        if ( scale[0] == 'A'+i )
            return (4 - i) + plus(scale[1]);
    return 0.0;
}
void find_gpa(Stu *s) {
    double sum = 0.0;
    s->N_credit = 0;
    for ( int i = 0; i < s->N_class; i++) {
        sum += convert(s->all_class[i].score) * s->all_class[i].academic_credit;
        s->N_credit += s->all_class[i].academic_credit;
    }
    s->GPA = sum / s->N_credit;
}
int valid(Stu *s) {
    if ( s->GPA >= 3.38 && s->N_credit >= 15 )
        return 1;
    return 0;
}
void GPA_calculation(struct Student all_student[], int N) {
    int award_n = (N - 1) / 20 + 1;
    Stu *ptr[N];
    for ( int i = 0; i < N; i++) {
        find_gpa(&all_student[i]);
        ptr[i] = &all_student[i];
    }
    qsort(ptr, N, sizeof(Stu*), cmp);
    for ( int i = 0; i < award_n; i++)
        if ( valid(ptr[i]) )
            printf("%d %s %f\n", i+1, ptr[i]->name, ptr[i]->GPA);
}
