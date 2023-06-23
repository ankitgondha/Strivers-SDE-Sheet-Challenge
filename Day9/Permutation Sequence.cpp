class Solution {
public:
    string getPermutation(int p, int k) {
        int fact = 1;
        vector<int>n;
        for(int i= 1; i<p;i++){
            fact *= i;
            n.push_back(i);
        }
        n.push_back(p);
        k--;
        string ans ="";
        while(true){
            ans += to_string(n[k/fact]);
            n.erase(n.begin()+ k/fact);
            if(n.size()==0) break;

            k = k %fact;
            fact = fact /  n.size();
        }
        return ans;
    }
};