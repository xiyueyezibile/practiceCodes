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
//��һ��ڶ��⣬g
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