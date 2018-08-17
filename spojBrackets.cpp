#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct node
{
    int open;
    int close;
};

node tree[3*30005];
char a[30005];

void update(int l,int r,int qs,int qe,int i)
{
    if(qs==l&&qe==r)
    {
        if(tree[i].open==1)
        {tree[i].open=0;
         tree[i].close=1;
        }
        else
        {
         tree[i].open=1;
         tree[i].close=0;
        }
    }
    else
    {
        int m=(l+r)/2;
       if(qs <= m)
         update(l,m,qs,qe,2*i+1);
      else
         update(m+1,r,qs,qe,2*i+2);
        tree[i].open=(tree[2*i+1].open+tree[2*i+2].open-min(tree[2*i+1].open,tree[2*i+2].close));
        tree[i].close=(tree[2*i+1].close+tree[2*i+2].close-min(tree[2*i+1].open,tree[2*i+2].close));
    }
}

void build(int l,int r,int i)
{
    if(l==r)
    {
        if(a[l]=='(')
          {tree[i].open=1;
          tree[i].close=0;}
        else
          {tree[i].close=1;
          tree[i].open=0;}
    }
    else{
    int m=(l+r)/2;
    build(l,m,2*i+1);
    build(m+1,r,2*i+2);
    int c=min(tree[2*i+1].open,tree[2*i+2].close);
    tree[i].open=(tree[2*i+1].open+tree[2*i+2].open-c);
    tree[i].close=(tree[2*i+1].close+tree[2*i+2].close-c);}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while(t<=10)
    {
        int n;
        cin>>n;
        int i=0;
        for(i=0;i<n;i++)
           cin>>a[i];
        a[i]='\0';
        build(0,n-1,0);
        int m;
        cin>>m;
        cout<<"Test "<<t<<":\n";
        while(m--)
        {
            int s;
            cin>>s;
            if(s)
            {
              update(0,n-1,s-1,s-1,0);
            }
            else
            {
               if(tree[0].open==0&&tree[0].close==0)
                  cout<<"YES\n";
               else
                cout<<"NO\n";
            }
        }
        t++;
    }
}


