#include "student.h"

void load_record(struct student **);
int main()
{
struct student *hptr=0;
load_record(&hptr);
	int c;
	char op;
	while(1)
	{
		printf("******** STUDENT RECORD MENU ********\na/A : Add new record\nd/D : Delete a record\ns/S : Show the list\nm/M : Modify a record\nv/V : Save records\ne/E : Exit\nt/T : Sort the list\nl/L : Delete all the records\nr/R: Reverse the list\n");
		printf("enter your choice:");
		scanf(" %c",&op);
		switch(op)
		{
			case 'a' :
			case 'A' : 
				Add_new_record(&hptr);break;
			case 'd':
			case 'D': 
				Delete_a_record(&hptr);break;
			case 's':
			case 'S': 
				Show_the_list(hptr);break;
			case 'm':
			case 'M': 
				Modify_a_record(&hptr);break;
			case 'v':
			case 'V': 
				Save_records(hptr);break;
			case 'e':
			case 'E': 
				Exit(&hptr);break;
			case 't':
			case 'T': 
				Sort_the_list(hptr);break;
			case 'l':
			case 'L':
				Delete_all_the_records(&hptr);break;
			case 'r':
			case 'R':
				Reverse_the_list(&hptr);break;
			default:printf("unknown option\n");
		}
	}
}
