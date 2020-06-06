/*Contains all functions required to handle records in file*/
#include"Filefunctions.h"
dept* add(dept* d,int x,FILE *fp,int* flag)
{	
	int i;
	char y[14],ch;
	printf("\t\tTelephone Directory Maintenance System\n");
	printf("\t\t--------------------------------------\n");
	printf("\t\t--------------------------------------\n");
	printf("\t\t\tAdd a Department\n");
	printf("\t\t\t----------------\n");
	printf("\t\t\t----------------\n");
	printf("\t\tEnter the name of Dept:");
	scanf("%s",y);
	y[15]='\0';
	for(i=0;i<x;i++)
	{
		if(strcasecmp(y,d[i].name)==0)	
		{
			*flag=0;
			return d;
		}
	}
	i--;
	*flag=1;
	d[i].code=(x-1)+1000;
	strcpy(d[i].name,y);
	printf("\t\tDepartment code:%d\n",d[i].code);
//	printf("%d\t%s\n",d[i].code,d[i].name);
	fp=fopen("dept.txt","a");
	fprintf(fp,"%d\t%s\n",d[i].code,d[i].name);
	fclose(fp);
	printf("\n");
	printf("\t\tPress any key to continue\n");
	scanf(" %c",&ch);
	return d;
}
dept* view(dept *d,int x,int *flag)
{
	int i;
	printf("\t\tdepartmentcode    departmentname\n");
	if(*flag==0) x--;
	for(i=0;i<x;i++)
	{
		printf("\t\t%d\t\t\t%s\n",d[i].code,d[i].name);
	}
	return d;
}
emp* add_emp(emp *e,int x,FILE* fp,int *flag,dept *d,int d_count)
{
        int i,l=0,code,j,z;
        char y[25],loc[5],ch;
	printf("\t\tWelcome to telephone directory\n");
        printf("\t\t------------------------------\n");
        printf("\t\t------------------------------\n");
        printf("\n");
        printf("\t\t\tAdd a Employee\n");
        printf("\t\t\t----------------\n");
        printf("\t\t\t----------------\n");
        printf("\t\tEnter Employee Name:");
        scanf("%s",y);
        y[25]='\0';
	j=x-1;
        *flag=1;
	int k=(x-1)+1000;
	printf("\n\t\tEmployee id:%d\n",k);
	printf("\t\tdepartmentcode\tdepartmentname\n");
	for(i=0;i<d_count;i++)
		printf("\t\t%d\t\t\t%s\n",d[i].code,d[i].name);
	printf("\t\tEnter Department code:");
	scanf("%d",&code);
	for(i=0;i<d_count;i++)
	{
		if(d[i].code==code)
		{
			printf("\n\t\tDepartment Name:%s\n",d[i].name);
			break;
		}
	}
	if(d[i].code!=code)
	{
		printf("\t\tInvalid Code\n");
		*flag=0;
		return e;
	}
	e[j].tel_no=0;
        e[j].e_id=k;
	e[j].d_code=code;
        strcpy(e[j].e_name,y);
	strcpy(e[j].d_name,d[i].name);
	printf("\t\tEnter location:");
	scanf("%s",loc);
	printf("\n");
	loc[5]='\0';
	strcpy(e[j].loc,loc);
        fp=fopen("emp.txt","a");
        fprintf(fp,"%d\t%s\t\t\t%d\t%s\t\t%s\t%d\n",e[j].e_id,e[j].e_name,e[j].d_code,e[j].d_name,e[j].loc,e[j].tel_no);
        fclose(fp);
        printf("\t\tPress any key to continue\n");
        scanf(" %c",&ch);
        return e;
}
emp* print(emp* e,int x,int* flag)
{
	int i;
	printf("\t\tEmp_id  \tEmp_name  \tDept_code  \tDept_name  \tLocation\n");
	if(*flag==0)
		 x--;
        for(i=0;i<x;i++)
        {
                printf("\t\t%d\t\t%s\t\t%d\t\t%s\t\t%s\n",e[i].e_id,e[i].e_name,e[i].d_code,e[i].d_name,e[i].loc);

        }
        return e;
}
emp* add_telno(emp* e,int x,FILE *fptr)
{
	int id,i,w=1,no,z;
	char ch;
	printf("\t\tWelcome to telephone directory\n");
        printf("\t\t------------------------------\n");
        printf("\t\t------------------------------\n");
        printf("\n");
        printf("\t\t\tAdd a Telephone Number\n");
        printf("\t\t\t----------------\n");
        printf("\t\t\t----------------\n");
	printf("\t\tEnter Employee id:");
	scanf("%d",&id);
		for(i=0;i<x;i++)
		{
			if(id==e[i].e_id)
			{
			printf("\t\tLocation=%s\n\t\tDeparment code=%d\n",e[i].loc,e[i].d_code);
				break;
			}
		}
		if(id!=e[i].e_id)
		{
			printf("\t\tInvalid employee id\n");
			return e;
		}
	no=(e[i].d_code)*1000+w;
	for(z=0;z<x;z++)
	{
		if(no==e[z].tel_no)
		{
			w++;
			no++;
		}
	}
	e[i].tel_no=(e[i].d_code)*1000+w;
	printf("\t\tTelephone Number Allocated=%d\n",e[i].tel_no);
	fptr=fopen("emp.txt","w");
	for(i=0;i<x;i++)
	{
                fprintf(fptr,"%d\t%s\t\t\t%d\t%s\t\t%s\t%d\n",e[i].e_id,e[i].e_name,e[i].d_code,e[i].d_name,e[i].loc,e[i].tel_no);
	}
	fclose(fptr);
	printf("\t\tPress any key to continue\n");
        scanf(" %c",&ch);
	return e;
}
emp* enquiry(emp *e,int x,int ch)
{
	int count=0,i,no;
	char name[25];
	printf("\t\tWelcome to telephone directory\n");
        printf("\t\t------------------------------\n");
        printf("\t\t------------------------------\n");
        printf("\n");
	if(ch==1)
	{
		printf("\t\t\tTelephone Number enquiry by Name\n");
       		printf("\t\t\t----------------\n");
       		printf("\t\t\t----------------\n");
		printf("\t\tEnter employee name:");
		scanf("%s",name);
		for(i=0;i<x;i++)
		{
			if(strcasecmp(e[i].e_name,name)==0)
			{
				printf("\t\tEmployeeName  DepartmentName  Location  Telephone no.\n");
				 printf("\t\t%s\t\t%s\t\t%s\t%d\n",e[i].e_name,e[i].d_name,e[i].loc,e[i].tel_no);
				count++;
			}
		}
		if(count==0)
		{
			printf("\t\tInvalid name\n");
			return e;
		}
	}
	if(ch==2)
	{	
		printf("\t\t\tTelephone Number enquiry\n");
                printf("\t\t\t----------------\n");
                printf("\t\t\t----------------\n");
		count=0;
		printf("\t\tEnter Telephone number:");
		scanf("%d",&no);
		for(i=0;i<x;i++)
                {
                        if(e[i].tel_no==no)
                        {
				printf("\t\tEmployeeName  DepartmentName  Location\n");
                                 printf("\t\t%s\t\t%s\t\t%s\n",e[i].e_name,e[i].d_name,e[i].loc);
                                count++;
                        }
                }
                if(count==0)
                {
                        printf("\t\tInvalid number\n");
                      return e;
		}
	}
		return e;
	
}
