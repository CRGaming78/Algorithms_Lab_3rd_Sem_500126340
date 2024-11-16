#include <iostream>
#include <vector>
using namespace std;

bool subsetSum(vector<int> &nums, vector<int> &subset, int target, int index) {
    if (target == 0) {
        cout << "Subset Found: ";
        for (int num : subset) cout << num << " ";
        cout << endl;
        return true;
    }
    if (index >= nums.size() || target < 0) return false;
    subset.push_back(nums[index]);
    if (subsetSum(nums, subset, target - nums[index], index + 1)) return true;
    subset.pop_back();
    if (subsetSum(nums, subset, target, index + 1)) return true;
    return false;
}

int main() {
    int n, target;
    cout << "Enter the number of elements in the set: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the set:\n";
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << "Enter the target sum: ";
    cin >> target;
    vector<int> subset;
    if (!subsetSum(nums, subset, target, 0)) {
        cout << "No subset with the given sum found." << endl;
    }
    return 0;
}