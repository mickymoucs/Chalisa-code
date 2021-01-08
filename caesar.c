/*โปรแกรมแปลงคำปกติ เป็นคำใหม่โดยการเข้าหัสตาม input เช่น
./caesar 1
plaintext:  HELLO
ciphertext: IFMMP*/

#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    string s;int k=0;string j=0;int p=0;int c=0;int b=0;char x='\0';
    
    if(argc == 2)
    { s = argv[1];
    
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if(s[i] < '0' || s[i] > '9')
        {
            k  +=1;
        }
    }
    
    if(k>0)
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }
    if(k==0)
    {    
        j = get_string("plaintext:  ");
    
      for (int i = 0, n = strlen(j); i < n; i++)
    {
        int key = atoi(argv[1]);
        
        
        if (j[i] >= 'a' && j[i] <= 'z')
        {
            j[i] -= 96; 
            j[i] = ( j[i] + key) % 26; 
            j[i] += 96;
        }
         if (j[i] >= 'A' && j[i] <= 'Z')
        {
            j[i] -= 64; 
            j[i] = ( j[i] + key) % 26;
            j[i] += 64;
            
        }
    }    
        printf("ciphertext: %s\n", j );
    }
    }

    if(argc != 2)
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }
    
}


