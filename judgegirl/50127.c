int *table[1 << 20];

void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N)
{
    for ( int i = 0; i < N; i++) {
        for ( int j = 0; j < N; j++) {
            table[A[i][j]] = &A[i][j];
        }
    }
    int final = N * N - 1;
    for ( int i = 0; i < N; i++) {
        for ( int j = 0; j < N; j++) {
            if ( A[i][j] == final ) {
                B[i][j] = table[0];
            } else {
                B[i][j] = table[A[i][j] + 1];
            }
        }
    }
}
