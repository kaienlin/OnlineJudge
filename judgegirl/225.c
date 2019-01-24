#include <stdio.h>
#include <string.h>

struct person {
    unsigned int id;
    char name[32];
};

struct friends {
    unsigned id1;
    unsigned id2;
};

struct person people[10000];
struct friends relation[10000];

int main()
{
    FILE *f = fopen("friends", "rb");
    int P;
    fread(&P, sizeof(int), 1, f);
    fread(people, sizeof(struct person), P, f);
    int F;
    fread(&F, sizeof(int), 1, f); 
    fread(relation, sizeof(struct friends), F, f);
    char name1[32], name2[32];
    unsigned int id1, id2;
    while ( scanf("%s%s", name1, name2) != 1 ) {
        id1 = 10000;
        id2 = 10000; // unsigned int should not be negative!!
        for ( int i = 0; i < P; i++) {
            if ( strcmp(name1, people[i].name) == 0 ) {
                id1 = people[i].id;
            }
            if ( strcmp(name2, people[i].name) == 0 ) {
                id2 = people[i].id;
            }
            if ( id1 < 10000 && id2 < 10000 ) {break;}
        }
        int j;
        for ( j = 0; j < F; j++) {
            if ( id1 == relation[j].id1 && id2 == relation[j].id2 || id2 == relation[j].id1 && id1 == relation[j].id2 ) {
                printf("yes\n");
                break;
            }
        }
        if ( j == F ) {
            printf("no\n");
        }
    }
    fclose(f);
    return 0;
}