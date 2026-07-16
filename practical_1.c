#include<stdio.h>
int main()
{
    int n,i,x,count=0,b;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int a[50];
    for(i=0;i<n;i++)
    {
        printf("Enter element number %d of the array: \n",i);
        scanf("%d",&a[i]);
    }
    printf("Enter the number x to search: ");
    scanf("%d",&x);
    for(i=0;i<n;i++)
    {
        if(a[i]==x)
        {
            count++;
            if(count==1)
            {
                b=i+1;
            }
        }
    }
    if(count==0)
    {
        printf("The number searched does not exist in the array");
    }
    else if(count==1)
    {
        printf("The number searched %d is found found in the array, but it is not repeating",x);
    }
    else
    {
        printf("The number searched %d is found in array and the number of occurences of the searched number is %d\n",x,count);
        printf("The position of the first occurence of the searched number is: %d",b);
    }
    return 0;
}