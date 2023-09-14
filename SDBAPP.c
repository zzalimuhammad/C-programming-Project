#include "STD.h"

    int i=1;
    int idd;
    extern idarr;
    int iii=0;
void SDB_APP ()
{
    int choice;

    while(i)
    {

        printf("\nTo add entry, enter 1\n");
        printf("To get used size in database, enter 2\n");
        printf("To read student data, enter 3\n");
        printf("To get the list of all student IDs, enter 4\n");
        printf("To check is ID is existed, enter 5\n");
        printf("To delete student data, enter 6\n");
        printf("To check is database is full, enter 7\n");
        printf("To exit enter 0\n\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        getchar();
        system("cls");
        SDB_action(choice);

    }

}
void SDB_action (uint8 choice)
{
     switch(choice)
        {
            case 1:
                SDB_AddEntry();
            break;
            case 2:
                SDB_GetUsedSize();
            break;
            case 3:
                printf(" Enter Student id To Start Searching : ");
                scanf("%d",&idd);
                SDB_ReadEntry(idd);
            break;
            case 4:
                SDB_GetList (SDB_GetUsedSize,idarr);
            break;
            case 5:
                printf(" Enter Student id To Start Searching : ");
                scanf("%d",&idd);
                SDB_IsIdExist (idd);
            break;
            case 6:
                printf("Enter Student id To Delete : ");
                scanf("%d",&idd);
                SDB_DeletEntry (idd);


            break;
            case 7:
                SDB_IsFull ();
            break;
            case 0:
                printf("Good Bye ... <3 ");
                i=0;
            break;
            default:
            printf("Wrong Choice !\n");
            break;
        }

}




