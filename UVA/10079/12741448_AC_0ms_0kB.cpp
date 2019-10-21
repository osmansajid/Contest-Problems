#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    while(cin>>n){
        if(n<0){
            break;
        }
        cout<<(n*n + n +2)/2<<endl;
    }
}
