#include <stdio.h>
#define BUF 1<<24

char buf[BUF];

int readchar() {
    static char *p = buf, *end = buf;
    if ( p == end ) {
        if ( (end = buf + fread(buf, 1, BUF, stdin)) == buf )
            return EOF;
        p = buf;
    }
    return *p++;
}
