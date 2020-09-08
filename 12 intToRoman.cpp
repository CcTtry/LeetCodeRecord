#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>
#include <map> 
using namespace std;

class Solution {
public:
	string intToRoman(int num) {
    	string res = "";
		
		int  temp_num = num;
		map<int, string> strMap;
		strMap[1] = "I";    strMap[2] = "II";	strMap[3] = "III";
		strMap[4] = "IV";   strMap[5] = "V";	strMap[6] = "VI";
		strMap[7] = "VII";	strMap[8] = "VIII";	strMap[9] = "IX";
		strMap[10] = "X";
		
		strMap[20] = "XX"; strMap[30] = "XXX";	strMap[40] = "XL";
		strMap[50] = "L";  strMap[60] = "LX";	strMap[70] = "LXX";
		strMap[80] = "LXXX";	strMap[90] = "XC";
		
		strMap[100] = "C";  strMap[200] = "CC";  strMap[300] = "CCC";
		strMap[400] = "CD"; strMap[500] = "D";   strMap[600] = "DC"; 
		strMap[700] = "DCC";strMap[800] = "DCCC";strMap[900] = "CM"; 
		strMap[1000] = "M"; strMap[2000] = "MM"; strMap[3000] = "MMM"; 
		const int N = strMap.size();
		if(strMap.count(num)){
			return strMap[num];
		}
//		sort(strMap.begin(), strMap.end());
		map<int, string>::iterator iter;
    	int temp[N] , i;
//    	for(int i = 0; i)
		for(iter = strMap.begin(), i = 0 ; iter != strMap.end(); iter++){
//			cout<<iter->first<<"  hello :"<<iter->second<<endl;
			temp[i] = int(iter->first);
			i++;
		}
//		int temp[N] = {1, 5, 10, 50, 100, 500, 1000}; //存储对应的数字 
		int nums[N]; // 存储对应的数字分解之后的构成情况 num = 1*X + 50*Y 
		for(int i = N-1; i>=0; i--){
			nums[i] = temp_num/temp[i];
			temp_num %= temp[i];
		}
		int sum = 0;
		for(int i = N-1; i>0; i--){
//			cout<<nums[i]*temp[i]<<" + " ;
			res += strMap[nums[i]*temp[i]];
			sum += nums[i]*temp[i];
		}
//		cout<<nums[0]*temp[0]<<endl;
		sum += nums[0]*temp[0];
		res += strMap[nums[0]*temp[0]];
//		cout<<sum<<endl;
//		cout<<res<<endl;	    
		return res;	
    }
    string intToRoman1(int num) {  // 符合要求就减去对应的数值
        int values[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string reps[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        
        string res;
        for(int i=0; i<13; i++){
            while(num>=values[i]){
                num -= values[i];
                res += reps[i];
            }
        }
        return res;
    }
};

int main() {
	Solution sl;
	cout<<sl.intToRoman(58)<<endl;
	cout<<sl.intToRoman(1994)<<endl;
	return 0;
}