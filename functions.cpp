#include <iostream>
#include "functions.h"
using namespace std;

void innitializer(int table[][3])
{
  int val=0;
  for(int x=0; x<3; x++)
  {
    for(int y=0; y<3; y++)
    {
        table[x][y]=val;
        val++;
    }
  }
}
void print_table(int table[][3])
{
  for(int x=0; x<3; x++)
  {
    for(int y=0; y<3; y++)
    {
      cout<<table[x][y]<<" | ";
    }
    cout<<endl;
    if(x<3){
      for(int z=0; z<9; z++)
        cout<<"-";
    }
    cout<<endl;
  }
}
void marker(int table[][3],int block,char x)
{
  for(int i=0, i<3, i++)
  {
    for(int j=1, j<3, j++)
    {
      if(table[i][j]==block)
        table[i][j]=x;
    }
  }
}

bool is_valid(int number){
  if(number>0 && number<9)
    return true;
  else
    {cout<<"\nWrong choice try again\n"; return false;}
}
