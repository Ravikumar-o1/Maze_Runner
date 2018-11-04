#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include"2tpmaze.h"
int m[5][5]; //Array For Maze
Pathdata *top=NULL,*gtop=NULL,*wr=NULL; //Stack Pointer
int flg=1; //For checking whether the starting Point.
int left(int h,int v)
{
	if(v==0||m[h][v-1]==1)
		return 0;
    return 1;
}
int right(int h,int v)
{
	if(v==4||m[h][v+1]==1)
		return 0;
    return 1;
}
int  up(int h,int v)
{
	if(h==0||m[h-1][v]==1)
		return 0;
    return 1;
}
int down(int h,int v)
{
	if(h==4||m[h+1][v]==1)
		return 0;
	 return 1;
}
int isValid(int h,int v)
{
	if(h-1<0 ||v-1 <0||m[h-1][v-1]==1 ||h-1>4||v-1>4)
	{
		printf("invalid");
	return 1;
    }


	return 0;

}
int maze(int h,int v)
{
    Pathdata p;         //Locale Variable for inserting into stack.
    int th=h,tv=v,l,term=0,r,u,d,cnt=0;    // term for  checking recursive  sucess	
    p.h=h;
    p.v=v;
    l=left(h,v);        //To check the path to left
    r=right(h,v);       //To check the path to left
    u=up(h,v);          //To check the path to left
    d=down(h,v);        //To check the path to left
    cnt=l+r+u+d;        //To count path at present point
    if(m[h][v]==2)
    {
        printf("(%d %d)",h+1,v+1);
        printf("\nFinish Pathis\n");
        push(&p,&top);
        return 1;
    }
    if(cnt==1&&!flg)
    {
    	push(&p,&wr);
    	printf("(%d %d)->",h+1,v+1);
    	return 0;
	}
    printf("(%d %d)->",h+1,v+1);
    if(l&&(top->h!=th||top->v!=tv-1||flg))
    {
        if(!flg&&top->h!=th&&top->v!=tv)
            push(&p,&top);
        flg=0;
        term=maze(h,v-1);
        if(term==1)
           return 1;
    }
    if(r&&(top->h!=th||top->v!=tv+1||flg))
    {
        if(!flg&&(top->h!=th||top->v!=tv))
            push(&p,&top);
        flg=0;
        term=maze(h,v+1);
        if(term==1)
           return 1;
    }
    if(u&&(top->h!=th-1||top->v!=tv||flg))
    {
        if(!flg&&(top->h!=th||top->v!=tv))
        	push(&p,&top);
		flg=0;
        term=maze(h-1,v);
        if(term==1)
            return 1;
    }
    if(d&&(top->h!=th+1||top->v!=tv||flg))
    {
        if(!flg&&(top->h!=th||top->v!=tv))
            push(&p,&top);
		flg=0;
        term=maze(h+1,v);
        if(term==1)
          return 1;
    }
    if(term!=1){
    		push(top,&wr);
    		printf("(%d %d)->",top->h+1,top->v+1);
    		pop(&top);
            return 0;
    }
    return 1;
}
void printM()
{
    int gm,gd=0,tv=wr->v,th=wr->h,i=0;
    initgraph(&gd,&gm,"");
    outtextxy(270,120,"Mouse-Maze");
    outtextxy(290,170+5*30,"Correct path");
    outtextxy(290,200+5*30,"Wrong path");
    setcolor(YELLOW);
    line(250,178+5*30,280,178+5*30);
    circle(250,178+5*30,4);
    circle(280,178+5*30,4);
    setcolor(13);
    line(250,209+5*30,280,209+5*30);
    circle(250,209+5*30,4);
    setcolor(12);
    circle(280,209+5*30,4);
                while(i<=5){        //for printing maze box
                    setcolor(WHITE);
                    line(235,150+i*30,235+5*30,150+i*30);
                    line(235+i*30,150,235+i*30,150+5*30);
                    i++;
            }
            while(wr!=NULL)
            {                           //for printing wrong path or point
                setcolor(13);
                if(tv==wr->v||th==wr->h)
                    line(250+tv*30,165+th*30,250+wr->v*30,165+wr->h*30);
                circle(250+wr->v*30,165+wr->h*30,4);
                th=wr->h;
                tv=wr->v;
                pop(&wr);
            }
            th=gtop->h;
            tv=gtop->v;
            i=0;
        while(gtop!=NULL)        //for printing correct path
        {
            if(i==16)
                i=0;
            setcolor(i);
            outtextxy(270,120,"Mouse-Maze");
           setcolor(YELLOW);
           line(250+tv*30,165+th*30,250+gtop->v*30,165+gtop->h*30);
           delay(200);
           setcolor(12);
           circle(250+gtop->v*30,165+gtop->h*30,4);
           delay(200);
           th=gtop->h;
           tv=gtop->v;
           pop(&gtop);
           i++;
        }
        getch();
        closegraph();
}
int main()
 {
  	  int i=0,j=0,x,y,term;
  	  Pathdata p;
 	  for(i=0;i<5;i++)
 	  {
 	  	for(j=0;j<5;j++)
 	  	{
 	  		if(i==0 )
 	  		{
 	  			if(j>i)
					m[i][j]=1;
				else
					m[i][j]=0;

		   }
		   if(i==1)
		   {
                if(j<4)
                    m[i][j]=0;
                else
                    m[i][j]=1;
		   }
		   if(i==2 )
		   {
                if(j==1 || j==4)
                    m[i][j]=0;
                else
                    m[i][j]=1;
		   }
		   if(i==3)
		   {
                m[i][j]=0;
		   }
		   if(i==4)
		   {
		   		if(j==1)
		   			m[i][j]=0;
		   		else
		   			m[i][j]=1;
		   }
	   }
 	}
 	m[2][4]=2;
 	for(i=0;i<5;i++)
 	{
 		for(j=0;j<5;j++)
 		{
 			printf("%4d ",m[i][j]);
		 }
		 printf("\n");
	 }
    do{
          printf("enter the coordinates(x,y) (1<=x,y<=5)");
          scanf("%d %d",&x,&y);
       }while(isValid(x,y));
    p.h=x-1;
    p.v=y-1;
    push(&p,&top);
    maze(x-1,y-1);
    while(top->next!=NULL)
    {
        printf("(%d %d)--->",top->h+1,top->v+1);
        push(top,&gtop);
        pop(&top);
    }
    push(top,&gtop);
    printf("(%d %d)",top->h+1,top->v+1);
    printM();       //For printing graphical maze and Path
    return 0;
 }
