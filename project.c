
#include<stdio.h>
#include<conio.h>
#include<windows.h>



/// for animation
void gotoxy(int x, int y)
{
    COORD c = { x, y };
    SetConsoleCursorPosition(  GetStdHandle(STD_OUTPUT_HANDLE) , c);
}

struct st
{
    char first_name[20];
    char last_name[20];
    char user_name[20];
    char password[20];

};

struct st user[10];

/// number of  id  curently saved
int id_num;

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

  ///login function

void login()
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
    printf("***Succesful login***");}
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
     ///signup function
void signup()
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
