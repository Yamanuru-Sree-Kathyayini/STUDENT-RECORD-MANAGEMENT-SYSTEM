
#include "student.h"
void Show_the_list(struct student *p)
{
	if(p==0)
	{
		printf("no students records avialable\n");
		return ;
	}
	printf("----------------------------------------\n");
	printf("RollNo	 Name  Percentage\n");	
	printf("----------------------------------------\n");
	while(p)
	{
		printf("%d     %s     %f\n",p->rollno,p->name,p->percentage);
		p=p->next;
	}
	printf("----------------------------------------\n");
}
