//Carlos Garcia
//David Moreno
//Kevin Perez
//*********To DO************

#include <iostream>
#include <string>
#include <chrono>

using namespace std;
using namespace chrono;

// Implement linear search
// Return true if x exist in the array A with size n, and return false otherwise

bool linear_search(int x, int* A, int n)
{
	for (int i = 0; i < n; i++) {
		if (A[i] == x) {
			return true;
		}
	}
	return false;
}

// Implement binary search iteratively
// Return true if x exist in the array A with size n, and return false otherwise
// Hint: don't forget you have while loop :D 

bool binary_search(int x, int* A, int n)
{
	int l = 0;
	int r = n - 1;
	int m = (l + r) / 2;
	while (m != l || m != r) {
		if (A[m] == x)
			return true;
		else if (A[m] < x) {
			l = m + 1;
			m = (l + r) / 2;
		}
		else {
			r = m - 1;
			m = (l + r) / 2;
		}
	}
	return false;
}

// Implement binary search 
// Return true if x exist in the array A with size n, and return false otherwise

bool binary_search_recursion(int x, int* A, int s, int n) {
	int m = (s + n) / 2;
	if (m == s || m == n) {
		return false;
	}
	if (x == A[m]) {
		return true;
	}
	else if(A[m] < x){
		s = m + 1;
		return binary_search_recursion(x, A, s, n);
	}
	else {
		n = m - 1;
		return binary_search_recursion(x, A, s, n);
	}
}

// Implement Insertion Sort 
// You can use a method "swap" to swap the location of two elements
// For example swap(A[0],A[n-1]) would swap the first element and last element

void insertion_sort(int* A, int n)
{
	for (int x = 1; x < n; x++) {
		for (int y = x; y > 0; y--) {
			if (A[y] < A[y - 1]) {
				swap( A[y - 1] , A[y] );
			}
		}
	}
}


int main() {
	int A[10] = { 1, 3, 4, 7, 9, 11, 14, 15, 17, 20 };


	if (!linear_search(0, A, 10))
		cout << "0 is not in the array." << endl;
	else
		cout << " your linear algorithm is wrong" << endl;

	if (linear_search(9, A, 10))
		cout << "9 is in the array." << endl;
	else
		cout << " your linear algorithm is wrong" << endl;

	if (!binary_search(0, A, 10))
		cout << "0 is not in the array." << endl;
	else
		cout << " your binary algorithm is wrong" << endl;

	if (binary_search(17, A, 10))
		cout << "17 is in the array." << endl;
	else
		cout << " your binary algorithm is wrong" << endl;

	if (!binary_search_recursion(0, A, 0, 10))
		cout << "0 is not in the array." << endl;
	else
		cout << " your binary recursion algorithm is wrong" << endl;

	if (binary_search_recursion(17, A, 0, 10))
		cout << "17 is in the array." << endl;
	else
		cout << " your binary recursion algorithm is wrong" << endl;



	int B[11] = { 6, -1, 9, 3, 4, 6, 0, -5, -9, 7, 1 };

	insertion_sort(B, 11);

	cout << "the following array should be sorted" << endl;
	for (int i = 0; i < 11; ++i)
		cout << B[i] << " ";
	cout << endl;

	system("pause");

	return 0;

}
