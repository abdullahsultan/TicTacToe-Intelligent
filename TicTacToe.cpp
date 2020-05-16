#include <iostream>
#include "functions.h"
using namespace std;

int main(int argc, char const *argv[]) {
  int table[3][3];
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
  int block;
  if(first =='Y' || first=='y')
    {
      cout<<"\nChoose block(0-8)\n";
      while (true) {
        cin>>block;
        if(is_valid(block))
        {marker(table,block,'X'); break;}
      }
      print_table(table);
    }


///////////////// Playing Real Game//////////////////////////
    while (complete(table) != true) {
      backtrack(table);
      print_table(table);
      if(check_win(table)=='O')
        {cout<<"\n AI won \n"; return 0;}
      cout<<"\nChoose block(0-8)\n";
      while (true) {
        cin>>block;
        if(is_valid(block))
        {marker(table,block,'X'); break;}
        }
      print_table(table);
    }





  return 0;
}
