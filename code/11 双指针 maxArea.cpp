#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height){
        int begin = 0, end = height.size() - 1; // begin end 表示下标 
        int area = -1;
        int i, j;
        while(begin < end ){
            int tem = (end - begin) * (height[begin]>height[end]?height[end]:height[begin]);
            if(tem > area){
                i = begin;
                j = end;
                area = tem;
            }
            int flag = (height[begin] > height[end])?1:0;
            if(flag){
                end--;
            }else{
                begin++;
            }
        }
        //cout<<i<<"  "<<j<<endl; 
        return area;
    }
};
int main(){
	Solution sl;
	vector<int> a {1,8,6,2,5,4,8,3,7};
	printf("%d\n",sl.maxArea(a));
//	printf("%d is ? %d\n", a, sl.isPalindrome(c));
//	printf("%d is ? %d\n", a, sl.isPalindrome(d));
}