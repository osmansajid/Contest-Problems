#include<iostream>
#include<cstdio>
int main()
{
    float a;
    while(std::cin>>a)
    {
        int i;
        float s=0;
        if(a==0.00)
        {
           break;
        }
        else
        {
            for(i=2;;i++)
            {
                s+=double(1.00/i);
                //printf("%.2lf ",a);
                if(s>=double(a))
                {
                    printf("%d card(s)\n",i-1);
                    break;
                }
            }
        }
    }
}
