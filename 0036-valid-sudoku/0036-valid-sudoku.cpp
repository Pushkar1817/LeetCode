class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& matrix) {
        int n = 9;
    
        for(int i = 0 ; i < n ; i++){
            vector<int> row(n);
            vector<int> col(n);
            
            for(int j = 0 ; j < n ; j++){
                
                if(matrix[i][j] != '.'){row[matrix[i][j] - 1-48]++;}
                if(matrix[j][i] != '.'){col[matrix[j][i] - 1-48]++;}
            }
            
            for(int i = 0 ; i < n ; i++){
                if(row[i] > 1 || col[i] > 1) 
                    return false;
            }
        }
        
        int row = 0;
        int col = 0;
        int rowEnd = row+2;
        int colEnd = col +2;
        for(int k = 0 ;k<9 ;k++){
            if(k!=0){
                if(k%3 == 0 ){
                row+=3;
                rowEnd = row+2;
                col=0;
                colEnd = col+2;
                }
                else{
                    col +=3;
                    colEnd = col +2;
                }
            }
            vector<int> box(n);
            
            for(int i = row ; i<rowEnd+1 ;i++){
                for(int j = col ;j<colEnd+1 ;j++){
                    if(matrix[i][j] != '.'){
                        box[matrix[i][j]-1-48]++;
                    }
                }
            }
            for(int i = 0 ;i< n ;i++){
                if(box[i] > 1){
                    return false;
                }
            }
            for(int i = 0 ;i< n;i++){
                box[i]=0;
            }
        } 
        return true;
    }
};