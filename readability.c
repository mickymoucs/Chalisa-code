โปรแกรมนับจำนวนตัวอักษร คำ และประโยค และประมวลผลออกมาเป็นเกรดตามเกณฑ์ที่กำหนดไว้

#include<stdio.h>
#include<cs50.h>
#include<math.h>
#include<ctype.h>
#include<string.h>


int main(void)
{
    int count_letter=0;int count_word=0;int count_sentence=0;float L=0;float h=0;int g=0;
    
    string s = get_string("Text:  ");
    
    for (int i = 0, n = strlen(s); i < n; i++)
    
        if (s[i] >= 'A' && s[i] <= 'Z')
    {
        count_letter +=1;
    }
        else if (s[i] >= 'a' && s[i] <= 'z')
    {
       count_letter +=1;
    }
    

    for (int i = 0, n = strlen(s); i < n; i++)
    {        
        if(s[i] ==' ')
        {
        count_word +=1;
        }
    }
    count_word +=1;
    
    L = round(100*count_letter)/count_word;
    
        for (int i = 0, n = strlen(s); i < n; i++)
    {        
         if(s[i] =='.')
        {
        count_sentence +=1;
        }
         if(s[i] =='?')
        {
        count_sentence +=1;
        }
         if(s[i] =='!')
        {
        count_sentence +=1;
        }
        
    }
   
    
    h = round(100*count_sentence)/count_word;
    
    g = round(0.0588 * L - 0.296 * h - 15.8);
    
    if(g>1 && g<16)
    {
        printf("Grade %i\n",g);
    }
    if(g<1)
    {
        printf("Before Grade 1\n");
    }
    if(g>16)
    {
        printf("Grade 16+\n");
    }
    
}







