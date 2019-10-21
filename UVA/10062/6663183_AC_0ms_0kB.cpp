#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    int c[101],k,freq[130],flag=0;
    while(getline(cin,a))
    {
        if(flag==1)
        {
            printf("\n");
        }
        int count,i,j;
        k=0;
        for(i=127;i>=32;i--)
        {
            count=0;
            for(j=a.size()-1;j>=0;j--)
                {
                    if(i==a[j])
                    {
                        count++;
                    }
                }
               //printf("%d\n",count);
                    freq[i]=count;
        }
        int max = 0;
		for(i=32;i<=127;i++)
        {
          if(freq[i]>max)
          {
            max = freq[i];
          }
        }
		    for(j=1;j<=max;j++)
            {
                for(k=127;k>=32;k--)
                {
                    if(freq[k]==j)
                    {
                        printf("%d %d\n",k,j);
                    }

                }

            }
      flag=1;
    }
}
