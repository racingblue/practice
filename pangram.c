#include <stdio.h>

int pangram(char str[])
{
    char str2[30];
    for(int i=0;i<26;i++)
    {
        str2[i]=i+97;
    }
    
    for(int i=0;str[i]!='\0';i++)
    {
        for(int j=0;str2[j]!='\0';j++)
        {
            if(str[i]+0==str2[j])
            {
                str2[j]='1';
            }
            else if(str[i]+0==str2[j]-32)
             str2[j]='1';
             
           
        }
         //printf("%c",str2[i]);
    }
   /* for(int i=0;str2[i]!='\0';i++)
   {
     printf("%c",str2[i]);
   }
   */
    int flag=0;
    for(int i=0;str2[i]!='\0';i++)
    {
        if(str2[i]!='1')
        {
            flag=1;
            return 0; 
        }
       
        
    }
    if(flag==0)
    return 1;
}

int main()
{
    char str[100];
   // printf("Enter the string");
    scanf("%[^\n]",str);
   int ret= pangram(str);
    if(ret)
    printf("The Entered String is a Pangram String");
    else
    printf("The Entered String is not a Pangram String");
    return 0;
    
}