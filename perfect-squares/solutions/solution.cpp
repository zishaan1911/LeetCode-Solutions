class Solution {
public:
    int fun(vector<int>&s, int idx, int sum, vector<vector<int>>&dp)
    {
        if(sum==0) return 0; 
        if(idx==0)
        {
            if(sum%s[idx]==0) return sum/s[idx];
            return 1e7;
        }
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        int nt = fun(s,idx-1,sum,dp);
        int t = INT_MAX;
        if(s[idx]<=sum) t = 1 + fun(s,idx,sum-s[idx],dp);
        return dp[idx][sum] = min(t,nt);
    }
    int numSquares(int n) 
    {
        vector<int>s;
        int i=1;
        while(1)
        {
            if(i*i<=n)
            {
                s.push_back(i*i);
                i++;
            }
            else break;
        }
        int size = s.size();
        vector<vector<int>>dp(size,vector<int>(n+1,-1)); 
        return fun(s,size-1,n,dp);
    }
};