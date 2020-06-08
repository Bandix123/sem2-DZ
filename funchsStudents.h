#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define MAXCHAR 1000
#define STUDENT 100

struct student{
	int id;
	char name[100];
	char surname[100];
	char faculty[100];
	char speciality[100];
}student[STUDENT]; 



void print_all_students(){
	FILE *fp;

	int i=1;
	fp=fopen("students.txt","r");
	printf("______________________________________________________\n");
	printf("|--ID--|--NAME--|--SURNAME--|--FACULTY--|--SPECIALITY--|\n");
	while (fscanf(fp,"%d;%[a-zA-z];%[a-zA-Z];%[a-zA-Z];%[a-zA-Z]\n",&student[i].id,student[i].name,student[i].surname,student[i].faculty,student[i].speciality)!=EOF){
		printf("|%6d|%8s|%11s|%11s|%14s|\n",student[i].id,student[i].name,student[i].surname,student[i].faculty,student[i].speciality);
		i++;
	}
	printf("|______|__________|________|_____________|___________|\n");
	fclose(fp);
}

int check_id_student(int id){
	FILE *fp;
    int i=0;
    fp=fopen("students.txt","r");

	while (fscanf(fp,"%d;%s;%s;%d;%d",&student[i].id,student[i].name,student[i].surname,student[i].faculty,student[i].speciality)!=EOF){
	if(id==student[i].id){
		return 2;
	} else {
	return 1;
	}i++;
}
fclose(fp);

}

void add_student(int id, char name[],char surname[],char faculty[], char speciality[]){	
	FILE *fp;
    int i=0;


    
    fp = fopen("students.txt", "a");	
   
rewind(fp);

	
	fprintf(fp,"%d;%s;%s;%s;%s\n",id,name,surname,faculty,speciality);



	fclose(fp);

}

void print_one_student(int id){
	
	FILE *fp;
	int i=0;
	int check=0;
	fp=fopen("students.txt","r");
	
	while (fscanf(fp,"%d;%[a-zA-z];%[a-zA-Z];%[a-zA-Z];%[a-zA-Z]",&student[i].id,student[i].name,student[i].surname,student[i].faculty,student[i].speciality)!=EOF){
	if (id==student[i].id){
		printf("%d %s %s %s %s \n \n \n ",student[i].id,student[i].name,student[i].surname,student[i].faculty,student[i].speciality); break;
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

void delete_student (int id){
	FILE *all;
	FILE *temp;
	FILE *complete;
	int i=0;
	int temp_id;
	char temp_name[100];
	char temp_surname[100];
	char temp_faculty[100];
	char temp_speciality[100];
	
	
	all=fopen("all.txt","w");
	temp=fopen("delete.txt","w");
	complete=fopen("students.txt","r+");

	
	while (fscanf(complete,"%d;%[a-zA-z];%[a-zA-Z];%[a-zA-Z];%[a-zA-Z]",&student[i].id,student[i].name,student[i].surname,student[i].faculty,student[i].speciality)!=EOF){

fprintf(all,"%d;%s;%s;%s;%s\n",student[i].id,student[i].name,student[i].surname,student[i].faculty,student[i].speciality);


	if (id==student[i].id){
	temp_id=student[i].id;
	strcpy(temp_name,student[i].name);
	strcpy(temp_surname,student[i].surname);
	strcpy(temp_faculty,student[i].faculty);
	strcpy(temp_speciality,student[i].speciality);
fprintf(temp,"%d;%s;%s;%d;%d \n",temp_id,temp_name,temp_surname,temp_faculty,temp_speciality);

}else {

}
	i++;
	}
fclose(all);
fclose(temp);
fclose(complete);	
	
}

void complete_file_student(){
	FILE *all;
	FILE *temp;
	FILE *complete;
	int i=0;
	int temp_id;
	char temp_name[100];
	char temp_surname[100];
	char temp_faculty[100];
	char temp_speciality[100];
	
	
	all=fopen("all.txt","r");
	temp=fopen("delete.txt","r");
	complete=fopen("students.txt","w");
	fscanf(temp,"%d;%[a-zA-z];%[a-zA-Z];%[a-zA-Z];%[a-zA-Z]",&temp_id,temp_name,temp_surname,temp_faculty,temp_speciality); //считали то, что надо удалить
		
	while (fscanf(all,"%d;%[a-zA-z];%[a-zA-Z];%[a-zA-Z];%[a-zA-Z]",&student[i].id,student[i].name,student[i].surname,student[i].faculty,student[i].speciality)!=EOF){
		if (student[i].id!=temp_id){

fprintf(complete,"%d;%s;%s;%s;%s \n",student[i].id,student[i].name,student[i].surname,student[i].faculty,student[i].speciality);
		}
		i++;

	}	
	

fclose(all);
fclose(temp);
fclose(complete);	
	


}



void change_student(int id, char name[],char surname[],char faculty[], char speciality[]){
	
	FILE *fp;
	int i=0;
		
	fp=fopen("students.txt","a");
	
	while (fscanf(fp,"%d;%[a-zA-z];%[a-zA-Z];%[a-zA-Z];%[a-zA-Z]",&student[i].id,student[i].name,student[i].surname,student[i].faculty,student[i].speciality)!=EOF){

	if (id==student[i].id){
		strcpy(student[i].name,name);
		strcpy(student[i].surname,surname);
		strcpy(student[i].faculty,faculty);
		strcpy(student[i].speciality,speciality);
	}i++;

	}


}
