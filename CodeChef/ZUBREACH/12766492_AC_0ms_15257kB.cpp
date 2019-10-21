#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,tc=0;
    cin>>t;
    while(t--){
        int n,m,p,q,c,row=0,col=0;
        cin>>m>>n>>p>>q>>c;
        string s;
        cin>>s;
        for(int i=0;i<s.size();i++){
            if(s[i]=='U') row+=1;
            else if(s[i]=='D') row-=1;
            else if(s[i]=='R') col+=1;
            else col-=1;
        }
        //cout<<row<<" "<<col<<endl;
        if(row==q && col==p) cout<<"Case "<<++tc<<": REACHED"<<endl;
        else if(row>=0 && row<=n && col>=0 && col<=m) cout<<"Case "<<++tc<<": SOMEWHERE"<<endl;
        else cout<<"Case "<<++tc<<": DANGER"<<endl;
    }
}
