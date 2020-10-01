#include <bits/stdc++.h>
#include <algorithm>
#include <climits>
using namespace std;

// Minimum steps to One
// n=> n/3 or n/2 or n-1
int minStepsTopDown(int n,int dp[]){
    // Base Case
    if(n==1)
     return 0;

    //  Recursive Case
    // Lookup if n is already computed
    if(dp[n]!=0)
      return dp[n];

    int op1,op2,op3;
    op1=op2=op3=INT_MAX;

    if(n%3==0)
      op1=minStepsTopDown(n/3,dp)+1;

    if(n%2==0)
      op2=minStepsTopDown(n/2,dp)+1;

    op3=minStepsTopDown(n-1,dp)+1;

    int ans=min(min(op1,op2),op3);

    return dp[n]=ans;
}

int minStepsBottomUp(int n2,int *dp2){
//   Base Case
    dp2[1]=0;

   for(int i=2;i<=n2;i++){
       int op1,op2,op3;
    op1=op2=op3=INT_MAX;

    if(i%3==0)
      op1=dp2[i/3];

    if(i%2==0)
      op2=dp2[i/2];

    op3=dp2[i-1];

    dp2[i]=min(min(op1,op2),op3)+1;

   }
    return dp2[n2];
}


int main(){
    int n; cin>>n;
    int n2=n;
    int dp[n+1],dp2[n+1];
    for(int i=0;i<=n;i++)
    { dp[i]=0; dp2[i]=0; }

    int x=minStepsTopDown(n,dp);
    int y=minStepsBottomUp(n2,dp2);
    cout<<x<<"\n"<<y;

}
