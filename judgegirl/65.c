#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAXLEN 1024
#define MAXVAR 64
#define MAXN 64

/* Note that if I want to use function to change some variables value, I must pass it by reference. */

typedef struct expTree {
    char opr;
    int value;
    struct expTree *left, *right;
} Exp;

typedef struct variable {
    char name[MAXVAR];
    int value;
} Var;

Exp *newNode(char opr, int val)
{
    Exp *ret = (Exp*)malloc(sizeof(Exp));
    ret->opr = opr;
    ret->value = val;
    ret->left = ret->right = NULL;
    return ret;
}

int find_value(char *name, Var vars[], int n)
{
    for ( int i = 0; i < n; i++)
        if ( !strcmp(name, vars[i].name ) )
            return vars[i].value;
}

char *nextToken1(char *str)
{
    while ( isspace(*str) ) {str++;}
    while ( !isspace(*str) ) {str++;}
    while ( isspace(*str) ) {str++;}
    return str;
}

char *nextToken2(char *str)
{
    int x = 1;
    while (x > 0) {
        if ( *str == ')' )
            x--;
        else if ( *str == '(' )
            x++;
        str++;
    }
    while (isspace(*str)) {str++;}
    return str;
}

void build_tree(char *str, Var vars[], int vn, Exp **root)
{
    if ( str[0] != '(' ) {
        char a[MAXVAR];
        sscanf(str, "%s", a);
        if ( isdigit(a[0]) ) {
            *root = newNode('\0', atoi(a));
        } else {
            *root = newNode('\0', find_value(a, vars, vn));
        }
        return;
    } else {
        str++; // ignore a '(', now on a space in front of operator
        char op[2];
        sscanf(str, "%s", op);
        *root = newNode(op[0], 0);
        str = nextToken1(str); // now on the first alphabet of first subtree
        build_tree(str, vars, vn, &(*root)->left);
        if ( *str == '(' ) {
            str++;
            str = nextToken2(str);
        } else {
            str--;
            str = nextToken1(str);
        }
        build_tree(str, vars, vn, &(*root)->right);
        switch(op[0]) {
            case '+':
                (*root)->value = (*root)->left->value + (*root)->right->value;
                break;
            case '-':
                (*root)->value = (*root)->left->value - (*root)->right->value;
                break;
            case '*':
                (*root)->value = (*root)->left->value * (*root)->right->value;
                break;
            case '/':
                (*root)->value = (*root)->left->value / (*root)->right->value;
                break;
        }
    }
}

int main()
{
    char input[MAXLEN], sign[2];
    fgets(input, MAXLEN, stdin);
    Var vars[MAXN];
    int cnt = 0;
    while ( scanf("%s%s%d", vars[cnt].name, sign, &vars[cnt].value) != EOF ) {
        cnt++;
    }
    Exp *root = NULL;
    build_tree(input, vars, cnt, &root); // pass root by reference because I need to change it in function
    printf("%d", root->value);
    return 0;
}