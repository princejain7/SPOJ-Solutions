#include<bits/stdc++.h>
using namespace std;
#define INTMAX 25000001

int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
    {
        int f,e;
        cin>>f>>e;
        int n;
        cin>>n;
        vector<pair<int ,int>>a;
        for(int i=0;i<n;i++)
            {
                int p,w;
                cin>>p>>w;
                a.push_back(make_pair(w,p));
            }
        sort(a.begin(),a.end());
        long long int dp[e-f+1];
        for(int i=0;i<=e-f;i++)
                dp[i]=INTMAX;

        dp[0]=0;
        for(int i=0;i<n;i++)
          {
            for(int j=1;j<=e-f;j++)
              {
                if(j>=a[i].first)
                    {
                        if(dp[j-a[i].first]!=INTMAX)
                        dp[j]=min(dp[j],dp[j-a[i].first]+a[i].second);
                    }

                }
            }
        if(dp[e-f]!=INTMAX)
             cout<<"The minimum amount of money in the piggy-bank is "<<dp[e-f]<<".\n";
        else
            cout<<"This is impossible.\n";

    }
}
