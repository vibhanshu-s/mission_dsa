class Solution {
public:
    string removeKdigits(string num, int k) {
        deque<int> dq;
        string ans = "";

        for (int i = 0; i < num.size(); i++) {
            int digit = num[i] - '0';

            while (!dq.empty() && k > 0 && dq.back() > digit) {
                dq.pop_back();
                k--;
            }

            dq.push_back(digit);
        }

        while (!dq.empty() && k > 0) {
            dq.pop_back();
            k--;
        }

        while (!dq.empty() && dq.front() == 0)
            dq.pop_front();

        if (dq.empty())
            return "0";

        while (!dq.empty()) {
            ans += to_string(dq.front());
            dq.pop_front();
        }

        return ans;
    }
};
