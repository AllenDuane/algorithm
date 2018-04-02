class Solution {
public:
    int findComplement(int num) {
        int input=num,mask=1;
        while(input){
            input>>=1;
            mask<<=1;
        }
        return (mask-1)^num;
    }
};
