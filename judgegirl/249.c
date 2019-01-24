#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct employee {
  int id;
  char first_name[32];
  char last_name[32];
  int boss_id;
} Employee;

int cmp(const void *a, const void *b)
{
    Employee x = *(Employee *)a;
    Employee y = *(Employee *)b;
    return x.id - y.id;
}

int binary_search(Employee data[], int n, int target_id)
{
    int left = 0, right = n;
    int index = (left + right) / 2;
    while ( data[index].id != target_id ) {
        if ( data[index].id > target_id ) {
            right = index - 1;
        } else {
            left = index + 1;
        }
        index = (left + right) / 2;
    }
    return index;
}

int main()
{
    int n;
    scanf("%d", &n);
    Employee data[n];
    for ( int i = 0; i < n; i++) {
        scanf("%d%s%s%d", &data[i].id, data[i].first_name, data[i].last_name, &data[i].boss_id);
    }
    int m;
    scanf("%d", &m);
    char f_name1[32], l_name1[32], f_name2[32], l_name2[32];
    int id1, id2;
    int boss_id1, boss_id2;
    int boss_list_1[n], boss_list_2[n];
    while ( m-- ) {
        scanf("%s%s%s%s", f_name1, l_name1, f_name2, l_name2);
        id1 = -1;
        id2 = -1;
        for ( int i = 0; i < n; i++) {
            if ( strcmp(f_name1, data[i].first_name) == 0 && strcmp(l_name1, data[i].last_name) == 0 ) {
                id1 = data[i].id;
                boss_id1 = data[i].boss_id;
            }
            if ( strcmp(f_name2, data[i].first_name) == 0 && strcmp(l_name2, data[i].last_name) == 0 ) {
                id2 = data[i].id;
                boss_id2 = data[i].boss_id;
            }
            if ( id1 >= 0 && id2 >= 0 ) {break;}
        }
        qsort(data, n, sizeof(Employee), cmp);
        int count1 = 0;
        int index = binary_search(data, n, boss_id1);
        while ( data[index].id != data[index].boss_id ) {
            boss_list_1[count1] = data[index].id;
            count1++;
            index = binary_search(data, n, data[index].boss_id);
        }
        boss_list_1[count1] = data[index].id;
        int count2 = 0;
        index = binary_search(data, n, boss_id2);
        while ( data[index].id != data[index].boss_id ) {
            boss_list_2[count2] = data[index].id;
            count2++;
            index = binary_search(data, n, data[index].boss_id);
        }
        boss_list_2[count2] = data[index].id;
        int flag = 0;
        for ( int i = 0; i <= count1; i++) {
            if ( boss_list_1[i] == id2 ) {
                printf("subordinate\n");
                flag = 1;
                break;
            }
        }
        for ( int i = 0; i <= count2 && !flag; i++) {
            if ( boss_list_2[i] == id1 ) {
                printf("supervisor\n");
                flag = 1;
                break;
            }
        }
        for ( int i = 0; i <= count1 && !flag; i++) {
            for ( int j = 0; j <= count2; j++) {
                if ( boss_list_1[i] == boss_list_2[j] ) {
                    printf("colleague\n");
                    flag = 1;
                    break;
                }
            }
        }
        if ( !flag ) {
            printf("unrelated\n");
        }
    }
    return 0;
}