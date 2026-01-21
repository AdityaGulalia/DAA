#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeSort(vector<int>& arr, int left, int right) {
    if (left == right) {
        return {arr[left]};
    }

    int mid = left + (right - left) / 2;

    vector<int> leftSorted = mergeSort(arr, left, mid);
    vector<int> rightSorted = mergeSort(arr, mid + 1, right);

    vector<int> result;
    int i = 0, j = 0;

    while (i < leftSorted.size() && j < rightSorted.size()) {
        if (leftSorted[i] <= rightSorted[j]) {
            result.push_back(leftSorted[i++]);
        } else {
            result.push_back(rightSorted[j++]);
        }
    }

    while (i < leftSorted.size())
        result.push_back(leftSorted[i++]);

    while (j < rightSorted.size())
        result.push_back(rightSorted[j++]);

    return result;
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    vector<int> arr2 = {38, 27, 43, 3, 9, 82, 10};

    vector<int> sorted1 = mergeSort(arr, 0, arr.size() - 1);
    vector<int> sorted2 = mergeSort(arr2, 0, arr2.size() - 1);

    cout << "Sorted first array: ";
    for (int x : sorted1) cout << x << " ";

    cout << "\nSorted second array: ";
    for (int x : sorted2) cout << x << " ";

    return 0;
}
