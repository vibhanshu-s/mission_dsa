#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
    vector<long long> piles(3);
    cin>>piles[0]>>piles[1]>>piles[2];
    sort(piles.begin(),piles.end());
    if(piles[1] == piles[0] + 1 && piles[2] == piles[1] + 1)
        cout<<"YES"<<"\n";
    else cout<<"NO"<<"\n";
    }
    return 0;
}
