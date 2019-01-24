#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAXS 41

typedef struct stu_node {
    bool exist;
    struct stu_node *next[95];
} Student;

typedef struct club_node {
    char leader[MAXS];
    struct club_node *next[95];
    struct stu_node *members;
} Club;

Student *init_stu_node() {
    Student *ret = (Student*)malloc(sizeof(Student));
    for ( int i = 0; i < 95; i++)
        ret->next[i] = NULL;
    ret->exist = false;
    return ret;
}

Club *init_club_node() {
    Club *ret = (Club*)malloc(sizeof(Club));
    for ( int i = 0; i < 95; i++)
        ret->next[i] = NULL;
    ret->members = NULL;
    ret->leader[0] = '\0';
    return ret;
}

Club *create_club(Club *root, char *leader, char *club) {
    if ( club[0] == '\0' ) {
        strcpy(root->leader, leader);
        root->members = init_stu_node();
    } else {
        int idx = club[0] - '!';
        if ( root->next[idx] == NULL )
            root->next[idx] = init_club_node();
        root->next[idx] = create_club(root->next[idx], leader, club + 1);
    }
    return root;
}

Club *search_club(Club *root, char *club) {
    if ( root == NULL )
        return NULL;
    if ( club[0] == '\0' )
        if ( root->leader[0] != '\0' )
            return root;
        else
            return NULL;
    return search_club(root->next[club[0]-'!'], club + 1);
}

Student *join_club(Student *root, char *name) {
    if ( name[0] == '\0' ) {
        root->exist = true;
    } else {
        int idx = name[0] - '!';
        if ( root->next[idx] == NULL )
            root->next[idx] = init_stu_node();
        root->next[idx] = join_club(root->next[idx], name + 1);
    }
    return root;
}

Student *search_member(Student *root, char *name) {
    if ( root == NULL )
        return NULL;
    if ( name[0] == '\0' )
        if ( root->exist )
            return root;
        else
            return NULL;
    return search_member(root->next[name[0]-'!'], name + 1);
}

int main()
{
    int K;
    scanf("%d", &K);
    int cmd;
    char stu[MAXS], club[MAXS];
    Club *clubs = init_club_node();
    while (K--) {
        scanf("%d %s %s", &cmd, stu, club);
        if ( cmd ) {
            Club *tojoin = search_club(clubs, club);
            tojoin->members = join_club(tojoin->members, stu);
        } else
            clubs = create_club(clubs, stu, club);
    }
    int Q;
    scanf("%d", &Q);
    while (Q--) {
        scanf("%d", &cmd);
        if ( cmd ) {
            scanf("%s%s", stu, club);
            Club *club_result = search_club(clubs, club);
            if ( club_result == NULL )
                puts("-1");
            else {
                if ( !strcmp(stu, club_result->leader) ) {
                    puts("1");
                    continue;
                }
                Student *stu_result = search_member(club_result->members, stu);
                if ( stu_result == NULL )
                    puts("0");
                else
                    puts("1");
            }
        } else {
            scanf("%s", club);
            Club *result = search_club(clubs, club);
            if ( result == NULL )
                puts("None");
            else
                puts(result->leader);
        }
    }
    return 0;
}