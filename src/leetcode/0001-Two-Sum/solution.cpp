#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> map;
        for (decltype(nums.size()) i = 0; i < nums.size(); i++) {
            if (map.find(target - nums[i]) != map.end()) {
                return vector<int>{map[target - nums[i]], (int)i};
            }
            map[nums[i]] = i;
        }

        return vector<int>();
    }
};

int main() {
    vector<int> nums = {2, 7, 9, 11};
    int target = 9;
    vector<int> ret = Solution().twoSum(nums, target);

    for (auto i : ret) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}