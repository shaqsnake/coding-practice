class KthLargest {
public:
    KthLargest(int k, vector<int> &nums) : kth(k) {
        for (const auto &n : nums) {
            add(n);
        }
    }

    int add(int val) {
        pq.push(val);
        while (pq.size() > kth)
            pq.pop();
        return pq.top();
    }

private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int kth;
};