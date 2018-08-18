#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        vector<int>a;
        for(int i=0;i<n;i++)
        {
            int b;
            cin>>b;
            a.push_back(b);
        }
        vector<vector<pair<int,int>>>t(n);
        int h;
        for(int i=0;i<n;i++)
        {
            h=0;
            for(int j=n-1-i;j>=0;j--)
            {
                if(i==0)
                t[i+h]=vector<pair<int,int>>(n);
                if(h==i+h)
                {t[h][i+h].first=0;
                 t[h][i+h].second=a[h];
                }
                else{
                int min1=1000000,sum;
                for(int k=h;k<i+h;k++)
                {
                    sum=t[h][k].second*t[k+1][i+h].second+t[h][k].first+t[k+1][i+h].first;
                    if(sum<min1)
                        {min1=sum;
                         t[h][i+h].second=(t[h][k].second+t[k+1][i+h].second)%100;
                        }
                }
                t[h][i+h].first=min1;
                }
                h++;

            }
        }
        cout<<t[0][n-1].first<<"\n";
    }
}
