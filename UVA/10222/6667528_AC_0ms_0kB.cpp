#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    while(getline(cin,a))
    {
        int i;
    for(i=0;i<a.size();i++)
    {
        a[i]=tolower(a[i]);
        if(a[i]=='2')cout<<"`";
        else if(a[i]=='3')cout<<"1";
        else if(a[i]=='4')cout<<"2";
        else if(a[i]=='5')cout<<"3";
        else if(a[i]=='6')cout<<"4";
        else if(a[i]=='7')cout<<"5";
        else if(a[i]=='8')cout<<"6";
        else if(a[i]=='9')cout<<"7";
        else if(a[i]=='0')cout<<"8";
        else if(a[i]=='-')cout<<"9";
        else if(a[i]=='=')cout<<"0";
        else if(a[i]=='d')cout<<"a";
        else if(a[i]=='f')cout<<"s";
        else if(a[i]=='g')cout<<"d";
        else if(a[i]=='h')cout<<"f";
        else if(a[i]=='j')cout<<"g";
        else if(a[i]=='k')cout<<"h";
        else if(a[i]=='l')cout<<"j";
        else if(a[i]==';')cout<<"k";
        else if(a[i]==39)cout<<"l";
        else if(a[i]=='c')cout<<"z";
        else if(a[i]=='v')cout<<"x";
        else if(a[i]=='b')cout<<"c";
        else if(a[i]=='n')cout<<"v";
        else if(a[i]=='m')cout<<"b";
        else if(a[i]==',')cout<<"n";
        else if(a[i]=='.')cout<<"m";
        else if(a[i]=='/')cout<<",";
        else if(a[i]=='[')cout<<"o";
        else if(a[i]==']')cout<<"p";
        else if(a[i]=='\\')cout<<"[";
        else if(a[i]=='e')cout<<"q";
        else if(a[i]=='r')cout<<"w";
        else if(a[i]=='t')cout<<"e";
        else if(a[i]=='y')cout<<"r";
        else if(a[i]=='u')cout<<"t";
        else if(a[i]=='i')cout<<"y";
        else if(a[i]=='o')cout<<"u";
        else if(a[i]=='p')cout<<"i";
        else cout<<a[i];
    }
    printf("\n");
    }

}
