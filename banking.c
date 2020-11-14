#include<stdio.h>
#include "banking.h"
#include<stdlib.h>
#include<windows.h>
#include<stdbool.h>
int i,j;
int main_exit;
void menu();
int atm();
void close();
struct date{
    int month,day,year;
};
struct {

    char name[100];
    int acc_no,age;
    char address[100];
    char citizenship[100];
    double phone;
    char acc_type[100];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;

    }add,upd,check,rem,transaction;

float interest(float t,float amount,int rate)
{
    float SI;
    SI=(rate*t*amount)/100.0;
    return (SI);
}
void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}
void new_account()
{
    int choice;
    FILE *ptr;

    ptr=fopen("file1.txt","a+");
    account_no:
    system("cls");
    printf("\t\t\t**** ADD RECORD  ****");
    printf("\n\n\nEnter today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
    printf("\nEnter the account number:");
    scanf("%d",&check.acc_no);
    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (check.acc_no==add.acc_no)
            {printf("Account no. already in use!");
            fordelay(1000000000);
                goto account_no;

            }
    }
    add.acc_no=check.acc_no;
        printf("\nEnter your Name:");
    scanf("%s",add.name);
    printf("\nEnter your date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
    printf("\nEnter your age:");
    scanf("%d",&add.age);
    printf("\nEnter address:");
    scanf("%s",add.address);
    printf("\nEnter citizenship number:");
    scanf("%s",add.citizenship);
    printf("\nEnter phone number: ");
    scanf("%lf",&add.phone);
    printf("\nEnter the amount to deposit: Rs ");
    scanf("%f",&add.amt);
    printf("\nType of account:\n\t.saving\n\t.current\n\t.FD5(5 year term)\n\t.FD10(10 year's term)\n\t.FD15(15 year's term)\n\n\tEnter your choice:");
    scanf("%s",add.acc_type);

        fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);


    fclose(ptr);
    printf("\nAccount created successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}
void view_info()
{
    FILE *view;
    view=fopen("file1.txt","r");
    int test=0;
    system("cls");
    printf("\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");

    while(fscanf(view,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
       {
           printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf",add.acc_no,add.name,add.address,add.phone);
           test++;
       }

    fclose(view);
    if (test==0)
        {   system("cls");
            printf("\nNO RECORD FOUND!!\n");}

    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}
void edit(void)
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("file1.txt","r");
    newrec=fopen("file2.txt","w");

    printf("\nEnter the account no. of the customer whose information needs to be changed: ");
    scanf("%d",&upd.acc_no);
    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (add.acc_no==upd.acc_no)
        {   test=1;
            printf("\nWhich information do you want to change?\n1.Address\n2.Phone\n\nEnter your choice:");
            scanf("%d",&choice);
            system("cls");
            if(choice==1)
                {printf("Enter the new address:");
                scanf("%s",upd.address);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,upd.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                system("cls");
                printf("Changes saved!");
                }
            else if(choice==2)
                {
                    printf("Enter the new phone number:");
                scanf("%lf",&upd.phone);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,upd.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                system("cls");
                printf("Changes saved!");
                }

        }
        else
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
    }
    fclose(old);
    fclose(newrec);
    remove("file1.txt");
    rename("file2.txt","file1.txt");

if(test!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            edit_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)

                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    edit();
                else
                    {printf("\nInvalid!\a");
                    goto edit_invalid;}
        }
    else
        {printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
        }
}

void transact(void)
{   int choice,test=0;
    FILE *old,*newrec;
    old=fopen("file1.txt","r");
    newrec=fopen("file2.txt","w");

        printf("Enter the account no. of the customer:");
    scanf("%d",&transaction.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {

            if(add.acc_no==transaction.acc_no)
            {   test=1;
                if(strcmpi(add.acc_type,"FD5")==0||strcmpi(add.acc_type,"FD10")==0||strcmpi(add.acc_type,"FD15")==0)
                {
                    printf("\a\a\a\n\nTransaction Not Possible in fixed deposit account!!!!!");
                    fordelay(1000000000);
                    system("cls");
                    menu();

                }
                printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice:");
                scanf("%d",&choice);
                if (choice==1)
                {
                    printf("Enter the amount you want to deposit: Rs. ");
                    scanf("%f",&transaction.amt);
                    add.amt+=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nTransaction Successfull!");
                }
                else
                {
                    printf("Enter the amount you want to withdraw: Rs. ");
                    scanf("%f",&transaction.amt);
                    add.amt-=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nTransaction successfull!");
                }

            }
            else
            {
               fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
            }
   }
   fclose(old);
   fclose(newrec);
   remove("file1.txt");
   rename("file2.txt","file1.txt");
   if(test!=1)
   {
       printf("\n\nRecord not found!!");
       transact_invalid:
      printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
      scanf("%d",&main_exit);
      system("cls");
      if (main_exit==0)
        transact();
    else if (main_exit==1)
        menu();
    else if (main_exit==2)
        close();
    else
    {
        printf("\nInvalid!");
        goto transact_invalid;
    }

   }
   else
   {
       printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
   }

}
void erase(void)
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("file1.txt","r");
    newrec=fopen("file2.txt","w");
    printf("Enter the account no. of the customer you want to delete:");
    scanf("%d",&rem.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {
        if(add.acc_no!=rem.acc_no)
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);

        else
            {test++;
            printf("\nRecord deleted!!\n");
            }
   }
   fclose(old);
   fclose(newrec);
   remove("file1.txt");
   rename("file2.txt","file1.txt");
   if(test==0)
        {
            printf("\nRecord not found!!\a\a\a");
            erase_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);

                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    erase();
                else
                    {printf("\nInvalid!\a");
                    goto erase_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
        }

}

void see(void)
{
    FILE *ptr;
    int test=0,rate;
    int choice;
    float time;
    float intrst;
    ptr=fopen("file1.txt","r");
    printf("Do you want to check by\n1.Account no\n2.Name\nEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("Enter the account number:");
        scanf("%d",&check.acc_no);

        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(add.acc_no==check.acc_no)
            {   system("cls");
                test=1;

                printf("\nAccount No.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited: Rs. %.2f \nDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,
                add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcmpi(add.acc_type,"FD5")==0)
                    {
                        time=5.0;
                        rate=10;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get Rs %.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+5);
                    }
                else if(strcmpi(add.acc_type,"FD10")==0)
                    {
                        time=10.0;
                        rate=12;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get Rs .%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+10);

                    }
                else if(strcmpi(add.acc_type,"FD15")==0)
                    {
                        time=15.0;
                        rate=14;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get Rs .%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+15);

                    }
                 else if(strcmpi(add.acc_type,"saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get Rs .%.2f as interest on %d of every month",intrst,add.deposit.day);

                     }
                 else if(strcmpi(add.acc_type,"current")==0)
                    {

                        printf("\n\nNo Intrest\a\a");

                     }

            }
        }
    }
    else if (choice==2)
    {   printf("Enter the name:");
        scanf("%s",&check.name);
        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(strcmpi(add.name,check.name)==0)
            {   system("cls");
                test=1;
                printf("\nAccount No.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$%.2f \nDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,
                add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcmpi(add.acc_type,"FD5")==0)
                    {
                        time=5.0;
                        rate=10;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get Rs .%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+5);
                    }
                else if(strcmpi(add.acc_type,"FD10")==0)
                    {
                        time=10.0;
                        rate=12;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get Rs .%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+10);

                    }
                else if(strcmpi(add.acc_type,"FD15")==0)
                    {
                        time=15.0;
                        rate=14;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get Rs .%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+15);

                    }
                 else if(strcmpi(add.acc_type,"saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get Rs .%.2f as interest on %d of every month",intrst,add.deposit.day);

                     }
                 else if(strcmpi(add.acc_type,"current")==0)
                    {

                        printf("\n\nNo Interest\a\a");

                     }

            }
        }
    }


    fclose(ptr);
     if(test!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            see_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    see();
                else
                    {
                        system("cls");
                        printf("\nInvalid!\a");
                        goto see_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);}
        if (main_exit==1)
        {
            system("cls");
            menu();
        }

        else
           {

             system("cls");
            close();
            }

}

void close(void)
{
    printf("\n\n\n\nThank You");
}

void menu(void)
{   int choice;
    system("cls");
    system("color 6");
    printf("\n\n\t\t\t        ABC BANK MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t\xB3\xB3\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE ABC BANK \xB2\xB2\xB2\xB2\xB2\xB3\xB3");
    printf("\n\n\t\t<1> Create a new account\n\t\t<2> Update information of existing account\n\t\t<3> Transactions\n\t\t<4> Check the details of existing account\n\t\t<5> Delete existing account\n\t\t<6> View customer details\n\t\t<7> ATM \n\t\t<8> Exit\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);

    system("cls");
    switch(choice)
    {
        case 1:new_account();
        break;
        case 2:edit();
        break;
        case 3:transact();
        break;
        case 4:see();
        break;
        case 5:erase();
        break;
        case 6:view_info();
        break;
        case 7:atm();
        break;
        case 8:close();
        break;
    }
}
int main()
{
    char pass[10],password[10]= "user";
    int i=0;
    system("color 6");
    printf("\n\n\n\t\t\t\t           ABC Bank \n\t\t\t\t\t Login Portal ");
    printf("\n\n\n\n\n\t\t\t\tEnter the password to login: ");
    scanf("%s",pass);
    if (strcmp(pass,password)==0)
        {printf("\n\nLogged In Successfully!\nLoading");
        for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf("* ");
        }
        printf("\n");
                system("pause");
				system("cls");
                
            menu();
        }
    else
        {   printf("\n\nIncorrect password!!\a\a\a");
            login_try:
            printf("\nEnter 1 to try again and 0 to exit:");
            scanf("%d",&main_exit);
            if (main_exit==1)
                    {

                        system("cls");
                        main();
                    }

            else if (main_exit==0)
                    {
                    system("cls");
                    close();}
            else
                    {printf("\nInvalid!");
                    fordelay(1000000000);
                    system("cls");
                    goto login_try;}

        }
        return 0;
}
//ATM Code:
int atm(){
void mainMenu();
void Balcheck(float balance);
float Deposit(float balance);
float Withdraw(float balance);
void menuExit();
void errorMessage();

int login(void)
{
  float number = 1234;
  int pass;
  printf("\n\n\t\t\tEnter the PIN No:");
  scanf("%d", &pass);

  if (pass == number)
    {
      printf("\n\nPIN Matched!\nLOADING");
        for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(".");
        }
        system("cls");
      mainMenu();
    }
  else
    {
      printf("Invalid\n Try Again");
      login();
    }
  return 0;
}
//Main Code
    int option;
    float balance = 10000.00;
    int choose;
    bool again = true;
    
    login();
    while (true)
	{
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("Your Selection:\t");
    scanf("%d", &option);
     system("CLS"); 
    
        switch (option) {
            case 1:
                Balcheck(balance);
                break;
            case 2:
                balance = Deposit(balance);
                break;
            case 3:
                balance = Withdraw(balance);
                break;
            
            case 4:
                menuExit();
                return 0;
                
            default:
                errorMessage();
                break;
        }
       
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("Would you like to do another transaction:\n");
        printf("< 1 > Yes\n");
        printf("< 2 > No\n");
        scanf("%d", &choose);
         system("CLS"); 
        
        
        
        if (choose == 2) {
            again = false;
            menuExit();
           
        }
		else{
        	mainMenu();
		}
}

	return 0;
}
//code for ATM menu...
void mainMenu() {
    
    printf("\n\n\t\t==========Welcome to ABC ATM==========\n\n");
    printf("\n\t\t----Select one of the options below----\n");
    printf("\n\t\t < 1 >  Balance Check\n");
    printf("\n\t\t < 2 >  Deposit\n");
    printf("\n\t\t < 3 >  Withdraw\n");
    printf("\n\t\t < 4 >  Exit\n\n");
}
//balance check...
void Balcheck(float balance) {
    printf("Your Available Balance is:   Rs %.2f\n\n", balance);
}
//deposit amount...
float Deposit(float balance) {
    float deposit;
    printf("Your Balance is: Rs %.2f\n\n", balance);
    printf("Enter Deposit Amount\n");
    scanf("%f", &deposit);
    
    
    balance += deposit;
    
    printf("Your New Balance is:   Rs %.2f\n\n", balance);
    return balance;
}
//withdraw amount...
float Withdraw(float balance) {
    float withdraw;
    bool back = true;
    
    printf("Your Balance is: Rs %.2f\n\n", balance);
    
    while (back) {
    printf("Enter withdrawal amount :\n");
    scanf("%f", &withdraw);
    
    
    if (withdraw < balance) {
        back = false;
        balance -= withdraw;
        printf("Withdrawal amount is:  Rs %.2f\n", withdraw);
        printf("New Balance is:   Rs %.2f\n\n", balance);
        
    }
    
        else  {
        
        printf("\nNot possible!!!");
        printf("\nYour Balance is:   Rs %.2f\n\n", balance);
    
    }
    }
    return balance;
}
//exit...
void menuExit() {
        printf("-----Thank you for using 'ABC' ATM!!!-----\n");
    
    
}
void errorMessage() {
    printf("!!!Invalid number!!!\n");
}
