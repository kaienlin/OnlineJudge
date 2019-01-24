#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct variable {
    char name[8];
    int value;
} VAR;

typedef struct if_statement {
    char var1[8];
    char op[3];
    char var2[8];
    int line;
} IF;

typedef struct assign_statement {
    char result[8];
    char var1[8];
    char op;
    char var2[8];
} AS;

int main()
{
    char var[20];
    int val;
    VAR variables[100];
    int var_num = 0;
    while ( 1 ) {
        scanf("%s", var);
        if ( strcmp(var, "END") == 0 ) {
            break;
        } else if ( strcmp(var, "=") == 0 ) {
            scanf("%d", &val);
            variables[var_num].value = val;
            var_num++;
        } else {
            strcpy(variables[var_num].name, var);
        }
    }
    getchar();

    int line_type[1001] = {0}; // store type of statement
    char line[100]; // raw statement 
    char statement[6][20]; // parsed statement
    int line_count = 1;
    int goto_count = 0;
    int if_count = 0;
    int assign_count = 0;
    int print_count = 0;

    int goto_index[1000];
    IF if_index[1000];
    AS assign_index[1000];
    char print_index[1000][8];

    while ( gets(line) != NULL ) {
        char *t = line;
        strtok(t, " ");
        int count = 0;
        while ( t != NULL ) {
            strcpy(statement[count], t);
            count++;
            t = strtok(NULL, " ");
        }
        if ( strcmp(statement[0], "GOTO") == 0 ) {
            line_type[line_count] = goto_count * 10;
            goto_index[goto_count] = atoi(statement[1]);
            line_count++;
            goto_count++;

        } else if ( strcmp(statement[0], "IF") == 0 ) {
            line_type[line_count] = if_count * 10 + 1;
            strcpy(if_index[if_count].var1, statement[1]);
            strcpy(if_index[if_count].op, statement[2]);
            strcpy(if_index[if_count].var2, statement[3]);
            if_index[if_count].line = atoi(statement[5]);
            line_count++;
            if_count++;

        } else if ( strcmp(statement[0], "PRINT") == 0 ) {
            line_type[line_count] = print_count * 10 + 3;
            strcpy(print_index[print_count], statement[1]);
            line_count++;
            print_count++;

        } else if ( strcmp(statement[0], "STOP") == 0 ) {
            line_type[line_count++] = 4;
        } else {
            line_type[line_count] = assign_count * 10 + 2;
            strcpy(assign_index[assign_count].result, statement[0]);
            strcpy(assign_index[assign_count].var1, statement[2]);
            assign_index[assign_count].op = statement[3][0];
            strcpy(assign_index[assign_count].var2, statement[4]);
            line_count++;
            assign_count++;
        }
    }

    int i = 1;
    int v, var1, var2;
    while ( line_type[i] != 4 ) {
        switch ( line_type[i] % 10 ) {
            case 0:
                i = goto_index[line_type[i] / 10];
                break;
            case 1:
                for ( int j = 0; j < var_num; j++) {
                    if ( strcmp(variables[j].name, if_index[line_type[i] / 10].var1) == 0 ) {
                        var1 = variables[j].value;
                    }
                    if ( strcmp(variables[j].name, if_index[line_type[i] / 10].var2) == 0 ) {
                        var2 = variables[j].value;
                    }
                }
                if ( strcmp(if_index[line_type[i] / 10].op, "==") == 0 ) {
                    if ( var1 == var2 ) {
                        i = if_index[line_type[i] / 10].line;
                    } else {
                        i++;
                    }
                } else if ( strcmp(if_index[line_type[i] / 10].op, "!=") == 0 ) {
                    if ( var1 != var2 ) {
                        i = if_index[line_type[i] / 10].line;
                    } else {
                        i++;
                    }
                } else if ( strcmp(if_index[line_type[i] / 10].op, ">") == 0 ) {
                    if ( var1 > var2 ) {
                        i = if_index[line_type[i] / 10].line;
                    } else {
                        i++;
                    }
                } else if ( strcmp(if_index[line_type[i] / 10].op, "<") == 0 ) {
                    if ( var1 < var2 ) {
                        i = if_index[line_type[i] / 10].line;
                    } else {
                        i++;
                    }
                } else if ( strcmp(if_index[line_type[i] / 10].op, ">=") == 0 ) {
                    if ( var1 >= var2 ) {
                        i = if_index[line_type[i] / 10].line;
                    } else {
                        i++;
                    }
                } else if ( strcmp(if_index[line_type[i] / 10].op, "<=") == 0 ) {
                    if ( var1 <= var2 ) {
                        i = if_index[line_type[i] / 10].line;
                    } else {
                        i++;
                    }
                }
                break;
            case 2:
                for ( int j = 0; j < var_num; j++) {
                    if ( strcmp(variables[j].name, assign_index[line_type[i] / 10].var1) == 0 ) {
                        var1 = variables[j].value;
                    }
                    if ( strcmp(variables[j].name, assign_index[line_type[i] / 10].var2) == 0 ) {
                        var2 = variables[j].value;
                    }
                    if ( strcmp(variables[j].name, assign_index[line_type[i] / 10].result) == 0 ) {
                        v = j;
                    }
                }
                switch ( assign_index[line_type[i] / 10].op ) {
                    case '+':
                        variables[v].value = var1 + var2;
                        break;
                    case '-':
                        variables[v].value = var1 - var2;
                        break;
                    case '*':
                        variables[v].value = var1 * var2;
                        break;
                    case '/':
                        variables[v].value = var1 / var2;
                        break;
                    case '%':
                        variables[v].value = var1 % var2;
                        break;
                }
                i++;
                break;
            case 3:
                for ( int j = 0; j < var_num; j++) {
                    if ( strcmp(variables[j].name, print_index[line_type[i] / 10]) == 0 ) {
                        v = variables[j].value;
                        break;
                    }
                }
                printf("%d\n", v);
                i++;
                break;
        }
    }

    return 0;
}