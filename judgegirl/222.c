#include <stdio.h>

/* shift over data size can cause undefined behavior */

int hasEOF = 0;

int readchar() {
    static int N = 1<<20;
    static char buf[1<<20];
    static char *p = buf, *end = buf;
    if(p == end) {
        if((end = buf + fread(buf, 1, N, stdin)) == buf) {
            hasEOF = 1;
            return EOF;
        }
        p = buf;
    }
    return *p++;
}

unsigned long long ReadInt(long long *x) {
    char c, neg;
    while((c = readchar()) < '-')    {if(c == EOF) return 0;}
    neg = (c == '-') ? -1 : 1;
    *x = (neg == 1) ? c-'0' : 0;
    while((c = readchar()) >= '0')
        *x = (*x << 3) + (*x << 1) + c-'0';
    *x *= neg;
    return 1;
}

int main() {
    unsigned long long read;
    unsigned long long bookshelf = 0;
    int match, booknumber;
    while (ReadInt(&read)) {
        booknumber = 0;
        for ( int i = 7; i >= 0; i--) {
            if ( !( read ^ ((bookshelf >> (i * 8)) & 255ULL) ) ) {
                booknumber = i + 1;
                break;
            }
        }
        unsigned long long copy = 0;
        if ( booknumber > 1 && booknumber < 8 ) {
            copy |= ( ~0ULL << (8 * booknumber) ) & bookshelf; // make a copy of books on the left of read book
            bookshelf &= ((~0ULL) >> ( (9 - booknumber) * 8 ) ); // delete books on the left of read book plus itself
            bookshelf <<= 8;
            bookshelf |= read;
            bookshelf |= copy;
        } else if ( booknumber == 1 ) {
            bookshelf &= 0xFFFFFFFFFFFFFF00;
            bookshelf |= read;
        } else {
            bookshelf <<= 8;
            bookshelf |= read;
        }
    }
    for ( int i = 7; i >= 0; i--) {
        printf("%ld ", bookshelf >> (i * 8) & 255ULL );
    }
    return 0;
}