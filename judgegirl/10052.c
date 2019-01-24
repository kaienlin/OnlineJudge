#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXS 65536

/* Some floating point expression omit the '1' before '.' */

double parse(char *expr)
{
    if ( isdigit(expr[0]) || expr[0] == '-' || expr[0] == '.' ) {
        return atof(expr);
    } else {
        expr++; // ignore a '('
        double p = parse(expr);
        if ( expr[0] == '(' ) {
            int x = 1;
            expr++;
            while ( x > 0 ) {
                if ( *expr == '(')
                    x++;
                else if ( *expr == ')' )
                    x--;
                expr++;
            }
            expr++;
        } else {
            while (!isspace(*expr)) {expr++;}
            expr++;
        }
        double i1 = parse(expr);
        if ( expr[0] == '(' ) {
            int x = 1;
            expr++;
            while ( x > 0 ) {
                if ( *expr == '(')
                    x++;
                else if ( *expr == ')' )
                    x--;
                expr++;
            }
            expr++;
        } else {
            while (!isspace(*expr)) {expr++;}
            expr++;
        }
        double i2 = parse(expr);
        return p * (i1 + i2) + (1.0 - p) * (i1 - i2);
    }
}

int main()
{
    char expr[MAXS];
    while ( fgets(expr, MAXS, stdin) != NULL ) {
        printf("%.2lf\n", parse(expr));
    }
}