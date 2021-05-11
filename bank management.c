#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
 struct bank_details{
	int acc_no,ph,amt;
	char name[50];
	char address[50];
	int age;
};
struct bank_details verify,add,trans,delete_acc;
void delay(int );
void create_acc(){
	int ch;
	FILE *ptr;
	open_acc:
	ptr=fopen("bankRecord.dat","a+");
	printf("Enter Account Number: ");
	scanf("%d",&verify.acc_no);
	while(fscanf(ptr,"%d %d %s %s %d %d",&add.acc_no,&add.ph,&add.name,&add.address,&add.age,&add.amt)!=EOF){
		if(verify.acc_no==add.acc_no){
			printf("Accounnt Number Already exists..");
			delay(1000000000);
                goto open_acc;
		}
	}
	add.acc_no=verify.acc_no;
	printf("Enter Your Name: ");
	scanf("%s",add.name);
	printf("Enter Mobile No. ");
	scanf("%d",&add.ph);
	printf("Enter Your Age: ");
	scanf("%d",&add.age);
	printf("Give Your Address: ");
	scanf("%s",&add.address);
	printf("Enter the to be deposite:$");
	scanf("%d",&add.amt);
	fprintf(ptr,"%d %d %s %s %d %d\n",add.acc_no,add.ph,add.name,add.address,add.age,add.amt);
	fclose(ptr);
	printf("Account Successfully Created\n");
	printf("Press 1:Main Menu\n2:Exit");
	scanf("%d",&ch);
	system("cls");
	if(ch==1)
		menu1();
	else if(ch==2)
	    exit_k();
	else
	printf("Invalid Input");
	 
}
void delete_account(){
FILE *old;
FILE *new_file;	
int t=0,ch;
	old=fopen("bankRecord.dat","r");
	new_file=fopen("newBankRecord.dat","w");
	printf("Enter Account no. Which you want to DELETE: ");
	scanf("%d",&delete_acc.acc_no);
	while(fscanf(old,"%d %d %s %s %d %d",&add.acc_no,&add.ph,&add.name,&add.address,&add.age,&add.amt)!=EOF){
		if(add.acc_no!=delete_acc.acc_no)
		  fprintf(new_file,"%d %d %s %s %d %d\n",add.acc_no,add.ph,add.name,add.address,add.age,add.amt);
		else{
			t++;
			printf("\n\n\t\t...Account Deleted Successfully...\n");
		} 
    }
    fclose(old);
    fclose(new_file);
    remove("bankRecord.dat");
    rename("newBankRecord.dat","bankRecord.dat");
if(t==0){
  printf("\nAccount Not Found\n");
  printf("\nPress 1:Main Menu\n2:Try Again\n3:Exit\n");
	scanf("%d",&ch);
	system("cls");
	if(ch==1)
		menu1();
	else if(ch==2)
	    delete_account();
	else if(ch==3)
	    exit_k();
	else
	printf("Invalid Input");
 }
 else{
 	printf("Press 1:Main Menu\n2:Exit\n");
	scanf("%d",&ch);
	system("cls");
	if(ch==1)
		menu1();
	else if(ch==2)
	    exit_k();
	else
	 printf("Invalid Input");
 }
}

void acc_list()
{    int ch,t=0;
	FILE *ptr;
	ptr=fopen("bankRecord.dat","r");
	printf("\n\tAcc No.\tName\tMobile\t\tAge\tAddress\t\tAccount Balance");
	while(fscanf(ptr,"%d %d %s %s %d %d",&add.acc_no,&add.ph,&add.name,&add.address,&add.age,&add.amt)!=EOF){
      printf("\n\t%d \t%s \t%d \t\t%d \t%s \t\t%d\n",add.acc_no,add.name,add.ph,add.age,add.address,add.amt);		
      t++;
	}
	fclose(ptr);
if(t==0){
	system("cls");
	printf("\n\t:::No Record Found:::\n");
    printf("\nPress 1:Main Menu\n2:Exit\n");
	scanf("%d",&ch);
	system("cls");
	if(ch==1)
		main();
	else if(ch==2)
	    exit_k();
	else
	 printf("Invalid Input");
 }
 else{
 	printf("\nPress 1:Main Menu\n2:Exit\n");
	scanf("%d",&ch);
	system("cls");
	if(ch==1)
 	  main();
 	else if(ch==2)
 		exit_k();
	else
	   printf("\n!Invalid Input!\n");
  }
}

void Transactions(){
	//trans
	FILE *old,*new_file;
	int ch,t=0;
	old=fopen("bankRecord.dat","r");
	new_file=fopen("newBankRecord.dat","w");
	printf("Enter customer Account Number: ");
	scanf("%d",&trans.acc_no);
	while(fscanf(old,"%d %d %s %s %d %d",&add.acc_no,&add.ph,&add.name,&add.address,&add.age,&add.amt)!=EOF){
		if(add.acc_no==trans.acc_no){
			t++;
		 printf("Do you Want to\n1.Deposit\n2.Withdraw\nEnter your Choice: ");
		 scanf("%d",&ch);
		 if(ch==1){
		 	printf("\nEnter Amount Want to Deposit: ");
		 	scanf("%d",&trans.amt);
		 	add.amt=add.amt+trans.amt;
		 	fprintf(new_file,"%d %d %s %s %d %d\n",add.acc_no,add.ph,add.name,add.address,add.age,add.amt);
		 	printf("\n\t\t::Successfully Deposite::\n");
		 }
		 else if(ch==2){
		 	printf("\nEnter Amount Want to Withdraw: ");
		 	scanf("%d",&trans.amt);
		 	if(add.amt>=trans.amt){
		 	add.amt=add.amt-trans.amt;
		 	fprintf(new_file,"%d %d %s %s %d %d\n",add.acc_no,add.ph,add.name,add.address,add.age,add.amt);
		 	printf("\n\t\t::Successfully Withdraw::\n");
		    }
		    else
		    	printf("\n\t\t::Insufficient Balance::\n");	 	
		 }
		}
		else
		 fprintf(new_file,"%d %d %s %s %d %d\n",add.acc_no,add.ph,add.name,add.address,add.age,add.amt);
	}
fclose(old);
fclose(new_file);
remove("bankRecord.dat");
rename("newBankRecord.dat","bankRecord.dat");
if(t==0){
	system("cls");
	printf("\n\t:::Accounr Not Found:::\n");
    printf("\nPress 1:Try Again\n2:Main Menu\n3:Exit\n");
	scanf("%d",&ch);
	system("cls");
	if(ch==1)
	Transactions();
	else if(ch==2)
	  menu2();
	else if(ch==3)
	    exit_k();
	else
	 printf("Invalid Input");
 }
	
}

void delay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}
void exit_k(){
	printf("\t\t\t\t\:::::THANK YOU FOR BANKING::::::\n\t\t\t\tHAVE A GOOD DAY");
}
void menu1(){
	int choice;
    system("cls");
    printf("\n\n\t\t\tCUSTOMER CARE BANKING MANAGEMENT");
    printf("\n\n\t\t1.Create new account\n\t\t2.Removing existing account\n\t\t3.Check the details of existing account\n\t\t4.Exit\n\n\n\n\n\t\t Enter your choice: ");
    scanf("%d",&choice);

    system("cls");
    switch(choice)
    {
        case 1:create_acc();
        break;
        case 2:delete_account();
        break;
        case 3:acc_list();
        break;
        case 4:exit_k();
        break;

    }

}
void menu2()
{	int choice;
    system("cls");
    printf("\n\n\t\t\tCASHIER BANKING MANAGEMENT");
    printf("\n\t\t1.Transactions\n\t\t2.Check the details of existing account\n\t\t3.Exit\n\n\n\n\n\t\t Enter your choice: ");
    scanf("%d",&choice);

    system("cls");
    switch(choice)
    {
        case 1:Transactions();
        break;
        case 2:acc_list();
        break;
        case 3:close();
        break;

    }
}

void main(){
	char pass[50],passw[50]="abcd";int i,ch,choice;
	printf("\t\t:::::Swiss Bank International::::::\nEnter User Type\n1.Customer\n2.Cashier\n");
	printf("\nEnter your choice\n");
	scanf("%d",&ch);
	if(ch==1){
		printf("Give Login Password: ");
		scanf("%s",&pass);
		if(strcmp(pass,passw)==0){
		printf("\n\nPassword Matched!!\nLOADING");
        for(i=0;i<=6;i++)
        {
            delay(100000000);
            printf(".");
        }
        system("cls");
        menu1();
		}
		else{
	printf("\n\n!!Wrong password!!");
            error_login1:
            printf("\nEnter 1:Try Again\n 0:Exit:");
            scanf("%d",&choice);
            if (choice==1)
                    {

                        system("cls");
                        main();
                    }

            else if (choice==0)
               {
                system("cls");
                exit_k();
				}
            else{
			 printf("\nInvalid!");
             delay(1000000000);
             system("cls");
             goto error_login1;
			 }
	   }
	}
	else if(ch==2){
		printf("Give Login Password: ");
		scanf("%s",&pass);
		if(strcmp(pass,passw)==0){
		printf("\n\nPassword Matched::\nLOADING");
        for(i=0;i<=6;i++)
        {
            delay(100000000);
            printf(".");
        }
        system("cls");
        menu2();
		}
		else{
	printf("\n\nWrong password!!");
            error_login2:
            printf("\nEnter 1:Try Again\n 0:Exit:");
            scanf("%d",&choice);
            if (choice==1)
            {
            system("cls");
              main();
            }

            else if (choice==0)
               {
                system("cls");
                exit_k();
				}
            else{
			 printf("\nInvalid!");
             delay(1000000000);
             system("cls");
             goto error_login2;
			 }
	   }
	}
	else{
       printf("\nChoose A correct User");
       delay(1000000000);
       main();
        }
	
}