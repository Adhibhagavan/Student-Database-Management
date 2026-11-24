#include "student.h"
void stud_save()
{
    Student *temp;
    FILE *fp;
    fp = fopen("student.dat", "w");
    if(fp == NULL)
    {
        printf("File opening error!\n");
        return;
    }
    temp = head;
    while(temp != NULL)
    {
        fprintf(fp, "%d %s %.2f\n",
                temp->roll_no,
                temp->name,
                temp->percentage);

        temp = temp->next;
    }
    fclose(fp);
    printf("\nRecords saved successfully!\n");
}
void stud_load()
{
    Student *newnode, *temp;
    FILE *fp;
    fp = fopen("student.dat", "r");
    if(fp == NULL)
    {
        printf("No previous records found!\n");
        return;
    }
    while(1)
    {
        newnode = malloc(sizeof(Student));
        if(newnode == NULL)
            break;
        if(fscanf(fp, "%d %49s %f",
                  &newnode->roll_no,
                  newnode->name,
                  &newnode->percentage) != 3)
        {
            free(newnode);
            break;
        }
        newnode->next = NULL;
        if(head == NULL)
            head = newnode;
        else
        {
            temp = head;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
    }
    fclose(fp);
    printf("Records loaded successfully!\n");
}
