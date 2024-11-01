#include <iostream>
#include <vector>

using namespace std;

vector<int> generatePrimes(int maxNum){
  vector<bool> isPrime(maxNum + 1, true);
  isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime numbers.

  for(int i = 2; i * i <= maxNum; i++){
    if(isPrime[i]){
      for(int j = i * i; j <= maxNum; j += i){
        isPrime[j] = false;
      }
    }
  }

  vector<int> primes;
  for(int i = 2; i <= maxNum; i++){
    if(isPrime[i]){
      primes.push_back(i);
    }
  }

  return primes;

}

int main () {
  int maxNum = 50;
  vector<int> primes = generatePrimes(maxNum);

  cout << "Prime numbers less than or equal to: " << maxNum << ": ";
  for(int prime: primes){
    cout << prime << " ";
  }
  cout << endl;

  return 0;
}