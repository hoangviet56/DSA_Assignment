#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

int main(int argc, char* argv[]) {
    ifstream input(argv[1]);  // Đọc file input từ tham số dòng lệnh
    
    vector<int> arr;
    int num;    
    while (input >> num) arr.push_back(num);

    auto start = high_resolution_clock::now();
    sort(arr.begin(), arr.end());
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(end - start).count();

    ofstream clearFile("output.txt", ios::trunc);
    clearFile.close();

    ofstream output("output.txt");  // Ghi kết quả vào file
    output << duration << endl;

    return 0;
}
