#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student {
	char name[64];
	struct student *left, *right;
} Student;

typedef struct club {
	char name[64];
	char leader[64];
	Student *root;
	struct club *left, *right;
} Club;

Student *new_stu(char *name); 

Club *found(Club *root, char *leader, char *name) {
	if ( root == NULL ) {
		Club *ret = (Club*)malloc(sizeof(Club));
		strcpy(ret->name, name);
		strcpy(ret->leader, leader);
		ret->left = ret->right = NULL;
		ret->root = new_stu(leader);
		return ret;
	} else if ( strcmp(name, root->name) < 0 )
		root->left = found(root->left, leader, name);
	else
		root->right = found(root->right, leader, name);
	return root;
}

Club *search_club(Club *root, char *name) {
	if ( root == NULL )
		return NULL;
	int cmp = strcmp(name, root->name);
	if ( cmp == 0 )
		return root;
	else if ( cmp < 0 )
		return search_club(root->left, name);
	else
		return search_club(root->right, name);
}

Student *new_stu(char *name) {
	Student *ret = (Student*)malloc(sizeof(Student));
	ret->left = ret->right = NULL;
	strcpy(ret->name, name);
	return ret;
}

void insert_stu(Student *root, char *name) {
	int cmp = strcmp(name, root->name);
	if ( cmp < 0 )
		if ( root->left == NULL )
			root->left = new_stu(name);
		else
			insert_stu(root->left, name);
	else
		if ( root->right == NULL )
			root->right = new_stu(name);
		else
			insert_stu(root->right, name);
}

int search_stu(Student *root, char *name) {
	if ( root == NULL )
		return 0;
	int cmp = strcmp(name, root->name);
	if ( cmp == 0 )
		return 1;
	else if ( cmp < 0 )
		return search_stu(root->left, name);
	else
		return search_stu(root->right, name);
}

int main()
{
	Club *root = NULL;
	int K;
	scanf("%d", &K);
	int cmd;
	char s1[64], s2[64];
	while (K--) {
		scanf("%d%s%s", &cmd, s1, s2);
		if ( cmd )
			insert_stu(search_club(root, s2)->root, s1);
		else
			root = found(root, s1, s2);
	}
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		scanf("%d", &cmd);
		if ( cmd == 0 ) {
			scanf("%s", s1);
			Club *result = search_club(root, s1); 
			if ( result == NULL )
				puts("None");
			else
				puts(result->leader);
		} else {
			scanf("%s%s", s1, s2);
			Club *result = search_club(root, s2);
			if ( result == NULL )
				puts("-1");
			else
				printf("%d\n", search_stu(result->root, s1));
		}
	}
	return 0;
}
