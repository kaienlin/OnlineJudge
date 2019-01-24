#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXIN 1024
#define MAXVAR 64
#define MAXN 50

typedef struct {
    char name[MAXVAR];
    int val;
} VAR;

VAR variables[MAXN];
int n;

int find_val(char *vname) {
    for ( int i = 0; i < n; i++)
        if ( !strcmp(variables[i].name, vname) )
            return variables[i].val;
}

typedef struct tree_node {
    char opr;
    int val;
    struct tree_node *left, *right;
} Exp;

int compute(char opr, int lv, int rv) {
    switch (opr) {
        case '+':
            return lv + rv;
        case '-':
            return lv - rv;
        case '*':
            return lv * rv;
        case '/':
            return lv / rv;
    }
}

Exp *eval(char *in, int *idx) {
    while ( in[*idx] == ')' || in[*idx] == ' ' )
        (*idx)++;
    Exp *ret = (Exp*)calloc(1, sizeof(Exp));
    if ( in[*idx] == '(' ) {
        (*idx) += 2;
        ret->opr = in[*idx];
        (*idx) += 2;
        ret->left = eval(in, idx);
        ret->right = eval(in, idx);
        ret->val = compute(ret->opr, ret->left->val, ret->right->val);
    } else if ( isdigit(in[*idx]) ) {
        while ( isdigit(in[*idx]) ) {
            ret->val = (ret->val << 3) + (ret->val << 1) + (in[*idx]-'0');
            (*idx)++;
        }
    } else if ( isalpha(in[*idx]) || in[*idx] == '_' || in[*idx] == '$' ) {
        char str[MAXVAR];
        int i = 0;
        str[i++] = in[(*idx)++];
        while ( isalpha(in[*idx]) || in[*idx] == '_' || in[*idx] == '$' || isdigit(in[*idx]) )
            str[i++] = in[(*idx)++];
        str[i] = '\0';
        ret->val = find_val(str);
    }
    return ret;
}

int main()
{
    char in[MAXIN];
    fgets(in, MAXIN, stdin);
    char junk[2];
    while ( ~scanf("%s%s%d", variables[n].name, junk, &variables[n].val) )
        n++;
    int idx = 0;
    Exp *root = eval(in, &idx);
    printf("%d\n", root->val);
    return 0;
}