#include <iostream>

#include <math.h>

using namespace std;

int main ( ) 
{
  int array[5]={12,24,24,12,24};
  int ar[5];
  int i,j, k,size=5;
for (i = 0; i < size; i++)
 {
   for (j = i + 1; j < size;) 
   {
    if (array[j] == array[i]) {
      for (k = j; k < size; k++) {
array[k] = array[k + 1];
}
size--;
} else
j++;
}
}
for (i = 0; i < size; i++) {
printf("%d\n", array[i]);
}


return 0;

}

