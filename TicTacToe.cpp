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

  int block;
  if(first =='Y' || first=='y')
    {
      cout<<"\nChoose block(0-8)\n";
      while (true) {
        cin>>block;
        if(is_valid(block))
        {marker(table,block,'X'); break;}
      }
    }

    while (complete(table)) {
      backtrack(table);
    }





  return 0;
}
