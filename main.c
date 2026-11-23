#include "student.h"
Student *head = NULL;
int main()
{
int choice;
stud_load();
while(1)
{
printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
printf("1. Add New Record\n");
printf("2. Delete a Record\n");
printf("3. Show the List\n");
printf("4. Modify a Record\n");
printf("5. Save\n");
printf("6. Sort the List\n");
printf("7. Exit\n");
printf("\nEnter your choice: ");
scanf("%d", &choice);
switch(choice)
{
case 1:
stud_add();
break;
case 2:
stud_del();
break;
case 3:
stud_show();
break;
case 4:
stud_mod();
break;
case 5:
stud_save();
break;
case 6:
stud_sort();
break;
case 7:
{
int ch;
printf("\nDo you want to save before exiting?");
printf("\n1. Save and Exit");
printf("\n2. Exit Without Saving");
printf("\n3. Cancel Exit");
printf("\nEnter your choice: ");
scanf("%d", &ch);
if(ch == 1)
{
 stud_save();
 printf("Exiting program...\n");
 return 0;
 }
else if(ch == 2)
{
        printf("Exiting Without Saving...\n");
        return 0;
    }
else if(ch == 3)
{
        printf("Exit Cancelled!\n");
    }
else
    {
        printf("Invalid Choice!\n");
    }

    break;
}
default:
printf("Invalid choice! Try again.\n");
}
}
return 0;
}
