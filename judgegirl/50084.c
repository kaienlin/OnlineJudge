#include <stdio.h>
#include <string.h>

int alldone(int jobs[], int m)
{
    for ( int i = 0; i < m; i++) {
        if ( !jobs[i] ) {
            return 0;
        }
    }
    return 1;
}

int tasks[500][500];

int main(void)
{
    int n, m; // n: number of machines, m: number of jobs
    scanf("%d%d", &n, &m);
    int arrival[m];
    int q[m]; // number of tasks
    for ( int i = 0; i < m; i++) {
        scanf("%d%d", &arrival[i], &q[i]);
        for ( int j = 0; j < q[i]; j++) {
            scanf("%d", &tasks[i][j]);
            tasks[i][j] *= 1000;
            int tmp;
            scanf("%d", &tmp);
            tasks[i][j] += tmp;
            // the first three digit represent machine index
            // the lease three digit represent time it takes
        }
    }
    int ready[n];
    int finish[m];
    memset(ready, 0, sizeof(ready));
    memset(finish, 0, sizeof(finish));

    int min;
    int min_index;
    int comple_time;
    int done_jobs[m];
    memset(done_jobs, 0, sizeof(done_jobs));

    while (!alldone(done_jobs, m)) {
        min = __INT_MAX__;
        for ( int i = 0; i < m; i++) {
            if (done_jobs[i]) {
                continue;
            }
            if ( ready[tasks[i][finish[i]] / 1000] >= arrival[i]) {
                comple_time = ready[tasks[i][finish[i]] / 1000] + tasks[i][finish[i]] % 1000; 
            } else {
                comple_time = arrival[i] + tasks[i][finish[i]] % 1000;
            }
            if ( comple_time < min ) {
                min = comple_time;
                min_index = i; // i th jobs
            }
        }
        arrival[min_index] = min;
        ready[tasks[min_index][finish[min_index]] / 1000] = min;
        finish[min_index]++;
        if ( finish[min_index] >= q[min_index] ) {
            done_jobs[min_index] = min;
        }
    }

    for ( int i = 0; i < m; i++) {
        printf("%d\n", done_jobs[i]);
    }

    return 0;
}