/*
	217. �����ظ�Ԫ��
	����һ���������� nums �������һֵ�������г��� �������� ������ true �����������ÿ��Ԫ�ػ�����ͬ������ false ��
ʾ�� 1��
���룺nums = [1,2,3,1]
�����true
ʾ�� 2��
���룺nums = [1,2,3,4]
�����false
ʾ�� 3��
���룺nums = [1,1,1,3,3,4,3,2,4,2]
�����true
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
using namespace std;
////ʧ�ܣ��������10�����ݸ����ܳ�ʱ��,ʱ�临�Ӷ�O(N*2),�ռ临�Ӷ�O(N)
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
////�ٷ����1.�����㷨
//class Solution {
//public:
//    bool containsDuplicate(vector<int>& nums) {
//        //�����㷨
//        sort(nums.begin(), nums.end());
//
//        int n = nums.size();
//        //��Ϊ�Ѿ�������ˣ�����ֻ���ж������Ƿ���ͬ
//        for (int i = 0; i < n - 1; i++) {
//            if (nums[i] == nums[i + 1]) {
//                return true;
//            }
//        }
//        return false;
//    }
//};
////�ٷ����2.��ϣ��
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
    53. ����������
    ����һ���������� nums �������ҳ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�
������ �������е�һ���������֡�
ʾ�� 1��
���룺nums = [-2,1,-3,4,-1,2,1,-5,4]
�����6
���ͣ����������� [4,-1,2,1] �ĺ����Ϊ 6 ��
ʾ�� 2��
���룺nums = [1]
�����1
ʾ�� 3��
���룺nums = [5,4,-1,7,8]
�����23
��ʾ��
1 <= nums.length <= 105
-104 <= nums[i] <= 104
���ף�������Ѿ�ʵ�ָ��Ӷ�Ϊ O(n) �Ľⷨ������ʹ�ø�Ϊ����� ���η� ��⡣
*/
//�˽���ʲô�Ƕ�̬�滮�Լ��������ʹ��
/*
* ��̬�滮
    �����ĳ��÷���:
    1.��ĳ���ڵ�Ϊ��ͷ������������: �� [a]��[a, b]��[ a, b, c] ... �ٴ��� b Ϊ��ͷ�������п�ʼ���� [b] [b, c]��
    2.���������еĳ���Ϊ��ˣ����ȱ����������г���Ϊ 1 �������У��ڱ���������Ϊ 2 �� �ȵȡ�
    3.�������еĽ����ڵ�Ϊ��׼���ȱ�������ĳ���ڵ�Ϊ���������������У���Ϊÿ���ڵ㶼���ܻ��������еĽ����ڵ㣬���Ҫ�������������У�
      ��: �� b Ϊ�����������������: [a , b] [b] �� c Ϊ�����������������: [a, b, c] [b, c] [ c ]��
*/
//����һ����̬�滮
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        //��¼ÿһ����iλ��Ԫ��Ϊ�յ�����������������
        vector<int> dp(nums.size());
        //��ʼ��
        dp[0] = nums[0];
        int result = dp[0];
        //��ϵʽ
        for (int i = 1; i < nums.size(); i++) {
            //ǰһ�������������ֵ������������������Ƚ�ѡ�����ֵ
            dp[i] = max(dp[i - 1] + nums[i], nums[i]); // ״̬ת�ƹ�ʽ
            if (dp[i] > result) result = dp[i]; // result ����dp[i]�����ֵ
        }
        return result;
    }
};
/*
    1. ����֮��
    ����һ���������� nums ��һ������Ŀ��ֵ target�������ڸ��������ҳ� ��ΪĿ��ֵ target  ���� ���� ���������������ǵ������±ꡣ
����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ���ڴ��ﲻ���ظ����֡�
����԰�����˳�򷵻ش𰸡�
ʾ�� 1��
���룺nums = [2,7,11,15], target = 9
�����[0,1]
���ͣ���Ϊ nums[0] + nums[1] == 9 ������ [0, 1] ��
ʾ�� 2��
���룺nums = [3,2,4], target = 6
�����[1,2]
ʾ�� 3��
���룺nums = [3,3], target = 6
�����[0,1]
��ʾ��
2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
ֻ�����һ����Ч��
���ף���������һ��ʱ�临�Ӷ�С�� O(n2) ���㷨��
*/
//�ɹ���ʱ�临�Ӷ�Ӧ����O(n2)
//�ύ����
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
//�ٷ���������ϣ��
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
    88. �ϲ�������������
���������� �ǵݼ�˳�� ���е��������� nums1 �� nums2�������������� m �� n ���ֱ��ʾ nums1 �� nums2 �е�Ԫ����Ŀ��
���� �ϲ� nums2 �� nums1 �У�ʹ�ϲ��������ͬ���� �ǵݼ�˳�� ���С�
ע�⣺���գ��ϲ������鲻Ӧ�ɺ������أ����Ǵ洢������ nums1 �С�Ϊ��Ӧ�����������nums1 �ĳ�ʼ����Ϊ m + n������ǰ m ��Ԫ�ر�ʾӦ�ϲ���Ԫ�أ��� n ��Ԫ��Ϊ 0 ��Ӧ���ԡ�nums2 �ĳ���Ϊ n ��
ʾ�� 1��
���룺nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
�����[1,2,2,3,5,6]
���ͣ���Ҫ�ϲ� [1,2,3] �� [2,5,6] ��
�ϲ������ [1,2,2,3,5,6] ������б��Ӵֱ�ע��Ϊ nums1 �е�Ԫ�ء�
ʾ�� 2��
���룺nums1 = [1], m = 1, nums2 = [], n = 0
�����[1]
���ͣ���Ҫ�ϲ� [1] �� [] ��
�ϲ������ [1] ��
ʾ�� 3��
���룺nums1 = [0], m = 0, nums2 = [1], n = 1
�����[1]
���ͣ���Ҫ�ϲ��������� [] �� [1] ��
�ϲ������ [1] ��
ע�⣬��Ϊ m = 0 ������ nums1 ��û��Ԫ�ء�nums1 �н���� 0 ������Ϊ��ȷ���ϲ��������˳����ŵ� nums1 �С�
��ʾ��
nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109
���ף���������ʵ��һ��ʱ�临�Ӷ�Ϊ O(m + n) ���㷨�����������
*/
//�Լ����O(NlogN)
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