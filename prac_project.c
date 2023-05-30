
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include<math.h>


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

struct transaction
{
    char userID[20]; /// user name for each id
    int id_balance; /// balance for each id
    int tran_num;  ///transaction number for each id
};

struct transaction id[10]; /// for multiple transaction
struct st user[10];


int id_num;   /// number of  id  curently saved
int balance;   /// total balance;
int num;        ///tran ending point for each id
int id_pos;   /// id position
int tran_add;

char name[20];
char password[20];


void login();
void signup();
void main_page();
void add_money();
void read_tran();
void write_tran();
void show_tran();
void remove_tran();
void remove_money();
void search_id();

int t_num;   ///how many transaction done

int number; /// for remove_tran function


void read_tran()  ///to read  transactions
{
    FILE* ch;

    ch=fopen("transaction.txt","r");
   // if(ch==0)
       // printf("file doesnot exixit");
    fscanf(ch,"%d",&id_num);

    num=0;

    int i,k=0,j=0;

    for( i=0;i<id_num;i++)
    {
        int k=j;

    fscanf(ch,"%s",&id[i].userID);
    fscanf(ch,"%d",&id[i].id_balance);
    fscanf(ch,"%d",&id[i].tran_num);

      if(strcmp(name,id[j].userID)==0) /// id balance
        balance = id[i].id_balance;

    num += id[i].tran_num ; ///tran ending point for each id

    for( j=k;j<num;j++)
    {
        fscanf(ch,"%s",&t_user[j].name);
        fscanf(ch,"%d",&t_user[j].amount);
        fscanf(ch,"%s",&t_user[j].date);
    }

  //  k=j;

    }

    fclose(ch);
}

void write_tran() /// to write transaction
{
    FILE* ch;
    ch=fopen("transaction.txt","w");
    if(ch==0)
        printf("file doesnot exixit");

         num=0;

    fprintf(ch,"%d\n",id_num);

    int i,k,j=0;

    for( i=0;i<id_num;i++)
    {
        int k=j;

    fprintf(ch,"%s\n",id[i].userID);
    fprintf(ch,"%d\n",id[i].id_balance);
    fprintf(ch,"%d\n",id[i].tran_num);

    num += id[i].tran_num;  ///tran ending point for each id

    for( j=k;j<num;j++)
    {
        fprintf(ch,"%s\n",t_user[j].name);
        fprintf(ch,"%d\n",t_user[j].amount);
        fprintf(ch,"%s\n",t_user[j].date);
    }

  //  k=j;

    }
    fclose(ch);


}

void remove_money()
{
    read_tran();
   // id_search();
         gotoxy(18,8);
   printf("Enter name : ");
   scanf("%s",&t_user[t_num].name);

    gotoxy(18,10);
   printf("Enter amount : -");
   scanf("%d",&t_user[t_num].amount);

    gotoxy(18,12);
   printf("Enter date (dd/mm/yy) format: ");
    scanf("%s",&t_user[t_num].date);

    ///to check if enough balance is available to remove

    if(balance>=t_user[t_num].amount)
    {

    balance -= t_user[t_num].amount;

    t_num++;

    write_tran();

       gotoxy(40,15);
    printf("**Transaction successfull**");

    }
    else
    {
             gotoxy(40,15);
        printf("**Insufficient balance**");
    }


    gotoxy(40,17);
    printf("=>Press any key to get back<=");

    getch();
    system("CLS");


    main_page();
}


void remove_tran()
{
    read_tran();

    int k=t_num;

     for(int i=0;i<t_num;i++)
    {

    gotoxy(25,5+i);
    printf("%d . ",i+1);
    gotoxy(30,5+i);
    printf("%s  ",t_user[i].name);
    gotoxy(50,5+i);
    printf("%d  ",t_user[i].amount);
    gotoxy(65,5+i);
    printf("%s",t_user[i].date);

    }


   gotoxy(40,k+10);
    printf("Enter ther transaction number you want to remove : ");
    scanf("%d",&number); /// number declared globally

    t_num--;

    for(int i=number;i<t_num;i++)
    {
        t_user[i-1]=t_user[i];
    }

    write_tran();

    gotoxy(40,k+12);
    printf("Press any key to get back");

    getch();
    system("CLS");

    main_page();


}

void show_tran()    /// to print and show trasantions
{

    read_tran();

    num = 0;

   // write_tran();

    int k=0;

    for(int j=0;j<id_num;j++)
        {
             num += id[j].tran_num;


       if(strcmp(name,id[j].userID)==0){

            //printf("done");

              int start = num - id[j].tran_num;

    for(int i=start;i<num;i++)
    {

    gotoxy(25,i+1);
    printf("%d . ",i+1);
    gotoxy(30,i+1);
    printf("%s",t_user[i].name);
    gotoxy(50,i+1);
    printf("%d  ",t_user[i].amount);
    gotoxy(65,i+1);
    printf("%s",t_user[i].date);

     k = i + 15;


         }
       }

     }

    gotoxy(40,k);
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

   //  id_num++;
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

void search_id()
{

    read_tran();

      FILE* ch;

    ch=fopen("transaction.txt","r");

     int i,k=0,j=0;

    for(i=0;i<id_num;i++)
    {
        tran_add += id[i].tran_num;


        if(strcmp(name,id[i].userID)==0)

            id_pos = i;


    }

    fclose(ch);

}
void main_page()  /// account main page
{
    int choice;

    read_tran();

    gotoxy(18,5);
    printf("|| Balance : %d",balance); /// from read_tran
    gotoxy(18,7);
    printf("What do you want");
    gotoxy(18,9);
    printf("1. Add money");
    gotoxy(18,11);
    printf("2. Remove money");
    gotoxy(18,13);
    printf("3. View Transaction History");
    gotoxy(18,15);
    printf("4.Delete Transaction ");
   // printf("4. Exit\n");

    gotoxy(50,17);
    printf("Enter your choice: ");
    scanf("%d",&choice);

    system("CLS");

     if(choice==1)
        add_money();

     else if(choice==2)
        remove_money();

     else if(choice==3)
        show_tran();

     else if(choice==4)
        remove_tran();


}

void add_money()
{

    read_tran();
    search_id();

     gotoxy(18,8);
   printf("Enter name : ");
   scanf("%s",&t_user[tran_add].name);

    gotoxy(18,10);
   printf("Enter amount : +");
   scanf("%d",&t_user[tran_add].amount);

    gotoxy(18,12);
   printf("Enter date (dd/mm/yy) format: ");
    scanf("%s",&t_user[tran_add].date);

    id[id_pos].id_balance += t_user[tran_add].amount;

    id[id_pos].tran_num++;

    write_tran();

     gotoxy(40,15);
    printf("***Transaction successfull***");

    gotoxy(40,17);
    printf("=>Press any key to get back<=");

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

         strcpy(name,login_user_name);

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
   read_tran();

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

    strcpy(id[id_num].userID,user[id_num].user_name);
    id[id_num].id_balance = 0;
    id[id_num].tran_num = 0;

    id_num++;

  // strcpy(password,user[id_num].password);

  write_data();
  write_tran();

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
