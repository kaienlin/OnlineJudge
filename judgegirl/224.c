#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"

/* some compilation note: 1. Remember include the header file which define the struct or function prototype.
                          2. Remember to read the CE error message to find the problem.
*/

Employee* find_employee_by_id( Employee *set, int n, int id )
{
    for ( int i = 0; i < n; i++) {
        if ( set[i].id == id ) {
            return &set[i];
        }
    }
}
Employee* find_employee_by_name( Employee *set, int n, const char *first_name, const char *last_name )
{
    for ( int i = 0; i < n; i++) {
        if ( strcmp(set[i].first_name, first_name) == 0 && strcmp(set[i].last_name, last_name) == 0 ) {
            return &set[i];
        }
    }
}
Employee* find_root_boss( Employee *set, int n, Employee *employee )
{
    int boss = (*employee).boss_id;
    int i;
    if ( boss == (*employee).id ) { return employee; }
    while ( 1 ) {
        for ( i = 0; i < n; i++) {
            if ( set[i].id == boss ) {
                boss = set[i].boss_id;
                break;
            }
        }
        if ( boss == set[i].id ) {
            return &set[i];
        }
    }
}
int check_relationship(Employee *set, int n, Employee *A, Employee *B)
{
    int boss_list_A[n];
    int boss_list_B[n];
    memset(boss_list_A, -1, sizeof(boss_list_A));
    memset(boss_list_B, -1, sizeof(boss_list_B));
    int boss = (*A).boss_id;
    int countA = 0;
    int i;
    while ( 1 ) {
        if ( boss == (*B).id ) { return 1; }
        boss_list_A[countA++] = boss;
        for ( i = 0; i < n; i++) {
            if ( set[i].id == boss ) {
                boss = set[i].boss_id;
                break;
            }
        }
        if ( boss == set[i].id ) {
            break;
        }
    }
    boss = (*B).boss_id;
    int countB = 0;
    while ( 1 ) {
        if ( boss == (*A).id ) { return 2;}
        boss_list_B[countB++] = boss;
        for ( i = 0; i < n; i++) {
            if ( set[i].id == boss ) {
                boss = set[i].boss_id;
                break;
            }
        }
        if ( boss == set[i].id ) {
            break;
        }
    }

    for ( int i = 0; i < countA; i++) {
        for ( int j = 0; j < countB; j++) {
            if ( boss_list_A[i] == boss_list_B[j] ) {
                return 3;
            }
        }
    }
    return 0;
}

void init_storage(Employee **storage, int n)
{
    // allocate memory space to store employee data
    // no need to understand this function now.
 
    (*storage) = (Employee *)malloc(sizeof(Employee) * n);
}
 
void free_storage(Employee **storage)
{
    free(*storage);
    *storage = 0;
}