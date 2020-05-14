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

void backtrack(int table[][3])
{
  for(int i=0, i<3, i++)
  {
    for(int j=1, j<3, j++)
    {
      if(table[i][j]!='X' || table[i][j]!='O')
        {
          table[i][j]='X';
          break;
        }
    }
  }

}

bool complete(int table[][3])
{
  for(int x=0; x<3; x++)
  {
    for (int y = 0; y < 3; y++) {
      if(table[x][y]!='X' || table[x][y]!='O')
        return false;
    }
  }
  return true;
}

char check_win(int table[][3])
{
  //////////////////////////////// Checking Row Wise /////////////////
  if(table[0][0] == table[0][1] && table[0][1]==table[0][2])
    return table[0][0];
  else if(table[1][0] == table[1][1] && table[1][1]==table[1][2])
      return table[1][0];
  else if(table[2][0] == table[2][1] && table[2][1]==table[2][2])
          return table[2][0];
  ////////////////////////////// Checking Columns //////////////////
  else if(table[0][0] == table[1][0] && table[1][0]==table[2][0])
          return table[0][0];
  else if(table[0][1] == table[1][1] && table[1][1]==table[2][1])
          return table[0][1];
  else if(table[0][2] == table[1][2] && table[1][2]==table[2][2])
          return table[0][2];
  /////////////////////////// Checking Diagonals////////////////////
  else if(table[0][0] == table[1][1] && table[1][1]==table[2][2])
          return table[0][0];
  else if(table[2][0] == table[1][1] && table[1][1]==table[0][2])
          return table[2][0];
  else
          return 'N';
}
bool check_draw(int table[][3])
{
  if(complete(table) == true && check_win(table) == 'N')
    return true;
  else
    return false;
}
