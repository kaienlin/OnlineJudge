int matrixA[1000][1000] = 0;
int matrixB[1000][1000] = 0;
 
void matrix_multiplication(int N, int** ptrA, int M, int** ptrB, int S, int *result)
{
    for ( int i = 0; i < N; i++) {
        matrixA[ptrA[1][i]][ptrA[2][i]] = ptrA[0][i];
    }
    for ( int i = 0; i < M; i++) {
        matrixB[ptrB[1][i]][ptrB[2][i]] = ptrB[0][i];
    }
 
    int product, count = 0;
    for ( int i = 0; i < S; i++) {
        for ( int j = 0; j < S; j++) {
            product = 0;
            for ( int k = 0; k < S; k++) {
                product += matrixA[i][k] * matrixB[k][j];
            }
            result[count++] = product;
        }
    }
}