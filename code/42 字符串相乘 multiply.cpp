class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1[0]=='0' || num2[0]=='0') return string("0");
        const int len1 = num1.size();
        const int len2 = num2.size();
        int resInt[len1+len2+1] ;
        for(int i = 0; i< len1+len2+1; i++){
            resInt[i] = 0;
        }
        string res = "";

        for(int i = len1 - 1 ; i >= 0; i--){
            int carry = 0, index = len1 - 1- i;
            for(int j = len2 - 1; j >= 0; j--){
                int temp = (num1[i] - '0')*(num2[j] - '0');
                if(resInt[index] + temp%10 + carry >= 10){
                    // printf("first temp=%d, temp\%10=%d, carry=%d %d\n", temp, temp%10, carry, resInt[index] + temp%10 + carry);
                    int tem_carry = temp/10 + (resInt[index] + temp%10 + carry)/10;
                    
                    resInt[index] = (resInt[index] + temp%10 + carry)%10;
                    // printf("firstEND  temp=%d,  resInt[%d]=%d temp\%10=%d, carry=%d %d\n", temp, index, resInt[index], temp%10, carry, resInt[index] + temp%10 + carry);
                    carry = tem_carry;
                    index++;
                }
                else{
                    resInt[index] = (resInt[index] + temp%10 + carry);
                    carry =  temp/10;
                    index++;
                }
                // cout<<"第"<<index<<"位"<<resInt[index-1]<<"   carry="<<carry<<endl;

                

            }
            if(carry>=1) {
                // cout<<"hello hello \n\n";
                resInt[index] = carry;
            }
           
        }
        int i = len1 + len2;
        while(resInt[i]==0) i--;
        for(; i>=0; i--){
            res += std::to_string(resInt[i]);
            // cout<<resInt[i]<<" ";
        }
        // cout<<endl;
        return res;
        
    }
};