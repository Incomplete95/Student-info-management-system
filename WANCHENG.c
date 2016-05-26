#include<stdio.h>
#include<stdlib.h>
#define NULL 0
#define LEN sizeof(struct stu)
#define P printf
struct stu
{int num;
int score;
char name[60];
struct stu * next;
};
int n;
struct stu *head;

struct stu *creat(void)
{struct stu * p1, * p2;
n=0;
p1=p2=(struct stu *)malloc(LEN);
scanf("%d,%d,%s",&p1->num,&p1->score,p1->name);
head=NULL;
while(p1->num!=0)
{n=n+1;
if(n==1)head=p1;
else p2->next=p1;
p2=p1;
p1=(struct stu *)malloc(LEN);
scanf("%d,%d,%s",&p1->num,&p1->score,p1->name);
}
p2->next=NULL;
return(head);
}

void print(struct stu * head)
{struct stu * p;
printf("\nNow, Thses %d records are:\n",n);
p=head;
if(head!=NULL)
do
{printf("%4d,%4d,%s\n",p->num,p->score,p->name);
p=p->next;
}while(p!=NULL);
}

struct stu *del(struct stu *head,int number)
{struct stu *p1, *p2;
 if(head==NULL)
  {printf("\nlist null\n");return(head);}
 p1=head;
 while(number!=p1->num && p1->next!=NULL)
 {p2=p1;p1=p1->next;}
 if(number==p1->num)
   {if(p1==head)head=p1->next;
    else p2->next=p1->next;
    printf("delete:%d\n",number);
    n=n-1;
   }
 else printf("%ld is not found\n",number);
return(head);
}

struct stu *insert(struct stu *head,struct stu *stud)
{struct stu *p0,*p1,*p2;
p1=head;
p0=stud;
if(head==NULL)
  {head=p0;p0->next=NULL;}
else
  {
    while((p0->num > p1->num) && (p1->next!=NULL))
     {p2=p1;p1=p1->next;}
     if(p0->num < p1->num)
       {if(head==p1)head=p0;
        else p2->next=p0;
        p0->next=p1;
       }
     else
     {p1->next=p0;p0->next=NULL;}
  }
n=n+1;
return(head);
}
void sum(struct stu*head)
{struct stu *p;
 int sum=0;
 if(head==NULL)
  {printf("\n mingming shuole rang xian shuru shuju dema\n");}
 else
 {
   p=head;
   do 
    {sum+=(p->score);
     p=p->next;
    }while(p!=NULL);
 }
 printf("The sum is %d",sum);
}
void save(struct stu *p)
{FILE *fp;
 if((fp=fopen("stu_list","wb"))==NULL)
   {printf("cannot opent file\n");
    return;
   }
 for(p=head;p->next!=NULL;p++)
  if(fwrite(p,LEN,1,fp)!=1)
  printf("file write error\n");
  fclose(fp);
}

void load(struct stu *p)
{FILE *fp;
/*int i;*/
fp=fopen("stu_list","rb");
for(p=head;p->next!=NULL;p++)
{fread(p,LEN,1,fp);
printf("%5d,%5d\n",p->num,p->score);
}
fclose(fp);
return;
}


main()
{struct stu *student;
long del_num;
char Q;
clrscr();
printf("******Now please input first records including num,score,name:********\n");
head=creat();
getchar();
loop:
P("                 ***********************************************\n");
P("                 *                                             *\n");
P("                 *            The management system            *\n");
P("                 *                                             *\n");
P("                 *                 Functions:                  *\n");
P("                 *              i.insert records;              *\n");
P("                 *              d.delete records;              *\n");
P("                 *              p.print records                *\n");
P("                 *              s.save files;                  *\n");
P("                 *              l.load files;                  *\n");
P("                 *              q.sum records up;              *\n");
P("                 *              e.exit                         *\n");
P("                 *                                             *\n");
P("                 ***********************************************\n");

Q=getchar();
getchar();
switch(Q)
{case 'p': print(head);goto loop;
 case 'd': printf("input the delete number:");
	   scanf("%d",&del_num);
	   getchar();
	   head=del(head,del_num);
	   print(head);
	   goto loop;
case 'i':  printf("input the inserted record:");
	   student=(struct stu *)malloc(LEN);
	   scanf("%d,%d,%s",&student->num,&student->score,student->name);
	   head=insert(head,student);
	   print(head);
	   goto loop;
case 'q':  sum(head);
case 'v':  save(head);goto loop;
case 'o':  load(head);goto loop;
case 'e':  exit(0);
default:   printf("error\n");clrscr();
}
}

