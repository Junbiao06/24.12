#include<stdio.h>

int main (void)
{
    int array[]={1,2,3,4,5,6,7,8,9,10};
    static int p[10];
    int m;
    scanf("%d",&m);
    for(int i=0;i<10;i++)
    {
        if(m+i>=10)
            p[m+i-10]=array[i];
        else
            p[m+i]=array[i];
    }
    //p[(i+m)%10]==array[i]
    for(int i=0;i<10;i++)
    printf("%3d",p[i]);
}