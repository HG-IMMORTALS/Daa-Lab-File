#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>arr,int i,int j,vector<vector<int>>&dp)
{
if(i>=j)
return 0;
if(dp[i][j]!=-1)
return dp[i][j];
int mn=INT_MAX;
for(int k=i;k<j;k++)
{
int tempans=solve(arr,i,k,dp)+solve(arr,k+1,j,dp)+arr[i-1]*arr[k]*arr[j];
if(tempans<mn)
mn=tempans;
}
return dp[i][j]=mn;
}
int main()
{
int n,n1,n2;
cin>>n;
vector<int>arr;
for(int i=0;i<n;i++)
{
cin>>n1>>n2;
if(i==0)
{
arr.push_back(n1);
arr.push_back(n2);
}
else
arr.push_back(n2);
} 
n=arr.size();
vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
cout<<solve(arr,1,n-1,dp); }