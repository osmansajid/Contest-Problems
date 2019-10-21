#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,m,j,min;
    scanf("%d %d",&n,&m);
    int a[m];
    int b[m];
        for(i=0;i<m;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+m);
    j=0;
    for(i=m-1;i>=0;i--)
    {
        b[j]=a[i];
        j++;
    }
    min=b[0]-b[n-1];
    for(i=0, j=n-1+i ;j<m; j++, i++)
    {
        if((b[i]-b[j])<min)
        {
            min=b[i]-b[j];
        }
    }
    printf("%d",min);
    return 0;
}
