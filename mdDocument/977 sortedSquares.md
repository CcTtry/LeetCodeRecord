使用合并两个数组的办法
```C++
class Solution {
public:
    int square(int num){
        return num*num;
    }
    vector<int> sortedSquares(vector<int>& A) {
        const int n = A.size();
        vector<int> res(n);
        vector<int> tempB;
        vector<int> tempU;
        int slice = 0;
        // push the elem(value is less than 0) into temp
        for(int i = 0; i < n; i++){
            if(A[i] < 0){
                continue;
            }
            else{
                slice = i;
                break;
            }
        }
        if(A[n-1] <= 0) slice = n-1;
        for(int i = slice - 1; i >= 0; i--){
            tempB.push_back(A[i]*A[i]);
        }
        for(int i = slice; i < n; i++){
            tempU.push_back(A[i]*A[i]);
        }
        if(tempB.size() == 0 || tempU.size() == 0) return tempU.size()==0?tempB:tempU;

        int count = 0, bIndex = 0, uIndex = 0;
        while(bIndex < tempB.size() && uIndex < tempU.size() && count < n){
            if( (tempB[bIndex]) < (tempU[uIndex])){
                res[count] = tempB[bIndex];
                count ++;
                bIndex ++;
            }
            else{
                res[count] = tempU[uIndex];
                count ++;
                uIndex ++;
            }
        }
        
        if(bIndex == tempB.size()){
            while(uIndex < tempU.size()){
                res[count] = tempU[uIndex];
                count ++;
                uIndex++;
            }
        }
        else if(uIndex == tempU.size()) {
            while(bIndex < tempB.size()){
                res[count] = tempB[bIndex];
                count ++;
                bIndex ++;
            }
        }
        return res;

    }
};
```

使用双指针的办法

```C++
class Solution {
public:
    int square(int num){
        return num*num;
    }
    vector<int> sortedSquares(vector<int>& A) {
        const int n = A.size();
        vector<int> res(n);
        vector<int> temp;
        
        for(int i = 0; i < n; i++){
            temp.push_back(A[i]*A[i]);
        }

        int index = n-1, left = 0, right = n-1, count = 0;
        while(left <= right && count < n && index >=0 ){
            if(temp[left] > temp[right]){
                res[index] = temp[left];
                count ++;
                left ++;
                index --;
            }
            else{
                res[index] = temp[right];
                count ++;
                right --;
                index --;
            }
        }
        return res;

    }
};
```