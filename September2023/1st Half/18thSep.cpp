// Link:https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/?envType=daily-question&envId=2023-09-18

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        // we are going to solve this by a way
        vector<int>ans;
        vector<pair<int,int>>r(mat.size());
        int n =mat.size();
        for(int i=0;i<n;i++)
        {
            r[i] = make_pair(accumulate(mat[i].begin(),mat[i].end(),0),i);
        }
                       
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq(r.begin(),r.end());
         while(!pq.empty() && k)
         {
            ans.emplace_back(pq.top().second);
            pq.pop();
            k--;
         }
         return ans;
    }
};
