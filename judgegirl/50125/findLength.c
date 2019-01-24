int findLength (int array[][256], int N, int r, int c, int dr, int dc)
{
    int len = 0, maxlen = 0;
    while ( r >= 0 && c >= 0 && r < N && c < N ) {
        if ( array[r][c] ) {
            len++;
            if ( len > maxlen ) {
                maxlen = len;
            }
        } else {
            len = 0;
        }
        r += dr;
        c += dc;
    }
    return maxlen;
}