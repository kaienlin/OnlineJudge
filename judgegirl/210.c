#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* gets() will be affected by the newline characters in the buffer */

struct person {
    char lastname[81];
    char firstname[81];
    char ID[81];
    int salary;
    int age;
};

typedef struct person Person;

void print(int selected_field[], Person data, int n)
{
    for ( int i = 0; i < n; i++) {
        switch(selected_field[i]) {
            case 0:
                printf("%s", data.lastname);
                break;
            case 1:
                printf("%s", data.firstname);
                break;
            case 2:
                printf("%s", data.ID);
                break;
            case 3:
                printf("%d", data.salary);
                break;
            case 4:
                printf("%d", data.age);
        }
        putchar(i == n - 1 ? '\n' : ' ');
    }
}

int main()
{
    int n;
    Person data[50];
    scanf("%d", &n);
    for ( int i = 0; i < n; i++) {
        scanf("%s%s%s%d%d", data[i].lastname, data[i].firstname, data[i].ID,
                            &data[i].salary, &data[i].age);
    }

    char query[500];
    int selected_field[8];
    int cmp_field;
    int operator;
    int cmp_number;
    char cmp_str[81];
    const char *field[5] = {"lastname", "firstname", "ID", "salary", "age"};
    int query_num;
    scanf("%d", &query_num);
    while ( query_num-- ) {
        int stage = 1;
        int count = 0;
        memset(selected_field, 0, sizeof(selected_field));
        while ( 1 ) {
            scanf("%s", query);
            if ( stage == 1 ) {
                if ( strcmp(query, "where") == 0 ) {
                    stage++;
                    continue;
                }
                for ( int i = 0; i < 5; i++) {
                    if ( strcmp(query, field[i]) == 0 ) {
                        selected_field[count++] = i;
                    }
                }
            } else if ( stage == 2 ) {
                for ( int i = 0; i < 5; i++) {
                    if ( strcmp(query, field[i]) == 0 ) {
                        cmp_field = i;
                        break;
                    }
                }
                stage++;
            } else if ( stage == 3 ) {
                if ( cmp_field <= 2 ) {
                    if ( query[0] == '=' ) {operator = 0;}
                    else {operator = 1;}
                } else {
                    if ( query[0] == '=' ) {operator = 0;}
                    else if ( query[0] == '>' ) {operator = 1;}
                    else {operator = 2;}
                }
                stage++;
            } else if ( stage == 4 ) {
                if ( cmp_field > 2 ) {
                    cmp_number = atoi(query);
                    break;
                } else {
                    strcpy(cmp_str, query);
                    break;
                }
            }
        }
        // qtoken[0] = "select"
        for ( int i = 0; i < n; i++) {
            if ( cmp_field <= 2 ) {
                char tmp_str[81];
                switch(cmp_field) {
                    case 0:
                        strcpy(tmp_str, data[i].lastname);
                        break;
                    case 1:
                        strcpy(tmp_str, data[i].firstname);
                        break;
                    case 2:
                        strcpy(tmp_str, data[i].ID);
                        break;
                }
                if ( operator == 1) {
                    if ( strcmp(tmp_str, cmp_str) != 0 ) {
                        print(selected_field, data[i], count);
                    }
                } else {
                    if ( strcmp(tmp_str, cmp_str) == 0 ) {
                        print(selected_field, data[i], count);
                    }
                }
            } else {
                int tmp_num;
                switch(cmp_field) {
                    case 3:
                        tmp_num = data[i].salary;
                        break;
                    case 4:
                        tmp_num = data[i].age;
                        break;
                }
                if ( operator == 0 ) {
                    if ( tmp_num == cmp_number ) {
                        print(selected_field, data[i], count);
                    }
                } else if ( operator == 1 ) {
                    if ( tmp_num > cmp_number ) {
                        print(selected_field, data[i], count);
                    }
                } else {
                    if ( tmp_num < cmp_number ) {
                        print(selected_field, data[i], count);
                    }
                }
            }
        }
    }
    return 0;
}