class Solution {
public:
    int fib(int n) {
      //binet formula - works correctly upto n=32
        
        return (pow((1+sqrt(5))/2, n) - pow((1-sqrt(5))/2,n))/sqrt(5); 
    }
};