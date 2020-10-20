#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <set>
#include <map> 
#include <vector>
using namespace std;
map<string, int> cnt;
vector<string> words;

string repr(const string &s){
	string ans = s;
	for(int i =0; i<ans.length(); i++){
		ans[i] = tolower(ans[i]);		
	}
	sort(ans.begin(), ans.end()); // 画成小写之后，根据字母进行排序 
	return ans;
}

int main(){
	 int n = 0;
	string s;
	while(cin>>s){
		if(s=="#") {
			cout<<"结束了";
			break;
		}else{
			cout<<"continue \n"; 
		}
		
		words.push_back(s);
		string r = repr(s);
		cout<<r<<endl;
		if(!cnt.count(r)) cnt[r] = 0;  // map.count(Key)返回值为1或者0，1返回存在，0返回不存在
		cnt[r]++ ;
	}
	std::vector<string> ans;
	for(int i = 0; i < words.size(); i++){
		cout<<"测试 \n";
		if(cnt[repr(words[i])] == 1){
			cout<<"通过"; 
			ans.push_back(words[i]);
		}
	}
	sort(ans.begin(), ans.end());
	cout<<"准备打印  \n"<< ans.size(); 
	for(int i = 0; i < ans.size(); i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}