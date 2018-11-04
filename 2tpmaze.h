#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct pdata
{
	int h,v;
	struct pdata *next;
}Pathdata;

Pathdata *createNode(int m,int n)
{
	Pathdata *a=(Pathdata *)malloc(sizeof(Pathdata));
	a->h=m;
	a->v=n;
	a->next=NULL;
	//a->flg=0;
	return a;
}

void push(Pathdata *d,Pathdata **s)
{
	Pathdata *tmp=createNode(d->h,d->v);
//	printf("stack push h=%d v=%d \n",d->h,d->v);
		tmp->next=(*s);
		(*s)=tmp;
}
void pop(Pathdata **s)
{
        Pathdata *p=(*s);
		if((*s)==NULL)
		{
				//printf(" underflow");
				return ;
		}
		else
		{
			(*s)=(p)->next;
		//	printf("pop h=%d v=%d \n",p->h,p->v);
			free(p);
		}
}
Pathdata *stop(Pathdata **s)
{
		Pathdata *p=*s;
		if(*s==NULL){
			//printf(" empty");
			return *s;
		}
		else
		{
		   // printf("stktop h=%d v=%d\n",p->h,p->v);
			return  *s;
		}

}

int isempty(Pathdata **s)
{
	if(*s==NULL)
	{
		return 0;
	}
	else
	return 1;
}
