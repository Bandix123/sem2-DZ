#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define MAXCHAR 1000
#define BOOK 100

struct book{
	int id;
	char author[100];
	char name[100];
	int available;
	int all;
}book[BOOK]; 



void print_all_books(){
	FILE *fp;

	int i=1;
	fp=fopen("books.txt","r");
	printf("______________________________________________________\n");
	printf("|--ID--|--AUTHOR--|--NAME--|--AVAILABLE--|--AMMOUNT--|\n");
	while (fscanf(fp,"%d;%[a-zA-z];%[a-zA-Z];%d;%d\n",&book[i].id,book[i].author,book[i].name,&book[i].available,&book[i].all)!=EOF){
		printf("|%6d|%10s|%8s|%13d|%11d|\n",book[i].id,book[i].author,book[i].name,book[i].available,book[i].all);
		i++;
	}
	printf("|______|__________|________|_____________|___________|\n");
	fclose(fp);
}

int check_id_book(int id){
	FILE *fp;
    int i=0;
    fp=fopen("books.txt","r");

	while (fscanf(fp,"%d;%s;%s;%d;%d",&book[i].id,book[i].author,book[i].name,&book[i].available,&book[i].all)!=EOF){
	if(id==book[i].id){
		return 2;
	} else {
	return 1;
	}i++;
}
fclose(fp);

}

void add_book(int id, char author[],char name[],int available, int all){	
	FILE *fp;
    int i=0;


    
    fp = fopen("books.txt", "a");	
   
rewind(fp);

	
	fprintf(fp,"%d;%s;%s;%d;%d\n",id,author,name,available,all);



	fclose(fp);

}

void print_one_book(int id){
	
	FILE *fp;
	int i=0;
	int check=0;
	fp=fopen("books.txt","r");
	
	while (fscanf(fp,"%d;%[a-zA-z];%[a-zA-Z];%d;%d",&book[i].id,book[i].author,book[i].name,&book[i].available,&book[i].all)!=EOF){
	if (id==book[i].id){
		printf("%d %s %s %d %d \n \n \n ",book[i].id,book[i].author,book[i].name,book[i].available,book[i].all); break;
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

void delete_book (int id){
	FILE *all;
	FILE *temp;
	FILE *complete;
	int i=0;
	int temp_id;
	char temp_author[100];
	char temp_name[100];
	int temp_available;
	int temp_all;
	
	
	all=fopen("all.txt","w");
	temp=fopen("delete.txt","w");
	complete=fopen("books.txt","r+");

	
	while (fscanf(complete,"%d;%[a-zA-z];%[a-zA-Z];%d;%d",&book[i].id,book[i].author,book[i].name,&book[i].available,&book[i].all)!=EOF){

fprintf(all,"%d;%s;%s;%d;%d\n",book[i].id,book[i].author,book[i].name,book[i].available,book[i].all);


	if (id==book[i].id){
	temp_id=book[i].id;
	strcpy(temp_author,book[i].author);
	strcpy(temp_name,book[i].name);
	temp_available=book[i].available;
fprintf(temp,"%d;%s;%s;%d;%d \n",temp_id,temp_author,temp_name,temp_available,temp_all);

}else {

}
	i++;
	}
fclose(all);
fclose(temp);
fclose(complete);	
	
}

void complete_file_book(){
		FILE *all;
	FILE *temp;
	FILE *complete;
	int i=0;
	int temp_id;
	char temp_author[100];
	char temp_name[100];
	int temp_available;
	int temp_all;
	
	
	all=fopen("all.txt","r");
	temp=fopen("delete.txt","r");
	complete=fopen("books.txt","w");
	fscanf(temp,"%d;%[a-zA-z];%[a-zA-Z];%d;%d",&temp_id,temp_author,temp_name,&temp_available,&temp_all); //считали то, что надо удалить
		
	while (fscanf(all,"%d;%[a-zA-z];%[a-zA-Z];%d;%d",&book[i].id,book[i].author,book[i].name,&book[i].available,&book[i].all)!=EOF){
		if (book[i].id!=temp_id){

fprintf(complete,"%d;%s;%s;%d;%d \n",book[i].id,book[i].author,book[i].name,book[i].available,book[i].all);
		}
		i++;

	}	
	

fclose(all);
fclose(temp);
fclose(complete);	
	


}
