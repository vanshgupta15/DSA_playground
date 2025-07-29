#include<stdio.h>
#include<string.h>
//student structure
struct Student
{
    int rollNo;
    char name[50];
    float cgpa;
};

void main()
{
    struct Student student[3];
    for(int i=0;i<3;i++)
    {
        printf("Enter the roll number");
        scanf("%d",&student[i].rollNo);
        printf("Enter the name");
        scanf("%s",&student[i].name);
        printf("Enter the cgpa");
        scanf("%0.2f",&student[i].cgpa);
    }
    int choice;
    printf("Student data CRUD :-\n1. Insertion\n2. Deletion\n3. Search a student\n4. Exit");
    scanf("%d",&choice);
    while(1)
    {
        switch (choice)
        {
            case 1:
            {
                //insertion
                int size= sizeof(student)/sizeof(student[0]);
                int index;
                printf("Enter index at which you want to insert the student");
                scanf("%d",&index);
                if((index+1)==size)
                {
                    printf("Insertion is not allowed");
                    exit(0);
                }
                else if()
                {

                }
            }
            case 4:
            {
                printf("Thankyou!! bye bye");
                return 0;
            }
            default: printf("Please enter a valid choice");
            break;
        }
        
}