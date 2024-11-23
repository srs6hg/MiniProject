#include "Functions.h"

int main() {
	int s = 0;
	vector<int> ogv;
	srand(time(NULL));
	cout << "Vector Size: ";
	cin >> s; cout << endl;

	fiveHundredNumbers(ogv, s);
}