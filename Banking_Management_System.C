#include <stdio.h>  
#include <stdlib.h> 
#include <time.h>  

char name[20];
int dip_amt, amt = 10000, acc_no, ac, count = 0; 
int trans_amt;
int with_amt;

void deposit_money();
void withdraw_money();
void transfer_money();
void checkDetail();
void LastDetail();
void transaction_details();
void menu();

void divider()
{
    for (int i = 0; i < 50; i++)
    {
        printf("-");
    }
}

int main()
{
    FILE *ptr = fopen("Account.txt", "w");
    if (ptr == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    int ch;
    printf("Enter your name : \n");
    scanf("%s",name);
    fprintf(ptr, "\nName : %s\n", name);
    printf("Enter your account no. : ");
    scanf("%d", &acc_no);
    fprintf(ptr, "Account no. : %d\n", acc_no);

    fclose(ptr);
    menu();

    while (1)
    {
        printf("Enter your choice :\n");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                deposit_money();
                break;
            case 2:
                withdraw_money();
                break;
            case 3:
                transfer_money();
                break;
            case 4:
                checkDetail();
                break;
            case 5:
                transaction_details();
                break;
            case 6:
                LastDetail();
                return 0;
            default:
                printf("*****Invalid choice*****\n");
        }
    }

    return 0;
}

void menu()
{
    divider();
    printf("\tMENU\n");
    divider();
    printf("\n1.Deposit Money\n");
    printf("2.Withdraw Money\n");
    printf("3.Transfer Money\n");
    printf("4.Account details\n");
    printf("5.Transaction details\n");
    printf("6.Exit\n");
    divider();
}

void deposit_money()
{
    time_t tm;
    time(&tm);
    FILE *ptr = fopen("Account.txt", "a");
    if (ptr == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    printf("*****DEPOSITING MONEY*****\n");
    divider();
    printf("\nEnter the amount you want to deposit\n");
    scanf("%d", &dip_amt);
    amt += dip_amt;
    printf("****Money Deposited****\n");
    printf("Now balance : %d\n", amt);
    fprintf(ptr, "\nRs%d had been deposited to your account \n", dip_amt);
    fprintf(ptr, "Date/Time of transaction :  %s\n", ctime(&tm));
    count++;

    fclose(ptr);
    printf("Press any key....\n");
}

void withdraw_money()
{
    time_t tm;
    time(&tm);
    FILE *ptr = fopen("Account.txt", "a");
    if (ptr == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    printf("*****WITHDRAWING MONEY*****\n");
    divider();
    printf("\nEnter the amount you want to withdraw\n");
    scanf("%d", &with_amt);

    if (amt < with_amt)
    {
        printf("****Insufficient balance****\n");
    }
    else
    {
        amt = amt - with_amt;
        printf("*****Money withdrawn*****\n");
        printf("Current balance : %d\n", amt);
        fprintf(ptr, "\nRs%d had been withdrawn from your account \n", with_amt);
        fprintf(ptr, "Date/Time of transaction :  %s\n", ctime(&tm));
        count++;
    }

    fclose(ptr);
    printf("Press any key....\n");
}

void transfer_money()
{
    time_t tm;
    time(&tm);
    FILE *ptr = fopen("Account.txt", "a");
    if (ptr == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    printf("*****TRANSFERRING MONEY*****\n");
    divider();
    printf("\nEnter the account no. in which you want to transfer the money : ");
    scanf("%d", &ac);
    printf("\nEnter the amount you want to transfer\n");
    scanf("%d", &trans_amt);

    if (amt < trans_amt)
    {
        printf("****You have not sufficient balance****\n");
    }
    else
    {
        amt = amt - trans_amt;
        printf("****Money Transferred****\n");
        printf("Current balance : %d\n", amt);
        fprintf(ptr, "\nRs%d had been transferred from your account to %d\n", trans_amt, ac);
        fprintf(ptr, "Date/Time of transaction :  %s\n", ctime(&tm));
        count++;
    }

    fclose(ptr);
    printf("Press any key....\n");
}

void checkDetail()
{
    printf("ACCOUNT DETAILS\n");
    divider();
    printf("Name : %s\n", name);
    printf("Account No. : %d\n", acc_no);
    printf("Total balance = %d\n ", amt);
    printf("%d transactions have been made from your account \n", count);
    printf("Press any key.....\n");
}

void transaction_details()
{
    FILE *ptr = fopen("Account.txt", "r");
    if (ptr == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    char c = fgetc(ptr);
    if (c == EOF)
    {
        printf("TRANSACTION DETAILS\n");
        divider();
        printf("*******NO RECENT TRANSACTION*******\n");
    }
    else
    {
        printf("TRANSACTION DETAILS\n");
        divider();
        printf("%d transactions have been made from your account \n", count);
        while (c != EOF)
        {
            printf("%c", c);
            c = fgetc(ptr);
        }
    }

    fclose(ptr);
}

void LastDetail()
{
    printf("ACCOUNT DETAILS\n");
    divider();
    printf("Name : %s\n", name);
    printf("Account No. : %d\n", acc_no);
    printf("Total balance = %d\n ", amt);
    printf("Press any key to exit.....\n");
}
