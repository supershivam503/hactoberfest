#include <bits/stdc++.h>
using namespace std;

#define ll long long



//Seive Approach - Generating a array containing prime numbers
vector<int> PrimeSieve(int *p, int n) {

	//first all odd numbers as prime as they can be potential prime
	for (int i = 3; i <= 1000000; i += 2) {
		p[i] = 1;
	}
	//Sieve
	for (ll i = 3; i <= 1000000; i += 2) {
		//if current number is not marked (it is prime)
		if (p[i] == 1) {
			//mark all the multiples of i as not prime
			for (ll j = i * i; j <= 1000000; j = j + i) {
				p[j] = 0;
			}
		}
	}
	//Special cases
	p[2] = 1;
	p[1] = p[0] = 0;

	vector<int> primes;
	primes.push_back(2);

	for (int i = 3; i <= n; i += 2) {
		if (p[i] == 1)
			primes.push_back(i);

	}

	return primes;


}

vector<int> factorize(int m, vector<int> &primes) {

	vector<int> factors;
	factors.clear();

	int i = 0;
	int p = primes[0];

//if we want to store the count of factors, we can make a pair
	// and store the counts as well
	while (p * p <= m) {
		if (m % p == 0) {
			factors.push_back(p);
			while (m % p == 0) {
				m = m / p;
			}
		}
		// go to next position
		i++;
		p = primes[i];
	}

//if m is not reduced to 1 , it means m also a prime number
	if (m != 1) {
		factors.push_back(m);
	}
	return factors;

}




int main() {


	int p[1000000] = {0};
	vector<int> primes = PrimeSieve(p, 100000);

	int t; cin >> t;
	while (t--) {
		int no; cin >> no;

		vector<int> factors = factorize(no, primes);

		for (auto f : factors) {
			cout << f << " ";
		}
		cout << endl;
	}

	return 0;


}