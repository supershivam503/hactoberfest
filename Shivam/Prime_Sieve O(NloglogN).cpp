#include <bits/stdc++.h>
using namespace std;

#define ll long long

//Brute Approach O(sqrt(N))
bool isPrime(int n) {
	if (n == 1) {
		return false;
	}
	if (n == 2) {
		return true;
	}
	for (int i = 2; i * i < n; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

//Seive Approach - Generating a array containing prime numbers
void prime_seive(int *p) {

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


}



int main() {
	int n; cin >> n;

	int p[1000005] = {0};

	prime_seive(p);

	//lets print prime upto range n
	for (int i = 0; i <= n; i++) {

		if (p[i] == 1) {
			cout << i << " ";
		}
	}
}