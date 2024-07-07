class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1, prev = -1, last = -1, minDis = INT_MAX;
        for (int i = 0; head->next->next; i++, head = head->next) {
            if (nextIsMaxima(head)) {
                if (first == -1) first = i;
                prev = last;
                last = i;
                if (prev != -1) minDis = min(minDis, last - prev);
            }
        }
        if (prev == -1) {
            return {-1, -1};
        }
        return {minDis, last - first};
    }
private:
    bool nextIsMaxima(ListNode* node) {
        return  node->val < node->next->val 
                && node->next->next->val < node->next->val
                || 
                node->val > node->next->val 
                && node->next->next->val > node->next->val;
    }
};