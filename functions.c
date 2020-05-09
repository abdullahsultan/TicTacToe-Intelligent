#include <iostream>
#include "functions.h"

innitializer(int table[3][3])
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
void print_table(table[3][3]);
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
