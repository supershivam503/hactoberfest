#include<bits/stdc++.h>
#include <climits>
using namespace std;

int MinCoinsBottomUp(int N,int coins[],int T){
    int dp[1000]={0};
// Iterate over all states 1....N
    for(int n=1;n<=N;n++){
    // Initialise the current ans as INT MAX
        dp[n]=INT_MAX;

        for(int i=0;i<T;i++){
            if(n-coins[i]>=0){
                int subprob = dp[n-coins[i]];
                dp[n]=min(dp[n],subprob+1);
            }
        }
    }
    return dp[N];

}
int main(){
    int N; cin>>N;
    int coins[]={1,3,10};
    int T=sizeof(coins)/sizeof(int);

    cout<<MinCoinsBottomUp(N,coins,T);

}