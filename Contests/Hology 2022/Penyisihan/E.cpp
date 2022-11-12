//
// Created by Tyrone Matthew on 11/5/2022.
//
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define endl '\n'
#define all(x) (x).begin(), (x).end()

bool comp( const pair<ll, pair<double, string>>& p1, const pair<ll, pair<double, string>>& p2 ) {
    return p1.first < p2.first;
}

void precompute() {

}

void work() {
    ll n;
    cin >> n;
    string dummy;
    getline(cin, dummy);
    string gn;
    vector<pair<string, pair<double, string>>> d;
    for ( int i = 0 ; i < n ; i++ ) {
        getline(cin, gn);
        for ( int j = 0 ; j < gn.length() ; j++ ) if ( gn[j] == ',' ) gn[j] = '.';
//        cout << gn << endl;
        stringstream ss(gn);
        pair<string, pair<double, string>> p;
        ss >> p.second.second >> p.second.first >> p.first;
        reverse(all(p.first));
        d.pb(p);
    }
    sort(all(d));
    ll counter = 1;
    for ( int j = 0 ; j < d.size() ; j++ ) {
        cout << counter << ". " << d[j].second.second << " : ";
        cout << fixed << setprecision(1) << round(d[j].second.first * (d[j].first[0]-'0') * 1.0) << endl;
        counter++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
//    cin >> t;
    while ( t-- ) work();
    return 0;
}