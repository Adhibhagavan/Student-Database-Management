#include "student.h"
void stud_save()
{
  Student *temp;
 FILE *fp;
fp = fopen("student.dat", "wb");
if(fp == NULL)
{
 printf("File opening error!\n");
  return;
}
temp = head;
while(temp != NULL)
{
fwrite(&temp->roll_no, sizeof(int), 1, fp);
fwrite(temp->name, sizeof(temp->name), 1, fp);
fwrite(&temp->percentage, sizeof(float), 1, fp);
 temp = temp->next;
 }
fclose(fp);
 printf("\nRecords saved successfully!\n");
}
void stud_load()
{
 Student *newnode, *temp;
FILE *fp;
fp = fopen("student.dat", "rb");
if(fp == NULL)
{
printf("No previous records found!\n");
return;
 }
while(1)
{
newnode = (Student *)malloc(sizeof(Student));
if(newnode == NULL)
{
printf("Memory allocation failed!\n");
 break;
     }
if(fread(&newnode->roll_no, sizeof(int), 1, fp) != 1)
{
  free(newnode);
break;
}
if(fread(newnode->name, sizeof(newnode->name), 1, fp) != 1 ||
 fread(&newnode->percentage, sizeof(float), 1, fp) != 1)
 {
 free(newnode);
 printf("Invalid or incomplete data in file!\n");
break;
    }
newnode->next = NULL;
if(head == NULL)
{
 head = newnode;
  }
else
{
temp = head;
while(temp->next != NULL)
{
       temp = temp->next;
  }
temp->next = newnode;
  }
}
fclose(fp);
printf("Records loaded successfully!\n");
}
