#include <stdio.h>
#include <string.h>
#include "Function.h"

void displayMenu(){
		printf("\n*** Student Management System Using C ***\n");
		printf(" \n");
		printf("         =========MENU=========\n");
		printf("         [1] Add A New Student.\n");
		printf("         [2] Show All Students.\n");
		printf("         [3] Search A Student.\n");
		printf("         [4] Edit A Student.\n");
		printf("         [5] Delete A Student.\n");
		printf("         [6] Arrange students\n");
		printf("         [0] Exit Program.\n");
		printf("         ======================\n");
		printf("         Enter Your Choice: ");
} 

void addStudent(){
	FILE *file = fopen("Student.bin", "ab");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return;
    }

    int numberStudents;
    printf("Enter the number of students you want to add: ");
    scanf("%d", &numberStudents);
    getchar();

    for (int i = 0; i < numberStudents; i++) {
        Student student;
        printf("\nStudent %d:\n", i + 1);
        printf("Enter ID: ");
        scanf("%d", &student.id);
        getchar();
        printf("Enter name: ");
        fgets(student.name, 50, stdin);
        student.name[strcspn(student.name, "\n")] = '\0';
        printf("Enter class: ");
        scanf("%d", &student.classroomId);
        getchar();
        printf("Enter gender: ");
        fgets(student.gender, 10, stdin);
        student.gender[strcspn(student.gender, "\n")] = '\0';
        printf("Enter email: ");
        fgets(student.email, 50, stdin);
        student.email[strcspn(student.email, "\n")] = '\0';
        printf("Enter phone: ");
        fgets(student.phone, 20, stdin);
        student.phone[strcspn(student.phone, "\n")] = '\0';

        fwrite(&student, sizeof(Student), 1, file);
    }
    fclose(file);
    printf("\n%d student added successfully.\n", numberStudents);
}

void displayStudents() {
    FILE *file = fopen("Student.bin", "rb");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return;
    }
    
    Student student;
    
    printf("\nStudent list:\n");
    printf("--------------------------------------------------------------------------------------\n");
    printf("ID   | Name                 | Class | Gender  | Email                     | Phone    \n");
    printf("--------------------------------------------------------------------------------------\n");
    
    while (fread(&student, sizeof(Student), 1, file)) {
        printf("%-4d | %-20s | %-5d | %-7s | %-25s | %-10s \n",
               student.id, student.name, student.classroomId, student.gender, student.email, student.phone);
    }
    printf("--------------------------------------------------------------------------------------\n");
    fclose(file);
}

