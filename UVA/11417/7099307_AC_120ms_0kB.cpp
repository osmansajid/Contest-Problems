#include<bits/stdc++.h>
using namespace std;
int GCD(int i,int j)
{
    while(j!=0)
    {
        i=i%j;
        swap(i,j);
    }
    return i;;
}
int main()
{
    int G,i,j,N;
    while(cin>>N)
    {
        if(N==0)
        {
            break;
        }
        G=0;
        for(i=1;i<N;i++)
        {
            for(j=i+1;j<=N;j++)
            {
             G+=GCD(i,j);
            }
        }
        cout<<G<<endl;
    }
    return 0;
}
