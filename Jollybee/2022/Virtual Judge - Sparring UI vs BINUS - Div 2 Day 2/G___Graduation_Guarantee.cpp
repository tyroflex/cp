//  G - Graduation Guarantee
//  Francis Alexander

#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
// #define double long double

int n, k;
double p[5005];
double dp[5005][2*5005];

void solve(){
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> p[i];
    }
    sort(p+1, p+1+n);
    reverse(p+1,p+1+n);
    dp[0][5004]=1;
    double ans=0;
    for(int i=1;i<=n;i++){
        double temp=0;
        for(int j=5004-n;j<=5004+n;j++){
            dp[i][j]=(p[i]*dp[i-1][j-1]) + ((1-p[i])*dp[i-1][j+1]);
            if(j>=k+5004){
                temp+=dp[i][j];
            }
        }
        ans=max(ans,temp);
    }
    cout<<setprecision(15)<<fixed<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}