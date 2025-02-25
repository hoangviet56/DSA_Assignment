#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

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
    int num
;    while (input >> num) arr.push_back(num);

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
