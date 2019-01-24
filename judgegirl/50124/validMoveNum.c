int validMoveNum(int r, int c, int n, int visited[100][100])
{
    if ( r < 0 || r >= n || c < 0 || c >= n || visited[r][c] != 0 ) { // miss the situation if visited[r][c] != 0
        return -1;
    }
    const int dr[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    const int dc[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    int valid = 0;
    for ( int i = 0; i < 8; i++) {
        int rp = r + dr[i];
        int cp = c + dc[i];
        if ( rp >= 0 && rp < n && cp >= 0 && cp < n && visited[rp][cp] == 0 ) {
            valid++;
        }
    }
    return valid;
}