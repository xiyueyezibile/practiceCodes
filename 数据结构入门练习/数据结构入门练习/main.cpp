/*
	217. 存在重复元素
	给你一个整数数组 nums 。如果任一值在数组中出现 至少两次 ，返回 true ；如果数组中每个元素互不相同，返回 false 。
示例 1：
输入：nums = [1,2,3,1]
输出：true
示例 2：
输入：nums = [1,2,3,4]
输出：false
示例 3：
输入：nums = [1,1,1,3,3,4,3,2,4,2]
输出：true
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
////失败，最后跑了10万数据给我跑超时了,时间复杂度O(N*2),空间复杂度O(N)
//class Solution {
//public:
//    bool containsDuplicate(vector<int>& nums) {
//        vector<int> a;
//        for (vector<int>::iterator it = (nums).begin(); it != (nums).end(); it++) {
//            bool s = true;
//            for (vector<int>::iterator ita = a.begin(); ita != a.end(); ita++) {
//                if (*it == *ita) {
//                    s = false;
//                    return true;
//                }
//            }
//            if (s) {
//                a.push_back(*it);
//            }
//        }
//        return false;
//    }
//};
////官方题解1.排序算法
//class Solution {
//public:
//    bool containsDuplicate(vector<int>& nums) {
//        //排序算法
//        sort(nums.begin(), nums.end());
//
//        int n = nums.size();
//        //因为已经排序过了，所以只需判断相邻是否相同
//        for (int i = 0; i < n - 1; i++) {
//            if (nums[i] == nums[i + 1]) {
//                return true;
//            }
//        }
//        return false;
//    }
//};
////官方题解2.哈希表
//class Solution {
//public:
//    bool containsDuplicate(vector<int>& nums) {
//        unordered_set<int> s;
//        for (int x : nums) {
//            if (s.find(x) != s.end()) {
//                return true;
//            }
//            s.insert(x);
//        }
//        return false;
//    }
//};

/*
    53. 最大子数组和
    给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
子数组 是数组中的一个连续部分。
示例 1：
输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
示例 2：
输入：nums = [1]
输出：1
示例 3：
输入：nums = [5,4,-1,7,8]
输出：23
提示：
1 <= nums.length <= 105
-104 <= nums[i] <= 104
进阶：如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的 分治法 求解。
*/
//第一天第二题，g
/*
* 动态规划
    遍历的常用方法:
    1.以某个节点为开头的所有子序列: 如 [a]，[a, b]，[ a, b, c] ... 再从以 b 为开头的子序列开始遍历 [b] [b, c]。
    2.根据子序列的长度为标杆，如先遍历出子序列长度为 1 的子序列，在遍历出长度为 2 的 等等。
    3.以子序列的结束节点为基准，先遍历出以某个节点为结束的所有子序列，因为每个节点都可能会是子序列的结束节点，因此要遍历下整个序列，
      如: 以 b 为结束点的所有子序列: [a , b] [b] 以 c 为结束点的所有子序列: [a, b, c] [b, c] [ c ]。
*/
//方法一：动态规划
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        //记录每一个以i位置元素为终点的连续子数组的最大和
        vector<int> dp(nums.size());
        //初始化
        dp[0] = nums[0];
        int result = dp[0];
        //关系式
        for (int i = 1; i < nums.size(); i++) {
            //前一个连续数组最大值加上新数与新数本身比较选出最大值
            dp[i] = max(dp[i - 1] + nums[i], nums[i]); // 状态转移公式
            if (dp[i] > result) result = dp[i]; // result 保存dp[i]的最大值
        }
        return result;
    }
};