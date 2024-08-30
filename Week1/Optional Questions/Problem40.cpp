#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Problem40 {
public:
    vector<vector<int>> CombinationSum2(vector<int> arr, int n, int k) {
        vector<vector<int>> result;
        vector<int> combination;
        sort(arr.begin(), arr.end());  
        backtrack(result, combination, arr, k, 0);
        return result;
    }

private:
    void backtrack(vector<vector<int>>& result, vector<int>& combination, 
                   vector<int>& arr, int remain, int start) {
        if (remain < 0) return;
        if (remain == 0) {
            result.push_back(combination);
            return;
        }
        for (int i = start; i < arr.size(); i++) {
            if (i > start && arr[i] == arr[i - 1]) continue;
            combination.push_back(arr[i]);
            backtrack(result, combination, arr, remain - arr[i], i + 1); 
            combination.pop_back(); 
        }
    }
};

int main() {
    Problem40 problem40;
    vector<int> arr = {4, 1, 1, 4, 4, 4, 4, 2, 3, 5};
    int target = 10;
    vector<vector<int>> result = problem40.CombinationSum2(arr, arr.size(), target);

    for (const auto& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
