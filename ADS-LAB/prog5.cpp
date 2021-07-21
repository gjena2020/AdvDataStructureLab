#include<iostream>
#include<conio.h>
#include<process.h>
#define max 5
using namespace std;
class graph
{
 private:int g[max][max];
 public:graph();
void create();
void insertvertex();
void deletevertex();
void findvertex();
void insertedge();
void deleteedge();
void display();
};
graph::graph()
{
 for(int i=0;i<max;i++)
 {
  for(int j=0;j<max;j++)
  {
   g[i][j]=0;
   g[j][i]=0;
  }
 }
}


void graph::create()
{
 int v1,v2;
 char ans='y';
 while(ans=='y')
 {
  cout<<"\n Enter the vertices v1 and v2:\n";
  cin>>v1>>v2;
  g[v1][v2]=1;
  g[v2][v1]=1;
  cout<<"\n Do you want to insert more vertex?(y/n):";
  ans=getch();
 }
}
void graph::insertvertex()
{
 int v1,v2;
 char ans='y';
 cout<<"Enter the vertex to be inserted:\n";
 cin>>v1;
 while(ans=='y')
 {
  cout<<"\n Enter neighbouring vertex:\n";
  cin>>v2;
  g[v1][v2]=1;
  g[v2][v1]=1;
  cout<<"\n More neighbouring vertex?";
  ans=getch();
 }
}

void graph::deletevertex()
{
 int i,v;
 cout<<"Enter the vertex to be deleted:\n";
 cin>>v;
 for(i=0;i<max;i++)
 {
  g[v][i]=0;
  g[i][v]=0;
 }
 cout<<"The vertex is deleted";
}
void graph::findvertex()
{
 int i,v,flag=0;
 cout<<"Enter the vertex to be searched in the graph:\n";
 cin>>v;
 for(i=0;i<max;i++)
 {
  if(g[v][i]==1)
  {
   flag=1;
   cout<<"\n Neighbouring vertex is:"<<i;
  }
 }
 if(flag==0)
  cout<<"\n Vertex not present in the graph:";
}



void graph::insertedge()
{
 int v1,v2;
 cout<<"\n Enter the edge to be inserted by v1 and v2:";
 cin>>v1>>v2;
 g[v1][v2]=1;
 g[v2][v1]=1;
}
void graph::deleteedge()
{
 int v1,v2;
 cout<<"\n Enter the edge to be inserted by v1 and v2:";
 cin>>v1>>v2;
 g[v1][v2]=0;
 g[v2][v1]=0;
}
void graph::display()
{
 cout<<"\n";
 for(int i=0;i<max;i++)
 {
  for(int j=0;j<max;j++)
  {
   cout<<"   "<<g[i][j];
  }
  cout<<"\n";
 }
}



int main()
{
 graph g;
 int choice;
 char ch='y';
 cout<<"\n.....Graph Operations......";
 g.create();
 g.display();
 while(ch=='y')
 {
  cout<<"\n 1.insertvertex \n 2.deletevertex \n 3.findvertex \n 4.insertedge \n 5.deleteedge \n 6.exit \n";
  cout<<"\n Enter ur choice:";
  cin>>choice;
  switch(choice)
  {
   case 1:g.insertvertex();
              g.display();
              break;
   case 2:g.deletevertex();
              g.display();
              break;
   case 3:g.findvertex();
              g.display();
              break;
   case 4:g.insertedge();
              g.display();
              break;


   case 5:g.deleteedge();
              g.display();
              break;
   case 6:exit(0);
  }
  cout<<"\n Do you want to go mainmenu?(y/n):";
  ch=getch();
 }
}
