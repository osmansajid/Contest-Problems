#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    int mark[366];
    memset(mark,0,sizeof mark);
    for(int i=0;i<n;i++){
        cin>>a[i];
        mark[a[i]]=1;
    }
    int st=0,cl=0,cnt=0,m=0;
    for(int i=1;i<=365;i++){
        //if(st==1){
        if(cl+(m*1)>19){
            cnt++;
            cl=0;
            m=0;
        }
        else cl+=(m*1);
        //cout<<cl<<endl;
        if(mark[i]==1){
            //st=1;
            m++;
        }
        //cout<<cl<<" "<<i<<endl;

        //if(i==84)cout<<cl<<endl;
    }
    if(cl>0 || m>0){
        cnt++;
    }
    cout<<cnt<<endl;
}
