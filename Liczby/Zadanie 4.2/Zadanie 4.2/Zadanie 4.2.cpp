#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <unordered_map>

using namespace std;

unordered_map<int, int> primeFactorization(int number) {
    unordered_map<int, int> factors;
    int sqrtNumber = sqrt(number);

    for (int i = 2; i <= sqrtNumber; i++) {
        while (number % i == 0) {
            factors[i]++;
            number /= i;
        }
    }

    if (number > 1) {
        factors[number]++;
    }

    return factors;
}

int main() {
    ifstream file("liczby.txt");
    string line;
    int maxPrimeFactors = 0;
    int maxDistinctPrimeFactors = 0;
    int numberWithMaxPrimeFactors = 0;
    int numberWithMaxDistinctPrimeFactors = 0;

    while (getline(file, line)) {
        int number = stoi(line);
        unordered_map<int, int> factors = primeFactorization(number);
        int numPrimeFactors = 0;
        int numDistinctPrimeFactors = factors.size();

        for (const auto& factor : factors) {
            numPrimeFactors += factor.second;
        }

        if (numPrimeFactors > maxPrimeFactors) {
            maxPrimeFactors = numPrimeFactors;
            numberWithMaxPrimeFactors = number;
        }

        if (numDistinctPrimeFactors > maxDistinctPrimeFactors) {
            maxDistinctPrimeFactors = numDistinctPrimeFactors;
            numberWithMaxDistinctPrimeFactors = number;
        }
    }

    file.close();

    ofstream output("wyniki4.txt");
    output << "4.2: " << numberWithMaxPrimeFactors << " " << maxPrimeFactors << " "
        << numberWithMaxDistinctPrimeFactors << " " << maxDistinctPrimeFactors << endl;
    output.close();

    return 0;
}
