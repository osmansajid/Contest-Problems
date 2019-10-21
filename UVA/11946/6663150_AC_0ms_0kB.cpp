#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
int main()
{
    char a[100];
    int t,i,j,l;


cin>>t;
{
getchar();
    for(j=0;j<t;j++)
    {
        while(gets(a)!='\0')
        {

            l=strlen(a);
            if(l==0)
            {
              break;
            }

        for(i=0;i<l;i++)
          {

           if(a[i]=='1') cout<<"I";
           else     if(a[i]=='2')cout<<"Z";
           else     if(a[i]=='3')cout<<"E";
           else     if(a[i]=='4')cout<<"A";
           else     if(a[i]=='5')cout<<"S";
           else     if(a[i]=='6')cout<<"G";
           else     if(a[i]=='7')cout<<"T";
           else     if(a[i]=='8')cout<<"B";
           else     if(a[i]=='9')cout<<"P";
           else     if(a[i]=='0')cout<<"O";
           else cout<<a[i];

          }
          cout<<endl;

        }
       if(j!=t-1)cout<<endl;
    }
}

}
