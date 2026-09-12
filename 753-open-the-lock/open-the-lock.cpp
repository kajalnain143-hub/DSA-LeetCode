class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string>q;
        int move = 0;
       
        unordered_set<string>visited;
        unordered_set<string>deadlocks;
        for(string ch : deadends){
            deadlocks.insert(ch);
        }
        string start = "0000";
        if(deadlocks.find(start)==deadlocks.end()){
            q.push(start);
            visited.insert(start); 
        }
        else{
            return -1;
        }
       
        while(!q.empty()){
            int size = q.size();
            while(size--){
         string current = q.front();
         q.pop();
         if(current==target){
            return move;
         }
         for(int i=0;i<4;i++){
            string next = current;
            next[i] = (next[i]-'0'+1)% 10 + '0';
            if(visited.find(next)==visited.end() && deadlocks.find(next)==deadlocks.end()){
                q.push(next);
                visited.insert(next);
            }
             next = current;
            next[i] = (next[i] - '0' + 9) % 10 + '0';
            if(visited.find(next)==visited.end() && deadlocks.find(next)==deadlocks.end()){
                q.push(next);
                visited.insert(next);
            }
         }
         
         }
         move++;
        }
        return -1;
    }
};