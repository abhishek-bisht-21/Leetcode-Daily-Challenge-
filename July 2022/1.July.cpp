// 1710. Maximum Units on a Truck

// Approach 1 : SORTING WITH COMPARATOR
class Solution {
public:
    static bool myfunction(vector<int>& a, vector<int>& b){
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
	    //custom sort (in increasing order of numberOfUnitsPerBox as we have to return  maximum total number of units )
        sort(boxTypes.begin(),boxTypes.end(),myfunction);
		//greedily pick boxes till capacity is full
        int ans=0;
        for(auto box: boxTypes){
            int x=min(box[0],truckSize);  //choose minimum boxes from available boxes and capacity left
            ans+=(x*box[1]);  //adding units in ans
            truckSize-=x;  //reduce the capacity
            if(!truckSize) break;  //capacity full
        }
        return ans;
    }
}

// Approach 2: PRIORITY QUEUE

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        priority_queue<pair<int,int>> pq;
        
        for(auto &box: boxTypes){
            pq.push({box[1], box[0]});
        }
        
        int units = 0;
        int count = 0;
        
        while(!pq.empty() && count < truckSize){
            
            if(count + pq.top().second < truckSize){
                
                count += pq.top().second;
                units += pq.top().second*pq.top().first;
                pq.pop();
            }else{
                
                
                int qty = truckSize - count;
                count += qty;
                units += qty * pq.top().first;
                pq.pop();
            }
        }
        
        return units;
    }
};