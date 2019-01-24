#include <stdlib.h>
#include "employee.h"

/* if a function return an address of an array which declare within the function, then it will cause SIGFAULT because the memory is free after
   the end of this function call*/

void search_top(Employee* e, Employee *boss_list[])
{
    for ( int i = 0; i < 32; i++) {boss_list[i] = NULL;}
    int count = 0;
    Employee *eptr = e;
    do {
        boss_list[count] = eptr->boss;
        count++;
        eptr = eptr->boss;
    } while ( eptr->boss != eptr );
    boss_list[count] = eptr;
}

int relation(Employee *employee1, Employee *employee2) {
    Employee *bosses1[32], *bosses2[32]; 
    search_top(employee1, bosses1);
    search_top(employee2, bosses2);
    for ( int i = 0; bosses1[i] != NULL; i++) {
        if ( bosses1[i] == employee2 ) {
            return 1;
        }
    }
    for ( int i = 0; bosses2[i] != NULL; i++) {
        if ( bosses2[i] == employee1 ) {
            return 2;
        }
    }
    for ( int i = 0; bosses1[i] != NULL; i++) {
        for ( int j = 0; bosses2[j] != NULL; j++) {
            if ( bosses1[i] == bosses2[j] ) {
                return 3;
            } 
        }
    }
    return 4;
}
