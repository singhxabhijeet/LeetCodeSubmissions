class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while(left <= right){
            int mid = left + (right-left)/2;
            // cout << left << ", " << mid << ", " << right << endl;
            if(isBadVersion(mid)){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return left;
    }
};