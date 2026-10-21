class Solution {
public:
  
    bool isSufficientDays(vector<int>& weights, int days , int mid){
        int n = weights.size();
        int curWeg = 0 , curDays = 1;

        for(int i = 0 ; i < n ; i++){
            curWeg += weights[i];
           
            if(curWeg > mid){
                curDays++;             
                curWeg = weights[i];    
            }
        }
        return curDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

       
        int low = INT_MIN , high = 0;
        for(int i = 0 ; i < n ; i++){
            high += weights[i];
            if(weights[i] > low) low = weights[i];
        }

       
        while(low < high){
            int mid = low + (high - low)/2;
            if(isSufficientDays(weights , days , mid)) 
                high = mid;    
            else 
                low = mid + 1; 
        }
        return high; 
    }
};