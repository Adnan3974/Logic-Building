#include <iostream>
using namespace std;

void generateNumbers(int N, int K, int currentNum, int length, int lastDigit) {
    if (length == N) {
        cout << currentNum << endl;
        return;
    }
    
    for (int nextDigit = 0; nextDigit <= 9; nextDigit++) {
        if (abs(lastDigit - nextDigit) == K) {
            generateNumbers(N, K, currentNum * 10 + nextDigit, length + 1, nextDigit); //recursive call
        }
    }
}

int main() {
    cout<<"Enter N and K: ";
    int N,K;cin>>N>>K;
    for (int firstDigit = 1; firstDigit <= 9; firstDigit++) {
        generateNumbers(N, K, firstDigit, 1, firstDigit);
    }
    
    return 0;
}