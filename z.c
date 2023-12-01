#include <stdio.h>
#include <string.h>

struct legends {
    char first_name[20]; 
    char last_name[20]; 
    int fastest;
    double weight; 
    int comps; 
    char grade[20];
    };

void read_file (struct legends *);
void display_array (struct legends *);
void new_grade (struct legends *);
void write_file (struct legends *);

int main (void) {

    struct legends eaters[16];

    read_file(eaters);

    display_array(eaters);

    new_grade (eaters);

    printf("\n\n");
    display_array(eaters);

    write_file(eaters);

    return 0;

}

void read_file(struct legends *in_array) {

    FILE *file = fopen("legends.dat", "r");

    for (int i = 0; i < 16; i++) {

        fscanf(file, "%s %s %d %lf %d %s", in_array[i].first_name,
               in_array[i].last_name, &in_array[i].fastest, &in_array[i].weight,
               &in_array[i].comps, in_array[i].grade);

    }

    fclose(file);

    return;

}

void display_array(struct legends *in_array) {

    for (int i = 0; i < 16; i++) {

        printf("\n%s %s %d %.2lf %d %s", in_array[i].first_name,
               in_array[i].last_name, in_array[i].fastest, in_array[i].weight,
               in_array[i].comps, in_array[i].grade);

    }

    return;

}

void new_grade(struct legends *in_array) {

    for (int i = 0; i < 16; i++) {

        if ((in_array[i].fastest > 20)
            && (in_array[i].weight > 7.0)
            && (in_array[i].comps >= 25))
            strcpy(in_array[i].grade, "Grade 5");
        else if ((in_array[i].fastest > 20)
                && (in_array[i].weight > 7.0))
                strcpy(in_array[i].grade, "Grade 4");
        else if((in_array[i].weight > 7.0)
                && (in_array[i].comps >= 25))
                strcpy(in_array[i].grade, "Grade 3");
        else if ((in_array[i].fastest > 20)
                && (in_array[i].comps >= 25))
                strcpy(in_array[i].grade, "Grade 2");
        else if ((in_array[i].fastest > 20)
                || (in_array[i].weight > 7.0)
                || (in_array[i].comps >= 25))
                strcpy(in_array[i].grade, "Grade 1");
        else
            strcpy(in_array[i].grade, "Grade 0");   

    }

    return;

}

void write_file(struct legends *in_array) {

    FILE *file = fopen("legends_rated.dat", "w");

    for (int i = 0; i < 16; i++) {

        fprintf(file, "%s %s %d %g %d %s\n", in_array[i].first_name,
                in_array[i].last_name, in_array[i]. fastest,
                in_array[i].weight, in_array[i].comps, in_array[i].grade);

    }

    return;

}