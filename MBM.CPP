#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<dos.h>
#include<stdlib.h>
#include<graphics.h>
int bipartiteGraph[40][40],temp[40][40],pos,pos_col;
int M,N,i,j,min;
int count=0,number[20];
int x1[20],y1[20],x2[20],y2[20];
int bipartiteMatch(int u, int visited[], int assign[]);
int maxMatch();
void input();
void name();
void ty();
void output_graph();
void input_graph();
void loading();
void result();
void main()
{
clrscr();
name();
input();
ty();
getch();
}
//*************************************************************************
void name()
{
int f=0;
top:
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
setcolor(3);
settextstyle(10,0,7);
setcolor(12);
outtextxy(100,20,"M");
if(f==0){for(long int i=0;i<10000000;++i);cleardevice();  }
setcolor(11);
outtextxy(170,20,"A");
if(f==0){for(long int i=0;i<10000000;++i);cleardevice();  }
setcolor(10);
outtextxy(240,20,"X");
if(f==0){for(long int i=0;i<10000000;++i);cleardevice();  }
setcolor(9);
outtextxy(290,20,"I");
if(f==0){for(long int i=0;i<10000000;++i);cleardevice();  }
setcolor(14);
outtextxy(320,20,"M");
if(f==0){for(long int i=0;i<10000000;++i);cleardevice();  }
setcolor(13);
outtextxy(390,20,"U");
if(f==0){for(long int i=0;i<10000000;++i);cleardevice();  }
setcolor(2);
outtextxy(450,20,"M");
if(f==0){for(long int i=0;i<10000000;++i);cleardevice();  }
//****************************************************************
setcolor(3);
outtextxy(80,150,"B");
if(f==0){for(long int i=0;i<10000000;++i);cleardevice();  }
setcolor(4);
outtextxy(140,150,"I");
if(f==0){for(long int i=0;i<10000000;++i);cleardevice();  }
setcolor(13);
outtextxy(170,150,"P");
if(f==0){for(long int i=0;i<10000000;++i);cleardevice();  }
setcolor(2);
outtextxy(220,150,"A");
if(f==0){for(long int i=0;i<10000000;++i);cleardevice();  }
setcolor(1);
outtextxy(290,150,"R");
if(f==0){for(long int i=0;i<10000000;++i);cleardevice();  }
setcolor(14);
outtextxy(350,150,"T");
if(f==0){for(long int i=0;i<10000000;++i);cleardevice();  }
setcolor(13);
outtextxy(410,150,"I");
if(f==0){for(long int i=0;i<10000000;++i);cleardevice();  }
setcolor(12);
outtextxy(435,150,"T");
if(f==0){for(long int i=0;i<10000000;++i);cleardevice();  }
setcolor(6);
outtextxy(495,150,"E");
if(f==0){for(long int i=0;i<10000000;++i);cleardevice();  }
setcolor(4);
//if(f==1)for(long int i=0;i<10000000;++i);
if(f==0){for(long int i=0;i<10000000;++i);cleardevice();  }
settextstyle(10,0,7);
setcolor(14);
outtextxy(90,280,"M");
if(f==0){for(long int i=0;i<10000000;++i);cleardevice(); }
setcolor(2);
outtextxy(160,280,"A");
if(f==0){for(long int i=0;i<10000000;++i); cleardevice();}
setcolor(6);
outtextxy(210,280,"T");
if(f==0){for(long int i=0;i<10000000;++i);cleardevice(); }
setcolor(5);
outtextxy(265,280,"C");
if(f==0){for(long int i=0;i<10000000;++i);cleardevice(); }
setcolor(4);
outtextxy(330,280,"H");
if(f==0){for(long int i=0;i<10000000;++i); cleardevice();}
setcolor(1);
outtextxy(390,280,"I");
if(f==0){for(long int i=0;i<10000000;++i); cleardevice();}
setcolor(3);
outtextxy(420,280,"N");
if(f==0){for(long int i=0;i<10000000;++i);cleardevice();  }
setcolor(4);
outtextxy(480,280,"G");
if(f==0){for(long int i=0;i<10000000;++i);cleardevice();  }

f++;
if(f==1)goto top;
getch();
closegraph();
}
//*********************************************************
void input_graph()
{
clrscr();
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
gotoxy(1,4);
cout<<"\nInput Graph according to the adjacency matrix is:\n";
int k=100;
for(i=0;i<M;++i)
{
circle(100,k,10);
x1[i]=100;
y1[i]=k;
k=k+50;
}
k=100;
for(i=0;i<N;++i)
{
circle(500,k,10);
x2[i]=500;
y2[i]=k;
k=k+50;
}
for(i=0;i<M;++i)
{
for(j=0;j<N;++j)
{
if(bipartiteGraph[i][j]!=0)
{
line(x1[i],y1[i],x2[j],y2[j]);
}
}
}
gotoxy(1,25);
cout<<"\nPress Enter to process the result\n";
getch();
closegraph();
}
//*********************************************************
void loading()
{
int gd,gm;
 detectgraph(&gd,&gm);
 initgraph(&gd,&gm,"c:\\turboc3\\bgi");
 int x,y,i;
 cleardevice();
 x=getmaxx()/2;
 y=getmaxy()/2;
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
 setbkcolor(0);
 setcolor(0);
 int c=150;
for(int e=0;e<45;e++)
 {for(int i=50;i<100;i++)
  {settextstyle(SMALL_FONT, HORIZ_DIR, 10);
   setcolor(5);
   outtextxy(x,y-10,"Processing...");
   setcolor(7);
   settextstyle(SMALL_FONT, HORIZ_DIR, 5);
   if(e<7){outtextxy(x+5,y+30,"Creating Graph...");}
   else if(e<14){outtextxy(x+5,y+30,"Creating Connections...");}
   else if(e<21){outtextxy(x+5,y+30,"Checking Graph...");}
   else if(e<29){outtextxy(x+5,y+30,"Matching Graph...");}
   else if(e<36){outtextxy(x+5,y+30,"Rechecking ...");}
   else if(e<44){outtextxy(x+5,y+30,"Creating Maximum Matching...");}
   setcolor(3);
   circle(x,y,i);
   circle(x,y,c);
   c--;
   cleardevice();
}
 }
  setcolor(8);
  settextstyle(SMALL_FONT, HORIZ_DIR, 100);
   outtextxy(x-150,y-30,"Processing Complete");
  setcolor(0);
  gotoxy(1,25);cout<<"Press Enter Key for Result..";
getch();
 closegraph();
}
//**************************************************************
void input()
{
int gd,gm;
detectgraph(&gd,&gm);
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
cleardevice();
setcolor(4);
gotoxy(1,7);
cout<<"\nEnter number of applicants";
cin>>M;
cout<<"\nEnter number of jobs";
cin>>N;
cout<<"\nEnter adjacency Matrix for the Graph\n";
for(i=0;i<M;++i)
{
for(j=0;j<N;++j)
{
cin>>bipartiteGraph[i][j];
temp[i][j]=bipartiteGraph[i][j];
}
}
input_graph();
loading();
output_graph();
getch();
closegraph();
}
//********************************************************
int bipartiteMatch(int u, int visited[], int assign[]) {
for (int v = 0; v < N; v++)
{
if (bipartiteGraph[u][v] && !visited[v])
{
visited[v] = 1;
if (assign[v] < 0 || bipartiteMatch(assign[v], visited, assign))
{

assign[v] = u;
return 1;
}
}
}
return 0;
}
//************************************************************
int maxMatch()
{
int assign[30];
for(int i = 0; i<N; i++)
assign[i] = -1;
int jobCount = 0;
for (int u = 0; u < M; u++)
{
int visited[30];
for(int i = 0; i<N; i++)
visited[i] = 0;
if(bipartiteMatch(u, visited, assign))
jobCount++;
}
return jobCount;
}
//******************************************************************
void result()
{
for(i=0;i<10;++i)
number[i]=0;
for(int k=0;k<M;++k)
{
for(i=0;i<M;++i)
{
count=0;
	for(j=0;j<N;++j)
	{
	if(temp[i][j]==1)
	{
		count=count+1;
	}
	}
	if(number[i]!=999)
	number[i]=count;
}
for(int u=0;u<M;++u)
{
pos=0;
min=number[0];
for(i=1;i<M;++i)
{
	if(number[i]<min && number[i]>0)
	{
	min=number[i];
	pos=i;
	}
}
}
for(j=0;j<N;++j)
{
	if(temp[pos][j]==1)
	{
	pos_col=j;
	break;
	}
}
for(i=0;i<M;++i)
{
	if(i==pos)
	{
		for(j=0;j<N;++j)
		{
		if(j!=pos_col)
		{
		temp[pos][j]=0;
		//temp[j][pos]=0;
		}
		}
		for(int q=0;q<M;++q)
		{
		if(q!=pos)
		temp[q][pos_col]=0;
		}
	}
}
number[k]=999;
}
}

//*********************************************
void output_graph()
{
clrscr();
result();
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
int k=100;
for(i=0;i<M;++i)
{
circle(100,k,10);
x1[i]=100;
y1[i]=k;
k=k+50;
}
k=100;
for(i=0;i<N;++i)
{
circle(500,k,10);
x2[i]=500;
y2[i]=k;
k=k+50;
}
for(i=0;i<M;++i)
{
for(j=0;j<N;++j)
{
if(temp[i][j]!=0)
{
line(x1[i],y1[i],x2[j],y2[j]);
}
}
}
gotoxy(2,4);
cout << "Maximum number of applicants matching for job: " << maxMatch();
getch();
closegraph();
}
//******************************************************************
void ty()
{
int i;
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
cleardevice();
settextstyle(7,0,50);
setcolor(5);
outtextxy(90,50,"T");
delay(500);
outtextxy(150,50,"H");
delay(500);
outtextxy(240,50,"A");
delay(500);
outtextxy(320,50,"N");
delay(500);
outtextxy(410,50,"K");
delay(500);
outtextxy(150,220,"Y");
delay(500);
outtextxy(240,220,"O");
delay(500);
outtextxy(320,220,"U");
getch();
closegraph();
}
