โปรแกรมคำนวณการทอนเงินจากเหรียญที่มีมูลค่ามากกว่าไปน้อยกว่า

#include<stdio.h>
#include<cs50.h>
#include<math.h>

int main(void)
{
    float n;int a=0;int b=0;int c=0;int d=0;int g;int k;
  do
  {
      n = get_float("Change owed: ");
      g = round(n*100);
  }
  while(n<0);       

  if(g>=25)
  {     
    a = g/25;
    g=g-25*a;
  }
  if(g>=10)
  {
     b = g/10;
    g=g-10*b;
  }
  if(g>=5)
  {
      c = g/5;
      g=g-5*c;
  }
  if(g<=4)
  {
      d = g;
      g=g-1*d;
  }
  
  k = a+b+c+d;
  printf("%i\n",k);
      
}

