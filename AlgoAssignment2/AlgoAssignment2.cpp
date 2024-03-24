#include <iostream>
#include <vector>

using namespace std;

void printSubarray(const vector<int>& array, int start, int end, string prefix) {
    cout << prefix;
    for (int i = start; i <= end; ++i) {
        cout << array[i] << " ";
    }
    cout << "\n";
}

void merge(vector<int>& array, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = array[left + i];
    for (int j = 0; j < n2; j++) R[j] = array[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        }
        else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& array, int left, int right, int depth = 0) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(array, left, mid, depth + 1);
    mergeSort(array, mid + 1, right, depth + 1);

    printSubarray(array, left, mid, "Splitting (L): ");
    printSubarray(array, mid + 1, right, "Splitting (R): ");

    merge(array, left, mid, right);

    printSubarray(array, left, right, "Merging: ");
}

int main() {
    vector<int> arr = {11, 1, 30, 2, 51, 6, 29, 7, 67, 15, 118, 4, 89, 23};
    cout << "Initial array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl << endl;

    mergeSort(arr, 0, arr.size() - 1);

    cout << endl << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}