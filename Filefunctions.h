/*Header file which contains declarations of all functions and constants in Filefunctions.c*/
#ifndef Filefunctions
#define Filefunctions
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct department     //department structure
{
	int code;
	char name[14];
}dept;
typedef struct employee		//Employee structure
{
	char e_name[25];
	int e_id;
	char loc[5];
	int d_code;
	char d_name[14];
	int tel_no;
}emp;	
dept* add(dept*,int,FILE*,int*);  //Function used to add new department
dept* view(dept*,int,int*);	  //Function used to view all departments
emp* add_emp(emp*,int,FILE*,int*,dept*,int); //Function used to add a new employee
emp* print(emp*,int,int*);	//Function to print employee details
emp* add_telno(emp*,int,FILE*); //Function to add Telephone number to an employee
emp* enquiry(emp*,int,int);	//Function used to enquire about telephone number
int* choice(int*,emp*,dept*,int);	//Function used for display of menu
#endif
