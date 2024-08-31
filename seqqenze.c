#include <stdio.h>

void swap(int num,char str1[])
{
    
   for (int i = num;str1[i]!='\0'; i++,num++)
    {
       str1[num]=str1[num+1];  
       //if(str1[num+1]=='\0')
      // str1[num]='\0';
        //printf("%c",str1[num]);
    }
   
    
}
int length(char str[])
{
    int i;
    while(str[i]!='\0')
    i++;
    return i;
}

void squeeze(char str1[], char str2[])
{
    for(int i=0;str1[i]!='\0';i++)
    {
        for(int j=0;str2[j]!='\0';j++)
        {
            if(str1[i]==str2[j])
            {
               
                int len=length(str1);
              swap(i,str1);
              str1[len--]='\0';
              continue;
              
            }
        }
    }
}


int main()
{
    char str1[30], str2[30];
    
    printf("Enter string1:");
    scanf("%[^\n]", str1);
    getchar();
    

    printf("Enter string2:");
    scanf("%[^\n]", str2);
    
    squeeze(str1, str2);
    
    printf("After squeeze s1 : %s\n", str1);
    
}