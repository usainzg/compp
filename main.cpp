#include <stdio.h>
#include <iostream>
extern int yyparse();
bool hayError = false;
using namespace std;

int main(int argc, char **argv)
{
  cout << "ha comenzado..." << endl << endl ;
  if (yyparse() == 0 && !hayError) { 
    cout << "ha finalizado BIEN..." << endl << endl ;
  }
  else {
    cout << "ha finalizado MAL..." << endl << endl ;
  }
  return 0;
}
