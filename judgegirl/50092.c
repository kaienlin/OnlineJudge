#include <stdio.h>
#include <string.h>
#include <ctype.h>

// use extra %s to check if there are non-space character behind the command

int readCmd(char *from, int *ia, char *to, int *ib, int a, int b, int c)
{
    char s[64];
    char buffer[64];
    if ( fgets(s, 64, stdin) == NULL ) { return EOF; }
    else {
        if ( sscanf(s, "%s %d %s %d %s", from, ia, to, ib, buffer) != 4 ) { // use extra %s to check if there are non-space character behind the command
            return 0;
        } else if ( strcmp(from, "A") == 0 && *ia < a && *ia >= 0 && strcmp(to, "B") == 0 && *ib < b && *ib >= 0 ) {
            return 1;
        } else if ( strcmp(from, "B") == 0 && *ia < b && *ia >= 0 && strcmp(to, "C") == 0 && *ib < c && *ib >= 0 ) {
            return 1;
        } else {
            return 0;
        }
    }
}

void chasing(int **A[], int a, int *B[], int b, int C[], int c)
{
    for ( int i = 0; i < a; i++) {A[i] = NULL;}
    for ( int i = 0; i < b; i++) {B[i] = NULL;}
    
    char from[64], to[64];
    int ia, ib, valid;
    while ( (valid = readCmd(from, &ia, to, &ib, a, b, c)) != EOF ) {
        if ( valid ) {
            printf("1\n");
            if ( from[0] == 'A' ) {
                A[ia] = &B[ib];
            } else {
                B[ia] = &C[ib];
            }
        } else {
            printf("0\n");
        }
    }
}
