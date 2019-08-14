// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-14 17:17:57
 * @LastEditTime: 2019-08-14 17:22:02
 * @Description: 17. Letter Combinations of a Phone Number
 */

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;

        string letters[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        res.push_back("");
        for (const auto &d : digits) {
            vector<string> tmp;
            for (const auto &c : letters[d - '2']) {
                for (auto r : res) {
                    r += c;
                    tmp.push_back(r);
                }
            }
            res = tmp;
        }

        return res;
    }
};
