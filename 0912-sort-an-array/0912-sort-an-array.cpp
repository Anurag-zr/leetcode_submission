class Solution {
public:
    
//     int partition(vector<int> &nums,int lo,int high){
        
//         int pivot = nums[high];
//         int i = lo -1;
        
//         for(int j=lo;j<high;j++){
//             if(nums[j]<pivot){
//                 i++;
//                 swap(nums[i],nums[j]);
//             }
//         }
        
//         swap(nums[i+1],nums[high]);
//         return i+1;
//     }
    
//     void quickSort(vector<int> &nums,int l,int h){
//         if(l>=h) return;
        
//         int pivot = partition(nums,l,h);
//         quickSort(nums,l,pivot-1);
//         quickSort(nums,pivot+1,h);
//     }
    
    
    void heapify(int index,vector<int> &nums,int n){
        
        int largest = index;
        int left = 2*index+1;
        int right = 2*index+2;
        
        if(left<n && nums[left]>nums[largest]){
            largest = left;
        }
        
        if(right<n && nums[right]>nums[largest]){
            largest = right;
        }
        
        if(largest!=index){
            swap(nums[index],nums[largest]);
            heapify(largest,nums,n);
        }
    }
    
    
    void heapSort(vector<int> &nums,int n){
        
        for(int i=n/2-1;i>=0;i--){
            heapify(i,nums,n);
        }
        
        for(int i=n-1;i>=0;i--){
            swap(nums[i],nums[0]);
            heapify(0,nums,i);
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        heapSort(nums,n);
        
        return nums;
    }
};