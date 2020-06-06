/*Contains code for main menu and department menu*/
#include"Filefunctions.h"
int* choice(int *a,emp *e,dept *d,int x)            //menu
{
	int i,id;
	char ch;
	printf("\n\n\n");
	printf("\t\tWelcome to telephone directory\n");
	printf("\t\t------------------------------\n");
	printf("\t\t------------------------------\n");
	printf("\n");
	printf("\t\t\tMain Menu\n");
	printf("\t\t\t---------\n");
	printf("\t\t\t---------\n");
	printf("\t\t\t1.Department Maintenance\n\t\t\t2.Employee Maintenance\n\t\t\t3.Telephone Directory Maintenance\n\t\t\t4.Exit\n");
	printf("\t\t\tEnter ur choice:");
	scanf("%d",&a[0]);
	printf("\n\n\n");
        printf("\n");
	switch(a[0])
	{
		case 1:	printf("\t\tWelcome to telephone directory\n");
                        printf("\t\t------------------------------\n");
                        printf("\t\t------------------------------\n");
			printf("\t\t\tDepartment maintainance\n");
       			printf("\t\t\t-----------------------\n");
 		        printf("\t\t\t-----------------------\n");
 			printf("\t\t\t1.Add Department\n\t\t\t2.Print Department Details\n\t\t\t3.Mainmenu\n");
			break;
		case 2:	printf("\t\tWelcome to telephone directory\n");
       		        printf("\t\t------------------------------\n");
    	        	printf("\t\t------------------------------\n");
			printf("\t\t\tEmployee Maintenace Menu\n");
       	        	printf("\t\t\t-----------------------\n");
     		        printf("\t\t\t-----------------------\n");
		        printf("\t\t\t1.Add Employee\n\t\t\t2.Print Employee Details\n\t\t\t3.Mainmenu\n");
			break;
		case 3:printf("\t\t\tTelephone Directory Maintenance Menu\n");
       	        	printf("\t\t\t-----------------------\n");
       	        	printf("\t\t\t-----------------------\n");
			printf("\t\t\t1.Add Telephone Number\n\t\t\t2.Telephone Enquiry Menu\n\t\t\t3.MainMenu\n");	
			break;
		case 4:free(d);
		       free(e);
		       exit(0);
			printf("Goodbye\n");
			break;
	}
	printf("\t\t\tEnter ur choice:");
	scanf("%d",&a[1]);
	printf("\n\n\n");
	return a;	
}
