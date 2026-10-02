#include "student.h"


void Modify_a_record(struct student **p)
{
	char o;
	char name[20];
	int rollno;
	float percentage;
	struct student *ptr=*p;
	printf("R/r : Search by roll number\nN/n : Search by name\nP/p : Search by percentage\n");
	printf("enter the option:");
	scanf(" %c",&o);
	switch(o)
	{
		case 'r':
		case 'R':
			printf("enter rollno:");
			scanf("%d",&rollno);
			while(ptr)
			{
				if(ptr->rollno==rollno)
				{
					printf("%d  %s  %f\n",ptr->rollno,ptr->name,ptr->percentage);
					printf("enter name and percentage which is to be updated :");
					scanf("%s%f",ptr->name,&ptr->percentage);
					break;
				}
				ptr=ptr->next;
			}
			if (ptr == NULL)
			{
				printf("Record with roll number %d not found\n", rollno);
			}

			break;
		case 'n':
		case 'N':
			printf("enter name:");
			scanf(" %s", name);
			int flag = 0,search_roll;
			ptr = *p;
			while(ptr)
			{
				if(strcmp(ptr->name, name) == 0)
				{
					printf("%d  %s  %f\n",ptr->rollno,ptr->name,ptr->percentage);
					flag = 1;
				}
				ptr = ptr->next;
			}
			if(flag == 0)
			{
				printf("Record with name %s not found\n", name);
				return;
			}
			printf("Enter roll number of the record to modify:");
			scanf("%d", &search_roll);
			ptr = *p;
			while(ptr)
			{
				if(ptr->rollno == search_roll && strcmp(ptr->name, name) == 0)
				{
					printf("Current details:\n");
					printf("%d  %s  %f\n",ptr->rollno,ptr->name,ptr->percentage);
					printf("enter name and percentage which is to be updated:");
					scanf(" %s%f", ptr->name, &ptr->percentage);
					return;
				}
				ptr = ptr->next;
			}
			printf("Record with roll number %d not found\n", search_roll);
			break;
		case 'p':
		case 'P':
			printf("enter percentage:");
			scanf("%f", &percentage);
			flag = 0;
			ptr = *p;
			while(ptr)
			{
				if(ptr->percentage == percentage)
				{
					printf("%d  %s  %f\n",ptr->rollno,ptr->name,ptr->percentage);
					flag = 1;
				}
				ptr = ptr->next;
			}
			if(flag == 0)
			{
				printf("Record with percentage %f not found\n",percentage);
				return;
			}
			printf("Enter roll number of the record to modify:");
			scanf("%d", &search_roll);
			ptr = *p;
			while(ptr)
			{
				if(ptr->rollno == search_roll &&ptr->percentage == percentage)
				{
					printf("Current details:\n");
					printf("%d  %s  %f\n",ptr->rollno,ptr->name,ptr->percentage);
					printf("enter name and percentage which is to be updated:");
					scanf(" %s%f", ptr->name, &ptr->percentage);
					return;
				}
				ptr = ptr->next;
			}
			printf("Record with roll number %d not found\n",search_roll);
			break;
		default:
			printf("Invalid option\n");
	}
}


int  countnode(struct student *p)
{
	int c=0;
	while(p)
	{
		c++;
		p=p->next;
	}
	return c;
}

void Sort_the_list(struct student *p)
{
	if(p==0)
	{
		printf("no records are found\n");
		return ;
	}
	struct student *p1=p,*p2,t;
	int i,j,c=countnode(p);
	char opt;
	printf("N/n : Sort with name\nP/p : Sort with percentage\n");
		printf("enter the option:");
	scanf(" %c",&opt);
	switch(opt)
	{
		case 'n':
		case 'N':
			for(i=0;i<c-1;i++)
			{
				p2=p1->next;
				for(j=0;j<c-i-1;j++)
				{
					if(p1->name[0] < p2->name[0])
					{
						t.rollno=p1->rollno;
						strcpy(t.name,p1->name);
						t.percentage=p1->percentage;
						p1->rollno=p2->rollno;
						strcpy(p1->name,p2->name);
						p1->percentage=p2->percentage;
						p2->rollno=t.rollno;
						strcpy(p2->name,t.name);
						p2->percentage=t.percentage;
					}
					p2=p2->next;
				}
				p1=p1->next;
			}
			break;
		case 'p':
		case 'P':
			for(i=0;i<c-1;i++)
			{
				p2=p1->next;
				for(j=0;j<c-1-i;j++)
				{
					if(p1->percentage < p2->percentage)
					{
						t.rollno=p1->rollno;
						strcpy(t.name,p1->name);
						t.percentage=p1->percentage;
						p1->rollno=p2->rollno;
						strcpy(p1->name,p2->name);
						p1->percentage=p2->percentage;
						p2->rollno=t.rollno;
						strcpy(p2->name,t.name);
						p2->percentage=t.percentage;
					}
					p2=p2->next;
				}
				p1=p1->next;
			}
			break;
           default:printf("invalid option\n");
	}
}

void Reverse_the_list(struct student **p)
{
	if(*p==0)
	{
		printf("no records found\n");
		return ;
	}
	int i,c=countnode(*p);
	struct student **a,*t=*p;
	if(c>1)
	{
		a=malloc(sizeof(struct student *)*c);
		for(i=0;i<c;i++)
		{
			a[i]=t;
			t=t->next;
		}
		for(i=c-1;i>0;i--)
			a[i]->next=a[i-1];

		a[0]->next=0;
		*p=a[c-1];
	}
}

