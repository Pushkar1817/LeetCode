class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();

        for(int i =0 ;i<n ;i++){
            for(int j = 0 ;j< n ;j++){
                if(i == j){
                    continue;
                }

                int x1 = points[i][0], x2 = points[j][0], y1 = points[i][1], y2 = points[j][1];


                if(x1 >= x2 && y1 <= y2){
                    bool valid = true;
                    // cout<<i<<"  "<<j<<endl;
                    for(int k = 0 ;k< n ;k++){
                        if(k == i || k == j){
                            continue;
                        }

                        int x3 = points[k][0];
                        int y3 = points[k][1];

                        if((x3>=x2 && x3<=x1 ) &&(y3 >= y1 && y3 <= y2)){
                            valid = false;
                            break;
                        }
                    }
                    if(valid){
                        ans++;
                    }
                }

            }
        }
        return ans;
    }
};