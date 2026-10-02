#include "student.h"

void Add_new_record(struct student **p)
{
	struct student *new,*t;
	int roll = 1;
	int flag;
	new = malloc(sizeof(struct student));
	if (new == NULL)
	{
		printf("Memory allocation failed\n");
		return;
	}
	while (1)
	{
		t = *p;
		flag = 0;
		while (t!= NULL)
		{
			if (t->rollno == roll)
			{
				flag = 1;
				break;
			}
			t= t->next;
		}
		if (flag == 0)
			break;
		roll++;
	}
	new->rollno = roll;

	printf("Enter name: ");
	scanf(" %s", new->name);
	do
	{
		printf("Enter percentage: ");
		scanf("%f", &new->percentage);
		if (new->percentage < 0 || new->percentage > 100)
		{
			printf("Invalid percentage\n");
		}
	} while (new->percentage < 0 || new->percentage > 100);
	if(*p==0||(*p)->rollno>new->rollno)
	{
		new->next = *p;
		*p = new;
	}
	else
	{
		t=*p;
		while(t->next !=0 &&t->next->rollno < new->rollno)
			t=t->next;
		new->next=t->next;
		t->next=new;
	}
}
