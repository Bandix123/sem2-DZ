/*
delete.txt
all.txt
books.txt
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


#include "funchsBooks.h"
#include "funchsUsers.h"
#include "funchsStudents.h"


#define MAXCHAR 1000
#define BOOK 100



int main(){
	FILE *fp;
	int i=0;
	char fname[MAXCHAR];
	int choose;
	
	char login[100];
	char password[100];
	int menu;
	
	int id;
	char author[100];
	char name[100];
	int available;
	int all;
	
	char surname[100];
	char faculty[100];
	char speciality[100];

	
	printf("Please write your login and password \n");
	scanf("%s",login);
	scanf("%s",password);
	check_login(login,password);
	
	
	if (check_login(login,password)==1){
		
		printf("you have access to books and students \n");
		
		printf("What would you like to do?\n 1)access books \n 2)access students \n 0) enter differnt username \n");
		scanf("%d",&menu);
		
		switch (menu){
			case 0:
				
				break;
			case 1:
				#include "menuBooks.h"
				break;
			case 2:
				#include "menuStudents.h"
				break;
		}
		
		
		}else
//////////////////////////////////////////////////////////
		 if(check_login(login,password)==2){
			
			printf("you have access to books \n");
			
			#include "menuBooks.h"
		} else 
///////////////////////////////////////////////////////
		 if(check_login(login,password)==3){
		 	
			printf("you have access to students\n");
			
			#include "menuStudents.h"	
		}else {
			printf("Invalid username/password \n");
		}
		
	
	



return 0;
}
