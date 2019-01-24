#include <stdio.h>

int convert(int g)
{ 
    const int grade[10] = {90, 85, 80, 77, 73, 70, 67, 63, 60, 0};
    for ( int i = 0; i < 10; i++) {
        if ( g >= grade[i] ) {
            return i;
        }
    }
}

int main()
{
    int grade;
    double sum = 0.0, rankSum = 0.0;
    int num;
    char *rank[10] = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "F"};
    double rankGrade[10] = {4.3, 4.0, 3.7, 3.3, 3.0, 2.7, 2.3, 2.0, 1.7, 0.0};
    double rankTo100[10] = {95, 87, 82, 78, 75, 70, 68, 65, 60, 50};
    while ( scanf("%d", &grade) != EOF ) {
        num++;
#ifdef HUNDRED
        printf("%d ", grade);
        sum += grade;
#endif
#ifdef APLUS
        int index = convert(grade);
        printf("%s ", rank[index]);
        sum += rankTo100[index];
        rankSum += rankGrade[index];
#endif
    }
#ifdef HUNDRED
    printf("%.1lf", sum / num);
#endif
#ifdef APLUS
    printf("%.1lf ", rankSum / num);
    printf("%.1lf", sum / num);
#endif
}