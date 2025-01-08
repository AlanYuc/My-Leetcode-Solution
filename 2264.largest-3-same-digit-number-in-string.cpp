/*
 * @lc app=leetcode.cn id=2264 lang=cpp
 * @lcpr version=30204
 *
 * [2264] 字符串中最大的 3 位相同数�?
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:

    int isNumber(string subNum){
        int num = subNum[0];
        if(num != subNum[1] || num!= subNum[2]){
            return -1;
        }
        return num*100 + num*10+num;
    }

    string largestGoodInteger(string num) {
        int max = -1;
        string maxstr;
        int len = num.size();
        for(int i= 0;i<len - 2;i++){
            string temp;
            for(int j = i;j<i+3;j++){
                temp += num[j];
            }
            int niceNum = isNumber(temp);
            if(niceNum<0)
            {
                continue;
            }
            else{
                if(niceNum>max){
                    max = niceNum;
                    maxstr = temp;
                }
            }
        }
        return maxstr;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "6777133339"\n
// @lcpr case=end

// @lcpr case=start
// "2300019"\n
// @lcpr case=end

// @lcpr case=start
// "42352338"\n
// @lcpr case=end

 */

