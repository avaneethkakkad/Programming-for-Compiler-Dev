class Solution {
  public:
    void computeLPS(string& pat, vector<int>& LPS ,int M)
    {
        int len=0;//previous longest suffix 
        LPS[0]=0;
        int i=1;
        
        while(i<M)
        {
            if(pat[i]==pat[len])
            {
                len++;
                LPS[i]=len;
                i++;
            }
            else
            {
                if(len!=0)
                {
                len=LPS[len-1];
                } else{
                    LPS[i]=0;
                    i++;
                }
            }
        }
        
    }
    vector<int> search(string &pat, string &txt) {
        // code here
        int N = txt.length();
        int M = pat.length();
        
        vector<int> result;
        
        //create a LPS array where prefix and suffix is equal store its lenght
        vector<int> LPS(M,0);
        computeLPS(pat,LPS,M);
        
        //Apply KMP on the LPS
        int i=0;
        int j=0;
        
        while(i<N)
        {
            if(txt[i]==pat[j])
            {
                i++;
                j++;
            }
            if(j==M)
            {
                result.push_back(i-M);
                j=LPS[j-1];//push j back wards
            }
            else if(txt[i]!=pat[j])
            {
                if(j!=0)
                {
                j = LPS[j-1];
                }
                else
                {
                    i++;
                }
            }
        }
        return result;
    }
};
