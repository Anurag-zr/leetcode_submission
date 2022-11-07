class Solution {
public:
    
    int reverseNum(int num){
        int revNum=0;
        int rem;
        
        while(num){
            rem = num%10;
            num/=10;
            revNum = 10*revNum + rem;
        }
        
        
        return revNum;
    }
    
    int maximum69Number (int num) {
        int revNum = reverseNum(num);
        int modifiedNum=0;
        int rem;
        bool flag_first_six = true; 
        while(revNum){
            rem = revNum%10;
            if(rem==6 && flag_first_six){
              modifiedNum = 10*modifiedNum + 9;
                flag_first_six = false;
            }
            else{
                modifiedNum = 10*modifiedNum+ rem;
            }
            revNum/=10;
        }
        
        
        return modifiedNum;
    }
};