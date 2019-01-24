#include <stdio.h>
#include <string.h>

int main()
{
    int m;
    scanf("%d", &m);
    char author[128][64];
    char bookname[128][128][64]; // coorespond to author index
    char book[64], au[64]; // handle input
    int author_n = 0, book_n[128] = {0};
    for ( int i = 0; i < m; i++) {
        scanf("%s%s", au, book);
        int f = 1;
        for ( int j = 0; j < author_n; j++) {
            if ( strcmp(au, author[j]) == 0 ) {
                strcpy(bookname[j][ book_n[j] ], book);
                book_n[j]++;
                f = 0;
                break;
            }
        }
        if ( f ) {
            strcpy(author[author_n], au);
            strcpy(bookname[author_n][0], book);
            book_n[author_n]++;
            author_n++;
        }
    }
    int a_count[128] = {0};
    int num;
    for ( int i = 0; i < m; i++) {
        scanf("%s %d", book, &num);
        for ( int j = 0; j < author_n; j++) {
            for ( int k = 0; k < book_n[j]; k++) {
                if ( strcmp(bookname[j][k], book) == 0 ) {
                    a_count[j] += num;
                    j = author_n;
                    break;
                }
            }
        }
    }

    int max = 0, max_i;
    for ( int i = 0; i < author_n; i++) {
        if ( a_count[i] > max ) {
            max = a_count[i];
            max_i = i;
        } else if ( a_count[i] == max ) {
            if ( strcmp(author[i], author[max_i]) < 0 ) {
                max = a_count[i];
                max_i = i;
            }
        }
    }
    printf("%s %d", author[max_i], max);
    return 0;
}