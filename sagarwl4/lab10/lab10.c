#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3

typedef enum name {
    JASON,  /* = 0 */
    SUSIE,  /* = 1 */
    CHARLIE /* = 2 */
} name;

typedef struct assignment_t {
    double score;
    double possible;
} assignment_t;

typedef struct student_t {
    char *netid;
    assignment_t assignments[N];
} student_t;

typedef struct gradebook_t {
    student_t students[N];
} gradebook_t;

assignment_t* get_assignments(gradebook_t*, int);
student_t* get_student(gradebook_t*, int);
char* get_netid(gradebook_t*, int);
double get_score(gradebook_t*, int, int);
void set_score(gradebook_t*, int, int, double);
double student_average_score(gradebook_t*, int);
double assignment_maximum_score(gradebook_t*, int);

int main(void)
{
    /* Allocate a new gradebook */
    gradebook_t *gradebook = malloc(sizeof *gradebook);
    memset(gradebook, 0, sizeof *gradebook);
    int i, j;

    /* Populate gradebook with some initial values */
    gradebook->students[0].netid = malloc(sizeof "fox16");
    strcpy(gradebook->students[0].netid, "fox16");
    gradebook->students[0].assignments[0].score = 125;
    gradebook->students[0].assignments[1].score = 100;
    gradebook->students[0].assignments[2].score = 100;

    gradebook->students[1].netid = malloc(sizeof "derkins1");
    strcpy(gradebook->students[1].netid, "derkins1");
    gradebook->students[1].assignments[0].score = 94;
    gradebook->students[1].assignments[1].score = 92;
    gradebook->students[1].assignments[2].score = 75;

    gradebook->students[2].netid = malloc(sizeof "cbrown");
    strcpy(gradebook->students[2].netid, "cbrown");
    gradebook->students[2].assignments[0].score = 0;
    gradebook->students[2].assignments[1].score = 93;
    gradebook->students[2].assignments[2].score = 100;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            gradebook->students[i].assignments[j].possible = 100;
        }
    }

    /* Print out some information from the gradebook */
    printf("Susie's assignments pointer: %p\n",
            get_assignments(gradebook, SUSIE));

    printf("Pointer to the student Charlie: %p\n\n",
            get_student(gradebook, CHARLIE));

    printf("Charlie's netid: %s\n",
            get_netid(gradebook, CHARLIE));

    printf("Jason's netid: %s\n",
            get_netid(gradebook, JASON));

    printf("Jason's assignment 2 score: %g\n",
            get_score(gradebook, JASON, 2));

    printf("Susie's average score: %g\n",
            student_average_score(gradebook, SUSIE));

    printf("Max score on assignment 0: %g\n\n",
            assignment_maximum_score(gradebook, 0));

    printf("Charlie's assignment 0 score: %g\n",
            get_score(gradebook, CHARLIE, 0));

    /* Update Charlie's assignment 0 score */
    set_score(gradebook, CHARLIE, 0, 85);

    printf("Charlie's new assignment 0 score: %g\n",
            get_score(gradebook, CHARLIE, 0));

    for (i = 0; i < N; i++)
    {
        free(gradebook->students[i].netid);
    }
    free(gradebook);

    return 0;
}

/* 1/7 */
assignment_t* get_assignments(gradebook_t *gradebook, int student)
{
    /* TODO: Return pointer to student's assignments */
    return NULL;
}

/* 2/7 */
student_t* get_student(gradebook_t *gradebook, int student)
{
    /* TODO: Return pointer to current student in gradebook */
    return NULL;
}

/* 3/7 */
char* get_netid(gradebook_t *gradebook, int student)
{
    /* TODO: Return current student's netid */
    return NULL;
}

/* 4/7 */
double get_score(gradebook_t *gradebook, int student, int assignment)
{
    /* TODO: Return student's score for assignment */
    return 0;
}

/* 5/7 */
void set_score(gradebook_t *gradebook, int student,
               int assignment, double score)
{
    /* TODO: Set student's score for assignment */
}

/* 6/7 */
double student_average_score(gradebook_t *gradebook, int student)
{
    /* TODO: Return average score for student (all scores are
     *       weighted equally)
     */
    return 0;
}

/* 7/7 */
double assignment_maximum_score(gradebook_t *gradebook, int assignment)
{
    /* TODO: Return the maximum score for the given assignment */
    return 0;
}
