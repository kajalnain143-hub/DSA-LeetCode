class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int num : stones){
            pq.push(num);
        }
        while(pq.size()>1){
        int firstLargest = pq.top();
        pq.pop();
        int secondLargest = pq.top();
        pq.pop();
        if(firstLargest==secondLargest){
            continue;
        }
        else{
            pq.push(firstLargest - secondLargest);
        }
        }
       return pq.empty() ? 0 : pq.top();
    }
};