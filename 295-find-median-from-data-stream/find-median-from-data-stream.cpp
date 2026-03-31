// class MedianFinder {
// public:
//     MedianFinder() {
//        int MedianFinder;
//     }
//     vector<int>arr;
//     void addNum(int num) {
//         arr.push_back(num);
//     }
    
//     double findMedian() {
//         sort(arr.begin(),arr.end());
//         int n=arr.size();
//         if(arr.size()%2==0){// even{
//            double num1=arr[(n/2)-1];
//            double num2=arr[n/2];
//             double avg=(num1+num2)/2;
//             return avg;
//         }
//         else{
//                return arr[n/2];
//         }

//     }
// };


class MedianFinder {
public:
    MedianFinder() {}
    priority_queue<int>left; // max heap
    priority_queue<int,vector<int>,greater<int>>right;// min heap
    void addNum(int num) {
        
        
        if(left.size()==0 || num<=left.top()){
            // pehle left me daalo
            left.push(num);
        }
        else{
            right.push(num);
        }
        if(left.size()>right.size()+1){
            right.push(left.top());
            left.pop();
        }
         else if(left.size()<right.size()){
            int number=right.top();
            left.push(number);
            right.pop();
         }
    }
    
    double findMedian() {
        double ans=-1;
       if(left.size()==right.size()){ // even
           ans=(left.top()+right.top())/2.0;
          
       }
       else{
           ans=left.top();
       }
       return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */