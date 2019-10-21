#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<char,string> mp;
    mp['a']=mp['A']="@";
    mp['b']=mp['B']="8";
    mp['c']=mp['C']="(";
    mp['d']=mp['D']="|)";
    mp['e']=mp['E']="3";
    mp['f']=mp['F']="#";
    mp['g']=mp['G']="6";
    mp['h']=mp['H']="[-]";
    mp['i']=mp['I']="|";
    mp['j']=mp['J']="_|";
    mp['k']=mp['K']="|<";
    mp['l']=mp['L']="1";
    mp['m']=mp['M']="[]\\/[]";
    mp['n']=mp['N']="[]\\[]";
    mp['o']=mp['O']="0";
    mp['p']=mp['P']="|D";
    mp['q']=mp['Q']="(,)";
    mp['r']=mp['R']="|Z";
    mp['s']=mp['S']="$";
    mp['t']=mp['T']="']['";
    mp['u']=mp['U']="|_|";
    mp['v']=mp['V']="\\/";
    mp['w']=mp['W']="\\/\\/";
    mp['x']=mp['X']="}{";
    mp['y']=mp['Y']="`/";
    mp['z']=mp['Z']="2";
    string s;
    getline(cin,s);
    for(int i=0;i<s.size();i++){
        if((s[i]>='a' && s[i]<='z') ||(s[i]>='A' && s[i]<='Z')){
            cout<<mp[s[i]];
        }
        else{
            cout<<s[i];
        }
    }
    cout<<endl;
}
