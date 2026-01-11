class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
       int n=arr.size();
       int windowSum=0;

       for(int i=0;i<k;i++){
        windowSum+=arr[i];
       }
       int i=0;
       int count=0;
       int j=i+k-1;
       while(j<n){
           int currAvg=windowSum/k;
            if(currAvg>=threshold){
                count++;
            }
            windowSum-=arr[i];
            i++;
            j++;
            if(j<n){
                windowSum+=arr[j];
            }
       }
         return count;
    }
};