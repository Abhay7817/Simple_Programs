#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

void display_students(char students[][NAME_LENGTH], int count) {
    printf("Current list of students:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s\n", i + 1, students[i]);
    }
    printf("\n");
}

void create_student_list(char students[][NAME_LENGTH], int *count) {
    printf("Enter the number of students you want to add: ");
    scanf("%d", count);
    getchar();

    for (int i = 0; i < *count; i++) {
        printf("Enter student name: ");
        fgets(students[i], NAME_LENGTH, stdin);
        students[i][strcspn(students[i], "\n")] = 0;
    }
}

void insert_student(char students[][NAME_LENGTH], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Cannot insert, list is full.\n");
        return;
    }

    char name[NAME_LENGTH];
    int index;

    printf("Enter the name of the student to insert: ");
    getchar();
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0;

    printf("Enter the position (1 to %d) to insert the student: ", *count + 1);
    scanf("%d", &index);

    if (index < 1 || index > *count + 1) {
        printf("Invalid index!\n");
        return;
    }

    for (int i = *count; i >= index; i--) {
        strcpy(students[i], students[i - 1]);
    }
    strcpy(students[index - 1], name);
    (*count)++;

    display_students(students, *count);
}

void delete_student(char students[][NAME_LENGTH], int *count) {
    char choice;
    printf("Do you want to delete by (n)ame or (i)ndex? Enter n or i: ");
    getchar();
    scanf("%c", &choice);

    if (choice == 'n') {
        char name[NAME_LENGTH];
        printf("Enter the name of the student to delete: ");
        getchar();
        fgets(name, NAME_LENGTH, stdin);
        name[strcspn(name, "\n")] = 0;
        int found = 0;
        for (int i = 0; i < *count; i++) {
            if (strcmp(students[i], name) == 0) {
                found = 1;
                for (int j = i; j < *count - 1; j++) {
                    strcpy(students[j], students[j + 1]);
                }
                (*count)--;
                break;
            }
        }
        if (!found) {
            printf("Student not found!\n");
        }
    } else if (choice == 'i') {
        int index;
        printf("Enter the index (1 to %d) of the student to delete: ", *count);
        scanf("%d", &index);

        if (index < 1 || index > *count) {
            printf("Invalid index!\n");
            return;
        }

        for (int i = index - 1; i < *count - 1; i++) {
            strcpy(students[i], students[i + 1]);
        }
        (*count)--;
    } else {
        printf("Invalid choice!\n");
        return;
    }

    display_students(students, *count);
}

void traverse_students(char students[][NAME_LENGTH], int count) {
    display_students(students, count);
}

void search_student(char students[][NAME_LENGTH], int count) {
    char name[NAME_LENGTH];
    printf("Enter the name of the student to search for: ");
    getchar();
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i], name) == 0) {
            printf("%s found at position %d.\n", name, i + 1);
            return;
        }
    }

    printf("%s not found.\n", name);
}

int main() {
    char students[MAX_STUDENTS][NAME_LENGTH];
    int count = 0;

    while (1) {
        int choice;
        printf("\nStudent Management System\n");
        printf("1. Create Student List\n");
        printf("2. Insert Student\n");
        printf("3. Delete Student\n");
        printf("4. Traverse Students\n");
        printf("5. Search Student\n");
        printf("6. Exit\n");

        printf("Choose an operation (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_student_list(students, &count);
                break;
            case 2:
                insert_student(students, &count);
                break;
            case 3:
                delete_student(students, &count);
                break;
            case 4:
                traverse_students(students, count);
                break;
            case 5:
                search_student(students, count);
                break;
            case 6:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}

