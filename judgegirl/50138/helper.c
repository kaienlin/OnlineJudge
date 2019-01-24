#include "computeGrade.h"
#include <stdio.h>

void avg_of_exam(double avg[][2], int class_id, Classes *class) {
    int n = class->numStudent;
    for ( int i = 0; i < 18; i++) {
        int sum = 0;
        for ( int j = 0; j < n; j++)
            sum += class->student[j].score[i].rawScore;
        avg[i][class_id] = (double)sum / n;
    }
}
void scale(Classes *cls, double r, int exam) {
    int n = cls->numStudent;
    Student *stu = cls->student;
    for ( int i = 0; i < n; i++) {
        stu[i].score[exam].scaledScore = stu[i].score[exam].rawScore * r;
        if ( stu[i].score[exam].scaledScore > 100.0 )
            stu[i].score[exam].scaledScore = 100.0;
    }
}
void compute_scale_score(Classes cls[2], double avg[][2]) {
    for ( int i = 0; i < 18; i++) {
        if ( avg[i][0] > avg[i][1] ) {
            scale(&cls[1], avg[i][0] / avg[i][1], i);
            scale(&cls[0], 1.0, i);
        } else {
            scale(&cls[0], avg[i][1] / avg[i][0], i);
            scale(&cls[1], 1.0, i);
        }
    }
}
void compute_final_score(Classes *cls) {
    int n = cls->numStudent;
    Student *stu = cls->student;
    for ( int i = 0; i < n; i++) {
        double sum = 0.0;
        for ( int j = 0; j < 18; j++)
            sum += stu[i].score[j].scaledScore;
        stu[i].finalScore = sum * 0.06;
        if ( stu[i].finalScore > 100.0 )
            stu[i].finalScore = 100.0;
    }
}
void print(Classes *cls) {
    int n = cls->numStudent;
    for ( int i = 0; i < n; i++)
        printf("%s %f\n", cls->student[i].id, cls->student[i].finalScore);
}
void computeGrade(Classes classes[2]) {
    double avg[18][2] = {0.0};
    for ( int class = 0; class < 2; class++)
        avg_of_exam(avg, class, &classes[class]);
    compute_scale_score(classes, avg);
    for ( int class = 0; class < 2; class++) {
        compute_final_score(&classes[class]);
        print(&classes[class]);
    }
}