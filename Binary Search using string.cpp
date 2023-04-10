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
    int beg=0;
    int end=(name.size())-1;
    int mid=(beg+end)/2;
    while(beg<=end)
    {
    if(ch==name[mid])
    {
      cout<<ch<<" is found.";
      return 0;
    }
    else
    {
      if(int(ch)<int(name[mid]))
      {
        end=mid-1;
        
      }
      else
      {
        beg=mid+1;
      }
      cout<<beg<<end;
    }
    mid=(beg+end)/2;
    }
    cout<<ch<<" not is found.";

    return 0;
}
