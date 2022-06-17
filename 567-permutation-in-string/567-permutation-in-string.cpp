class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector <int> s1hash(26,0);
        vector <int> s2hash(26,0);
        int len1=s1.size();
        int len2=s2.size();
        int left=0,right=0;
        if(len1>len2){
            return false;
        }
        while(right<len1){
            s1hash[s1[right]-'a']+=1;
            s2hash[s2[right]-'a']+=1;
            right+=1;
        }
        right-=1;
        while(right<len2){
            if(s1hash==s2hash)
                return true;
            right+=1;
            if(right!=len2)
                s2hash[s2[right]-'a']+=1;
            s2hash[s2[left]-'a']-=1;
            left+=1;
            }
            return false;
        
    }
};