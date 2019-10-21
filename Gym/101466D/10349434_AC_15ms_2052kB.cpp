#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    while(n!=0){
        if(n%2==1){
            s.push_back('A');
            n=n/2;
        }
        else {
            s.push_back('B');
            n=(n/2)-1;
        }
    }
    reverse(s.begin(),s.end());
    cout<<s<<endl;
}
