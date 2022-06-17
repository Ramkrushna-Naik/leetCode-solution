class Solution {
public:
    int func(vector<int>& h) {
        int n=h.size(),m=0;
        stack<int> s;
        h.push_back(INT_MIN);
        vector<int> a(n+1,0);
        for(int i=0;i<=n;i++){
            while(!s.empty() and h[s.top()]>=h[i]){
                if(h[s.top()]>h[i]){
                    int b=a[s.top()],c=i-1;
                    m=max(m,(c-b+1)*h[s.top()]);
                }
                s.pop();
            }
            if(!s.empty()) a[i]=s.top()+1;
            s.push(i);
        }
        return m;
    }
    
    int maximalRectangle(vector<vector<char>>& mat) {
        int n=mat[0].size(),m=0;
        vector<int> v(n,0);
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]=='1') v[j]++;
                else v[j]=0;
            }
            m=max(m,func(v));
        }
        return m;
    }
};