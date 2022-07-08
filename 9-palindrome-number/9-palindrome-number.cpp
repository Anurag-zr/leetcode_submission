class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x!=0 && x%10==0)) return false;
        
        int reverseX=0;
        
        while(x>reverseX){
            reverseX=reverseX*10 + x%10;
            x=x/10;
        }
        
        return (x==reverseX) || (x==reverseX/10);
        
    }
};