#include <stdio.h>

struct Employee
{
    int id;
    char name[50];
    float salary;
    char department[30];
};

int main()
{
    struct Employee emp;
    int choice;

    // Input employee details
    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);

    printf("Enter Employee Name: ");
    scanf(" %[^\n]", emp.name);

    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    printf("Enter Department: ");
    scanf(" %[^\n]", emp.department);

    // Display details
    printf("\n--- Employee Details ---\n");
    printf("ID: %d\n", emp.id);
    printf("Name: %s\n", emp.name);
    printf("Salary: %.2f\n", emp.salary);
    printf("Department: %s\n", emp.department);

    // Update employee details
    printf("\nDo you want to update the details? (1-Yes / 0-No): ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("\nEnter New Name: ");
        scanf(" %[^\n]", emp.name);

        printf("Enter New Salary: ");
        scanf("%f", &emp.salary);

        printf("Enter New Department: ");
        scanf(" %[^\n]", emp.department);

        printf("\n--- Updated Employee Details ---\n");
        printf("ID: %d\n", emp.id);
        printf("Name: %s\n", emp.name);
        printf("Salary: %.2f\n", emp.salary);
        printf("Department: %s\n", emp.department);
    }

    return 0;
}
