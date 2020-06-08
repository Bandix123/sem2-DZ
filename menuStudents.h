	while(choose!=8){
	printf("\n choose what to do: \n 0) Show everything \n 1) Add student \n 2) Delete a student \n 3) Change student \n 4) See one student \n 8) End program \n ");
	scanf("%d",&choose);
	
	switch (choose){
///////////////////////////////////////////////////////////////////////////////////		
		case 0:
		print_all_students();
		break;
		
///////////////////////////////////////////////////////////////////////////////////		
		case 1: 
		printf("Write ID Name Surname Faculty and Speciality \n");
		scanf("%d",&id);
		scanf("%s",name);
		scanf("%s",surname);
		scanf("%s",faculty);
		scanf("%s",speciality);
		if(check_id_student(id)==1){
		add_student(id,name,surname,faculty,speciality);
	}else if(check_id_student(id)==2){
		printf("That ID is already taken \n \n \n");
	}
		break;

///////////////////////////////////////////////////////////////////////////////////		
		case 2:
		printf("Write student ID \n");
		scanf("%d",&id);
		delete_student(id);
		complete_file_student();
	
		break;
		
////////////////////////////////////////////////////////////////////////////////////		
		case 3:
		printf("Write student ID to change him \n");	
		scanf("%d",&id);
		printf("Write his new name surname faculty and speciality \n ");
		scanf("%s",name);
		scanf("%s",surname);
		scanf("%s",faculty);
		scanf("%s",speciality);
	delete_student(id);
	complete_file_student();
	add_student(id,name,surname,faculty,speciality);
		break;
		
///////////////////////////////////////////////////////////////////////////////////		
		case 4:
		printf("Write student ID\n");
		scanf("%d",&id);
		print_one_student(id);	
		break;
		
///////////////////////////////////////////////////////////////////////////////////				
		case 8: 
		
		break;
	}
}
