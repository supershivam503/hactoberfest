#include<bits/stdc++.h>
using namespace std;

void merge(int * a,int s,int e){
     int mid=(s+e)/2;

     int i=s;
     int j=mid+1;
     int k=s;
 
    // temporary array
     int temp[100];
    
    while(i<=mid && j<=e){
        if(a[i]<a[j]){
            temp[k++]=a[i++];
        }
        else{
            temp[k++]=a[j++];
        }
    }
    while(i<=mid){
         temp[k++]=a[i++];
    }
    while(j<=e){
        temp[k++]=a[j++];
    }
    for(int i=s;i<=e;i++)
      a[i]=temp[i];


}

void merge_sort(int a[],int s,int e){
    // base case 1 or 0 elements
    if(s>=e)
      return ;

    // Follow 3 steps
    // 1. Divide
    int mid=(s+e)/2;

    // 2.Recursively call the arrays : s,mid and mid+1,e
    merge_sort(a,s,mid);
    merge_sort(a,mid+1,e);

    // 3. Merge the two parts
    merge(a,s,e);
    
}
int main(){
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
      cin>>a[i];

      merge_sort(a,0,n-1);

      for(int i=0;i<n;i++)
        cout<<a[i]<<" ";


}
