#include<stdio.h>

long long palindrome(int a)
{
    int p,q;
    p=a;
    q=0;
    while(p!=0)
    {
        q=q*10+p%10;
        p=p/10;
    }
    if(a==q)
    {
        return 1;
    }
        return 0;
}

long long prime(int a)
{
    int i,flag=1;
    for(i=2;i<=a/2;++i)
  {
      if(a%i==0)
      {
          flag=0;
          break;
      }
  }
  return flag;
}
int main()
{
    long long int i,j,a;

    while(1)
    {
        scanf("%d",&a);
        printf("%d\n",2*a);
        if(palindrome(a)==1)
        {
             if(prime(a))
             {
                break;
             }

        }

    }
    return 0;
}
