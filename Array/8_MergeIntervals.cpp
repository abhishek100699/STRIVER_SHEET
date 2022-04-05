class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(ans.size()==0){
                ans.push_back(intervals[i]);
            }
            else{
                vector<int> &v = ans.back();
                int Y = v[1];
                if(intervals[i][0]<=Y){
                    v[1] = max(intervals[i][1],Y);
                }
                else{
                    ans.push_back(intervals[i]);
                }
            }
        }
        return ans;
    }
};
