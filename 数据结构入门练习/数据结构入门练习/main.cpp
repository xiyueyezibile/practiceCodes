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
#include<unordered_map>
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
//了解了什么是动态规划以及最基本的使用
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
/*
    1. 两数之和
    给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
你可以按任意顺序返回答案。
示例 1：
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
示例 2：
输入：nums = [3,2,4], target = 6
输出：[1,2]
示例 3：
输入：nums = [3,3], target = 6
输出：[0,1]
提示：
2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
只会存在一个有效答案
进阶：你可以想出一个时间复杂度小于 O(n2) 的算法吗？
*/
//成功，时间复杂度应该是O(n2)
//提交代码
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> arr;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {

                    arr.push_back(i);
                    arr.push_back(j);
                    return arr;
                }
            }
        }
        return arr;
    }
};
//官方解答二：哈希表
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return { it->second, i };
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};

/*
    88. 合并两个有序数组
给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。
示例 1：
输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
输出：[1,2,2,3,5,6]
解释：需要合并 [1,2,3] 和 [2,5,6] 。
合并结果是 [1,2,2,3,5,6] ，其中斜体加粗标注的为 nums1 中的元素。
示例 2：
输入：nums1 = [1], m = 1, nums2 = [], n = 0
输出：[1]
解释：需要合并 [1] 和 [] 。
合并结果是 [1] 。
示例 3：
输入：nums1 = [0], m = 0, nums2 = [1], n = 1
输出：[1]
解释：需要合并的数组是 [] 和 [1] 。
合并结果是 [1] 。
注意，因为 m = 0 ，所以 nums1 中没有元素。nums1 中仅存的 0 仅仅是为了确保合并结果可以顺利存放到 nums1 中。
提示：
nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109
进阶：你可以设计实现一个时间复杂度为 O(m + n) 的算法解决此问题吗？
*/
//自己解答，O(NlogN)
int comp(int a, int b) {
    return a < b;
}
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m; i < m + n; i++) {
            nums1[i] = nums2[i - m];
        }
        sort(nums1.begin(), nums1.end(), comp);

    }
};
//