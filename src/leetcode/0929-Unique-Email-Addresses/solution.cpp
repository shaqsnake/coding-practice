// Copyright (c) 2019 shaqsnake. All rights reserved.
/**
 * @Author: shaqsnake
 * @Email: shaqsnake@gmail.com
 * @Date: 2019-08-12 16:19:42
 * @LastEditTime: 2019-08-12 16:25:22
 * @Description: 929. Unique Email Addresses
 */

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> set;
        for (const auto &email : emails) {
            auto offset = email.find("@");
            string res;
            for (const auto &c : email.substr(0, offset)) {
                if (c == '+') break;
                else if (c != '.') res += c;
            }

            res += email.substr(offset);
            set.insert(res);
        }    

        return set.size();
    }
};
