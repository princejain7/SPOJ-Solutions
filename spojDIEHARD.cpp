#include<bits/stdc++.h>
using namespace std;

map<pair<int,int>,int>m;

int diehard(int h,int a)
{
    if(m[{h,a}]!=0)
        return m[{h,a}];
    else
    {if(h<=0||a<=0)
        return m[{h,a}]=0;
    else
    {
          return m[{h,a}]=max(2+diehard(h-2,a-8),2+diehard(h-17,a+7));

    }}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=0;
    cin>>t;
    while(t--)
    {
        int h,a;
        cin>>h>>a;
        cout<<diehard(h,a)-1<<"\n";
    }
}
