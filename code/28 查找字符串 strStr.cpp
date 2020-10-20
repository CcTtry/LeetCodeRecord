class Solution {
public:
    int strStr(string haystack, string needle) {
    	const int len1 = haystack.size(), len2 = needle.size();
    	int i = 0, j = 0;
    	while(i<len1 && j<len2){
    		if(haystack[i] == needle[j]){
    			i++;
    			j++;
    		}else{
    			i = i - j + 1;
    			j = 0;
    		}
    	}
    	if(j == len2) return i - j;
    	return -1;
    }
};