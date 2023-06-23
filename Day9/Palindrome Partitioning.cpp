class Solution {
    private:
    bool palindrome(string str){
        int s=0;
        int n=str.length() - 1;
        //base case
        while(s<n){
            if(str[s]!=str[n]){
                return false;
            }
                s++;
                n--;
        }
        return true;
        
    }

    void helper(string s, vector<vector<string>>&ans, vector<string>temp){
        //base case
        if(s.length()<=0){
            ans.push_back(temp);
        }
        for(int i=0; i<s.length();i++){
            string left = s.substr(0, i+1);
            if(palindrome(left)){
                temp.push_back(left);
                helper(s.substr(i+1), ans, temp);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        // string str= "";
        // int n=s.length();
        // for(int i=1; i<=n;i++){
        //     for(int j=0; j<=n-i;j++){
        //     int k = j + i - 1;            
        //     for (int p = k; p <= k; p++) 
        //         str.push_back(s[p]);
              
        //     if(palindrome(str ,str.length())){
        //         return str;
        //     }
        // }
        // }
        // }

        vector<vector<string>>ans;
        vector<string>temp;
        helper(s,ans,temp);
        return ans;
        
    }
};