class Solution {
public:
   void visit(vector<vector<int>>& rooms,vector<int>&visited,int i){
        if(visited[i]){
          return;
        }
      visited[i] = true;
       for(int key : rooms[i]){
        visit(rooms, visited, key);
       }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int>visited(rooms.size(),false);
       
            visit(rooms,visited,0);
           
      
       for(int i = 0; i < rooms.size(); i++)
{
    if(!visited[i])
        return false;
}

return true;
    }
};