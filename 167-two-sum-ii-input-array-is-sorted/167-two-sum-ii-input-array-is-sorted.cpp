class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int st=0;
        int ed=numbers.size()-1;
        while(st<ed){
            int sum=numbers[st]+numbers[ed];
            if(sum>target){
                ed--;
            }
            else if(sum<target){
                st++;
            }
            else{
                return vector <int> {(st+1),(ed+1)};
            }
        }
            return vector<int>{st + 1, ed + 1};
        
    }
};