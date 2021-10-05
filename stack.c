/*
 * Name        : StackList.c
 * Created on  : 23/9/2021
 * Version     : v00
 * Author      : Heba Safwat
 * Description : this file contain the functions definition of the Stack List
 */

/********************************************************************************************
 *                                                                                          *
 *                                       Includes                                           *
 *                                                                                          *
 *********************************************************************************************/
#include "stack.h"

/********************************************************************************************
 *                                                                                          *
 *                                 Functions Definition                                     *
 *                                                                                          *
 *********************************************************************************************/
void CreateStack (stack * pointerStack)
{
	pointerStack->top = NULL;                   //initialize the top of the stack to NULL
	pointerStack->size = 0;                     //initialize the size of the stack to zero
}

void push (student std,stack * pointerStack)
{
	static id = 0;                   
	stacknode * pointerNode = (stacknode * )malloc(sizeof(stacknode));     //create a node
	//insert the node at the top of the stack
	pointerNode->next = pointerStack->top;
	pointerStack->top = pointerNode;

	//initialize the node with the student data
	strcpy(pointerNode->StackEntry.std_name,std.std_name);
	pointerNode->StackEntry.std_id = ++id;
	strcpy(pointerNode->StackEntry.std_address,std.std_address);
	pointerNode->StackEntry.std_birthDate.day = std.std_birthDate.day ;
	pointerNode->StackEntry.std_birthDate.month = std.std_birthDate.month ;
	pointerNode->StackEntry.std_birthDate.year = std.std_birthDate.year ;
	pointerNode->StackEntry.std_phone_number = std.std_phone_number;
	pointerNode->StackEntry.GradeOnComputerScience = std.GradeOnComputerScience;
	pointerStack->size++;           //increment the size of the stack
}

/*function to delete a node from the stack*/
__uint8__ pop(__uint32__ node_ID,stack * pointerStack)
{
	stacknode * pointerNode1 = pointerStack->top;          //pointer to the previes nod of the nade we want to delete
	stacknode * pointerNode2 = pointerStack->top;          //pointer to the node we want to delete
	__uint8__ i ;
	__uint8__ flag = 0;
	//loop till find the Node that contain the same ID
	for(i=0;i<pointerStack->size;i++)
	{
		if(pointerNode2->StackEntry.std_id == node_ID)
		{
			flag = 1;
			break;
		}
		else
		{
			pointerNode1=pointerNode2;
			if(pointerNode2)   pointerNode2 = pointerNode2->next;
		}
	}
	if(flag == 1)
	{
		if(pointerNode1 == pointerNode2)         //case the node you want to delete is the first node
		{
			pointerStack->top = pointerStack->top->next;
			free(pointerNode2);
		}
		else
		{
			pointerNode1->next = pointerNode2->next;
			free(pointerNode2);
		}
		pointerStack->size--;
		return 1;  //delete successfully
	}
	else
	{
		return 0; //delete failed
	}
}

