#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void stud_sort(void)
{
    int choice;
    Student *p;
    Student *arr;
    int count = 0;
    int i, j;

if (head == NULL || head->next == NULL)
    {
        printf("Not enough records to sort.\n");
        return;
    }
for (p = head; p != NULL; p = p->next)
    {
        count++;
    }
   arr = malloc(count * sizeof(Student));
if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
   p = head;
   for (i = 0; i < count; i++)
    {
        arr[i].roll_no = p->roll_no;
        strcpy(arr[i].name, p->name);
        arr[i].percentage = p->percentage;

        p = p->next;
    }
printf("\n1. Sort by Name\n");
printf("2. Sort by Percentage\n");
printf("Enter Your Choice: ");
scanf("%d", &choice);

    if (choice != 1 && choice != 2)
    {
        printf("Invalid choice.\n");
        free(arr);
        return;
    }
for (i = 0; i < count - 1; i++)
    {
        for (j = 0; j < count - i - 1; j++)
        {
            int swap;

            if (choice == 1)
                swap = strcmp(arr[j].name, arr[j + 1].name) > 0;
            else
                swap = arr[j].percentage > arr[j + 1].percentage;

            if (swap)
            {
                Student temp = arr[j];

                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
printf("\n--- SORTED STUDENT RECORDS ---\n");
printf("%s\t%s\t%s\n",
           "Roll No", "Name", "Percentage");
for (i = 0; i < count; i++)
    {
        printf("%d\t%s\t%.2f\n",
               arr[i].roll_no,
               arr[i].name,
               arr[i].percentage);
    }

    printf("------------------------------\n");
    free(arr);
printf("Sorting completed successfully.\n");
}
