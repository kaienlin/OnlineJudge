#include "tct.h"
#include <string.h>
#include <stdio.h>

void printTree(Directory *fs, int level, int prefix[])
{
    if (fs == NULL) {return;}
    char *pre[2] = {"   ", "  |"};
    if ( level != 0 ) {
        prefix[level-1] = 1;
        putchar(' ');
        for ( int i = 0; i < level; i++)
            printf("%s", pre[prefix[i]]);
        putchar('\n');
        putchar(' ');
        for ( int i = 0; i < level - 1; i++)
            printf("%s", pre[prefix[i]]);
        printf("  ");
        if ( fs->silbingDir != NULL )
            prefix[level-1] = 1;
        else
            prefix[level-1] = 0;
    }
    printf("+- %s\n", fs->name);
    printTree(fs->childDir, level + 1, prefix);
    if ( level != 0 )
        printTree(fs->silbingDir, level, prefix);
}
void tree(Directory *fs)
{
    int prefix[1024] = {0};
    printTree(fs, 0, prefix);
}
Directory* cd(Directory *fs, char path[])
{
    fs = fs->childDir;
    char *sptr = strtok(path, "/");
    while (sptr!=NULL) {
        while (strcmp(sptr, fs->name)) {
            fs = fs->silbingDir;
        }
        sptr = strtok(NULL, "/");
        if ( sptr != NULL )
            fs = fs->childDir;
    }
    return fs;
}