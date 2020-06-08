#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


#define MAXCHAR 1000
#define BOOK 100





int check_login(char login[MAXCHAR],char password[MAXCHAR]){
	FILE *users;
	char check_login[100];
	char check_password[100];
	int book;
	int student;
	users=fopen("users.txt","r");
	while (fscanf(users,"%[a-zA-z];%[a-zA-Z];%d;%d\n",check_login,check_password,&book,&student)!=EOF){
		if((!strcmp(login,check_login))&&(!strcmp(password,check_password))){
			if((book==1)&&(student)==1){
				return 1;break;
			}  if((book==1)&&(student==0)){
				return 2;break;
			}  if((book==0)&&(student==1)){
				return 3;break;
			}
		} 
	}
	fclose(users);
	
}
