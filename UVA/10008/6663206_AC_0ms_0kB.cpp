#include<bits/stdc++.h>
using namespace std;
int main()
{
    string b;
    //string b=" ";
    int i,q,j,t,k,freq[130],count;
    scanf("%d",&t);
    getchar();
    for(q=1;q<=t;q++)
    {
        getline(cin,b);
        int m=0;
        for(i=0;i<b.size();i++)
        {
            if((b[i]>='A'&& b[i]<='Z')||(b[i]>='a'&&b[i]<='z'))
              {
                  b[m]=tolower(b[i]);
                  m++;
              }
        }
        if(q==1)
        {
            for(i=0;i<130;i++)
            {
                freq[i]=0;
            }
        }
       for(i=122;i>=97;i--)
        {
            count=0;
            for(j=m-1;j>=0;j--)
                {
                    if(i==b[j])
                    {
                        count++;
                    }
                }

               //printf("%d\n",count);
                freq[i]=freq[i]+count;
        }
    }
        int max = 0;
		for(i=97;i<=122;i++)
        {
          //-printf("%d\n",freq[i]);
          if(freq[i]>max)
          {
            max = freq[i];
          }
        }
            for(j=max;j>=1;j--)
            {
                for(k=97;k<=122;k++)
                {
                    if(freq[k]==j)
                    {
                        printf("%c %d\n",k-32,j);
                    }

                }

            }


}
