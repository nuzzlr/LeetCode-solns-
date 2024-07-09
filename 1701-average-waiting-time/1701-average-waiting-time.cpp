
class Solution {
public:
double averageWaitingTime(vector<vector<int>>& customers) {
long long ans = 0;
int n = customers.size(),t = customers[0][0];

    for(int i=0;i<n;i++){
        int burst = customers[i][1];
        int arrival = customers[i][0];

        if(t >= arrival){
            t+=burst;
            ans+=t-arrival;
        }
        
        else {
            t = burst + arrival;
            ans+=burst;
        }
        
    }

    return double(ans)/double(n);
}
};