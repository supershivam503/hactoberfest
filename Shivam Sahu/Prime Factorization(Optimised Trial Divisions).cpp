#include <bits/stdc++.h>
#include <vector>
using namespace std;

void printFactors(int n) {

	vector<pair<int, int>> factors;
	int count;

	for (int i = 2; i * i <= n; i++) {

		if (n % i == 0) {
			//keep on diving it by i till it is divisible
			count = 0;
			while (n % i == 0) {
				count++;
				n /= i;
			}
			factors.push_back(make_pair(i, count));
		}
	}

	if (n != 1) {
		factors.push_back(make_pair(n, 1));
	}

	// print the factors
	for (auto p : factors) {
		cout << p.first << "^" << p.second << endl;
	}
	return ;

}

int main() {
	int n; cin >> n;
	printFactors(n);

}