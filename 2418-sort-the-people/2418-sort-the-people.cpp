class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int numberOfPeople = names.size();
        map<int, string> heightToNameMap;
        for (int i = 0; i < numberOfPeople; i++) {
            heightToNameMap[heights[i]] = names[i];
        }

        vector<string> sortedNames(numberOfPeople);

        int currentIndex = numberOfPeople - 1;
        for (const auto& pair : heightToNameMap) {
            sortedNames[currentIndex] = pair.second;
            currentIndex--;
        }

        return sortedNames;
    }
};