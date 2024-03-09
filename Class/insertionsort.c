#include <stdio.h>

int main()
{
  int  array[9]={9,6,5,0,8,2,7,1,3};
	int c, d, t, flag = 0;
	int n=9;

  for (c = 1 ; c <= n - 1; c++) {
    t = array[c];
    
    for (d = c - 1 ; d >= 0; d--) {
      if (array[d] > t) {
        array[d+1] = array[d];
        flag = 1;
      }
      else
        break;
    }
    if (flag==1){
    	array[d+1] = t;
	}
  }

  printf("Sorted list in ascending order:\n");

  for (c = 0; c <= n - 1; c++) {
    printf("%d\t", array[c]);
  }

  return 0;
}
