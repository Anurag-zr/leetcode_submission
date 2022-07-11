class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int start = 0;
        int end= n-1;
        char ans;
        
        while(start<=end){
            
            int mid = start +(end -start)/2;
    
           if(target<letters[mid]){
                end= mid-1;
            }
            else{
                start= mid+1;
            }
        }
        
        return letters[start%n];
    }
};