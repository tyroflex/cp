#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define debug(x) cout << #x << " = " << x << endl
#define vl vector<ll>

void precompute() {

}

void work() {
    ll n, in;
    cin >> n;
    map<ll, ll> o;
    for ( int i = 0 ; i < n ; i++ ) {
        cin >> in;
        o[in]++;
    }
    vector<ll> occur = {0};
    for ( auto i : o ) {
        occur.pb(i.second);
    }
    sort(occur.begin()+1, occur.end(), greater<>());
    vector<ll> pref(occur.size(), 0);
    ll os = occur.size()-1;
    vector<ll> ans(n+1, 1e18);
    for ( int i = 1 ; i <= os ; i++ ) {
        pref[i] = pref[i-1] + occur[i];
    }
    for ( int i = 1 ; i <= n ; i++ ) {
        // if all suffice
        if ( occur[os] >= i ) {
            ans[i] = 0;
            continue;
        }
        // otherwise find the threshold where the number suffice
        ll threshold = 0;
        ll left = 1, right = os;
        while ( left <= right ) {
            ll mid = left + ( right - left ) / 2;
            if ( occur[mid] >= i ) {
                threshold = max(threshold, mid);
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        // we know how many we can use from the left side
        ll moreStorage = pref[threshold] - ( threshold*i );
        // find maximum number we can make.
        ll starter = threshold;
        left = threshold+1, right = os;
        while ( left <= right ) {
            ll mid = left + ( right - left ) / 2;
            // we can make this amount of number
            if ( moreStorage+(pref[os]-pref[mid]) >= ((mid-threshold)*i)-(pref[mid]-pref[threshold]) ) {
                starter = max(mid, starter);
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        // ternary between the two
        // cout << threshold << " " << starter << endl;
        left = threshold, right = starter;
        while ( left <= right ) {
            if ( right-left <= 10 ) break;
            ll m1 = left + ( right - left ) / 3;
            ll c1 = max(((m1-threshold)*i) - (pref[m1]-pref[threshold]), pref[os]-pref[m1]);
            ll m2 = right - ( right - left ) / 3;
            ll c2 = max(((m2-threshold)*i) - (pref[m2]-pref[threshold]), pref[os]-pref[m2]);
            if ( c1 <= c2 ) {
                ans[i] = min(ans[i], c1);
                right = m2;
            } else {
                ans[i] = min(ans[i], c2);
                left = m1;
            }
        }
        for ( int j = left ; j <= right ; j++ ) {
            ll leftover = (pref[os]-pref[j]);
            ll required = ((j-threshold)*i) - (pref[j]-pref[threshold]);
            // cout << leftover <<  " " << required << endl;
            ans[i] = min(ans[i], max(required, leftover));
        }
    }
    for ( int i = 1 ; i <= n ; i++ ) {
        cout << ans[i];
        if ( i < n ) cout << " ";
        else cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    ll t = 1;
    // cin >> t;
    while ( t-- ) work();
    return 0;
}