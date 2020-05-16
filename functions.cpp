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
  cout << "\n\n";
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
  cout << "\n\n";
}
void marker(int table[][3],int block,char p)
{
  for(int i=0; i<3; i++)
  {
    for(int j=0; j<3; j++)
    {
      if(table[i][j]==block)
        table[i][j]=p;
    }
  }
}

bool is_valid(int number){
  if(number>=0 && number<9)
    return true;
  else
    {cout<<"\nWrong choice try again\n"; return false;}
}

void backtrack(int table[][3])
{
  int c = critical_loose(table);
  if(c > -1)
  {
    for(int i=0; i<3; i++)
    {
      for(int j=0; j<3; j++)
      {
        if(table[i][j]==c)
          {
              table[i][j]='O'; return;
          }
      }
    }
  }
  int temp[3][3];
  copier(table,temp);
  for(int i=0; i<3; i++)
  {
    for(int j=0; j<3; j++)
    {
      if(temp[i][j]!='X' && temp[i][j]!='O')
        {
          int t = temp[i][j];
          temp[i][j] = 'O';
          cout << "\nBacktrack\n";
          print_table(temp);
          if(further(temp)=='O')
            {
              table[i][j]='O';
              return;
            }

          temp[i][j] = t;
        }
    }
  }
//  cout << "\nTTT\n" << '\n';
//  print_table(temp);
}

char further(int table[][3])
{
  //cout<<"\nFURTHERGGGGGGGGGG\n";
  bool turn = true;
  int temp[3][3];
  copier(table,temp);
  for(int i=0; i<3; i++)
  {
    for(int j=0; j<3; j++)
    {
      if(temp[i][j]!='X' && temp[i][j]!='O')
        {
          if(turn == true)
            {temp[i][j] = 'X'; turn = false;}
          else
            {temp[i][j] = 'O'; turn = true;}
        }
    }
  }
  cout << "\nFurther\n";
  print_table(temp);
  cout << "\nWin  \n"<<check_win(temp)<<endl;
  return check_win(temp);
}

bool complete(int table[][3])
{
  for(int x=0; x<3; x++)
  {
    for (int y = 0; y < 3; y++) {
      if(table[x][y]!='X' && table[x][y]!='O')
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

int critical_loose(int table[][3])
{
    int temp[3][3]; copier(table,temp);
    for(int x=0; x<3; x++)
    {
      for (int y = 0; y < 3; y++) {
        if(temp[x][y]!='X' || temp[x][y]!='O')
          {
            int t = temp[x][y];
            temp[x][y]='X';
            if (check_win(temp) == 'X') {
              return t;
            }
            temp[x][y]=t;
          }
      }
    }
    return -1;
}

void copier(int table[][3],int temp[][3])
{
  for(int x=0; x<3; x++)
  {
    for (int y = 0; y < 3; y++) {
      temp[x][y] = table[x][y];
    }
  }
}
