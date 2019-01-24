#include <stdio.h>
int main()
{
    int cnt=0;
    char c,prev='z';
    while ((c = getchar_unlocked())!=EOF)
        if(c>'a'&&c<='z'&&c!='e'&&c!='i'&&c!='o'&&c!='u') {
            if(c>prev)
                cnt++;
            prev=c;
        }
    printf("%d\n",cnt);
    return 0;
}