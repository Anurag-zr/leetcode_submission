class Solution {
public:
    int minMovesToMakePalindrome(string s) {
       
        vector<char> arr;
        for(auto c: s) arr.push_back(c);
        
        int i=0;
        int j= arr.size()-1;
        // cout<<j<<endl;
        int minDel =0;
        
        while(i<j){
            
            // cout<<arr[i]<<arr[j]<<endl;
            
            if(arr[i]==arr[j]){
                i++;
                j--;
                continue;
            }
            
            bool pairFound = false;
            int k;
            for(k =i;k<j;k++){
                if(arr[k]==arr[j]){
                    pairFound= true;
                    char temp = arr[k];
                    minDel+=k-i;
                    
                    for(int ptr= k-1;ptr>=i;ptr--){
                        arr[ptr+1]=arr[ptr];
                    }
                    
                    arr[i]= temp;
                    i++; j--;
                    break;
                }
            }
            
            
            if(!pairFound){ //for odd length string when corresponding equal char not found
                   int midInd = i+(j-i)/2;
                    char temp = arr[k];
                    minDel+=k-midInd;
                    
                    j--;
                    
//                     for(int ptr= k-1;ptr>=midInd;ptr--){
//                         arr[ptr+1]=arr[ptr];
//                     }
                
//                 arr[midInd] = temp;
                
            }
            
            
        }
        
        
        return minDel;
    }
};