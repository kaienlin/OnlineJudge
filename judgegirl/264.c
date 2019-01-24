#include <stdio.h>
#include <assert.h>

#define MAXN 65536
int count[MAXN] = {0};
short buffer[MAXN];

int main()
{
    char filename[201];
    scanf("%s", filename);
    FILE *f = fopen(filename, "rb");
    assert(f != NULL);
    int n;
    fread(&n, 4, 1, f);
    int max = 0, size_n;
    short max_i;
    while ( (size_n = fread(buffer, 2, MAXN, f)) != 0 ) {
        for ( int i = 0; i < size_n; i++) {
            count[ buffer[i] + 32768]++;
            if ( count[ buffer[i] + 32768] > max ) {
                max = count[ buffer[i] + 32768];
                max_i = buffer[i];
            } else if ( count[ buffer[i] + 32768] == max && buffer[i] > max_i ) {
                max = count[ buffer[i] + 32768];
                max_i = buffer[i];
            }
        }
    }
    printf("%d\n%d", max_i, max);
    return 0;
}