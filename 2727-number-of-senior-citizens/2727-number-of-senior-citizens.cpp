class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans=0;
        int age=0;
        for(auto &x:details)
        {
            age=stoi(x.substr(11,2));
            if(age > 60)
            {
                ans++;
            }
        }
        return ans;
    }
};