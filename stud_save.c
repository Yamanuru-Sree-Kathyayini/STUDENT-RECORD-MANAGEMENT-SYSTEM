#include "student.h"

void Save_records(struct student *p)
{

	FILE *fp=fopen("student.dat","w");
	if(fp==0)
	{
		printf("no records found\n");
		return ;
	}
	while(p)
	{
		fprintf(fp,"%d  %s  %f \n",p->rollno,p->name,p->percentage);
		p=p->next;
	}
	fclose(fp);
}

void load_record(struct student **p)
{
	FILE *fp=fopen("student.dat","r");
	if(fp==0)
	{
		printf("no records found\n");
		return ;
	}
	struct student *new,*last;
	char name[20];
	int rollno;
	float percentage;
	while(fscanf(fp,"%d%s%f",&rollno,name,&percentage)==3)
	{
		new=malloc(sizeof(struct student));
		new->rollno=rollno;
		strcpy(new->name,name);
		new->percentage=percentage;
		new->next=NULL;
		if(*p==0)
			*p=new;
		else
		{
			last = *p;
			while(last->next)
				last=last->next;
			last->next=new;
		}
	}
	fclose(fp);
}

void Exit(struct student **p)
{
	char op;
	printf("S/s : Save and exit\nE/e : Exit without saving\n");
	printf("choose the option:");
	scanf(" %c",&op);
	switch(op)
	{
		case 's':
		case 'S':
			Save_records(*p);
			Delete_all_the_records(p);
			exit(0);
		case 'e':
		case 'E':
			Delete_all_the_records(p);
			exit(0);
	}
}
