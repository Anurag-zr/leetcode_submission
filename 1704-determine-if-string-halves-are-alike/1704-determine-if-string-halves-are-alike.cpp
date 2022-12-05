class Solution {
public:
    bool halvesAreAlike(string s) {
        int firstCnt=0;
        int secCnt =0;
        
        int n = s.length();
        
        int i=0;
        int j=i+n/2;
        
        while(i<n/2){
            char c= tolower(s[i]);
            if(c=='a' || c=='e' || c=='i'|| c=='o' || c=='u') firstCnt++;
            
            char c2 = tolower(s[j]);
            if(c2=='a'|| c2=='e'|| c2=='i' || c2=='o' || c2=='u') secCnt++;
            
            
            i++;
            j++;
        }
        
        if(firstCnt == secCnt) return true;
        
        return false;
    }
};