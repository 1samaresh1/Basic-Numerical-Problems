/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

int main()
{
    string name;
    char ch;
    cout<<"Enter the Name:";
    cin>>name;
    cout<<"Enter the Alphabate that searching: ";
    cin>>ch;
    
    for(int i=0;i<name.size();i++)
    {
      if(ch==name[i])
      {
      cout<<ch<<" is Found. ";
      return 0;
        
      }
    }
    cout<<ch<<" is not Found. ";

    return 0;
}
