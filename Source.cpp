#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Function to search for a query in a given text file
vector<int> search(const string& query, const string& filename) {
    vector<int> results;
    ifstream file(filename);
    string line;
    int line_number = 1;
    while (getline(file, line)) {
        if (line.find(query) != string::npos) {
            results.push_back(line_number);
        }
        line_number++;
    }
    return results;
}

int main() {
    string query;
    cout << "Enter your search query: ";
    getline(cin, query);

    // Search multiple files (replace with your filenames)
    vector<int> results1 = search(query, "file1.txt");
    vector<int> results2 = search(query, "file2.txt");

    // Combine and display results
    vector<int> all_results(results1.begin(), results1.end());
    all_results.insert(all_results.end(), results2.begin(), results2.end());
    sort(all_results.begin(), all_results.end());

    if (all_results.empty()) {
        cout << "No results found!" << endl;
    }
    else {
        cout << "Results found in lines: ";
        for (int line_number : all_results) {
            cout << line_number << " ";
        }
        cout << endl;
    }

    return 0;
}