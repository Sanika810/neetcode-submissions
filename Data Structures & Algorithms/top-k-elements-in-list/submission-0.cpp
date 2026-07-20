class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map <int,int>freq;
        for(int i=0;i<n;i++)
        {
            freq[nums[i]]++;
        }
        map<int,vector<int>,greater<int>>mpp;
        for(auto &it : freq)
        {
            int cnt = it.second;
            int ele = it.first;
            mpp[cnt].push_back(ele);
        }
        vector<int>ans;
        for(auto &it : mpp)
        {
            vector<int>vec = it.second;
            for(int num : vec)
            {
                if(k == 0)
                    break;
                ans.push_back(num);
                k--;
            }
        }
        return ans;
    }
};
