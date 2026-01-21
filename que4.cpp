#include <iostream>
#include <vector>
using namespace std;

int maxSubarraySum(vector<int>& arr) {
    int currentSum = arr[0];
    int maxSum = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        currentSum = max(arr[i], currentSum + arr[i]);
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int main() {
    vector<int> arr = {-2, -5, 6, -2, -3, 1, 5, -6};

    cout << "Maximum subarray sum = " << maxSubarraySum(arr);

    return 0;
}
