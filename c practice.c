/*
//quick sort
#include <stdio.h>
#include <stdlib.h>

int main()
{
int arr[50];
int n,temp,j;
scanf("%d",&n);
for(int i=0;i<=n;i++)
{

    scanf("%d",&arr[i]);
}

for(int i=n;i>=0;i--)
{
arr[j]=n;
    for(int j=0;j<=n;j++)
    {

        if(arr[i]<arr[j])
        {
            break;
        }
        else{
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
        if(arr[i]>arr[j])
        {
            break;
        }
       else
        {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }


}
for(int i=0;i<=n;i++)
{

    printf("%d",arr[i]);
}
}
*/


//inserion sort
/*#include<stdio.h>
int main()
{
  int arr[50];
int n,temp;
scanf("%d",&n);
for(int i=0;i<n;i++)
{

    scanf("%d",&arr[i]);

}
for(int i=0;i<=n;i++)
{

    for(int j=1;j<=n;j++)
    {

        if(arr[i]<arr[j])
        {
            if(arr[j]==n)
            {
                break;
            }
            else
                continue;


        }
        else
        {

            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }


    }

}
for(int i=0;i<=n;i++)
{

    printf("%d",arr[i]);
}
}
*/


//electricity bill
/*#include<stdio.h>

int main()
{
float cost1,cost2,cost3;
    int scan1,scan2,units=1;
    float cost ;
    scanf("%d",&scan1);
    scanf("%d",&scan2);
    units=scan2-scan1;

    if(units<=100)
    {
       cost1=units*1.50;
    }
    else if(units>100&&units<=200)
    {
        cost2=units*2.50;

    }
    else if(units>200&&units<500)
    {
        cost3=units*3.50;
    }
    cost=cost1+cost2+cost3;
printf("%f",cost);
}
*/

/*#include<stdio.h>
int main()
 {
     // int emp1,emp2,emp3,emp4,emp5;
int arr[5];
int sal[5];
int salary[5];
int val[5];
int i,j,rem;
 printf("enter 5 employee timings");
 for(i=0;i<5;i++)
 {
    //scanf("%d%d%d%d%d",&emp1,&emp2,&emp3,&emp4&emp5);
 scanf("%d",&arr[i]);
 }

 //while(i!=5)
    for(i=0,j=0;i<5;i++,j++)
 {

    if( arr[i]>=40)

        val[j]=arr[i]-40;
 }
 for(i=0,j=0;i<5;i++,j++)
 {
    arr[i]=val[j]*15;
 }
 //if(arr[i]<40)

     for(i=0,j=0;i<5;i++,j++)
     {
         sal[i]=arr[i]+40;
         rem=arr[i]-sal[j];
         if(rem>0)
         salary[i]=rem*10;
     }


 printf("ot");

 for(i=0;i<5;i++)
 {
     printf("\n%d\t%d",arr[i],salary[i]);
 }
 }
/* printf("salary");
  for(i=0;i<5;i++)
 {
     printf("\n%d",salary[i]);

 }

 */

#include<stdio.h>
int main()
{

    float mrp,total,discount,cost;
    int items;
    scanf("%d%f",&items,&mrp);
    if (items>500)
    {
         cost=items*mrp;
    discount=cost*.15;
    total=cost-discount;
    }
    else
    {
        printf("no discount");
        total=items*20.5;
    }
       printf("%f",total);
}





