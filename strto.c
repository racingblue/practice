#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>

char *my_strtok(char str[], const char delim[])
{
    static char *temp;
    if(temp==NULL)
    {
      *temp=*str;  
    }
    char *dup=temp;
    for(int i=0;dup[i]!=0;i++)
    {
        for(int j=0;delim[j];j++)
        {
            if(dup[i]==delim[j])
            {
            dup[j]='\0';
                temp=(dup+j);
            }
        }
    }
    return dup;
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
