class Solution {
public:
    string countOfAtoms(string formula) {
    
        unordered_map<string, int> finalMap = parseFormula(formula);

        map<string, int> sortedMap(finalMap.begin(), finalMap.end());

        string ans;
        for (auto& [atom, count] : sortedMap) {
            ans += atom;
            if (count > 1) {
                ans += to_string(count);
            }
        }

        return ans;
    }

    unordered_map<string, int> parseFormula(string& formula) {
        unordered_map<string, int> currMap;
        string currAtom;
        string currCount;

      
        while (index < formula.length()) {
            if (isupper(formula[index])) {
                if (!currAtom.empty()) {
                    if (currCount.empty()) {
                        currMap[currAtom] += 1;
                    } else {
                        currMap[currAtom] += stoi(currCount);
                    }
                }

                currAtom = formula[index];
                currCount = "";
                index++;
            }


            else if (islower(formula[index])) {
                currAtom += formula[index];
                index++;
            }

            else if (isdigit(formula[index])) {
                currCount += formula[index];
                index++;
            }

            else if (formula[index] == '(') {
                index++;
                unordered_map<string, int> nestedMap = parseFormula(formula);
                for (auto& [atom, count] : nestedMap) {
                    currMap[atom] += count;
                }
            }


            else if (formula[index] == ')') {
   
                if (!currAtom.empty()) {
                    if (currCount.empty()) {
                        currMap[currAtom] += 1;
                    } else {
                        currMap[currAtom] += stoi(currCount);
                    }
                }

                index++;
                string multiplier;
                while (index < formula.length() && isdigit(formula[index])) {
                    multiplier += formula[index];
                    index++;
                }
                if (!multiplier.empty()) {
                    int mult = stoi(multiplier);
                    for (auto& [atom, count] : currMap) {
                        currMap[atom] = count * mult;
                    }
                }

                return currMap;
            }
        }


        if (!currAtom.empty()) {
            if (currCount.empty()) {
                currMap[currAtom] += 1;
            } else {
                currMap[currAtom] += stoi(currCount);
            }
        }

        return currMap;
    }

private:
    int index = 0;
};