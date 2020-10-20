#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
	int calFactorial(int num){
		int sum = 1;
		for(int i=1; i<=num; i++){
			sum *= i;
		}
		return sum;
	}
	int realIndex(int flags[], int n, int cur){ // 返回真实的当前数字  （需要跳过一些已经被排列的数字
		int add_num = 0, index = 1;
		while(add_num<cur){
			if(flags[index] == 0){ // 还没有被使用
				add_num++;
				index++;
			}else{
//				cout<<"没有使用过"<<endl;
				index ++;
			}
		}
		return (index - 1);
	}
    string getPermutation(int n, int k) {
		string str;  // 不可以直接赋值  
    	const int num = n;  //count 
        const int num_1 = n+1;
        int flags[num_1] = {0}, res[num] = {0}, k_num = k;  // res用于存储最终的结果
        //fllag 用于标记某个数字是否被使用了  1表示被使用 0表示未被使用
        // 每次都生成一个数字 生成n次 count用于表示还有多少个数字没有生成
        for(int i = 0; i < n; i++){
        	// 
        	int cur;
        	if(k_num != 0) {
				cur = 1 + (k_num - 1)/(calFactorial(n-i-1));  //  (calFactorial(n-i)/(n-i))表示某一层的排列数目 
			}else {
				cur = 1; 
			}   
        	cur = realIndex(flags, n, cur);
        	flags[cur] = 1;
        	k_num %= calFactorial(n-i-1);
        	
        	str  += cur + '0';
        	
        }
        return str;
    }
};
int main(){
	Solution sl;
	cout<<sl.getPermutation(3,3)<<endl;
	cout<<sl.getPermutation(4,9)<<endl;
	
}