 sd.claimed_amt = 0;
            sd.remaining_amt = 0;
            available_balance = deductible_amt - room_cost - icu_cost - c_supplies - c_surgical - c_other; // calculating amount remained to claim
            claimedAmt = room_cost + icu_cost + c_other + c_supplies + c_surgical; //Calculating amount claimed by insurer
            sd.claimable_amt = deductible_amt;

            printf("Claimable amount = %d\n",sd.claimable_amt);
            sd.claimed_amt = sd.claimed_amt + claimedAmt;

            printf("Claimed amount = %d",sd.claimed_amt);
            sd.remaining_amt = sd.claimable_amt - sd.claimed_amt;
            
            printf("\nREmaining amount = %d",sd.remaining_amt);

            if (sd.claimable_amt <= sd.claimed_amt){
                printf("Dear subscriber, your available balance amount has exceeded your Plan Subscription...\nNow, you need to pay %d from your account", abs(sd.remaining_amt)); 
                break;
            }
            else{
                struct tm *curtime;
                time_t currenttime;
                time(&currenttime);
                curtime = localtime(&currenttime);
                strftime(buffer,80,"%Y-%m-%d",curtime);
                strcpy(sd.claimed_time,buffer);
                printf("Date = %s",sd.claimed_time);
                
            }
        }
        ft = fopen("temp.txt","w");
        fwrite(&sd,sizeof(subscribers_details),1,ft);
    }
    fclose(ft);
    fclose(fr);
    
    if (found){
        ft = fopen("temp.txt","r");
        fw = fopen("subscribers.txt", "w");
        while(fread(&sd,sizeof(subscribers_details),1,ft)==1)
        {
            fwrite(&sd,sizeof(subscribers_details),1,fw);
            printf("\nYour claim amount has been paid successfully...\n");
        }
        fclose(fw);
        fclose(ft);
        }
    else
    {
        printf("\nRecord not found !!!\n");     
    }
}
        


void display_claim()
{
    FILE *fp;
    subscribers_details sd;
    fp = fopen("subscribers.txt", "r");
    if (!fp)
    {
        printf("Cannot find file");
        return;
    }
    printf("\nSubscriber ID\tName\t\tClaim Limit Type\tClaim Type\tClaimable Amount\tClaimed Amount\tAvailable Claim Amount\n");
    while(fread(&sd,sizeof(subscribers_details),1,fp)==1)
    {
        printf("\n%-16d%-16s%-16s\t%-2s\t%-20d\t%-9d\t%d",sd.subs_id,sd.name,sd.claim_type,sd.plan_type,sd.claimable_amt,sd.claimed_amt,sd.remaining_amt);
    }
    fclose(fp);

}