typedef struct ingredient {
    char name[128];
    unsigned int w;
} Ing;

typedef struct med {
    unsigned int act_w, inact_w;
    Ing act[2], inact[5];
    unsigned int act_n, inact_n;
} Medicine;

void init(Medicine *medicine);
int addActive(Medicine *medicine, char *name, int weight);
int addInactive(Medicine *medicine, char *name, int weight);
void print(Medicine *medicine);
int totalWeight(Medicine *medicine);
char *maxIngredient(Medicine *medicine);
