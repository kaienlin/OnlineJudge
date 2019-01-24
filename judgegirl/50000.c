#include <stdio.h>

int main(void)
{
    int k;
    scanf("%d", &k);
    int positive = 0, negative = 0;
    int mode = 0; // 1 is positve, 0 is negative
    int mid = 0; // 1 means process is in a alternating sequence
    int count = 0, maxlen = 0; // count: segments count
    int num;

    while ( 1 ) {
        scanf("%d", &num);
        if ( num == 0 ) {
            if ( mode == 1 && positive >= k ) { // I missed something here ( && positive >= k )
                count++;
                if ( count > 1 && k * count > maxlen ) {
                    maxlen = k * count;
                }
            }
            break;
        }

        if ( mid == 1 ) {
            if ( mode == 1 ) {
                if ( num > 0 ) {
                    positive++;
                } else {
                    if ( positive == k ) {
                        mode = 0;
                        positive = 0;
                        negative++;
                        count++;
                        if ( count > 1 && k * count > maxlen ) {
                            maxlen = k * count;
                        }
                    } else if ( positive > k ) {
                        count++;
                        if ( count > 1 && k * count > maxlen ) {
                            maxlen = k * count;
                        }
                        positive = 0;
                        negative++;
                        count = 1;
                        mode = 0;
                    } else {
                        mid = 0;
                        positive = 0;
                        negative = 0;
                        count = 0;
                        continue;
                    }
                }
            } else if ( mode == 0 ) {
                if ( num < 0 ) {
                    negative++;
                } else {
                    if ( negative == k ) {
                        mode = 1;
                        negative = 0;
                        positive++;
                        count++;
                    } else {
                        positive = 1;
                        mid = 0;
                        negative = 0;
                        count = 0;
                    }
                }
            }
        } else {
            if ( num > 0 ) {
                positive++;
            } else {
                if ( positive >= k ) { // first segment's length do not need to == k
                    mid = 1;
                    mode = 0;
                    positive = 0;
                    negative++; // brecause this is the first negative number
                    count++; // the first segment
                    continue;
                }
                positive = 0;
            }
        }
    }

    printf("%d", maxlen);

    return 0;
}
