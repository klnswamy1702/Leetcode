// Last updated: 07/11/2025, 13:40:48
// class Solution {
// public:
//     int countPaths(vector<vector<int>>& grid) {
        
//     }
// };


// #define ll long long
// class Solution {
// public:
//     ll m,n;
//     ll mod=1e9+7;
//     ll dp[1005][1005],a[1005][1005],vis[1005][1005];
//     ll dx[4]={1,-1,0,0};
//     ll dy[4]={0,0,1,-1};
//     void dfs(ll x,ll y){
//         if(vis[x][y])
//             return;
//         vis[x][y]=1;
//         dp[x][y]=1;
//         for(ll i=0;i<4;i++){
//             ll x1=x+dx[i],y1=y+dy[i];
//             if(x1>=0 && x1<m && y1>=0 && y1<n && a[x][y]<a[x1][y1]){
//                 dfs(x1,y1);
//                 if(dp[x1][y1]){
//                     dp[x][y]=(dp[x][y]+dp[x1][y1])%mod;
//                 }
//             }
//         }
//     }
//     int countPaths(vector<vector<int>>& matrix) {
//         m=matrix.size();
//         n=matrix[0].size();
//         for(ll i=0;i<m;i++){
//             for(ll j=0;j<n;j++){
//                 dp[i][j]=0;
//                 a[i][j]=matrix[i][j];
//                 vis[i][j]=0;
//             }
//         }
//         ll ans=0;
//         for(ll i=0;i<m;i++){
//             for(ll j=0;j<n;j++){
//                 if(vis[i][j]==0){
//                     dfs(i,j);
//                 }
//                 ans=(ans+dp[i][j])%mod;
//             }
//         }
//         return ans;
//     }
// };


// static int MOD=1e9+7;
// static vector<int> dirs={0,1,0,-1,0};
// class Solution {
// public:
//     vector<vector<long>> memo;
//     long dp(vector<vector<int>>& grid,int i,int j) {
//         long result=1;  // Contribution of current cell as an increasing sequence.
//         if(memo[i][j]!=-1)  // Return the cached results if they exist.
//             return memo[i][j];
//         for(int d=0;d<4;d++) {  // Check all 4 directions.
//             int x=i+dirs[d],y=j+dirs[d+1];
//             if(x>=0&&y>=0&&x<grid.size()&&y<grid[0].size()&&grid[x][y]>grid[i][j])
//                 result=(result+dp(grid,x,y))%MOD;       // Add the total number of cells in the longest path for all directions.
//         }
//         return memo[i][j]=result;
//     }
//     int countPaths(vector<vector<int>>& grid) {
//         long result=0;
//         memo.resize(grid.size(),vector<long>(grid[0].size(),-1));
//         for(int i=0;i<grid.size();i++)      // For each cell as a starting point calculate the number of increasing paths it can contribute.
//             for(int j=0;j<grid[0].size();j++)
//                 result=(result+dp(grid,i,j))%MOD;
//         return result;
//     }
// };


#define ll long long int
ll mod=1e9+7;
class Solution {
public:
    vector<int> dx={1,-1,0,0};
    vector<int> dy={0,0,1,-1};
    int n,m;
    bool isvalid(int i,int j)
    {
        return (i>=0&&i<n&&j>=0&&j<m);
    }
    int dfs( int i, int j,vector<vector<int>> &dp,vector<vector<int>> &grid)
    {
        if(dp[i][j]!=0)
        return dp[i][j];
        if(i<0||j<0||i>=n&&j>=m)
        return 0;
        int ans=1;
        for(int k=0;k<4;k++)
        {
            int new_x,new_y;
            new_x=i+dx[k];
            new_y=j+dy[k];
            
            if(isvalid(new_x,new_y)&&grid[new_x][new_y]>grid[i][j])
            {
                ans=(ans%mod+dfs(new_x,new_y,dp,grid)%mod)%mod;
            }
        }
        
        return dp[i][j]=ans%mod;
    }
    int countPaths(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();

        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vector<vector<int>> dp(n,vector<int>(m,0));
        ll sum=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                 sum=(sum%mod+dfs(i,j,dp,grid)%mod)%mod;
            }
        }
        return sum%mod;
    }
};