#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include<string.h>
#include<ctype.h>
struct date
    {
        int dd;
        int mm;
        int yy;
    };
typedef struct
    {
        char name[60],birth_date[20],gender[10],address[60],email[50],plan_type[15],claim_type[30],health_hstry[150],contact_no[15];
        int subs_id,subs_age;
        int charge_icu,charge_room,charge_supplies,charge_surgical,charge_other;
        int claimable_amt,claimed_amt,insured_amt;
        char claimed_time[20],claim_status[10];
    }subscribers_details;

int get_subs_id();
void store_subscribers_data(subscribers_details sd, struct date dob,int age);

int subscribe_insurance()  // find subscriber age and show insurance plan and benefits as per age
{
    subscribers_details sd;
    int y,m,d;
    printf("\nEnter dob (yyyy mm dd: ");
    scanf("%d %d %d",&y,&m,&d);
    struct date dob ={d,m,y};

    struct tm *cdate;
    time_t currenttime;
    time(&currenttime);
    cdate = localtime(&currenttime);

    cdate->tm_year+= 1900;
    cdate->tm_mon += 1;

    if (cdate->tm_mday < dob.dd)
    {
        d = (cdate->tm_mday +30) - dob.dd;
        cdate->tm_mday+=30;
        cdate->tm_mon--;
        
    }
    if (cdate->tm_mon < dob.mm)
    {
        cdate->tm_mon+=12;
        cdate->tm_year--;
    }
    d = cdate->tm_mday - dob.dd;
    m = cdate->tm_mon - dob.mm;
    y = cdate->tm_year - dob.yy;

    if (y<= 20)
    {
        printf("\n\t\t\tPlan 120 (RM) \t Plan 150 (RM) \t Plan200(RM)");
        printf("\nAnnual Claim Limit \t 120,000 \t 150,000 \t 200,000");
        printf("\nLifetime Claim Limit \t 600,000 \t 750,000 \t 1,000,000 \n\n\n");

        printf("Types of Claim \t\t Eligibility Amount (RM)");
        printf("\n\t\t\t Plan 120 \t Plan 150 \t Plan 200");
        printf("\nRoom Charges \t\t 120/day \t 150/day \t 200/day");
        printf("\nICU Charges \t\t 250/day \t 400/day \t 700/day");
        printf("\nHospital Supplies\nand Services");
        printf("\nSurgical Fees\t\t\t As Charged");
        printf("\nOther Fees\n");

        store_subscribers_data(sd,dob,y);

    }

    else if (y <=40)
    {
        printf("\n\t\t\tPlan 150 (RM) \t Plan200(RM)");
        printf("\nAnnual Claim Limit \t 150,000 \t 200,000");
        printf("\nLifetime Claim Limit \t 750,000 \t 1,000,000 \n\n\n");

        printf("Types of Claim \t\t Eligibility Amount (RM)");
        printf("\n\t\t\t Plan 150 \t Plan 200");
        printf("\nRoom Charges \t\t 150/day \t 200/day");
        printf("\nICU Charges \t\t 400/day \t 700/day");
        printf("\nHospital Supplies\nand Services");
        printf("\nSurgical Fees\t\t\t As Charged");
        printf("\nOther Fees\n");
        store_subscribers_data(sd,dob,y);
    }
    else if (y <=54)
    {
        printf("\n\t\t\tPlan200(RM)");
        printf("\nAnnual Claim Limit \t 200,000");
        printf("\nLifetime Claim Limit  \t 1,000,000 \n\n\n");

        printf("Types of Claim \t\t Eligibility Amount (RM)");
        printf("\n\t\t\t Plan 200");
        printf("\nRoom Charges \t\t 200/day");
        printf("\nICU Charges \t\t 700/day");
        printf("\nHospital Supplies\nand Services");
        printf("\nSurgical Fees\t\t\t As Charged");
        printf("\nOther Fees\n");
        store_subscribers_data(sd,dob,y);
    }
    else
    {
        printf("\nHealth Insurance Plan is not available for your age !!\n");
    }
return 0;
}


void store_subscribers_data(subscribers_details sd, struct date dob,int age)    // ask details from user and save in a file
    {
        int recread;
        int choice,sid;
        FILE *fp;
        char buffer[10];
        fp = fopen("subscribers.txt", "r");
        if (!fp)
        {
            fp = fopen("subscribers.txt", "w");
        }
        else
        {
            fclose(fp);
            fp = fopen("subscribers.txt", "a");
        }
        sd.subs_id = get_subs_id();
        sprintf(sd.birth_date,"%d-%d-%d",dob.yy,dob.mm,dob.dd); // converting date integer to string
        sd.subs_age = age;

        printf("\n\n--Fill the requirements to subscribe insurance plan--\n");
        
        printf("\nEnter Name: ");
        fflush(stdin);
        gets(sd.name);
        printf("\nEnter Gender: ");
        fflush(stdin);
        gets(sd.gender);
        printf("\nEnter address: ");
        fflush(stdin);
        gets(sd.address);
        printf("\nEnter contact no.: ");
        fflush(stdin);
        gets(sd.contact_no);
        printf("\nEnter Email ID: ");
        fflush(stdin);
        gets(sd.email);
        
        printf("\nEnter the claim limit type: ");
        printf("\n1. Annual Claim Limit\n2. Lifetime Claim Limit\n");
        fflush(stdin);
        scanf("%d",&choice);
        if (choice == 1)
        {
            strcpy(sd.claim_type,"Annual Claim Limit"); 
            printf("\nEnter name of Plan: ");
            if (age <= 20)
            {
                printf("\n1. Plan 120 \n2. Plan 150\n3. Plan 200\n");
                fflush(stdin);
                scanf("%d",&choice);
                if (choice == 1)
                {
                    strcpy(sd.plan_type,"Plan 120");
                    sd.claimable_amt = 120000;
                    }
                else if (choice == 2)
                {
                    strcpy(sd.plan_type,"Plan 150");
                    sd.claimable_amt = 150000;
                    }
                else if (choice == 3)
                {
                    strcpy(sd.plan_type,"Plan 200");
                    sd.claimable_amt = 200000;
                    }
            }
            else if (age <= 40)
            {
                printf("\n1. Plan 150 \n2. Plan 200\n");
                fflush(stdin);
                scanf("%d",&choice);
                if (choice == 1)
                    {
                    strcpy(sd.plan_type,"Plan 150");
                    sd.claimable_amt = 150000;
                    }
                else if (choice == 2)
                    {
                    strcpy(sd.plan_type,"Plan 200");
                    sd.claimable_amt = 200000;
                    }
            }
            else if(age <=54)
            {
                printf("\n1. Plan 200\n");
                fflush(stdin);
                scanf("%d",&choice);
                if (choice == 1)
                    {
                    strcpy(sd.plan_type,"Plan 200");
                    sd.claimable_amt = 200000;
                    }
            }
        }
        else if (choice == 2)
        {
            strcpy(sd.claim_type,"Lifetime Claim Limit"); 
            printf("\nEnter name of Plan: ");
            if (age <= 20)
            {
                printf("\n1. Plan 120 \n2. Plan 150\n3. Plan 200\n");
                fflush(stdin);
                scanf("%d",&choice);
                if (choice == 1)
                {
                    strcpy(sd.plan_type,"Plan 120");
                    sd.claimable_amt = 600000;
                    }
                else if (choice == 2)
                {
                    strcpy(sd.plan_type,"Plan 150");
                    sd.claimable_amt = 750000;
                    }
                else if (choice == 3)
                {
                    strcpy(sd.plan_type,"Plan 200");
                    sd.claimable_amt = 1000000;
                    }
            }
            else if (age <= 40)
            {
                printf("\n1. Plan 150 \n2. Plan 200\n");
                fflush(stdin);
                scanf("%d",&choice);
                if (choice == 1)
                    {
                    strcpy(sd.plan_type,"Plan 150");
                    sd.claimable_amt = 750000;
                    }
                else if (choice == 2)
                    {
                    strcpy(sd.plan_type,"Plan 200");
                    sd.claimable_amt = 1000000;
                    }
            }
            else if(age <=54)
            {
                printf("\n1. Plan 200\n");
                fflush(stdin);
                scanf("%d",&choice);
                if (choice == 1)
                    {
                    strcpy(sd.plan_type,"Plan 200");
                    sd.claimable_amt = 1000000;
                    }
            }
        }

        printf("\nEnter any chronic illness if you have in the past history: ");
        fflush(stdin);
        gets(sd.health_hstry);
       
        sd.claimed_amt = 0;
        sd.insured_amt = sd.claimable_amt;

        struct tm *curtime;
        time_t currenttime;
        time(&currenttime);
        curtime = localtime(&currenttime);
        strftime(buffer,80,"%Y-%m-%d",curtime);
        strcpy(sd.claimed_time,buffer);
       
        fwrite(&sd,sizeof(subscribers_details),1,fp);
        fclose(fp);
        printf("\nYou have successfully subscribed the plan...\n");
    }


int get_subs_id()   // generate unique and incremented subsriber id
{
    int sid = 100;
    FILE * fp = fopen("sid.txt", "r") ;
    if (!fp) {
        fp = fopen("sid.txt", "w") ;
        fprintf(fp, "%d", sid) ;
        fclose(fp) ;
        return sid;
    }

    fscanf(fp, "%d", &sid) ;
    sid++;

    fclose(fp);
    fp = fopen("sid.txt", "w") ; 
    fprintf(fp, "%d", sid) ;
    fclose(fp) ;
    return sid ;
}

void display_subscribers_data() // display subscribers details
    {
        FILE *fp;
        subscribers_details sd;
        fp = fopen("subscribers.txt", "r");
        if (!fp)
        {
            printf("Cannot find file");
            return;
        }
        printf("\nID\tName\t\t    Gender\tSubscribed Date\t    Age\t\tContact no.\tEmail");
        printf("\t\t    Address\t    Claim Type\t\t\tPlan Type\tInsured Amount\tHealth History\n");
        while (fread(&sd,sizeof(subscribers_details),1,fp))
        {
            printf("\n%-8d%-20s%-12s%-20s%-12d%-16s%-20s%-16s%-28s%-16s%-16d%-4s",
            sd.subs_id,sd.name,sd.gender,sd.claimed_time,sd.subs_age,sd.contact_no,sd.email,
            sd.address,sd.claim_type,sd.plan_type,sd.insured_amt,sd.health_hstry);
        }
        fclose(fp);
    }

//---------------Submit Claim-------------------------------

void submit_claim(){    // ask user for required claim information and calculates claim transactions
    subscribers_details sd;
    FILE *fr,*ft;
    int id,d_icu,d_room,icu_cost,room_cost;
    float c_supplies,c_surgical,c_other;
    char insured_name[40];
    int found = 0;

    printf("\n------ Fill out the following details to apply for claim ------\n");
    printf("Enter no. of days spend in a normal ward: \n");
    scanf("%d",&d_room);
    printf("Enter no. of days hospitalized in ICU: \n");
    scanf("%d",&d_icu);
    printf("Enter cost of Hospital Supplies and Services: \n");
    scanf("%f",&c_supplies);
    printf("Enter Surgical Fees: \n");
    scanf("%f",&c_surgical);
    printf("Enter Other Fees: \n");
    scanf("%f",&c_other);

    // # checking eligibility
    printf("Enter subscriber's ID: ");
    fflush(stdin);
    scanf("%d",&id);

    fr = fopen("subscribers.txt", "r");
    if (!fr)
    {
        printf("Cannot find file");
        return;
    }
    ft = fopen("temp.txt","w");  
    while(fread(&sd,sizeof(subscribers_details),1,fr)==1)
    {
        if(sd.subs_id == id ) // checking if name is available
        {
            found  = 1;
            if(strcmp(sd.claim_type,"Annual Claim Limit")==0) //Checking if annual annual Claim Limit
            {
                if(strcmp(sd.plan_type,"Plan 120")==0)
                {
                    room_cost = d_room * 120;
                    icu_cost = d_icu * 250;
                }
                else if(strcmp(sd.plan_type,"Plan 150")==0)
                {
                    room_cost = d_room * 150;
                    icu_cost = d_icu * 400;
                }
                else if(strcmp(sd.plan_type,"Plan 200")==0)
                {
                    room_cost = d_room * 200;
                    icu_cost = d_icu * 700;
                }
            }

            else if(strcmp(sd.claim_type,"Lifetime Claim Limit")==0)
            {
                if(strcmp(sd.plan_type,"Plan 120")==0)
                {
                    
                    room_cost = d_room * 120;
                    icu_cost = d_icu * 250;
                }
                else if(strcmp(sd.plan_type,"Plan 150")==0)
                {
                    
                    room_cost = d_room * 150;
                    icu_cost = d_icu * 400;
                }
                else if(strcmp(sd.plan_type,"Plan 200")==0)
                {
                    room_cost = d_room * 200;
                    icu_cost = d_icu * 700;
                }
            }
            int total_exp = room_cost + icu_cost + c_other + c_supplies + c_surgical; //Calculating amount claimed by insurer
            int amt_Claimed = sd.claimed_amt;
            if (sd.claimable_amt <= total_exp){
                printf("Dear subscriber, your available balance amount has exceeded your Plan Subscription...\nNow, you need to pay %d from your account", abs(total_exp - sd.claimable_amt)); 
                if(strcmp(sd.claim_type,"Annual Claim Limit")==0) //Checking if annual annual Claim Limit
                    {
                        if(strcmp(sd.plan_type,"Plan 120")==0)
                            sd.claimed_amt = 120000;
                        else if(strcmp(sd.plan_type,"Plan 150")==0)
                            sd.claimed_amt = 150000;
                        else if(strcmp(sd.plan_type,"Plan 200")==0)
                            sd.claimed_amt = 200000;
                    }

                else if(strcmp(sd.claim_type,"Lifetime Claim Limit")==0)
                {
                    if(strcmp(sd.plan_type,"Plan 120")==0)
                        sd.claimed_amt = 600000;
                    else if(strcmp(sd.plan_type,"Plan 150")==0)
                        sd.claimed_amt = 750000;
                    else if(strcmp(sd.plan_type,"Plan 200")==0)
                        sd.claimed_amt = 1000000; 
                }
                sd.claimable_amt = 0;
            }
            else{
                sd.claimed_amt  = amt_Claimed +((sd.claimable_amt + total_exp) - sd.claimable_amt);
                sd.claimable_amt = sd.claimable_amt - total_exp;
                strcpy(sd.claim_status,"active");
                                               
            }
        }
        
        fwrite(&sd,sizeof(subscribers_details),1,ft);
    }
    fclose(ft);
    fclose(fr);
    
    if (found){
        ft = fopen("temp.txt","r");
        fr = fopen("subscribers.txt", "w");
        while(fread(&sd,sizeof(subscribers_details),1,ft)==1)
        {
            fwrite(&sd,sizeof(subscribers_details),1,fr);
        }
        printf("\nYour claim amount has been paid successfully...\n");
        fclose(fr);
        fclose(ft);
        }
    else
    {
        printf("\nSubsriber ID is not available !!!\n");     
    }
}
        

void display_claim()    // display claim of only users who has began the claiming
{
    FILE *fp;
    subscribers_details sd;
    fp = fopen("subscribers.txt", "r");
    if (!fp)
    {
        printf("Cannot find file");
        return;
    }
    printf("\n\t\t\t\t\t *****  Subscribers Details *****\n");
    printf("\nSubscriber ID\tName\t\tClaim Limit Type\tClaim Type\tInsured Amount\tClaimable Amount\tClaimed Amount\n");
    while(fread(&sd,sizeof(subscribers_details),1,fp)==1)
    {
        if (strcmp(sd.claim_status,"active")==0)
            printf("\n%-16d%-16s%-16s\t%-2s\t%-20d\t%-20d\t%-9d",sd.subs_id,sd.name,sd.claim_type,sd.plan_type,sd.insured_amt,
            sd.claimable_amt,sd.claimed_amt);
    }
    fclose(fp);

}


//------------ Account Information------------
void claimByLifetimeSubscribers()   // display claim details of Lifetime Claim Limit Subscribers
{
    FILE *fp;
    subscribers_details sd;
    int total_claimed_amt = 0;
    fp = fopen("subscribers.txt", "r");
    if (!fp)
    {
        printf("Cannot find file");
        return;
    }
    printf("\nSubscriber ID\tName\t\tClaim Limit Type\tClaim Type\tInsured Amount\tClaimable Amount\tClaimed Amount\n");
    while(fread(&sd,sizeof(subscribers_details),1,fp)==1)
    {
        if (strcmp(sd.claim_type,"Lifetime Claim Limit") == 0)
        {
            printf("\n%-16d%-16s%-16s\t%-2s\t%-20d\t%-20d\t%-9d",sd.subs_id,sd.name,sd.claim_type,sd.plan_type,sd.insured_amt,
            sd.claimable_amt,sd.claimed_amt);
            total_claimed_amt += sd.claimed_amt;
        }
    }
    printf("\n\nTotal amount claimed by Lifetime Claim limit Subscribers = %d\n",total_claimed_amt);
    fclose(fp);

}
void exhaustedAnnualSubscribers()   // display claim details of those who has his all amount claimed
{
    FILE *fp;
    subscribers_details sd;
    int no_subs = 0;
    fp = fopen("subscribers.txt", "r");
    if (!fp)
    {
        printf("Cannot find file");
        return;
    }
    printf("\n\t\t\t\t\t *****  Subscribers Details *****\n");
    printf("\nSubscriber ID\tName\t\tClaim Limit Type\tClaim Type\tInsured Amount\tClaimable Amount\tClaimed Amount\n");
    while(fread(&sd,sizeof(subscribers_details),1,fp)==1)
    {
        if (strcmp(sd.claim_type,"Annual Claim Limit") == 0)
        {  
            if (sd.claimed_amt == 120000 || sd.claimed_amt == 150000 || sd.claimed_amt == 200000 || sd.claimed_amt == 600000 || sd.claimed_amt == 750000 || sd.claimed_amt == 1000000)
            {
                printf("\n%-16d%-16s%-16s\t%-2s\t%-20d\t%-20d\t%-9d",sd.subs_id,sd.name,sd.claim_type,sd.plan_type,sd.insured_amt,
                sd.claimable_amt,sd.claimed_amt);
                no_subs += 1;
            }
        }
    }
    printf("\n\nTotal number of Annual Limit Subscribers who have exhausted all their elegible amount = %d\n",no_subs);
    fclose(fp);

}

void view_all_subscribers_details()   // function to search subscriber record by subscriber name
    {
        FILE *fp;
        subscribers_details sd;
        fp = fopen("subscribers.txt", "r");
        if (!fp)
        {
            printf("Cannot find file");
            return;
        }
        printf("\t\t\t\t\t\t\t\t\t\t ************************ Subscriber Detail ***************************\n");
        printf("\nID\tName\t\t    Gender\tSubscribed Date\t    Age\t\tContact no.\tEmail\t\t    Address\t    Claim Type");
        printf("\t\t\tPlan Type\tHealth History\tInsured Amount\tClaimable Amount\tClaimed Amount\n");
        while (fread(&sd,sizeof(subscribers_details),1,fp))
        {
            printf("\n%-8d%-20s%-12s%-20s%-12d%-16s%-20s%-16s%-28s%-16s%-12s\t%-18d\t%-18d\t%d",
            sd.subs_id,sd.name,sd.gender,sd.claimed_time,sd.subs_age,sd.contact_no,sd.email,sd.address,
            sd.claim_type,sd.plan_type,sd.health_hstry,sd.insured_amt,sd.claimable_amt,sd.claimed_amt);
        }
        fclose(fp);
    }

// ------------- search record--------------


void search_by_id() // function to search subscriber record by id
    {
        FILE *fp;
        subscribers_details sd;
        int sub_id;
        int found = 0;
        printf("\nEnter subscriber ID: ");
        scanf("%d",&sub_id);

        fp = fopen("subscribers.txt", "r");
        if (!fp)
        {
            printf("Cannot find file");
            return;
        }
        printf("\nID\tName\t\t    Gender\tSubscribed Date\t    Age\t\tContact no.\tEmail\t\t    Address\t    Claim Type");
        printf("\t\t\tPlan Type\tHealth History\tInsured Amount\tClaimable Amount\tClaimed Amount\n");
        while (fread(&sd,sizeof(subscribers_details),1,fp))
        {
            if(sd.subs_id == sub_id)
            {
                found = 1;
                printf("\n%-8d%-20s%-12s%-20s%-12d%-16s%-20s%-16s%-28s%-16s%-12s\t%-18d\t%-18d\t%d",
                sd.subs_id,sd.name,sd.gender,sd.claimed_time,sd.subs_age,sd.contact_no,sd.email,sd.address,
                sd.claim_type,sd.plan_type,sd.health_hstry,sd.insured_amt,sd.claimable_amt,sd.claimed_amt);
            }
        }
        fclose(fp);
        if (!found)
            printf("\n\nSubscriber ID %d is not found !\n\n",sub_id);
    }

void search_by_name()   // function to search subscriber record by subscriber name
    {
        FILE *fp;
        subscribers_details sd;
        char sub_name[30];
        int found = 0;
        printf("\nEnter subscriber name: ");
        fflush(stdin);
        gets(sub_name);

        fp = fopen("subscribers.txt", "r");
        if (!fp)
        {
            printf("Cannot find file");
            return;
        }
        printf("\nID\tName\t\t    Gender\tSubscribed Date\t    Age\t\tContact no.\tEmail\t\t    Address\t    Claim Type\t\t\tPlan Type\tHealth History\tInsured Amount\tClaimable Amount\tClaimed Amount\n");
        while (fread(&sd,sizeof(subscribers_details),1,fp))
        {
            if (strcmp(sd.name,sub_name)==0)
            {
                found = 1;
                printf("\n%-8d%-20s%-12s%-20s%-12d%-16s%-20s%-16s%-28s%-16s%-12s\t%-18d\t%-18d\t%d",
                sd.subs_id,sd.name,sd.gender,sd.claimed_time,sd.subs_age,sd.contact_no,sd.email,sd.address,
                sd.claim_type,sd.plan_type,sd.health_hstry,sd.insured_amt,sd.claimable_amt,sd.claimed_amt);
            }
        }
        fclose(fp);
        if (!found)
            printf("\n %s's record not found !\n\n",sub_name);
    }

void search_by_plan()   // function to get subscriber record by subscriber's plan
    {
        FILE *fp;
        subscribers_details sd;
        int p_choice;
        char p_name[15];
        fp = fopen("subscribers.txt", "r");
        if (!fp)
        {
            printf("Cannot find file");
            return;
        }
        printf("\n---Available Plan---");
        printf("\n1. Plan 120 \n2. Plan 150\n3. Plan 200\n");
        printf("Choose plan (1-3): ");
        scanf("%d",&p_choice);

        if (p_choice == 1)
            strcpy(p_name,"Plan 120");
        else if (p_choice == 2)
            strcpy(p_name,"Plan 150");          
        else if (p_choice == 3)
            strcpy(p_name,"Plan 200");
        else
        {
            printf("\n\nInvalid input\n\n");
            search_by_plan();
        }


        printf("\nID\tName\t\t    Gender\tSubscribed Date\t    Age\t\tContact no.\tEmail\t\t    Address\t    Claim Type\t\t\tPlan Type\tHealth History\tInsured Amount\tClaimable Amount\tClaimed Amount\n");
        while (fread(&sd,sizeof(subscribers_details),1,fp))
        {
            if(strcmp(sd.plan_type,p_name)==0)
                printf("\n%-8d%-20s%-12s%-20s%-12d%-16s%-20s%-16s%-28s%-16s%-12s\t%-18d\t%-18d\t%d",
                sd.subs_id,sd.name,sd.gender,sd.claimed_time,sd.subs_age,sd.contact_no,sd.email,sd.address,
                sd.claim_type,sd.plan_type,sd.health_hstry,sd.insured_amt,sd.claimable_amt,sd.claimed_amt);
        }
        fclose(fp);
    }

void search_by_claim()  // function to get subscriber record by subscriber's claim type i.e. annual and lifetime
    {
        FILE *fp;
        subscribers_details sd;
        int choice;
        char claim_name[30];
        fp = fopen("subscribers.txt", "r");
        if (!fp)
        {
            printf("Cannot find file");
            return;
        }
        printf("\n---Available Claim---");
        printf("\n1. Annual Claim Limit \n2. Lifetime Claim Limit\n");
        printf("Choose claim (1-2): ");
        scanf("%d",&choice);

        if (choice == 1)
            strcpy(claim_name,"Annual Claim Limit");
        else if (choice == 2)
            strcpy(claim_name,"Lifetime Claim Limit");          
        else
        {
            printf("\n\nInvalid choice\n");
            search_by_claim();
        }

        printf("\nID\tName\t\t    Gender\tSubscribed Date\t    Age\t\tContact no.\tEmail\t\t    Address\t    Claim Type\t\t\tPlan Type\tHealth History\tInsured Amount\tClaimable Amount\tClaimed Amount\n");
        while (fread(&sd,sizeof(subscribers_details),1,fp))
        {
            if(strcmp(sd.claim_type,claim_name)==0)
                printf("\n%-8d%-20s%-12s%-20s%-12d%-16s%-20s%-16s%-28s%-16s%-12s\t%-18d\t%-18d\t%d",
                sd.subs_id,sd.name,sd.gender,sd.claimed_time,sd.subs_age,sd.contact_no,sd.email,sd.address,
                sd.claim_type,sd.plan_type,sd.health_hstry,sd.insured_amt,sd.claimable_amt,sd.claimed_amt);
        }
    fclose(fp);

    }

void search_by_age()    // function to get subscriber record through subscriber's age
    {
        FILE *fp;
        subscribers_details sd;
        int sub_age;
        int found = 0;
        printf("\nEnter subscriber age: ");
        scanf("%d",&sub_age);

        fp = fopen("subscribers.txt", "r");
        if (!fp)
        {
            printf("Cannot find file");
            return;
        }
        printf("\nID\tName\t\t    Gender\tSubscribed Date\t    Age\t\tContact no.\tEmail\t\t    Address\t    Claim Type\t\t\tPlan Type\tHealth History\tInsured Amount\tClaimable Amount\tClaimed Amount\n");
        while (fread(&sd,sizeof(subscribers_details),1,fp))
        {
            if(sd.subs_age == sub_age)
            {
                found = 1;
                printf("\n%-8d%-20s%-12s%-20s%-12d%-16s%-20s%-16s%-28s%-16s%-12s\t%-18d\t%-18d\t%d",
                sd.subs_id,sd.name,sd.gender,sd.claimed_time,sd.subs_age,sd.contact_no,sd.email,sd.address,
                sd.claim_type,sd.plan_type,sd.health_hstry,sd.insured_amt,sd.claimable_amt,sd.claimed_amt);
            }
        }
        fclose(fp);



























































































        
        if (!found)
            printf("\nSubscriber of age %d is not found !\n",sub_age);
    }
