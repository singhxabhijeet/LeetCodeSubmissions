class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int N = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int ans = nums[0]+nums[1]+nums[2];
        
        for(int i = 0; i < N-2; i++){
            int left = i+1, right = N-1;
            while(left < right){
                int cur = nums[i] + nums[left] + nums[right];
                // cout << i << " " << left << " " << right << " " << cur << endl;
                if(ans == INT_MAX || abs(cur - target) < abs(ans - target)){
                    ans = cur;
                }
                if(cur == target){
                    return cur;
                }else if(cur < target){
                    left++;
                }else{
                    right--;
                }
            }
        }
        
        return ans;
    }
};