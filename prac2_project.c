
#include<stdio.h>
#include<conio.h>
#include<windows.h>



/// for animation
void gotoxy(int x, int y)
{
    COORD c = { x, y };
    SetConsoleCursorPosition(  GetStdHandle(STD_OUTPUT_HANDLE) , c);
}

struct transaction_info
{
    char name[100];
    int amount;
    char date[10];
};

struct transaction_info t_user[100];

struct st
{
    char first_name[20];
    char last_name[20];
    char user_name[20];
    char password[20];

};

struct st user[10];


int id_num;  /// number of  id  curently saved

void login();
void signup();
void main_page();
void add_money();
void read_tran();
void write_tran();
void show_tran();
void remove_tran();

int t_num;   ///how many transaction done


void read_tran()  ///to read  transactions
{
    FILE* ch;
    ch=fopen("transaction.txt","r");
   // if(ch==0)
       // printf("file doesnot exixit");

    fscanf(ch,"%d",&t_num);
    for(int i=0;i<t_num;i++)
    {
        fscanf(ch,"%s",&t_user[i].name);
        fscanf(ch,"%d",&t_user[i].amount);
        fscanf(ch,"%s",&t_user[i].date);
    }

    fclose(ch);
}

void write_tran() /// to write transaction
{
    FILE* ch;
    ch=fopen("transaction.txt","w");
    if(ch==0)
        printf("file doesnot exixit");

    t_num++;

     fprintf(ch,"%d\n",t_num);

    for(int i=0;i<t_num;i++)
    {
        fprintf(ch,"%s\n",t_user[i].name);
        fprintf(ch,"%d\n",t_user[i].amount);
        fprintf(ch,"%s\n",t_user[i].date);
    }

    fclose(ch);


}

void show_tran()    /// to print and show trasantions
{
    read_tran();

    int k;

    for(int i=0;i<t_num;i++)
    {
    gotoxy(25,i+1);
    printf("%d . ",i+1);
    gotoxy(30,i+1);
    printf("%s  ",t_user[i].name);
    gotoxy(50,i+1);
    printf("%d  ",t_user[i].amount);
    gotoxy(65,i+1);
    printf("%s",t_user[i].date);

    k = i + 15;

    }

    gotoxy(40,k+2);
    printf("Transaction successfull");

    gotoxy(40,k+4);
    printf("Press any key to get back");

    getch();
    system("CLS");

    main_page();

}


void read_data()
{

     FILE* ch;
   ch = fopen("sign_up.txt","r");
   fscanf(ch,"%d",&id_num);
   for(int i=0;i<id_num;i++)
   {
       fscanf(ch,"%s",&user[i].first_name);
       fscanf(ch,"%s",&user[i].last_name);
       fscanf(ch,"%s",&user[i].user_name);
       fscanf(ch,"%s",&user[i].password);
   }

   fclose(ch);

}

 void write_data()
{
    FILE* ch;
     ch = fopen("sign_up.txt","w");

     id_num++;
     fprintf(ch,"%d\n",id_num);
     for(int i=0;i<id_num;i++)
     {
         fprintf(ch,"%s\n",user[i].first_name);
          fprintf(ch,"%s\n",user[i].last_name);
            fprintf(ch,"%s\n",user[i].user_name);
               fprintf(ch,"%s\n",user[i].password);
     }

     fclose(ch);



}

void main_page()  /// account main page
{
    int choice;
    gotoxy(18,5);
    printf("What do you want");
    gotoxy(18,7);
    printf("1. Add money");
    gotoxy(18,9);
    printf("2. Remove money");
    gotoxy(18,11);
    printf("3. View Transaction History");
   // printf("4. Exit\n");

    gotoxy(18,13);
    printf("Enter your choice: ");
    scanf("%d",&choice);

    system("CLS");

     if(choice==1)
        add_money();

     else if(choice==3)
        show_tran();

}

void add_money()
{

    read_tran();

     gotoxy(18,8);
   printf("Enter name : ");
   scanf("%s",&t_user[t_num].name);

    gotoxy(18,10);
   printf("Enter amount : ");
   scanf("%d",&t_user[t_num].amount);

    gotoxy(18,12);
   printf("Enter date (dd/mm/yy) format: ");
    scanf("%s",&t_user[t_num].date);

    write_tran();

    gotoxy(40,15);
    printf("Press any key to get back");

    getch();
    system("CLS");

    main_page();
}

void login()   ///login function

{
   gotoxy(50,2);

    printf("---------- login ----------");
    char login_user_name[30],login_password[30];

    gotoxy(18,7);
    printf("1.Enter user name : ");
    scanf("%s",&login_user_name);
   gotoxy(18,8);
    printf("2.Enter password  : ");
    scanf("%s",&login_password);


    read_data();

    int k=0;  /// position of the userID
              ///initially kept 0

   for(int i=0;i<id_num;i++)
   {
       if(strcmp(login_user_name,user[i].user_name)==0)
        k=i;
   }



    /// comparing id password

  int a = strcmp(login_user_name,user[k].user_name);
  int b = strcmp(login_password,user[k].password);

  if(a == 0 && b == 0){

    gotoxy(53,12);
    printf("***Succesful login***");
     gotoxy(51,14);
    printf("Press any key to continue");

    getch();
    system("CLS");

    main_page();

    }

  else{
    gotoxy(45,10);
    printf("***Incorrect user name or password***");

    gotoxy(53,11);
    printf("**please try again**");
     gotoxy(50,13);
    printf("Press any key to try again ");

    getch();
    system("CLS");
    login();

    }


    getch();
}

void signup()   ///sign up function
{
    char first_name[20];
    char last_name[20];
    char user_name[20];
    char password[20];



    char any_key;

   read_data();

   gotoxy(50,2);

   printf("----------sign up----------\n");

   gotoxy(18,6);
   printf("1.Enter first name : ");
   scanf("%s",&user[id_num].first_name);

   gotoxy(18,7);
    printf("2.Enter last name  : ");
    scanf("%s",&user[id_num].last_name);

   gotoxy(18,8);
    printf("3.Enter user name  : ");
    scanf("%s",&user[id_num].user_name);

   gotoxy(18,9);
   printf("4.Enter password   : ");
   scanf("%s",&user[id_num].password);

      int i;
     for(i=0;i<id_num;i++)  ///to check if the userID is taken
   {
       if(strcmp(user[id_num].user_name,user[i].user_name)==0){

            system("CLS");
        gotoxy(47,3);
        printf("*** user name already taken***");
        gotoxy(53,5);
        printf("Try another one");

        gotoxy(18,8);
    printf("3.Enter user name  : ");
    scanf("%s",&user[id_num].user_name);
     i=0;  /// to check if the new userID is taken
       }
   }


  write_data();

   gotoxy(18,12);
   printf("***login succesfull***");

    gotoxy(18,14);
   printf("Note : please sign in using your user name and password\n");

     gotoxy(18,16);
   printf("Press any key to continue : ");

   getch();

   system("CLS");

   login();

}

 void First_page()
{
     int n;
    gotoxy(50,2);
    printf("----------Welcome to HALKHATA----------");
    gotoxy(30,8);
    printf("1.Press 1 to login\n");
    gotoxy(30,9);
    printf("2.Press 2 to sign up\n\n");
    gotoxy(50,15);
    printf("Enter : ");
    scanf("%d",&n);

    system("CLS");

    if(n==2)
        signup();

    else if(n==1)
        login();

}

int main()
{
    First_page();

}