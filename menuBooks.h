	while(choose!=12){
	printf("\n choose what to do: \n 0) Show everything \n 1) Add book \n 2) Delete a book \n 3) Look at one book (enter its id) \n 12) End program \n ");
	scanf("%d",&choose);
	
	switch (choose){
///////////////////////////////////////////////////////////////////////////////////		
		case 0:
		print_all_books();
		break;
		
///////////////////////////////////////////////////////////////////////////////////		
		case 1: 
		printf("Write ID Author Name Available books and All books \n");
		scanf("%d",&id);
		scanf("%s",name);
		scanf("%s",author);
		scanf("%d",&available);
		scanf("%d",&all);
		if(check_id_book(id)==1){
		add_book(id,author,name,available,all);
	}else if(check_id_book(id)==2){
		printf("That ID is already taken \n \n \n");
	}
		break;

///////////////////////////////////////////////////////////////////////////////////		
		case 2:
		printf("Write book ID \n");
		scanf("%d",&id);
		delete_book(id);
		complete_file_book();
	
		break;
		
///////////////////////////////////////////////////////////////////////////////////		
		case 3:
		printf("Write book ID\n");
		scanf("%d",&id);
		print_one_book(id);	
		break;
		
///////////////////////////////////////////////////////////////////////////////////				
		case 12: 
		
		break;
	}
}
