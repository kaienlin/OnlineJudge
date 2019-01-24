#include <stdio.h>
#include <string.h>

/* use scanf("%s%c", ...) to implement is simpler than fgets() or getchar(), otherwise it is easy to read unexpected character */

char buffer[1 << 24];

int main()
{
    int N;
    scanf("%d", &N);
    char **first[1024];
    char *second[16384];
    int count2[1024] = {0};
    char buf[1024];
    int index_2 = 0, index_b = 0;
    char c;
    for ( int i = 0; i < N; i++) {
        first[i] = &second[index_2];
        while ( scanf("%s%c", &buffer[index_b], &c) != EOF ) {
            second[index_2] = &buffer[index_b];
            index_b += strlen(&buffer[index_b]) + 1;
            index_2++;
            count2[i]++;
            if ( c == '\n') { break;}
        }
    }
    int M;
    scanf("%d", &M);
    int l1, w1, l2, w2;
    while (M--) {
        scanf("%d%d%d%d", &l1, &w1, &l2, &w2);
        char *tmp = first[l1][w1];
        first[l1][w1] = first[l2][w2];
        first[l2][w2] = tmp;
    }

    for ( int i = 0; i < N; i++) {
        for ( int j = 0; j < count2[i]; j++) {
            printf("%s%c", first[i][j], " \n"[j == count2[i] - 1]);
        }
    }
    
    return 0;
}