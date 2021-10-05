/*
 * Name        : student.h
 * Created on  : 23/9/2021
 * Version     : v00
 * Author      : Heba Safwat
 * Description : this file contain the functions prototypes of each student
 */

#ifndef STUDENT_H_
#define STUDENT_H_

/********************************************************************************************
 *                                                                                          *
 *                                        Includes                                          *
 *                                                                                          *
 *********************************************************************************************/
#include <stdio.h>
#include <string.h>
#include "data_types.h"
#include "stack.h"

/********************************************************************************************
 *                                                                                          *
 *                                    Data structure                                        *
 *                                                                                          *
 *********************************************************************************************/
typedef enum
{
	name,phone_num,grade,birth_date,id
}check_type;

/********************************************************************************************
 *                                                                                          *
 *                                 Functions Prototypes                                     *
 *                                                                                          *
 *********************************************************************************************/
/*
 * pre  : None
 * post : displays the welcome screen and targeted activates.
 */
void MAIN_MENU (void);
/*
 * pre  : None
 * post : creates a new student account. it asks about details of the student such as name, date of birth, ID, address and phone number.
 */
void NEW_STUDENT(stack * user_stack);
/*
 * pre  : Student is Created
 * post : Delete a student account.
 */
void DELETE_STUDENT(stack * user_stack);
/*
 * pre  : Student is Created
 * post : view the students information (alphabetically ascending).
 */
void STUDENT_LIST(stack * user_stack);
/*
 * pre  : Student is Created
 * post : update a particular student account.
 */
void STUDENT_EDIT(stack * user_stack);
/*
 * pre  : Student is Created
 * post :  sort all students according to computer science score.
 */
void RANK_STUDENT(stack * user_stack);
/*
 * pre  : Student is Created
 * post : has been used for updating score of all students.
 */
void STUDENT_SCORE(stack * user_stack);

#endif /* STUDENT_H_ */

