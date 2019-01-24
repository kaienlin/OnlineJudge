#include <stdio.h>
#include <ctype.h>
 
char *cross(char *str)
{
    if ( isdigit(*str) )
        return str + 1;
    if ( *str == '-' )
        return cross(str+1);
    if ( *str == '(' ) {
        int x = 1;
        str++;
        while ( x > 0 ) {
            if ( *str == '(' )
                x++;
            else if ( *str == ')' )
                x--;
            str++;
        }
        return str;
    }
}

char buf[1<<20];
int first;
 
int expression_s(char *str)
{
    if ( first ) {
        first = 0;
        char *c = cross(str);
        if ( sscanf(c, "%s", buf) != EOF )
            return 1 << 31;
    }
    if ( isdigit(*str) )
        return *str - '0';
    if ( *str == '-' ) {
        int ret = expression_s(str+1);
        if ( ret == 1 << 31 )
            return 1 << 31;
        return -ret;
    }
    if ( *str == '(' ) {
        if ( str[1] == ')' )
            return 1 << 31;
        int lval, operator, rval;
        str++;
        lval = expression_s(str);
        str = cross(str);
        operator = *str;
        if ( operator != '+' && operator != '-' && operator != '*' && operator != '/' )
            return 1 << 31;
        str++;
        rval = expression_s(str);
        if ( lval == 1 << 31 || rval == 1 << 31 )
            return 1 << 31;
        switch(operator) {
            case '+':
                return lval + rval;
            case '-':
                return lval - rval;
            case '*':
                return lval * rval;
            case '/':
                if ( rval == 0 )
                    return 1 << 31;
                else
                    return lval / rval;
        }
    }
}

int expression(char *str)
{
    first = 1;
    return expression_s(str);
}