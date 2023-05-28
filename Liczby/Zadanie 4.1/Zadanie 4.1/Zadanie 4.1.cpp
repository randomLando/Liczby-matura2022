#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream file("liczby.txt");
    string line;
    int count = 0;
    string firstNumber;

    while (getline(file, line)) {
        int number = stoi(line);
        string numStr = to_string(number);
        if (numStr[0] == numStr[numStr.length() - 1]) {
            count++;
            if (firstNumber.empty()) {
                firstNumber = numStr;
            }
        }
    }

    file.close();

    ofstream output("wyniki4.txt");
    output << "4.1: " << count << " " << firstNumber << endl;
    output.close();

    return 0;
}
