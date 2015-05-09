#include <map>
#include <vector>


class Solution {

public:

    vector<int> twoSum(vector<int> &numbers, int target) {
        std::map<int, int> numMap;
        int numLen = numbers.size();
        for (int i = 0; i < numLen; ++i) {
            numMap[numbers[i]] = i;
        }

        vector<int> index;
        std::map<int, int>::iterator iter;
        for (int i = 0; i < numLen; ++i) {
            int left = target - numbers[i];
            iter = numMap.find(left);
            if (iter != numMap.end() && i != iter->second) {
                int leftIndex = iter->second;
                if (i > leftIndex) {
                    int t = i;
                    i = leftIndex;
                    leftIndex = i;
                }
                index.push_back(i + 1);
                index.push_back(leftIndex + 1);
                break;
            }
        }
        return index;
    }
};
