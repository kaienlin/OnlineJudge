void place(int bucket[1024],int N,int ball[16384],int M,int method,int result[16384])
{
    int i, j;
    if ( method == 0 ) {
        for ( i = 0; i < M; i++) {
            for ( j = 0; j < N; j++) {
                if ( bucket[j] >= ball[i] ) {
                    result[i] = j;
                    bucket[j] -= ball[i];
                    break;
                }
            }
            if ( j == N ) {
                result[i] = -1;
            }
        }
    } else if ( method == 1 ) {
        int smallest, smallest_index;
        for ( i = 0; i < M; i++) {
            smallest = __INT_MAX__;
            smallest_index = -1;
            for ( j = 0; j < N; j++) {
                if ( bucket[j] >= ball[i] && bucket[j] < smallest ) {
                    smallest = bucket[j];
                    smallest_index = j;
                }
            }
            if ( smallest_index == -1 ) {
                result[i] = -1;
            } else {
                result[i] = smallest_index;
                bucket[smallest_index] -= ball[i];
            }
         }
    } else {
        int largest, largest_index;
        for ( i = 0; i < M; i++) {
            largest = 0;
            largest_index = -1;
            for ( j = 0; j < N; j++) {
                if ( bucket[j] >= ball[i] && bucket[j] >= largest ) {
                    largest = bucket[j];
                    largest_index = j;
                }
            }
            if ( largest_index == -1 ) {
                result[i] = -1;
            } else {
                result[i] = largest_index;
                bucket[largest_index] -= ball[i];
            }
         }
    }
}