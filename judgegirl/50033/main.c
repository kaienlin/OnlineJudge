#include "account.h"
#include <stdio.h>
#include <stdlib.h>
#define MAXBUF 100000

int cmp0(const void *a, const void *b) {
    Account *x = (Account *)a, *y = (Account *)b;
    return x->accountNum - y->accountNum;
}
int cmp1(const void *a, const void *b) {
    Account *x = (Account *)a, *y = (Account *)b;
    return x->age - y->age;
}
int cmp2(const void *a, const void *b) {
    Account *x = (Account *)a, *y = (Account *)b;
    return x->zipcode - y->zipcode;
}

Account buffer[MAXBUF];

int main()
{
    char filename[64];
    scanf("%s", filename);
    FILE *fin = fopen(filename, "rb");
    int N = fread(buffer, sizeof(Account), MAXBUF, fin);
    fclose(fin);
    qsort(buffer, N, sizeof(Account), cmp0);
    puts("account, age, zipcode, balance");
    for ( int i = 0; i < N; i++)
        printf("%d, %d, %d, %d\n", buffer[i].accountNum, buffer[i].age, buffer[i].zipcode, buffer[i].balance);
    if ( SORTBY == AGE ) {
        qsort(buffer, N, sizeof(Account), cmp1);
        int prev_age = buffer[0].age;
        int sum = buffer[0].balance;
        puts("age, sum_balance");
        for ( int i = 1; i < N; i++) {
            if ( buffer[i].age != prev_age ) {
                printf("%d, %d\n", prev_age, sum);
                prev_age = buffer[i].age;
                sum = buffer[i].balance;
            } else {
                sum += buffer[i].balance;
            }
        }
        printf("%d, %d\n", prev_age, sum);
    }
    if ( SORTBY == ZIPCODE ) {
        qsort(buffer, N, sizeof(Account), cmp2);
        int prev_code = buffer[0].zipcode;
        int sum = buffer[0].balance;
        puts("zipcode, sum_balance");
        for ( int i = 1; i < N; i++) {
            if ( buffer[i].zipcode != prev_code ) {
                printf("%d, %d\n", prev_code, sum);
                prev_code = buffer[i].zipcode;
                sum = buffer[i].balance;
            } else {
                sum += buffer[i].balance;
            }
        }
        printf("%d, %d\n", prev_code, sum);
    }
    return 0;
}