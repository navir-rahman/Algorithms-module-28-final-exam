#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];

int unb_knp(int n, int s, int w[]){
    if(n==0) return 0;
    if(s==0) return 0;
if(dp[n][s]!=0)return dp[n][s];
    if(w[n-1] <=s){
        int op1= 1+ unb_knp(n, s-w[n-1], w);
        int op2= unb_knp(n-1,s,w);
        return max(op1, op2);
    }else{
        return unb_knp(n-1,s,w);
    }
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,M;
        cin>>n>>M;
        int a[n];
        for (int i = 0; i <n; i++)
        {
            cin>>a[i];
        }
        int s=1000-M;
        
        dp[0][0]=true;
        for (size_t i = 1; i <=s; i++)
        {
            dp[0][i]=false;
        }

        cout<<unb_knp(n,s,a)<<endl;

        
    }
    
    return 0;
}