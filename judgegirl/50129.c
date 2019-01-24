int visited[1000000] = {0};

void loops(int N, int *A, int *B[], int ans[4])
{
    int maxlen = 0, minlen = 99999999, max = 0, min = 1 << 30;
    for ( int i = 0; i < N; i++) {
        if ( !visited[i] ) {
            int *ptr = B[i], start = A[i], count = 1;
            int M = start, m = start;
            while ( *ptr != start ) {
                count++;
                M = *ptr > M ? *ptr : M;
                m = *ptr < m ? *ptr : m;
                visited[ptr - A] = 1;
                ptr = B[ptr - A];
            }
            if ( count > maxlen ) {
                maxlen = count;
                max = M;
            } else if ( count == maxlen ) {
                max = M > max ? M : max;
            }
            if ( count < minlen ) {
                minlen = count;
                min = m;
            } else if ( count == minlen ) {
                min = m < min ? m : min;
            }
        }
    }
    ans[0] = maxlen;
    ans[1] = minlen;
    ans[2] = max;
    ans[3] = min;
}
