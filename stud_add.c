#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void stud_add()
{
    Student *newnode, *temp;
    int roll = 0;

    newnode = (Student *)malloc(sizeof(Student));
if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
printf("Enter Student Name: ");
 scanf(" %49[^\n]", newnode->name);

printf("Enter Percentage: ");
scanf("%f", &newnode->percentage);
 temp = head;
while (temp != NULL)
    {
        if (temp->roll_no > roll)
        {
            roll = temp->roll_no;
        }

        temp = temp->next;
    }
newnode->roll_no = roll + 1;
newnode->next = NULL;
if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
    }

    printf("\nStudent added successfully!\n");
    printf("Assigned Roll Number: %d\n", newnode->roll_no);
}
