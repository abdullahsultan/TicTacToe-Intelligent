#include <iostream>
#include "functions.h"
using namespace std;

int main(int argc, char const *argv[]) {
  char table[3][3];
  innitializer(table);
  print_table(table);

  char first;
  cout<<"\nDo you want to try first?(Y/N)\n";
  while (true) {
    cin>>first;
    if(first=='Y' || first=='y' || first=='N' || first=='n')
      break;
    cout << "Wrong choice, try again" << '\n';
  }
/////////////////// If user chooses 1st //////////////////////
  int in;
  char block;
  if(first =='Y' || first=='y')
    {
      cout<<"\nChoose block(0-8)\n";
      while (true) {
        cin>> in;
        block = (char) in+48;
        cout<<"Block "<<block<<endl;
        if(is_valid(block))
        {marker(table,block,'X'); break;}
      }
      print_table(table);
      if(block != 52)
      {
        marker(table,4,'O');
        print_table(table);
      }
      else
        first = 'n';
    }


///////////////// Playing Real Game//////////////////////////
    while (complete(table) != true) {
      if(first !='Y' && first != 'y')
      {
        backtrack(table);
        print_table(table);
        if(check_win(table)=='O')
          {cout<<"\n AI won \n"; return 0;}

      }
      cout<<"\nChoose block(0-8)\n";
      while (true) {
        cin>> in;
        block = (char) in+48;
        if(is_valid(block))
          {
            marker(table,block,'X'); break;
            if(check_win(table)=='X')
              {cout<<"\n You won \n"; return 0;}
          }
        }
        first='N';
      print_table(table);
    }


 if(check_draw(table)==true)
    cout << "\nDRAW\n" << '\n';


  return 0;
}
