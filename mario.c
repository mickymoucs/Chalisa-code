โปรแกรมสร้างกำแพง mario ตาม input เช่น
Height: 4
   #
  ##
 ###
####

#include<stdio.h>
#include<cs50.h>

int main(void)
{
  int n;
  do
  {
      n = get_int("Height: ");

  }
  while(n<1 || n>8);

   for (int i = 0; i < n; i++)
  {
      for (int j = 0 ; j<n-i-1 ; j++)
      {
          printf(" ");
      }

      for (int j = 0; j < i+1 ; j++)
      {
          printf("#");
      }
      printf("\n");
  }
}




