#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

void quickSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int pivot = arr[left], i = left, j = right;

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i <= j) swap(arr[i++], arr[j--]);
    }

    quickSort(arr, left, j);
    quickSort(arr, i, right);
}

int main(int argc, char* argv[]) {
    ifstream input(argv[1]);  // Đọc file input từ tham số dòng lệnh
    vector<int> arr;

    int num;
    
    while (input >> num) arr.push_back(num);
    input.close();

    auto start = high_resolution_clock::now();
    quickSort(arr, 0, arr.size() - 1);
    auto end = high_resolution_clock::now();
    
    auto duration = duration_cast<milliseconds>(end - start).count();

    ofstream clearFile("output.txt", ios::trunc);
    clearFile.close();

    ofstream output("output.txt");  // Ghi kết quả vào file
    output << duration << endl;
    output.close();

    return 0;
}
