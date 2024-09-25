#include<stdio.h>
int main()
{
    int char_count=0,word_count=0,line_count=0;
    while(getchar()!=EOF)
    {
        char_count++;
        if(getchar()==' '||getchar()=='\t'||getchar()=='\n')
        word_count++;
        if(getchar()=='\n')
        line_count++;
    }
    printf("Character count: %d",char_count);
    printf("Line count: %d",line_count);
    printf("Word count : %d",word_count);
}
