#include "Functions.h"

void fiveHundredNumbers(vector<int>& ogv, int& s) {
	for (int i = 0; i < s; i++) {
		ogv.push_back(rand() % s);
	}
}

vector<int> algoSelect(vector<int> v) {
    int n = v.size();

    for (int i = 0; i < n - 1; ++i) {

        // Assume the current position holds
        // the minimum element
        int min_idx = i;

        // Iterate through the unsorted portion
        // to find the actual minimum
        for (int j = i + 1; j < n; ++j) {
            if (v[j] < v[min_idx]) {

                // Update min_idx if a smaller
                // element is found
                min_idx = j;
            }
        }

        // Move minimum element to its
        // correct position
        swap(v[i], v[min_idx]);
    }
}

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp vectors
    vector<int> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    // Merge the temp vectors back 
    // into arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], 
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], 
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

vector<int> algoMerge(vector<int> v) {
    mergeSort(v, 0, v.size() - 1);
}

vector<int> algoRadix(vector<int> v) {
    int n;
	int mx = v.at(0);
	for (int i = 1; i < n; i++)
		if (v.at(i) > mx)
			mx = v.at(i);

	for (int exp = 1; mx / exp > 0; exp *= 10) {
        vector<int> output(n);
        int i, count[10] = { 0 };

        // Store count of occurrences
        // in count[]
        for (i = 0; i < n; i++)
            count[(v.at(i) / exp) % 10]++;

        // Change count[i] so that count[i]
        // now contains actual position
        // of this digit in output[]
        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];

        // Build the output array
        for (i = n - 1; i >= 0; i--) {
            output[count[(v.at(i) / exp) % 10] - 1] = v.at(i);
            count[(v.at(i) / exp) % 10]--;
        }

        // Copy the output array to arr[],
        // so that arr[] now contains sorted
        // numbers according to current digit
        for (i = 0; i < n; i++)
            v.at(i) = output[i];
	}
    return v;
}