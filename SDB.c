#include <stdio.h>
#include <stdlib.h>
#include "SDB.h"
extern iii;
typedef struct node
{
    student data;
    struct node* next;
}node;

node* head=NULL;
node* new_student;
node* last;
uint8 NumberOfStudents=0;
uint32 idarr [10];

bool SDB_AddEntry()
{


    new_student = (node*) calloc(1,sizeof(node));
    printf("Enter Student ID : ");
    scanf("%u",&new_student->data.Student_ID);
    printf("Enter Course 1 ID : ");
    scanf("%u",&new_student->data.Course1_ID);
    printf("Enter Course 1 Grade : ");
    scanf("%u",&new_student->data.Course1_grade);
    printf("Enter Course 2 ID : ");
    scanf("%u",&new_student->data.Course2_ID);
    printf("Enter Course 2 Grade : ");
    scanf("%u",&new_student->data.Course2_grade);
    printf("Enter Course 3 ID : ");
    scanf("%u",&new_student->data.Course3_ID);
    printf("Enter Course 3 Grade : ");
    scanf("%u",&new_student->data.Course3_grade);

    if(head==NULL)
    {
        head=new_student;
        new_student->next=NULL;
    }
    else
    {

        last=head;
        while(last->next!=NULL)
        {
            last=last->next;
        }


           // printf("%d",last->data.Student_ID);


        last->next=new_student;
        new_student->next=NULL;

    }
    if(new_student->next==NULL)
    {
        printf("\nAdding Done ...\n");
        NumberOfStudents++;
        for(iii;iii<1;iii++)
        {
            printf("%d",iii);
            idarr[iii]=new_student->data.Student_ID;
        }

        return 1;
    }
    else
    {
        printf("\nAdding Not Done ... Add correct data ! \n");
        return 0;
    }

}

bool SDB_ReadEntry (uint32 id)
{
    node* target;
    if(head==NULL)
    {
        printf("\nThe DataBase Is empty\n");
    }
    else
    {
        target=head;
        while(target->next!=NULL)
        {
            if(target->data.Student_ID==id)
            {
                printf("Student Found ...\n");
                printf(" Course 1 id : %u\n",new_student->data.Course1_ID);
                printf(" Course 1 Grade : %u\n",new_student->data.Course1_grade);
                printf(" Course 2 id : %u\n",new_student->data.Course2_ID);
                printf(" Course 2 Grade : %u\n",new_student->data.Course2_grade);
                printf(" Course 3 id : %u\n",new_student->data.Course3_ID);
                printf(" Course 3 Grade : %u\n",new_student->data.Course3_grade);
                return 1;
            }
            else
            {
                target=target->next;
            }
        }
        if((target->next==NULL)&&(target->data.Student_ID==id))
        {
                printf("Student Found ...\n");
                printf(" Course 1 id : %u\n",new_student->data.Course1_ID);
                printf(" Course 1 Grade : %u\n",new_student->data.Course1_grade);
                printf(" Course 2 id : %u\n",new_student->data.Course2_ID);
                printf(" Course 2 Grade : %u\n",new_student->data.Course2_grade);
                printf(" Course 3 id : %u\n",new_student->data.Course3_ID);
                printf(" Course 3 Grade : %u\n",new_student->data.Course3_grade);
                return 1;
        }
        else
        {
            printf("\nStudent Not Found ...");
            return 0;
        }
    }
    return 1;
}

void SDB_DeletEntry (uint32 id)
{
 if(head==NULL)
    {

        printf("\nDatabase Empty ...\n");

        return ;
    }
    else
{

    node* target,* prev;
    target=head;
    prev=head;

    if(target->data.Student_ID==id)
    {
        printf("\nStudent Deleted Successfully ...\n");
        head=target->next;
        free(target);
        NumberOfStudents--;
        return ;
    }


  while(target->data.Student_ID!=id)
    {
        prev=target;
        target=target->next;
    }
    prev->next=target->next;
    free(target);
    NumberOfStudents--;
    if(target->data.Student_ID==id)
    {
        printf("\nStudent Deleted Successfully ...\n");
    }
    else if(target->next==NULL)
        {printf("\nStudent Not Found ! ...\n");}

}
}


uint8 SDB_GetUsedSize()
{
   if(NumberOfStudents==0)
   {
       printf("\nDatabase Empty ... \n");
       return NumberOfStudents;
   }
   else if (NumberOfStudents==10)
   {
        printf("\nDatabase is Full ... \n");
        return NumberOfStudents;
   }
   else
   {
       printf("\nNumber of Students in database is : %u \n",NumberOfStudents);
       return NumberOfStudents;
   }
}

bool SDB_IsIdExist (uint32 id)
{

    node* target;
    target=head;


     if(head==NULL)
    {

        printf("\nDatabase Empty ...\n");

        return 0 ;
    }
    else
    {
        if (target->data.Student_ID==id)
        {
           printf("\nStudent id Exist ! ...\n");
           return 1;
        }
        else if(target->data.Student_ID!=id)
            {
                printf("\nStudent id Not Found ! ...\n");
                return 0;
            }
        while(target->data.Student_ID!=id)
        {
        target=target->next;
        }

        if(target->data.Student_ID==id)
        {
        printf("\nStudent id Exist ! ...\n");
        return 1;
        }
        else if(target==NULL)
        {printf("\nStudent id Not Found ! ...\n");return 0;}
    }
}


bool SDB_IsFull ()
{
    if(NumberOfStudents==10)
    {
        printf("\nDatabase is Full ... \n");
        return true;
    }
    else if (NumberOfStudents<10)
    {
        printf("\nDatabase is Not Full ... \n");
        return false;
    }
}

void SDB_GetList (uint8 * count, uint32 * list)
{
    count=NumberOfStudents;
    printf("\n%d IDs \n",NumberOfStudents);
    printf("IDs is : ");

    for(int i=0;i<10;i++)
    {
        printf("%d   ",idarr[i]);
    }
    printf("\n");

}

