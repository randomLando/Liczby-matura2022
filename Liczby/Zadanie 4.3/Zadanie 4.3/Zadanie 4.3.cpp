#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream input("liczby.txt");
    std::ofstream output("wyniki4.txt");
    std::ofstream output2("trojki.txt");
    std::vector<int> numbers;
    int number;
    while (input >> number) {
        numbers.push_back(number);
    }
    input.close();
    std::sort(numbers.begin(), numbers.end());
    int good_triples = 0;
    int good_quintuples = 0;
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            if (numbers[j] % numbers[i] == 0) {
                for (int k = j + 1; k < numbers.size(); k++) {
                    if (numbers[k] % numbers[j] == 0) {
                        good_triples++;
                        output2 << numbers[i] << " " << numbers[j] << " " << numbers[k] << "\n";
                        for (int l = k + 1; l < numbers.size(); l++) {
                            if (numbers[l] % numbers[k] == 0) {
                                for (int m = l + 1; m < numbers.size(); m++) {
                                    if (numbers[m] % numbers[l] == 0) {
                                        good_quintuples++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    output << "4.3\na) " << good_triples << "\nb) " << good_quintuples;
    output.close();
    output2.close();
}
