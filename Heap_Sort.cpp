#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1, right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
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
    heapSort(arr);
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(end - start).count();

    ofstream clearFile("output.txt", ios::trunc);
    clearFile.close();

    ofstream output("output.txt");  // Ghi kết quả vào file
    output << duration << endl;
    
    return 0;
}
