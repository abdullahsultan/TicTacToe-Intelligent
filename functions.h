#pragma once
void innitializer(char table[][3]);
void print_table(char table[][3]);
void marker(char table[][3],char block,char p);
bool is_valid(char number,char table[][3]);
void backtrack(char table[][3]);
char further(char table[][3]);
char further_draw(char table[][3]);
bool complete(char table[][3]);
char check_win(char table[][3]);
bool check_draw(char table[][3]);
int critical_loose(char table[][3]);
int critical_win(char table[][3]);
void copier(char table[][3],char temp[][3]);
