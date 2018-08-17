#include <bits/stdc++.h>
using namespace std;

int djikstra(int s1, int d1,vector<vector<int>>&a,vector<vector<int>>&b,int n) {
     priority_queue< pair<int, int>, vector <pair<int, int>> , greater<pair<int, int>> > q;
     q.push(make_pair(0,s1));
    int dis[n];
    for(int i=0;i<n;i++)
        dis[i]=-1;
    dis[s1-1]=0;
     while(!q.empty())
     {
         int v=q.top().second;
         q.pop();
         for(int i=0;i<b[v-1][0];i++)
         {
                 int d;
                 d=dis[v-1]+a[v-1][b[v-1][i+1]];
                 if(dis[b[v-1][i+1]]==-1)
                 {
                     dis[b[v-1][i+1]]=d;
                     q.push(make_pair(d,b[v-1][i+1]+1));
                 }
                 else if(dis[b[v-1][i+1]]>d)
                 {
                     dis[b[v-1][i+1]]=d;
                     q.push(make_pair(d,b[v-1][i+1]+1));
                 }


         }
        if(v==d1)
            break;
     }
    return dis[d1-1];
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
    int n;
    cin>>n;
    map<string,int>s;
    vector<vector<int>>a(n);
    vector<vector<int>>b(n);
    for(int i=0;i<n;i++)
    {
        string s1;
        cin>>s1;
        s[s1]=i;
        int n1;
        scanf("%d",&n1);
        a[i] = vector<int>(n);
        b[i] = vector<int>(n1+1);
        b[i][0]=n1;
        for(int j=0;j<n1;j++)
          {
              int u,e;
              scanf("%d %d",&u,&e);
              a[i][u-1]=e;
              b[i][j+1]=u-1;
          }
    }
    int n2;
    scanf("%d",&n2);
    for(int i=0;i<n2;i++)
    {
        string s2,s3;
        cin>>s2>>s3;
        printf("%d\n",djikstra(s[s2]+1,s[s3]+1,a,b,n));
    }
    }
    return 0;
}
