#include "student.h"

void Delete_a_record(struct student **p)
{
	if(*p==0)
	{
		printf("no records found\n");
		return ;
	}
	char name[20];
	int opt,rollno,i,j;
	struct student *prev,*del=*p;
	printf("enter opt:");
	printf("1.delete a node using rollno\n2.delete a node using name\n");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1:
			printf("Enter a rollno to delete:");
			scanf("%d",&rollno);
			while(del)
			{
				if(del->rollno==rollno)
				{
					if(del==*p)
						*p=del->next;
					else
						prev->next=del->next;
					free(del);
					return ;
				}
				prev=del;
				del=del->next;
			}
			printf("rollno is not found\n");
			break;

		case 2:
			printf("Enter a name to delete:");
			scanf(" %s",name);
			while(del)
			{
				if(strcmp(name,del->name)==0)
				{
					if(del==*p)
						*p=del->next;
					else
						prev->next=del->next;
					free(del);
					return ;
				}
				prev=del;
				del=del->next;
			}
			printf("name is not found\n");
			break;
		default:
			printf("unknowm option\n");
	}
}

void Delete_all_the_records(struct student **p)
{
	if(*p==0)
	{
		printf("no record founnd\n");
		return ;
	}
	struct student *del=*p;
	while(del)
	{
		*p=del->next;
		free(del);
		del=*p;
	}
	printf("all nodes are deleted\n");
}
