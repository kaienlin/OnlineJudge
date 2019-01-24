#include <stdio.h>
#include <string.h>
#define MAXN 100
#define MAXM 100
#define MAXSTR 64

typedef struct raw {
    char name[MAXSTR];
    int amount, price;
} Raw;

int find(Raw r[], int N, char *t)
{
    for ( int i = 0; i < N; i++)
        if ( !strcmp(r[i].name, t) )
            return i;
}

int main()
{
    int N, M;
    scanf("%d%d", &N, &M);
    Raw ingredient[100];
    for ( int i = 0; i < N; i++)
        scanf("%s%d%d", ingredient[i].name, &ingredient[i].amount, &ingredient[i].price);
    int max_profit = 0;
    char ans_s[MAXSTR];
    while ( M-- ) {
        char name[MAXSTR], material[MAXSTR];
        int Q, amount, P;
        int max_amount = __INT_MAX__;
        int ii[MAXN];
        scanf("%s%d", name, &Q);
        for ( int i = 0; i < Q; i++) {
            scanf("%s%d", material, &amount);
            int index = find(ingredient, N, material);
            ii[i] = ingredient[index].price * amount;
            if ( ingredient[index].amount / amount < max_amount )
                max_amount = ingredient[index].amount / amount;
        }
        scanf("%d", &P);
        int profit = P * max_amount;
        for ( int i = 0; i < Q; i++)
            profit -= max_amount * ii[i];
        if ( profit > max_profit ) {
            strcpy(ans_s, name);
            max_profit = profit;
        } else if ( profit == max_profit && strcmp(name, ans_s) < 0 ) {
            strcpy(ans_s, name);
            max_profit = profit;
        }
    }
    printf("%s %d", ans_s, max_profit);
    return 0;
}