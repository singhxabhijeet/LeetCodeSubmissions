class valuecomparator
{
public:
    valuecomparator(){}
    bool operator() (const pair<int, int>& lhs, const pair<int, int>&rhs) const{
        return lhs.second > rhs.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> counter;
        vector<int> ans(k);
        
        for(int e : nums){
            counter[e]++;
        }
        
        //the larger the lower
        priority_queue<pair<int, int>, vector<pair<int, int>>, valuecomparator> pq1;

        for(auto it = counter.begin(); it != counter.end(); it++){
            pq1.push(*it);
            //the smallest will be popped first
            if(pq1.size() > k) pq1.pop();
        }

        //put into ans in reverse order
        for(int i = k-1; i >= 0; i--){
            pair<int, int> p = pq1.top();
            ans[i] = p.first;
            pq1.pop();
        }
        
        return ans;
    }
};