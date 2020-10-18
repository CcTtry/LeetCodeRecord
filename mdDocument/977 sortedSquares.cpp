#include <iostream>
#include <vector>
using namespace std;


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

void print(vector<int>& A){
    for(int i = 0; i < A.size(); i++){
        printf("%d  ", A[i]);
    }
    printf("\n");
}

// int main(){
//     vector<int> start ;
//     for(int i = -10; i<0; i+= 2){
//         start.push_back(i);
//     }
//     for(int i = 5; i<10; i++){
//         start.push_back(i);
//     }
//     print(start);
//     Solution sl;
//     vector<int> res;
//     res = sl.sortedSquares(start);
//     cout<<"\nresult is\n";
//     print(res);
// }
#include <iostream>
#include <queue>
using namespace std;
 
int main()
{
    queue<int> Qi;
    Qi.push(1);
    Qi.push(2);
    Qi.push(3);
    Qi.push(4);
    Qi.push(4);
    Qi.push(5);
 
    while(!Qi.empty()){
        cout<<Qi.front()<<endl;
        Qi.pop();
    }
}