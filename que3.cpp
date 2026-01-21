#include <iostream>
#include <vector>
using namespace std;

vector<int> quickSort(vector<int> arr) {
    if (arr.size() <= 1)
        return arr;

    int pivot = arr[0];  

    vector<int> left, equal, right;

    for (int x : arr) {
        if (x < pivot)
            left.push_back(x);
        else if (x == pivot)
            equal.push_back(x);
        else
            right.push_back(x);
    }

    left = quickSort(left);
    right = quickSort(right);

    vector<int> result;
    result.insert(result.end(), left.begin(), left.end());
    result.insert(result.end(), equal.begin(), equal.end());
    result.insert(result.end(), right.begin(), right.end());

    return result;
}

int main() {
    vector<int> arr = {4, 2, 6, 9, 2};

    vector<int> sortedArr = quickSort(arr);

    cout << "Sorted array: ";
    for (int x : sortedArr)
        cout << x << " ";

    return 0;
}
