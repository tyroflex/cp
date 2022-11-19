#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, st, arr[2][2][55], dp[2][2][55], ceker[5];

ll calminleft(ll num){
    ll zer = 0;
    if(num <= 0){
        ceker[0] = 1;
        return num;
    }
    else{
        return zer;
    }
}

ll calmaxleft(ll num){
    ll zer = 0;
    if(num >= 0){
        ceker[1] = 1;
        return num;
    }
    else{
        return zer;
    }
}

ll calminright(ll num){
    ll zer = 0;
    if(num <= 0){
        ceker[2] = 1;
        return num;
    }
    else{
        return zer;
    }
}

ll calmaxright(ll num){
    ll zer = 0;
    if(num >= 0){
        ceker[3] = 1;
        return num;
    }
    else{
        return zer;
    }
}

ll calc(ll wer, ll i, ll val){
    if(arr[wer][1][i]) return val * arr[wer][0][i];
    else return val + arr[wer][0][i];
}

void solve(){
    cin >> n >> st;
    for(ll i=1; i<=n; i++){
        ll x, y; char a, b;
        cin >> a >> x >> b >> y;
        arr[0][0][i] = x;
        arr[1][0][i] = y;
        if(a == '+') arr[0][1][i] = 0;
        else arr[0][1][i] = 1;
        if(b == '+') arr[1][1][i] = 0;
        else arr[1][1][i] = 1;
    }

    dp[0][0][1] = (calc(0, 1, st));
    dp[0][1][1] = (calc(0, 1, st));
    dp[1][0][1] = (calc(1, 1, st));
    dp[1][1][1] = (calc(1, 1, st));

    for(ll i=2; i<=n; i++){
        ll temp[4];
        temp[0] = dp[0][0][i-1];
        temp[1] = dp[0][1][i-1];
        temp[2] = dp[1][0][i-1];
        temp[3] = dp[1][1][i-1];
        dp[0][0][i] = (min(calc(0, i, temp[0]), min(calc(0, i, temp[1]), min(calc(0, i, temp[2]), calc(0, i, temp[3])))));
        dp[0][1][i] = (max(calc(0, i, temp[0]), max(calc(0, i, temp[1]), max(calc(0, i, temp[2]), calc(0, i, temp[3])))));
        dp[1][0][i] = (min(calc(1, i, temp[0]), min(calc(1, i, temp[1]), min(calc(1, i, temp[2]), calc(1, i, temp[3])))));
        dp[1][1][i] = (max(calc(1, i, temp[0]), max(calc(1, i, temp[1]), max(calc(1, i, temp[2]), calc(1, i, temp[3])))));
    }
    ll ans = LLONG_MIN;
        ans = max(ans, dp[0][0][n]);
        ans = max(ans, dp[0][1][n]);
        ans = max(ans, dp[1][0][n]);
        ans = max(ans, dp[1][1][n]);
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // int t; cin >> t; while(t--) solve();
    solve();
    // int t; cin >> t; for(int i=1; i<=t; i++) solve(i);

    return 0;
}