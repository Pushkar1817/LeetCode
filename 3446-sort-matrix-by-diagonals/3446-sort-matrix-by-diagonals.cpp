class Solution {
private:
    void getVec(vector<vector<int>>& grid,vector<int>&row,int i,int j,int n ){
        if(i >= n || j>= n || i<0 || j<0){
            return ;
        }
        row.push_back(grid[i][j]);
        getVec(grid,row,i+1,j+1,n);
        return ;
    }
    void placeVec(vector<vector<int>>& grid,vector<int>&row,int i,int j,int n ,int r){
        if(i >= n || j>= n || i<0 || j<0){
            return ;
        }
        grid[i][j] = row[r];
        placeVec(grid,row,i+1,j+1,n,r+1);
        return ;
    }
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        for(int i = 0 ;i< n ;i++){
            vector<int>row ;
            getVec(grid,row,i,0,n);
            sort(row.rbegin(),row.rend());
            placeVec(grid,row,i,0,n,0);
        }
        for(int i = 1 ;i< n ;i++){
            vector<int>row ;
            getVec(grid,row,0,i,n);
            sort(row.begin(),row.end());
            placeVec(grid,row,0,i,n,0);
        }
        
        return grid;
    }
};
