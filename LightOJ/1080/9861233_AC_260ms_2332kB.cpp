#include<bits/stdc++.h>
using namespace std;
int tree[100000];

int sum(int indx)
{
    int sum = 0;
    while (indx){
        sum += tree[indx];
        indx -= indx & -indx;
    }
    return sum;
}
//updates->
void update(int indx,int n, int val){
    while (indx <= n){
        tree[indx] += val;
        indx += indx & (-indx);
    }
}

int main()
{
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        memset(tree,0,sizeof tree);
        string s;
        cin>>s;
        int n=s.size();
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",++tc);
        while(q--){
            getchar();
            char ch;
            scanf("%c",&ch);
            if(ch=='I'){
                int a,b,x;
                scanf("%d %d",&a,&b);
                update(a,n,1);
                update(b+1,n,-1);
            }
            else{
                int a,x;
                scanf("%d",&a);
                if(sum(a)%2==0){
                    printf("%d\n",s[a-1]-'0');
                }
                else{
                    printf("%d\n",1-(s[a-1]-'0'));
                }
            }
        }
    }
}
