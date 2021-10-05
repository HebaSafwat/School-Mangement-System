/*
 * Name        : LinkedList.h
 * Created on  : 23/9/2021
 * Version     : v00
 * Author      : Heba Safwat
 * Description : this file contain the functions prototype of the Stack List
 */
#ifndef StackLIST_H_
#define StackLIST_H_

/********************************************************************************************
 *                                                                                          *
 *                                        Includes                                          *
 *                                                                                          *
 *********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data_types.h"



/********************************************************************************************
 *                                                                                          *
 *                                    Data structure                                        *
 *                                                                                          *
 *********************************************************************************************/
typedef struct date
{
	__uint8__ day;
	__uint8__ month;
	__uint32__ year;
}BirthDate;
typedef struct Student
{
	__uint8__   std_name[100] ;
	BirthDate   std_birthDate;
	__uint32__  std_id ;
	__uint8__   std_address[100];
	__uint32__  std_phone_number ;
	__float32__   GradeOnComputerScience;
    //__uint8__   std_birthDate[10] ;
}student;

typedef struct Stacknode
{
	student StackEntry;
	struct Stacknode * next;
}stacknode;

typedef struct Stack
{
	stacknode * top;
	int size ;
}stack;

/********************************************************************************************
 *                                                                                          *
 *                                 Functions Prototypes                                     *
 *                                                                                          *
 *********************************************************************************************/
/*
pre : none
post: Create a node
*/
void CreateStack(stack *);
/*
pre : Stack is Created
post: insert new node
*/
void push(student ,stack *);
/*
pre : Stack is Created and isn't empty
post: delete the last node and return 1 case success to delete and 0 case fail to delete
*/
__uint8__ pop(__uint32__ node_ID,stack * pointerStack);

#endif /* StackLIST_H_ */

