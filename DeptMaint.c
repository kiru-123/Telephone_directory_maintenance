#include"Filefunctions.h"
dept* create(int,dept*);   //creates a new block of department
emp* create_emp(int,emp*); //creates a new block for employee
int main()
{
	FILE *fp;
	FILE *fptr;
	int ch,l_count=0,i=0,n,countlines=0,x=0,flag=1,flag1=1,id,*p,a[2],no,j,id1;
	char *s,e_name[25],loc[5];
	char c,ch1;
	system("clear");     //clears screen
	fp=fopen("dept.txt","r"); //opens dept.txt in read mode
	if(!fp)
        {
                printf("Unable to open file\n");
                exit(0);
        }
        for(c=getc(fp);c!=EOF;c=getc(fp))      //used to count the no. of lines in file
        {
                if(c=='\n')
                        countlines++;
        }
	dept *d=(dept*)malloc(countlines*sizeof(dept));//creates dept structure dynamically
	rewind(fp);				//file pointer points to start of file
	while(fscanf(fp,"%d %s",&n,s)!=EOF)  //load the contents of file in structure
        { 
                strcpy(d[x].name,s);
                d[x].code=n;
                x++;
        }
	fclose(fp);		//closes file
	n=0;
	c=0;
	fptr=fopen("emp.txt","r");     //opens emp.txt in read mode
	if(!fptr)
        {
                printf("Unable to open file\n");
                exit(0);
        }
	for(c=getc(fptr);c!=EOF;c=getc(fptr))    //used to count the no. of lines in file
        {
                if(c=='\n')
                       l_count++;
        }
	emp *e=(emp*)malloc(l_count*sizeof(emp));//creates emp structure dynamically
	rewind(fptr);			   //file pointer points to start of file
	 //load the contents of file in structure
	while(fscanf(fptr,"%d %s %d %s %s %d",&id,e_name,&n,s,loc,&no)!=EOF)
	{
		strcpy(e[i].e_name,e_name);
		e[i].d_code=n;
		e[i].e_id=id;
		strcpy(e[i].d_name,s);
		strcpy(e[i].loc,loc);
		e[i].tel_no=no;
		i++;
	}
	fclose(fptr); //close file
	printf("\t\tWelcome to telephone directory\n");
        printf("\t\t------------------------------\n");
        printf("\t\t------------------------------\n");
        printf("\n");
        printf("\t\t\tLogin Screen\n");
        printf("\t\t\t------------\n");
        printf("\t\t\t------------\n");
        printf("Enter user ID:");
        scanf("%d",&id1);
        for(j=0;j<i;j++)
        {
                if(e[j].e_id==id)
                break;
        }
        if(e[j].e_id!=id)
        {
                printf("Login Denied\n");
                scanf("%c",&ch1);
                exit(0);
        }
	while(1)
	{
		p=choice(a,e,d,i);
		switch(*p)
		{
			case 1:switch(*(p+1))
				{
					case 1:if(flag==1)
						{
							x++;
							d=create(x,d);
						}
						d=add(d,x,fptr,&flag);
						break;
					case 2:d=view(d,x,&flag);
						break;
					case 3:continue;
						break;
				}
				break;
			case 2:switch(*(p+1))
				{
					case 1:if(flag1==1)
						{
							i++;
							e=create_emp(i,e);
						}
						e=add_emp(e,i,fptr,&flag1,d,x);
						break;
					case 2:e=print(e,i,&flag1);
						break;
					case 3:continue;
						break;
				}
				break;
			case 3:switch(*(p+1))
				{
					case 1:e=add_telno(e,i,fptr);
						break;
					case 2:printf("\t\t\t1.enquiry by employee name\n\t\t\t2.Enquiry by Telephone number\n\t\t\t3.Goto Mainmenu\n");
						printf("Enter ur choice:");
						scanf("%d",&ch);
						if(ch==1 || ch==2)
						e=enquiry(e,i,ch);
						if(ch==3)continue;
						break;
					case 3:continue;
						break;
				}
				break;
		}	
	}
	return(0);
}
dept* create(int l_count,dept* ptr)       //increases size of department structure
{	
	dept* ptr_new;
	ptr_new=(dept*)realloc(ptr,l_count*sizeof(dept));
	return ptr_new;
}
emp* create_emp(int count,emp* point)     //increases size of employee structure
{
	emp* new_ptr;
	new_ptr=(emp*)realloc(point,count*sizeof(emp));
	return new_ptr;
}


