#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include<string.h>
#include<ctype.h>
#include "insurance_f.h"
void insurance_plan_subscription();
void claim_processing();
void account_information();
void search_record();
void main()
{

    char choice;
    printf("\n\n::::::: ZeeMediLife Health Insurance Managment System :::::::\n");
    do {
        printf("\n\n****** Main Menu ******:\n\n");
        printf("1. Insurance Plan Subsription\n2. Claim Processing\n3. Accounts Information\n4. Searching Subsribers\n5. Exit");
        fflush(stdin);
        printf("\n\nSelect your choice (1-4): ");
        choice = tolower(getchar());
        switch (choice)
        {
            case '1':
                insurance_plan_subscription();
                break;
                
            case '2':
                claim_processing();
                break;

            case '3':
                account_information();
                break;

            case '4':
                search_record();
                break;
            default:
                printf("\nInvalid choice\n");
        }     
    }while (choice != '5');               
}

void insurance_plan_subscription()
{
    int choice;
    do{
        printf("\n\n---- Insurance Subscription Menu ----");
        printf("\n1. Subscribe Insurance Plan \n2. Display Subscriber Plan Details\n3. Back to Main Menu\n");
        fflush(stdin);
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                subscribe_insurance();
                break;
            case 2:
                display_subscribers_data();
                break;
            default:
                printf("\nInvalid Input !!\n");
            }
    }while (choice != 3);
    return;
}

void claim_processing()
{
    int choice;
    do
    {
        printf("\n\n----- Insurance Claim Menu -----");
        printf("\n1. Submit Claim  \n2. Display Claim Details  \n3. Back to Main Menu\n");
        fflush(stdin);
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            submit_claim();
            break;
        
        case 2:
            display_claim();
            break;
        default:
            printf("\nInvalid Input !!\n");
        }
    }while (choice != 3);
    return;
}


void account_information()  
{
    int choice;
    do{
        printf("\n\n---- Account Information Menu ----");
        printf("\n1. Claim by Lifetime Subscribers \n2. Annual Claim Limit Subscribers who have exhausted all their eligible amount  \n3. View all Subscribers Details \n4. Back to Main Menu\n");
        fflush(stdin);
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            claimByLifetimeSubscribers();
            break;
            
        case 2:
            exhaustedAnnualSubscribers();
            break;
        case 3:
            view_all_subscribers_details();
            break;
        default:
            printf("\nInvalid Input !!\n");
        }
    }while (choice != 4);
    return;
}

void search_record()
    {
        char choice;
        do{
            printf("\n\n\n---- Search Subscriber's Record ----\n");
            printf("\n1. Search by Subscriber ID\n");
            printf("2. Search by Name\n");
            printf("3. Search by Plan Name\n");
            printf("4. Search By Claim Limit Type\n");
            printf("5. Search by Age\n");
            printf("6. Back to Main Menu\n");

            fflush(stdin);
            choice = getchar();
            
            switch(choice)
            {
                case '1':
                    search_by_id();
                    break;
                case '2':
                    search_by_name();
                    break;
                case '3':
                    search_by_plan();
                    break;
                case '4':
                    search_by_claim();
                    break;
                case '5':
                    search_by_age();
                    break;
                
                default:
                    printf("\nInvalid input !!!\n");
            }
        }while(choice != '6');
    }
