#include "student.h"
void stud_mod()
{
Student *temp;
int choice, roll, found = 0;
float percentage;
char name[50], modify;
if(head == NULL)
{
   printf("\nNo records available!\n");
     return;
}
printf("\n1. Search by Roll Number\n");
 printf("2. Search by Name\n");
printf("3. Search by Percentage\n");
 printf("Enter your choice: ");
scanf("%d", &choice);
if(choice == 1)
{
 printf("Enter Roll Number: ");
 scanf("%d", &roll);
 }
else if(choice == 2)
{
printf("Enter Student Name: ");
scanf(" %49[^\n]", name);
    }
else if(choice == 3)
{
 printf("Enter Percentage: ");
  scanf("%f", &percentage);
    }
else
{
 printf("Invalid choice!\n");
 return;
 }
temp = head;
 printf("\nMatching Records:\n");
while(temp != NULL)
{
if((choice == 1 && temp->roll_no == roll) ||
 (choice == 2 && strcmp(temp->name, name) == 0) ||
 (choice == 3 && temp->percentage == percentage))
{
  printf("%d\t%s\t%.2f\n",
   temp->roll_no,
   temp->name,
   temp->percentage);
    found = 1;
}
  temp = temp->next;
  }
if(found == 0)
{
  printf("Student not found!\n");
    return;
  }

if(choice != 1)
{
 printf("\nEnter Roll Number to modify: ");
  scanf("%d", &roll);
  }
temp = head;
while(temp != NULL)
{
 if(temp->roll_no == roll)
  break;
  temp = temp->next;
  }
if(temp == NULL)
{
 printf("Invalid Roll Number!\n");
    return;
    }
printf("\n1. Modify Name\n");
  printf("2. Modify Percentage\n");
 printf("Enter your choice: ");
 scanf(" %c", &modify);
if(modify == '1')
{
 printf("Enter New Name: ");
 scanf(" %49[^\n]", temp->name);
 printf("Name updated successfully!\n");
}
else if(modify == '2')
{
printf("Enter New Percentage: ");
 scanf("%f", &temp->percentage);
 printf("Percentage updated successfully!\n");
  }
 else
{
  printf("Invalid choice!\n");
    }
}
