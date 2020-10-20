#include <iostream>
#include <vector>
#include <string.h>
#include <cstdio>
#include <algorithm>
using namespace std;
class Solution {
// 归并排序
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int N = nums1.size() + nums2.size();
        vector<int> merge(N);
        int i=0, j=0, k=0;  //分别是三个数组的指针
        while(i<nums1.size() && j<nums2.size()){
            int value1=nums1[i], value2 = nums2[j];
            if(nums1[i] > nums2[j]){ // 添加到新的队列中
                merge[k++] = value2;
                j++;
            }
            else{
                merge[k++] = value1;
                i++;
            }
        }
        if(j==nums2.size()){
            while(i<nums1.size()) merge[k++] = nums1[i++];
        }
        else if(i==nums1.size()){
            while(j<nums2.size()) merge[k++] = nums2[j++];
        }

        if(N%2==0){
            return (merge[N/2]+merge[N/2-1])/double(2);
        }else{
            return double(merge[N/2]);
        }
    }
     int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k) {
        /* 主要思路：要找到第 k (k>1) 小的元素，那么就取 pivot1 = nums1[k/2-1] 和 pivot2 = nums2[k/2-1] 进行比较
         * 这里的 "/" 表示整除
         * nums1 中小于等于 pivot1 的元素有 nums1[0 .. k/2-2] 共计 k/2-1 个
         * nums2 中小于等于 pivot2 的元素有 nums2[0 .. k/2-2] 共计 k/2-1 个
         * 取 pivot = min(pivot1, pivot2)，两个数组中小于等于 pivot 的元素共计不会超过 (k/2-1) + (k/2-1) <= k-2 个
         * 这样 pivot 本身最大也只能是第 k-1 小的元素
         * 如果 pivot = pivot1，那么 nums1[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums1 数组
         * 如果 pivot = pivot2，那么 nums2[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums2 数组
         * 由于我们 "删除" 了一些元素（这些元素都比第 k 小的元素要小），因此需要修改 k 的值，减去删除的数的个数
         */

        int m = nums1.size();
        int n = nums2.size();
        int index1 = 0, index2 = 0;

        while (true) {
            // 边界情况  递归的终止条件 
            if (index1 == m) {
                return nums2[index2 + k - 1];
            }
            if (index2 == n) {
                return nums1[index1 + k - 1];
            }
            if (k == 1) {
                return min(nums1[index1], nums2[index2]);
            }

            // 正常情况
            int newIndex1 = min(index1 + k / 2 - 1, m - 1);  //newIndex1 表示的是对应右指针的位置 index1表示的是左指针的位置（基线）  利用基线和k可以求得中间第k的位置。 
            int newIndex2 = min(index2 + k / 2 - 1, n - 1);
            int pivot1 = nums1[newIndex1];
            int pivot2 = nums2[newIndex2];
            if (pivot1 <= pivot2) {
//                k -= newIndex1 - index1 + 1;
                k = k + index1 - (newIndex1 + 1); 
                index1 = newIndex1 + 1;
                printf("k = %d   and newindex1 = %d    index1 = %d   \n", k, newIndex1, index1);
            }
            else {
//                k -= newIndex2 - index2 + 1;
                k =  k + index2 - (newIndex2 + 1);
                index2 = newIndex2 + 1;
                printf("k = %d   and  newIndex2 = %d  index2 = %d    \n\n\n", k, newIndex2, index2);

            }
        }
    }

    double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
        int totalLength = nums1.size() + nums2.size();
        if (totalLength % 2 == 1) {
            return getKthElement(nums1, nums2, (totalLength + 1) / 2);
        }
        else {
            return (getKthElement(nums1, nums2, totalLength / 2) + getKthElement(nums1, nums2, totalLength / 2 + 1)) / 2.0;
        }
    }

};
int main(){
    Solution sl;
    std::vector<int> v1 {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> v2 {1, 3, 4, 9};
    cout<<sl.findMedianSortedArrays1(v1,v2);

    return 0;
}