#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,a,b;
        cin>>n>>a>>b;
        if(n%2==1 && b<0)
            cout<<b<<endl;
        else if(n%2==1 && b>=0)
        {
            ll count=0;
            ll temp=n;
            for(ll i=3;i*i<=temp;i++)
            {
                while(n%i==0 || n>1)
                {
                    n/=i;
                    count+=b;
                }
                if(n==1)
                    break;
            }
            cout<<count<<endl;
        }
        else
        {
            ll count=0,temp=n;
            while(n%2==0 && n>1)
            {
                n/=2;
                count+=a;
            }
            if(n>1)
            {
                for(ll i=3;i*i<=temp;i++)
                {
                    while(n%i==0 || n>1)
                    {
                        n/=i;
                        count+=b;
                    }
                    if(n==1)
                      break;
                }
            }
            cout<<max(count,a)<<endl;
        }
    }
    return 0;
}