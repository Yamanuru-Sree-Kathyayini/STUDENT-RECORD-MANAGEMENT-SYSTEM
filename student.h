#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<unistd.h>

struct student
{
int rollno;
char name[50];
float percentage;
struct student *next;
};

extern struct student *hptr;

//void load(struct student **);
void Exit(struct student **);
void  Add_new_record(struct student **);
void Delete_a_record(struct student **);
void Show_the_list(struct student *);
void Modify_a_record(struct student **);
void Save_records(struct student *);
void Sort_the_list(struct student *);
void Delete_all_the_records(struct student **);
void Reverse_the_list(struct student **);
