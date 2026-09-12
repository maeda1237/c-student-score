/*
 * Student Score System
 * A console app to add, list and search student scores (C / Math).
 *
 * Features:
 *   1. Add student info   (duplicate ID check, score 0-100 check)
 *   2. Show all students
 *   3. Search student by ID
 *   0. Exit
 */

#include <stdio.h>
#include <string.h>

#define MAX_STU 50

struct Student {
    int id;
    char name[20];
    int scoreC, scoreMath;
    float average;
};

/* ---- function declarations ---- */
void showMenu(void);
void addStudent(struct Student stus[], int *count);
void showAllStudent(struct Student stus[], int count);
int findStudent(struct Student stus[], int count, int targetId);
void searchStudent(struct Student stus[], int count);

int main(void)
{
    struct Student stus[MAX_STU];
    int count = 0;
    int choice;

    while (1) {
        showMenu();
        /* if input is not a number, clear buffer and ask again */
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("Invalid input, try again!\n");
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(stus, &count);
                break;
            case 2:
                showAllStudent(stus, count);
                break;
            case 3:
                searchStudent(stus, count);
                break;
            case 0:
                printf("Program exit.\n");
                return 0;
            default:
                printf("Invalid choice, try again!\n");
                break;
        }
    }
}

/* print menu */
void showMenu(void)
{
    printf("\n===== Student Score System =====\n");
    printf("1. Add student info\n");
    printf("2. Show all students\n");
    printf("3. Search student by ID\n");
    printf("0. Exit\n");
    printf("Please select option: ");
}

/* add one student */
void addStudent(struct Student stus[], int *count)
{
    int id, scoreC, scoreMath;
    char name[20];

    if (*count >= MAX_STU) {
        printf("Student amount reaches upper limit!\n");
        return;
    }

    printf("Please input student id: ");
    scanf("%d", &id);
    while (getchar() != '\n');

    /* duplicate ID check */
    if (findStudent(stus, *count, id) != -1) {
        printf("Student ID %d already exists, add failed!\n", id);
        return;
    }

    printf("Please input student name: ");
    scanf("%s", name);
    while (getchar() != '\n');

    printf("Please input C score (0-100): ");
    scanf("%d", &scoreC);
    while (getchar() != '\n');
    if (scoreC < 0 || scoreC > 100) {
        printf("Invalid C score, add failed!\n");
        return;
    }

    printf("Please input Math score (0-100): ");
    scanf("%d", &scoreMath);
    while (getchar() != '\n');
    if (scoreMath < 0 || scoreMath > 100) {
        printf("Invalid Math score, add failed!\n");
        return;
    }

    stus[*count].id = id;
    strcpy(stus[*count].name, name);
    stus[*count].scoreC = scoreC;
    stus[*count].scoreMath = scoreMath;
    stus[*count].average = (scoreC + scoreMath) / 2.0f;
    (*count)++;

    printf("Add success!\n");
}

/* print all saved students */
void showAllStudent(struct Student stus[], int count)
{
    if (count == 0) {
        printf("No student data yet!\n");
        return;
    }

    printf("\n===== Student Information =====\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d\n", stus[i].id);
        printf("Name: %s\n", stus[i].name);
        printf("C Score: %d\n", stus[i].scoreC);
        printf("Math Score: %d\n", stus[i].scoreMath);
        printf("Average: %.2f\n", stus[i].average);
        printf("-----------------------\n");
    }
}

/* find student by id, return index or -1 */
int findStudent(struct Student stus[], int count, int targetId)
{
    for (int i = 0; i < count; i++) {
        if (stus[i].id == targetId) {
            return i;
        }
    }
    return -1;
}

/* search one student by id */
void searchStudent(struct Student stus[], int count)
{
    int id, index;

    if (count == 0) {
        printf("No student data!\n");
        return;
    }

    printf("Please input student id to search: ");
    scanf("%d", &id);
    while (getchar() != '\n');

    index = findStudent(stus, count, id);
    if (index == -1) {
        printf("Student not found!\n");
        return;
    }

    printf("\n===== Search Result =====\n");
    printf("ID: %d\n", stus[index].id);
    printf("Name: %s\n", stus[index].name);
    printf("C Score: %d\n", stus[index].scoreC);
    printf("Math Score: %d\n", stus[index].scoreMath);
    printf("Average: %.2f\n", stus[index].average);
}
