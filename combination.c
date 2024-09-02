#include<stdio.h> 

void combination(char str[],int len,int max)
{
   // printf("%s",str);
    
    for(int i=len;i<=max;i++)
    {
        
       
        char temp=str[i];
        str[i]=str[len];
        str[len]=temp;
        // printf("\n%s",str);
       
        combination(str,len+1,max);
        temp=str[i];
        str[i]=str[len];
        str[len]=temp;
         if(len==max)
     {
       printf("%s\n",str);
     }
        
    }
    
       
       // for(int i=0;str[i]!='\0';i++)
       /* {
          char temp =str[j];
          str[j]=str[i];
          str[i]=temp;
          if(j!=0)
          printf("%c",str[i]);
        }*/
        
    
}
int my_strlen(char str[])
{
    int len=0;
     while(str[len]!='\0')
        {
            len++;
        }
        return len;
}

int main()

{
        char str[50];
        int n;
        int res;
        int len=0,max=1;
        printf("Enter a string: ");
        scanf("%100[^\n]",str);  
       len=my_strlen(str);
        len=len-1;
       // printf("%d",n);
        while(n>1)
        {
          max=max*n;
          n--;
         
        }
      //  printf("%d\n",len);
        // printf("%d",max);
        n = my_strlen(str);
        n=0;
        combination(str,n,len);                       
        return 0;
}
#include<stdio.h> 

void combination(char str[],int len,int max)
{
   // printf("%s",str);
    
    for(int i=len;i<=max;i++)
    {
        
       
        char temp=str[i];
        str[i]=str[len];
        str[len]=temp;
        // printf("\n%s",str);
       
        combination(str,len+1,max);
        temp=str[i];
        str[i]=str[len];
        str[len]=temp;
         if(len==max)
     {
       printf("%s\n",str);
     }
        
    }
    
       
       // for(int i=0;str[i]!='\0';i++)
       /* {
          char temp =str[j];
          str[j]=str[i];
          str[i]=temp;
          if(j!=0)
          printf("%c",str[i]);
        }*/
        
    
}
int my_strlen(char str[])
{
    int len=0;
     while(str[len]!='\0')
        {
            len++;
        }
        return len;
}

int main()

{
        char str[50];
        int n;
        int res;
        int len=0,max=1;
        printf("Enter a string: ");
        scanf("%100[^\n]",str);  
       len=my_strlen(str);
        len=len-1;
       // printf("%d",n);
        while(n>1)
        {
          max=max*n;
          n--;
         
        }
      //  printf("%d\n",len);
        // printf("%d",max);
        n = my_strlen(str);
        n=0;
        combination(str,n,len);                       
        return 0;
}

