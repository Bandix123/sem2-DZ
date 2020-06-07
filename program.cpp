/*
temp.txt
all.txt
complete.txt
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funchs.h"

#define MAXCHAR 1000
#define BOOK 100



int main(){
	FILE *fp;
	int i=0;
	char fname[MAXCHAR];
	int choose;
	
	int id;
	char name[100];
	
	
	
	printf("Write file name and route: \n");
	scanf("%s",&fname);
	
	fp = fopen(fname, "r");
    if (fp == NULL){
        printf("Could not open file %s",fname);
        
    }else while(choose!=12){
	printf("\n choose what to do: \n 0) Show everything \n 1) Add book \n 2) Delete a book \n 3) Look at one book (enter its id) \n 12) End program \n ");
	scanf("%d",&choose);
	
	switch (choose){
///////////////////////////////////////////////////////////////////////////////////		
		case 0:
		print_all(fname);
		break;
		
///////////////////////////////////////////////////////////////////////////////////		
		case 1: 
		printf("Write ID and Name\n");
		scanf("%d",&id);
		scanf("%s",name);
		if(check_id(fname,id)==1){
		add_book(fname,id,name);
	}else if(check_id(fname,id)==2){
		printf("That ID is already taken \n \n \n");
	}
		break;

///////////////////////////////////////////////////////////////////////////////////		
		case 2:
		printf("Write book ID \n");
		scanf("%d",&id);
		delete_book(fname,id);
		complete_file(fname);
	
		break;
		
///////////////////////////////////////////////////////////////////////////////////		
		case 3:
		printf("Write book ID\n");
		scanf("%d",&id);
		print_one_book(fname,id);	
		break;
		
///////////////////////////////////////////////////////////////////////////////////				
		case 12: 
		
		break;
	}
}
return 0;
}
