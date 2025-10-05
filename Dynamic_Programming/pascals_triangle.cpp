class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        //first and last element is always 1 middle elements are the sum of previous rows 2 
        vector<vector<int>>result(numRows);
        //For rows greater than 2 sum the elements of previous row from (n=1 to n-1)
       
        for(int i=0;i<numRows;i++)
        {
            result[i].resize(i+1,1); // resize as triangle form
            for(int j=1;j<i;j++)
             result[i][j]=result[i-1][j-1]+result[i-1][j];
        }

        return result;
    }
};
