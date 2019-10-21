#include<bits/stdc++.h>
using namespace std;
int n,q,blk;
int a[1000010],org[1000010],frq[1000010];
int tot=0;

namespace fastio{
    int ptr, ye;
    char temp[25], str[32333667], out[15333667];

    void init(){
        ptr = 0, ye = 0;
        fread(str, 1, 32333667, stdin);
    }

    inline int number(){
        int i, j, val = 0;

        while (str[ptr] < 45 || str[ptr] > 57) ptr++;
        while (str[ptr] > 47 && str[ptr] < 58) val = (val * 10) + (str[ptr++] - 48);
        return val;
    }

    inline void convert(int x){
        int i, d = 0;
        if (x < 0) x = -x, out[ye++] = 45;

        for (; ;){
            temp[++d] = (x % 10) + 48;
            x /= 10;
            if (!x) break;
        }
        for (i = d; i; i--) out[ye++] = temp[i];
        out[ye++] = 10;
    }

    inline void print(){
        fwrite(out, 1, ye, stdout);
    }
}

struct query{
    int l,r,id,d;

    inline query() {}

    inline query(int a, int b, int c){
        id = c;
        l = a, r = b, d = l / blk;
    }

    inline bool operator < (const query& other) const{
        if (d != other.d) return (d < other.d);
        return ((d & 1) ? (r > other.r) : (r < other.r));
    }
}qq[1000010];


void add(int pos){
    frq[a[pos]]++;
    //cout<<a[pos]<<" "<<frq[a[pos]]<<" "<<tot<<endl;
    if(frq[a[pos]]>1)tot=tot^org[pos];
}

void rmv(int pos){
    frq[a[pos]]--;
    if(frq[a[pos]]>0)tot=tot^org[pos];
}

int main()
{
    fastio::init();
    n=fastio::number();
    blk=sqrt(n);
    //cout<<n<<endl;
    unordered_map<int,int>mp;
    int cur=1;
    for(int i=0;i<n;i++){
        a[i]=fastio::number();
        org[i]=a[i];
    }

    for(int i=0;i<n;i++){
        //scanf("%d",&a[i]);
        if(mp[a[i]]!=0){
            a[i]=mp[a[i]];
        }
        else{
            mp[a[i]]=cur;
            a[i]=cur;
            cur++;
        }
        //cout<<a[i]<<endl;
    }

    q=fastio::number();

    for(int i=0;i<q;i++){
        int l,r;
        l=fastio::number();
        r=fastio::number();
        l--;
        r--;
        qq[i]=query(l,r,i);
    }

    sort(qq,qq+q);

    int curl=0,curr=-1;
    int ans[q];
    for(int i=0;i<q;i++){
        //cout<<qq[i].l<<" "<<qq[i].r<<endl;
        while(curl<qq[i].l) rmv(curl++);
        while(curl>qq[i].l) add(--curl);
        while(curr<qq[i].r) add(++curr);
        while(curr>qq[i].r) rmv(curr--);
        ans[qq[i].id]=tot;
        //cout<<qq[i].l<<" "<<qq[i].r<<" "<<tot<<endl;
    }

    for(int i=0;i<q;i++){
        fastio::convert(ans[i]);
    }
    fastio::print();
    return 0;
}

