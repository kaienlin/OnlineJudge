#include <stdio.h>
#include <string.h>

int main()
{
    char user[32][64];
    int balance[32];
    int N;
    scanf("%d", &N);
    for ( int i = 0; i < N; i++)
        scanf("%s%d", user[i], &balance[i]);
    char name1[32], name2[32], cmd[32];
    int amount;
    char *cmds[4] = {"earns", "spends", "gives", "becomes"};
    while ( scanf("%s%s", name1, cmd) != EOF ) {
        int instr = -1;
        for ( int i = 0; i < 4; i++)
            if ( strstr(cmd, cmds[i]) != NULL )
                instr = i;
        if ( instr == -1 ) {
            char buf[512];
            fgets(buf, 512, stdin); // the buffer for flushing should be large enough !!!
            continue;
        } else {
            if ( instr == 0 ) {
                scanf("%d", &amount);
                for ( int i = 0; i < N; i++)
                    if ( strcmp(name1, user[i]) == 0 ) {
                        balance[i] += amount;
                        break;
                    }
            } else if ( instr == 1 ) {
                scanf("%d", &amount);
                for ( int i = 0; i < N; i++)
                    if ( strcmp(name1, user[i]) == 0 ) {
                        if ( balance[i] >= amount ) {
                            balance[i] -= amount;
                        }
                        break;
                    }
            } else if ( instr == 2 ) {
                scanf("%s%d", name2, &amount);
                int i1 = -1, i2 = -1;
                for ( int i = 0; i < N; i++) {
                    if ( strcmp(name1, user[i]) == 0 )
                        i1 = i;
                    if ( strcmp(name2, user[i]) == 0 )
                        i2 = i;
                    if ( i2 != -1 && i1 != -1 ){ break; }
                }
                if ( i1 == -1 || i2 == -1 ) {continue;}
                if ( balance[i1] >= amount ) {
                    balance[i1] -= amount;
                    balance[i2] += amount;
                }
            } else if ( instr == 3 ) {
                scanf("%d", &amount);
                for ( int i = 0; i < N; i++)
                    if ( strcmp(name1, user[i]) == 0 ) {
                        balance[i] = amount;
                        break;
                    }
            }
        }
    }
    for ( int i = 0; i < N; i++)
        printf("%s %d\n", user[i], balance[i]);
    return 0;
}