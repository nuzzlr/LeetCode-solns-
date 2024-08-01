class Solution {
public:
    int countSeniors(vector<string>& details) {
    return accumulate(details.begin(), details.end(), 0, [](int sum, string& s){
            return sum+=s.substr(11,2)>"60"?1:0;
    });
}
};