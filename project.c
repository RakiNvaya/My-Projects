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

struct st user[20];
      ///login function
void login()
{
   gotoxy(50,2);

    printf("*** login ***");
    char login_user_name[30],login_password[30];

    FILE* ch;
   ch = fopen("sign_up.txt","r");
    gotoxy(6,4);
    printf("1.Enter user name : ");
    scanf("%s",&login_user_name);
   gotoxy(6,5);
    printf("2.Enter password  : ");
    scanf("%s",&login_password);

    /// comparing id password

  int a = strcmp(login_user_name,user[0].user_name);
  int b = strcmp(login_password,user[0].password);

   //printf("\n\n\n\n%d%d",a,b);

  if(a == 0 && b == 0){

    gotoxy(40,8);
    printf("***Succesful login***");}
  else{
    gotoxy(40,8);
    printf("***Incorrect user name or password***");}

    getch();
}
     ///signup function
void signup()
{
    int any_key;

    struct st user[20];

   FILE* ch;
   ch = fopen("sign_up.txt","w");

   gotoxy(50,2);

   printf("----------sign up----------\n");

   printf("1.Enter first name : ");
   scanf("%s",&user[0].first_name);
   fprintf(ch,"%s\n",user[0].first_name);

    printf("2.Enter last name  : ");
    scanf("%s",&user[0].last_name);
   fprintf(ch,"%s\n",user[0].last_name);

    printf("3.Enter user name  : ");
    scanf("%s",&user[0].user_name);
   fprintf(ch,"%s\n",user[0].user_name);

   printf("4.Enter password   : ");
   scanf("%s ",&user[0].password);
   fprintf(ch,"%s\n",user[0].password);

   printf("\n***login succesfull***\n");

   printf("Note : please sign in using your user name and password\n");

   printf("  \nPress any key to continue : ");

   scanf("%d",&any_key);

   system("CLS");

   login();

}

int main()
{
    int n;
    gotoxy(50,2);
    printf("----------Main menu----------");
    gotoxy(6,4);
    printf("1.Press 1 to login\n");
    gotoxy(6,5);
    printf("2.Press 2 to sign up\n\n");
    gotoxy(6,7);
    printf("Enter : ");
    scanf("%d",&n);

    system("CLS");

    if(n==2)
        signup();

    else if(n==1)
        login();

}
