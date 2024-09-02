#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>

char *my_strtok(char str[], const char delim[])
{
    static char *temp;
    if(str!=NULL)
    {
      temp=str;  
    }
   int flag=1;
   char *dup;
   int i1;
    next:
         {
             temp+=i1;

         }
    for(int i=0;temp[i]!=0;i++)
    {
        
                
       
            char *dup=temp;
           
        
        for(int j=0;delim[j]!='\0';j++)
        {
            if(temp[i]==delim[j])
            {
                dup[i]='\0';
                temp+=i+1;
                if(i!=0)
                return dup;
               else
                for(i1=i;temp[i1]!='\0';i1++)
                {
                    int f=0;
                     for(int j1=0;delim[j1]!='\0';j1++)
                     {
                      if(temp[i1]==delim[j1]||temp[i1]=='\0')
                      {
                        i=i1;
                        f=1;
                      
                      }
                      
                      }
                      if(f==0)
                       goto next;
                }
               
                 
             
              // if(temp[i+1]!=delim[j])
             if(i1!=0)
              return dup;
           
            
            
            }
            
        }
    }
    //return NULL;
}

int main()
{
    char str[50], delim[50];
    
    printf("Enter the string  : ");
    scanf("%s", str);
    
    __fpurge(stdout);
 
    printf("Enter the delimeter : ");
    scanf("\n%s", delim);
    __fpurge(stdout);
    
    char *token = my_strtok(str, delim);
    printf("Tokens :\n");
    
    while (token)
    {
        printf("%s\n", token);
        token = my_strtok(NULL, delim);
    }


}
