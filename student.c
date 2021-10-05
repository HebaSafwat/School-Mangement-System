/*
 * Name        : student.c
 * Created on  : 23/9/2021
 * Version     : v00
 * Author      : Heba Safwat
 * Description : this file contain the functions definition of each student
 */

/********************************************************************************************
 *                                                                                          *
 *                                       Includes                                           *
 *                                                                                          *
 *********************************************************************************************/

#include "student.h"

/********************************************************************************************
 *                                                                                          *
 *                             private Functions Definition                                 *
 *                                                                                          *
 *********************************************************************************************/
static __uint8__ check_validation(check_type type,student std);

/********************************************************************************************
 *                                                                                          *
 *                                      Glopal Variables                                    *
 *                                                                                          *
 *********************************************************************************************/

__uint8__(*ptr)(check_type,student) = &check_validation; // pointer to function that take enum of type check_type and student sructure and return __uint8__
/********************************************************************************************
 *                                                                                          *
 *                                 Functions Definition                                     *
 *                                                                                          *
 *********************************************************************************************/
void MAIN_MENU (void)
{
	int  targent_num;           //the number of the target that the user wants to do
	stack  user_stack;

	CreateStack(&user_stack);         //Create a new stack
	while(1)
	{
		printf("\n***************** Welcome in our School Management System *****************\n\n");
		printf("please Choose one of our targeted activates: \n");

		printf("1- Create a new student\n2- Delete an existed student\n3- view the students list\n4- update student information\n5- sort all students according to subject score\n6- update score for all students\n");
        printf("====>");
		scanf("%d",&targent_num);

		switch(targent_num)
		{
		case 1 :  NEW_STUDENT   (& user_stack);                     break;
		case 2 :  DELETE_STUDENT(& user_stack);            	        break;
		case 3 :  STUDENT_LIST  (& user_stack);	                    break;
		case 4 :  STUDENT_EDIT  (& user_stack);           	        break;
		case 5 :  RANK_STUDENT  (& user_stack);                   	break;
		case 6 :  STUDENT_SCORE (& user_stack);                     break;
		default: printf("Please enter choose a number from 1 to 6 \n");
		}
	}
}
/*********************************************************************************************************************/
/*Create a new Student using stack List*/
/*it accept only one name at the student name and not implement the address yet*/
void NEW_STUDENT(stack * user_stack)
{
	
	student std_Data;                                        //local variable to store the data of the student
   
    //check_type user_check_type;                            //enum for the user checking type    
   printf("Please enter the student name\n");
   fflush(stdout);
   do
   {
   	    printf("====>");
        scanf(" %[^\n]",std_Data.std_name);
   }while(!(*ptr)(name,std_Data));

	/*printf("Please enter the student ID\n");
	fflush(stdout);
	scanf("%d",&std_Data.std_id);
    */
	printf("Please enter the date of birth \n");
	do
    {
	printf("Day:\n");
	fflush(stdout);
	printf("====>");
	scanf("%d",&std_Data.std_birthDate.day);
	printf("month:\n");
	fflush(stdout);
	printf("====>");
	scanf("%d",&std_Data.std_birthDate.month);
	printf("year:\n");
	fflush(stdout);
	printf("====>");
	scanf("%d",&std_Data.std_birthDate.year);
    }while(!(*ptr)(birth_date,std_Data));
	

	printf("Please enter the phone number\n");
	fflush(stdout);
	do
	{
		printf("====>");
		scanf("%d",&std_Data.std_phone_number);
	}while(!(*ptr)(phone_num,std_Data));
	
	printf("Please enter the address\n");
	printf("====>");
	scanf(" %[^\n]",std_Data.std_address);

    std_Data.GradeOnComputerScience = 0;
	push(std_Data,user_stack);

	printf("A New Student is added Successfully:)\n");
}
/*********************************************************************************************************************/
/*error to delete node in between nodes*/
void DELETE_STUDENT(stack * user_stack)
{
	__uint32__ ID_to_Remove;
	__uint8__ status;
	printf("enter the ID of the student you want to remove\n");
	fflush(stdout);
	printf("====>");
	scanf("%d",&ID_to_Remove);

	status = pop(ID_to_Remove , user_stack);
	if(status)
	{
		printf("the student is removed successfully\n");
		printf("the size after removing = %d\n",user_stack->size);
	}
	else
	{
		printf("No Student with this ID\n");
	}
}
/*********************************************************************************************************************/
void STUDENT_LIST(stack * user_stack)
{
	stacknode * pointerNode = user_stack->top;            //create a pointer to the last element
	stacknode * pointersecondNode = pointerNode->next;    //create a pointer to the last element

	student std;
	int i,j;
	for(i=0 ; i<user_stack->size ; i++)
	{
		for(j=i+1 ; j<user_stack->size ; j++)
		{
			if(strcmp(pointerNode->StackEntry.std_name,pointersecondNode->StackEntry.std_name)>0)
			{
				//SwapNodes(pointerNode,pointersecondNode);
				strcpy(std.std_name,pointerNode->StackEntry.std_name);
				strcpy(pointerNode->StackEntry.std_name,pointersecondNode->StackEntry.std_name);
				strcpy(pointersecondNode->StackEntry.std_name,std.std_name);

				std.std_id = pointerNode->StackEntry.std_id;
				pointerNode->StackEntry.std_id = pointersecondNode->StackEntry.std_id;
				pointersecondNode->StackEntry.std_id =  std.std_id;

				std.std_phone_number = pointerNode->StackEntry.std_phone_number;
				pointerNode->StackEntry.std_phone_number = pointersecondNode->StackEntry.std_phone_number;
				pointersecondNode->StackEntry.std_phone_number =  std.std_phone_number;
				
				std.std_birthDate.day = pointerNode->StackEntry.std_birthDate.day; 
				pointerNode->StackEntry.std_birthDate.day = pointersecondNode->StackEntry.std_birthDate.day;
				pointersecondNode->StackEntry.std_birthDate.day = std.std_birthDate.day;
                std.std_birthDate.month = pointerNode->StackEntry.std_birthDate.month; 
				pointerNode->StackEntry.std_birthDate.month = pointersecondNode->StackEntry.std_birthDate.month;
				pointersecondNode->StackEntry.std_birthDate.month = std.std_birthDate.month;
                std.std_birthDate.year = pointerNode->StackEntry.std_birthDate.year; 
				pointerNode->StackEntry.std_birthDate.year = pointersecondNode->StackEntry.std_birthDate.year;
				pointersecondNode->StackEntry.std_birthDate.year = std.std_birthDate.year;
				

				std.GradeOnComputerScience = pointerNode->StackEntry.GradeOnComputerScience;
				pointerNode->StackEntry.GradeOnComputerScience = pointersecondNode->StackEntry.GradeOnComputerScience;
				pointersecondNode->StackEntry.GradeOnComputerScience = std.GradeOnComputerScience;
			}
			else
			{

			}
			if(pointersecondNode) pointersecondNode = pointersecondNode->next;
		}
		pointerNode = pointerNode->next;
		if(pointerNode)    pointersecondNode = pointerNode->next;
	}
	pointerNode = user_stack->top;
	printf("----------------------------------------------------------\n");
	for(i=0;(i<user_stack->size);i++)
	{
		printf("data of student %d\n",i+1);
		printf("name    : %s\n",pointerNode->StackEntry.std_name);
		printf("ID      : %d\n",pointerNode->StackEntry.std_id);
		printf("Address : %s\n",pointerNode->StackEntry.std_address);
		printf("Date    : %d / %d /%d\n",pointerNode->StackEntry.std_birthDate.day,pointerNode->StackEntry.std_birthDate.month,pointerNode->StackEntry.std_birthDate.year);
		printf("Phone   : %d\n",pointerNode->StackEntry.std_phone_number);
		printf("Grade   : %0.2f\n",pointerNode->StackEntry.GradeOnComputerScience);
		printf("----------------------------------------------------------\n");
		pointerNode = pointerNode->next;
	}
}

/*********************************************************************************************************************/
void STUDENT_EDIT(stack * user_stack)
{
	int section,condition,id,flag=1;
	stacknode * pointerNode;
	/*choose the section to modify*/
	do
	{
		flag = 1;
		printf("enter the student ID\n");
		printf("====>");
	    scanf("%d",&id);
	    
	    pointerNode = user_stack->top;
	    /*search for the ID in the student list*/
	    while(pointerNode->StackEntry.std_id != id )
	    {
		   if(pointerNode->next!=NULL)
		   {
		   	  pointerNode= pointerNode->next;
	       } 
	       else
	       {
	       	flag = 0;
	       	break;
		   }
	    }
	    if(flag == 0 && !(pointerNode->next))
	    {
		    printf("this ID is not exist\n");
		    continue;
	    }

		printf("enter the section you want to modify :\n1-date of birth\n2-phone\n3-address\n");
		printf("====>");
		scanf("%d",&section);
		switch(section)
		{
		case 1 :
			printf("enter the new date of birth\n");
			do
            {
	            printf("Day:\n");
	            printf("====>");
	         	scanf("%d",&pointerNode->StackEntry.std_birthDate.day);
	            printf("month:\n");
	            printf("====>");
	        	scanf("%d",&pointerNode->StackEntry.std_birthDate.month);
	            printf("year:\n");
	            printf("====>");
	        	scanf("%d",&pointerNode->StackEntry.std_birthDate.year);
            }while(!(*ptr)(birth_date,pointerNode->StackEntry));
			break;
		case 2 :
			printf("enter the new phone number\n");
			printf("====>");
			scanf("%d",&pointerNode->StackEntry.std_phone_number);
			break;
		case 3 : 
			printf("enter the new address\n");
			printf("====>");
			scanf(" %[^\n]",&pointerNode->StackEntry.std_address);
			break;		
		}
		printf("the student data is updated if you want to update any other section for the same student press 1 otherwise press 0\n");		fflush(stdout);
		printf("====>");
		scanf("%d",&condition);
	}while(condition);
	printf("\nthank you :)\n");
}


void RANK_STUDENT(stack * user_stack)
{
	stacknode * pointerNode = user_stack->top;            //create a pointer to the last element
	stacknode * pointersecondNode = pointerNode->next;    //create a pointer to the next last element
	student std;
	int i,j;
	for(i=0 ; i<user_stack->size ; i++)
	{
		for(j=i+1 ; j<user_stack->size ; j++)
		{
			if(pointerNode->StackEntry.GradeOnComputerScience<pointersecondNode->StackEntry.GradeOnComputerScience)
			{
				strcpy(std.std_name,pointerNode->StackEntry.std_name);
				strcpy(pointerNode->StackEntry.std_name,pointersecondNode->StackEntry.std_name);
				strcpy(pointersecondNode->StackEntry.std_name,std.std_name);

				std.std_id = pointerNode->StackEntry.std_id;
				pointerNode->StackEntry.std_id = pointersecondNode->StackEntry.std_id;
				pointersecondNode->StackEntry.std_id =  std.std_id;

				std.std_phone_number = pointerNode->StackEntry.std_phone_number;
				pointerNode->StackEntry.std_phone_number = pointersecondNode->StackEntry.std_phone_number;
				pointersecondNode->StackEntry.std_phone_number =  std.std_phone_number;
                
                std.std_birthDate.day = pointerNode->StackEntry.std_birthDate.day; 
				pointerNode->StackEntry.std_birthDate.day = pointersecondNode->StackEntry.std_birthDate.day;
				pointersecondNode->StackEntry.std_birthDate.day = std.std_birthDate.day;
                std.std_birthDate.month = pointerNode->StackEntry.std_birthDate.month; 
				pointerNode->StackEntry.std_birthDate.month = pointersecondNode->StackEntry.std_birthDate.month;
				pointersecondNode->StackEntry.std_birthDate.month = std.std_birthDate.month;
                std.std_birthDate.year = pointerNode->StackEntry.std_birthDate.year; 
				pointerNode->StackEntry.std_birthDate.year = pointersecondNode->StackEntry.std_birthDate.year;
				pointersecondNode->StackEntry.std_birthDate.year = std.std_birthDate.year;

				std.GradeOnComputerScience = pointerNode->StackEntry.GradeOnComputerScience;
				pointerNode->StackEntry.GradeOnComputerScience = pointersecondNode->StackEntry.GradeOnComputerScience;
				pointersecondNode->StackEntry.GradeOnComputerScience = std.GradeOnComputerScience;

				strcpy(std.std_address,pointerNode->StackEntry.std_address);
				strcpy(pointerNode->StackEntry.std_address,pointersecondNode->StackEntry.std_address);
				strcpy(pointersecondNode->StackEntry.std_address,std.std_address);		
			}
			else
			{

			}
			if(pointersecondNode) pointersecondNode = pointersecondNode->next;
		}
		pointerNode = pointerNode->next;
		if(pointerNode)    pointersecondNode = pointerNode->next;
	}
	pointerNode = user_stack->top;
	
	//printf("\narrangement according to score\n");
	for(i=0;(i<user_stack->size);i++)
	{
		printf("data of student %d\n",i+1);
		printf("name    : %s\n",pointerNode->StackEntry.std_name);
		printf("ID      : %d\n",pointerNode->StackEntry.std_id);
		printf("Address : %s\n",pointerNode->StackEntry.std_address);
		printf("Date    : %d / %d /%d\n",pointerNode->StackEntry.std_birthDate.day,pointerNode->StackEntry.std_birthDate.month,pointerNode->StackEntry.std_birthDate.year);
		printf("Phone   : %d\n",pointerNode->StackEntry.std_phone_number);
		printf("Grade   : %0.2f\n",pointerNode->StackEntry.GradeOnComputerScience);
		printf("----------------------------------------------------------\n");
		pointerNode = pointerNode->next;
	}
}

void STUDENT_SCORE(stack * user_stack)
{
	int condition,id,flag=1;
	stacknode * pointerNode ;
	/*choose the section to modify*/
	do
	{
	    flag = 1;
		printf("enter the student ID\n");
		printf("====>");
	    scanf("%d",&id);
	    
	    pointerNode = user_stack->top;
	    /*search for the ID in the student list*/
	    while(pointerNode->StackEntry.std_id != id )
	    {
		   if(pointerNode->next!=NULL)
		   {
		   	  pointerNode= pointerNode->next;
	       } 
	       else
	       {
	       	flag = 0;
	       	break;
		   }
	    }
	    if(flag == 0 && !(pointerNode->next))
	    {
		    printf("this ID is not exist\n");
		    continue;
	    }
	    else
	    {
	    	do{
	    	     printf("enter the new grade of the student\n");
	    	     printf("====>");
		         scanf("%f",&pointerNode->StackEntry.GradeOnComputerScience);		
			}while(!(*ptr)(grade,pointerNode->StackEntry));

		}
		printf("the student data is updated if you want to update the score of another student press 1 otherwise press 0\n");
		printf("====>");
		scanf("%d",&condition);	
	}while(condition);
	printf("\nthank you :)\n");
}

__uint8__ check_validation(check_type type,student std)
{
	int i = 0;
	int min_year = 1990;
	int max_year = 2018;
    switch(type)
	{
		//check on name
		case name : 
		while(std.std_name[i] != '\0')
		{
			if(((std.std_name[i]>'A') &&(std.std_name[i]>'Z')) || ((std.std_name[i]>'a') &&(std.std_name[i]>'z'))||(std.std_name[i] == ' '))
			{
				i++;
			}
			else
			{
				printf("the name must contail only alphapitical litters\ntry again:\n");
				return 0;
			} 
		}
		return 1;
		break;
		//check on grade
		case grade :
			if(std.GradeOnComputerScience > 100 || std.GradeOnComputerScience <0)
			{
				printf("grade must be from 0 to 100\ntry again");
				return 0;
			}
			return 1;
		break;
		//check on date of birth
		case birth_date:

		     if(std.std_birthDate.day>0&&std.std_birthDate.day<30)
			 {
			 	if(std.std_birthDate.month>0&&std.std_birthDate.month<12)
			 	{
			 		if(std.std_birthDate.year>=min_year&&std.std_birthDate.year<=max_year)
			 		{
			 			return 1;
					}
					else
					{
						printf("the year of birth must be from %d to %d\ntry again:\n",min_year,max_year);
						return 0;
					}
				}
				else
				{
					printf("invalid month\ntry again:\n");
					return 0;
				}
			 }
			 else
			 {
			 	printf("invalid day\ntry again:\n");
			 	return 0;
			 }	
		break;
	}	
}
