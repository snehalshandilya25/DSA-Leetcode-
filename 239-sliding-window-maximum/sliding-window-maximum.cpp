class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;

        // Process the first window
        for(int i = 0; i < k; i++) {

            while(!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        // Process the remaining windows
        for(int i = k; i < nums.size(); i++) {

            // Store maximum of previous window
            res.push_back(nums[dq.front()]);

            // Remove indices outside current window
            while(!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Maintain decreasing order
            while(!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            // Insert current index
            dq.push_back(i);
        }

        // Store maximum of last window
        res.push_back(nums[dq.front()]);

        return res;
    }
};