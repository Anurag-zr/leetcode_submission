class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();

        if (letters[n-1] <= target) return letters[0];
        
        int start = 0;
        int end= n-1;
        
        while(start<=end){
            
            int mid = start +(end -start)/2;
    
           if(target<letters[mid]){
                end= mid-1;
            }
            else{
                start= mid+1;
            }
        }
        
        return letters[start];
    }
};