class RecentCounter {
public:
queue<int>q;
    RecentCounter() {
        
    }
    
    int ping(int t) {
         // Add the new request
        q.push(t);

        // Remove requests older than 3000 ms
        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }

        // Return the number of recent requests
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */