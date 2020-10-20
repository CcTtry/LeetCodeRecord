#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
	    if(x<0){
	        return false;
	    }
	    string str  = "";
	    while(x){
	        str += std::to_string(x%10);
	        x /= 10;
	    }
	    for(int i = 0; i<(str.length())/2; i++){
	    	if(str[i] != str[str.length() - i -1]){
	    		return false;
	    	}
	    }
	    return true;


    }
};
