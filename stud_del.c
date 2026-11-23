#include "student.h"
void stud_del()
{
Student *temp, *prev;
int choice, roll, found = 0;
char name[50];
if(head == NULL)
{
printf("\nNo records available!\n");
return;
    }
printf("\n1. Delete using Roll Number\n");
  printf("2. Delete using Name\n");
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
temp = head;
printf("\nMatching Records:\n");
while(temp != NULL)
{
if(strcmp(temp->name, name) == 0)
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
printf("Enter Roll Number to delete: ");
 scanf("%d", &roll);
 }
else
{
printf("Invalid choice!\n");
  return;
 }
temp = head;
prev = NULL;
while(temp != NULL)
{
if(temp->roll_no == roll)
{
 if(choice == 2 && strcmp(temp->name, name) != 0)
{
 temp = temp->next;
   continue;
}
if(prev == NULL)
   head = temp->next;
else
prev->next = temp->next;
   free(temp);
printf("\nStudent deleted successfully!\n");
 return;
  }
 prev = temp;
  temp = temp->next;
 }
 printf("\nStudent not found!\n");
}
