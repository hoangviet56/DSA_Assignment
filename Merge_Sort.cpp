#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;
    while (i < leftArr.size() && j < rightArr.size()) {
        arr[k++] = (leftArr[i] <= rightArr[j]) ? leftArr[i++] : rightArr[j++];
    }

    while (i < leftArr.size()) arr[k++] = leftArr[i++];
    while (j < rightArr.size()) arr[k++] = rightArr[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Missing input file!\n";
        return 1;
    }

    ifstream input(argv[1]);
    if (!input) {
        cerr << "Cannot open file: " << argv[1] << endl;
        return 1;
    }

    vector<int> arr;
    int num;
    while (input >> num) arr.push_back(num);

    auto start = high_resolution_clock::now();
    mergeSort(arr, 0, arr.size() - 1);
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(end - start).count();

    ofstream clearFile("output.txt", ios::trunc);
    clearFile.close();

    ofstream output("output.txt");  // Ghi kết quả vào file
    output << duration << endl;
    
    return 0;
}
