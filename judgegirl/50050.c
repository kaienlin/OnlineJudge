int g[1024][1024] = {{0}};
 
void SpiralSnake(int N, int *snake, int *result)
{
    int r = (N - 1) / 2;
    int c = (N - 1) / 2;
    int i = 0;
    g[r][c] = snake[i];
    c--;
    i++;
    const int dr[4] = {-1, 0, 1, 0};
    const int dc[4] = {0, 1, 0, -1};
    int len = 2;
    while ( i < N * N ) {
        for ( int j = 0; j < 4; j++) {
            for ( int k = 1; k <= len; k++) {
                g[r][c] = snake[i];
                i++;
                r += k == len ? dr[j == 3 ? 3 : j + 1] : dr[j]; // be careful about the direction
                c += k == len ? dc[j == 3 ? 3 : j + 1] : dc[j];
            }
        }
        len+=2; // len increment by 2 every round
    }
    for ( int x = 0; x < N; x++) {
        for ( int y = 0; y < N; y++) {
            result[x * N + y] = g[x][y];
        }
    }
}