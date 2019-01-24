const unsigned long long row[8] = {0xFF00000000000000, 0x00FF000000000000, 0x0000FF0000000000, 0x000000FF00000000, 0x00000000FF000000, 0x0000000000FF0000, 0x000000000000FF00, 0x00000000000000FF};
const unsigned long long col[8] = {0x8080808080808080, 0x4040404040404040, 0x2020202020202020, 0x1010101010101010, 0x0808080808080808, 0x0404040404040404, 0x0202020202020202, 0x0101010101010101};
const unsigned long long adj[2] = {0x8040201008040201, 0x0102040810204080};
int bingo(const unsigned long long int *board, int *rowColumn)
{
    for ( int i = 0; i < 8; i++) {
        if ( (*board & row[i]) == row[i] ) { // the precedence of == is higher than &, |, ^ ...
            *rowColumn = i;
            return 1;
        }
    }
    for ( int i = 0; i < 8; i++) {
        if ( (*board & col[i]) == col[i] ) {
            *rowColumn = i;
            return 2;
        }
    }
    for ( int i = 0; i < 2; i++) {
        if ( (*board & adj[i]) == adj[i] ) {
            *rowColumn = i;
            return 3;
        }
    }
    return 0;
}
