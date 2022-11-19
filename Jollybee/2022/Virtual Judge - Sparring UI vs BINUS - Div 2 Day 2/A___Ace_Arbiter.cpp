#include <bits/stdc++.h>
using namespace std;

int n, arr[2][105], alice[105], bob[105], ron[105];

void no(int x){
    cout << "error " << x << endl;
}

void solve(){
    cin >> n;
    for(int i=1; i<=n; i++){
        int x, y;
        scanf("%d-%d", &x, &y);
        arr[0][i] = x;
        arr[1][i] = y;
    }
    int gameend = 0;
    for(int i=1; i<=n; i++){
        int temp = arr[0][i] + arr[1][i];
        ron[i] = temp;
        if(ron[i] < ron[i-1]){
            no(i); return;
        }

        if(ron[i] == ron[i-1]){
            if(!(arr[0][i] == arr[0][i-1] && arr[1][i] == arr[1][i-1])){
                no(i); return;
            }
        }
        int turn;
        turn = ((ron[i]+1)/2)%2;
        if(turn == 1){
            bob[i] = arr[0][i];
            alice[i] = arr[1][i];
        }
        else{
            bob[i] = arr[1][i];
            alice[i] = arr[0][i];
        }

        if(alice[i] < alice[i-1]){
            no(i); return;
        }
        if(bob[i] < bob[i-1]){
            no(i); return;
        }
        int gain = (alice[i] - alice[i-1]) + (bob[i] - bob[i-1]);
        if(gain != ron[i] - ron[i-1]){
            no(i); return;
        }
        if(gameend != 0){
            if(gain > 0){
                no(i); return;
            }
        }
        if(alice[i] == 11) gameend = 1;
        if(bob[i] == 11) gameend = -1;
        if(alice[i] == 11 && bob[i] == 11){
            no(i); return;
        }
    }
    cout << "ok" << endl;
}

int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    solve();

    return 0;
}