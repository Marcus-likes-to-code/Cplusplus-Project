#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>
using namespace std;

class GroceryTracker {
public:
    GroceryTracker(const string& inputFile) {
        LoadItems(inputFile);
        WriteBackup("frequency.dat");
    }

    void SearchItem(const string& item) const {
        auto it = itemFrequency.find(item);
        if (it != itemFrequency.end()) {
            cout << item << " was purchased " << it->second << " times.\n";
        }
        else {
            cout << item << " was not found in today's purchases.\n";
        }
    }

    void PrintFrequencies() const {
        for (const auto& pair : itemFrequency) {
            cout << pair.first << " " << pair.second << endl;
        }
    }

    void PrintHistogram() const {
        for (const auto& pair : itemFrequency) {
            cout << setw(12) << left << pair.first << " ";
            for (int i = 0; i < pair.second; ++i) {
                cout << "*";
            }
            cout << endl;
        }
    }

private:
    map<string, int> itemFrequency;

    void LoadItems(const string& filename) {
        ifstream inFile(filename);
        string item;
        while (inFile >> item) {
            ++itemFrequency[item];
        }
        inFile.close();
    }

    void WriteBackup(const string& filename) const {
        ofstream outFile(filename);
        for (const auto& pair : itemFrequency) {
            outFile << pair.first << " " << pair.second << endl;
        }
        outFile.close();
    }
};

int main() {
    GroceryTracker tracker("CS210_Project_Three_Input_File.txt");

    int choice;
    string searchItem;

    do {
        cout << "\nCorner Grocer Menu:\n";
        cout << "1. Search for item frequency\n";
        cout << "2. Print all item frequencies\n";
        cout << "3. Print histogram\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Input validation
        while (cin.fail() || choice < 1 || choice > 4) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number between 1 and 4: ";
            cin >> choice;
        }

        cin.ignore(); // Clear newline for getline

        switch (choice) {
        case 1:
            cout << "Enter item name: ";
            getline(cin, searchItem);
            tracker.SearchItem(searchItem);
            break;
        case 2:
            tracker.PrintFrequencies();
            break;
        case 3:
            tracker.PrintHistogram();
            break;
        case 4:
            cout << "Exiting program. Goodbye!\n";
            break;
        }
    } while (choice != 4);

    return 0;
}
