#include "Functions.h"

int main() {
	int s = 0; int n;
	vector<int> ogv, nv;
	srand(time(NULL));
	cout << "Vector Size: ";
	cin >> s; cout << endl;

	fiveHundredNumbers(ogv, s);
	cout << "Algorithm: ";
	cin >> n; cout << endl;
	
	auto start = std::chrono::system_clock::now();
	switch (n) {
	case 1:
		nv = algoSelect(ogv);

		break;
	case 2:
		nv = algoMerge(ogv);

		break;
	case 3:
		nv = algoRadix(ogv);

		break;
	}
	auto end = std::chrono::system_clock::now();

	std::chrono::duration<double> t = end - start;

	cout << "Done\nTime: " << t.count() << endl;

	//printVector(nv);
}