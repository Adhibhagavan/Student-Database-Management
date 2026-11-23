#include "student.h"
void stud_show()
{
  Student *temp;
if(head == NULL)
{
printf("\nNo student records available!\n");
  return;
}
temp = head;
printf("\n---------------------------------------------\n");
   printf("Roll No\t\tName\t\tPercentage\n");
  printf("---------------------------------------------\n");
while(temp != NULL)
{
printf("%d\t\t%-15s\t%.2f\n",
       temp->roll_no,
           temp->name,
          temp->percentage);
        temp = temp->next;
}
 printf("---------------------------------------------\n");
}
