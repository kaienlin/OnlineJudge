struct td {
    char name[32];
    int *grade;
};

struct table {
    int count;
    int dim_n;
    struct td *tr[256];
};

typedef struct td Td;
typedef struct table ExamTable;

void init(ExamTable *self, int n);
void addrow(ExamTable *self, char *name, int score[]);
void print(ExamTable *self, int order[]);
