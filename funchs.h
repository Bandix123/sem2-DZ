#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define MAXCHAR 1000
#define BOOK 100

struct book{
	int id;

	char name[100];


}book[BOOK]; 



void print_all(char fname[MAXCHAR]){
	FILE *fp;

	int i=1;
	fp=fopen(fname,"r");
	printf(" _________________\n");
	printf(" |--ID--|--NAME--|\n");
	while (fscanf(fp,"%d;%s",&book[i].id,book[i].name)!=EOF){
		printf("%d|%6d|%8s|\n",i,book[i].id,book[i].name);
		i++;
	}
	printf(" |______|________|\n");
	fclose(fp);
}


int check_id(char fname[MAXCHAR],int id){
	FILE *fp;
    char str[MAXCHAR];
    int i=0;
    fp=fopen(fname,"r");

	while (fscanf(fp,"%d;%s",&book[i].id,book[i].name)!=EOF){
	if(id==book[i].id){
		return 2;
	} else {
	return 1;
	}i++;
}
fclose(fp);

}


void add_book(char fname[MAXCHAR],int id, char name[]){
	
	
	FILE *fp;
    char str[MAXCHAR];
    int i=0;


    
    fp = fopen(fname, "a");	
    if (fp == NULL) {
    printf("Could not open file %s",fname);
}
rewind(fp);

	
	fprintf(fp,"%d;%s\n",id,name);



	fclose(fp);

}

void print_one_book(char fname[MAXCHAR],int id){
	FILE *fp;
	int i=0;
	int check=0;
	fp=fopen(fname,"r");
	
	while (fscanf(fp,"%d;%s",&book[i].id,book[i].name)!=EOF){
	if (id==book[i].id){
		printf("%d %s \n \n \n ",book[i].id,book[i].name); break;
	} else{
//		check=1;
	}
		i++;
	}
//	if(check=1){
//		printf("Sorry, no book of a matching ID found \n \n \n");
//	}
	fclose(fp);
}
void delete_book (char fname[MAXCHAR],int id){
	FILE *all;
	FILE *temp;
	FILE *complete;
	int i=0;
	int temp_id;
	char temp_name[100];
	
	
	all=fopen("all.txt","w");
	temp=fopen("temp.txt","w");
	complete=fopen(fname,"r+");

	
	while (fscanf(complete,"%d;%s",&book[i].id,book[i].name)!=EOF){

fprintf(all,"%d;%s\n",book[i].id,book[i].name);


	if (id==book[i].id){
	temp_id=book[i].id;
	strcpy(temp_name,book[i].name);

fprintf(temp,"%d;%s \n",temp_id,temp_name);

}else {

}
	i++;
	}
fclose(all);
fclose(temp);
fclose(complete);	
	
}

void complete_file(char fname[MAXCHAR]){
		FILE *all;
	FILE *temp;
	FILE *complete;
	int i=0;
	int temp_id;
	char temp_name[100];
	
	
	all=fopen("all.txt","r");
	temp=fopen("temp.txt","r");
	complete=fopen(fname,"w");
	fscanf(temp,"%d;%s",&temp_id,temp_name); //считали то, что надо удалить
		
	while (fscanf(all,"%d;%s",&book[i].id,book[i].name)!=EOF){
		if (book[i].id!=temp_id){

fprintf(complete,"%d;%s \n",book[i].id,book[i].name);
		}
		i++;

	}	
	

fclose(all);
fclose(temp);
fclose(complete);	
	


}
	
	
	
	



