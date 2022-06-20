// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:
	int minStepToReachTarget(vector<int>&S, vector<int>&T, int N){
	    queue<pair<int,int>> q;
	    q.push({S[0]-1,S[1]-1});
	    bool vis[N][N];
	    memset(vis,false,sizeof(vis));
	    int ans=0;
	    bool found=false;
	    int moveI[8] = {1,1,-1,-1,2,2,-2,-2};
	    int moveJ[8] = {2,-2,2,-2,1,-1,1,-1};
	    while(!q.empty()){
	        int sz = q.size();
	        for(int i=0;i<sz;i++){
	            auto curr=q.front();
	            q.pop();
	            if(T[0]-1==curr.first and T[1]-1==curr.second) found=true;
	            if(found) break;
	            for(int k=0;k<8;k++){
	                int ni = curr.first+moveI[k];
	                int nj = curr.second+moveJ[k];
	                if(ni>=0 and nj>=0 and ni<N and nj<N){
	                    if(!vis[ni][nj]){
	                        vis[ni][nj]=true;
	                        q.push({ni,nj});
	                    }
	                }
	            }
	        }
            if(!found) ans++;
	        else break;
	    }
	    return ans;
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends