#include <stdio.h>

typedef struct {
    char name[20];
    int id;
    char phone[10];
    float grade[4];
    int birth_year;
    int birth_month;
    int birth_day;
} Student;

int main()
{
    char input[81];
    char output[81];
    scanf("%s%s", input, output);
    FILE *in = fopen(input, "rb");
    FILE *out = fopen(output, "wt");
    fprintf(out, "<table border=\"1\">\n<tbody>\n");
    Student buffer;
    while ( fread(&buffer, sizeof(Student), 1, in) != 0 ) {
        fprintf(out, "<tr>\n<td>%s</td>\n", buffer.name);
        fprintf(out, "<td>%d</td>\n", buffer.id);
        fprintf(out, "<td>%s</td>\n", buffer.phone);
        fprintf(out, "<td>%f, %f, %f, %f</td>\n", buffer.grade[0], buffer.grade[1], buffer.grade[2], buffer.grade[3]);
        fprintf(out, "<td>%d, %d, %d</td>\n</tr>\n", buffer.birth_year, buffer.birth_month, buffer.birth_day);
    }
    fprintf(out, "</tbody>\n</table>");
    fclose(in);
    fclose(out);

    return 0;
}