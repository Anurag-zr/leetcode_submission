class Solution {
public:
    int mirrorReflection(int p, int q) {
        //m is no. of room extension +1
        //n is no. of reflection +1;
        int m =1;   //no. of room extension ==0;
        int n=1;    //no. of reflection ==0;
        
        while(m*p != n*q){
            n++;
            m = n*q/p;
        }
        
        if (m % 2 == 1 && n % 2 == 0) return 2; //no of reflection is odd
        if (m % 2 == 0 && n % 2 == 1) return 0; //no of room extension is odd
        if (m % 2 == 1 && n % 2 == 1) return 1; //no of room extension is even
        
        return -1;
        
    }
};