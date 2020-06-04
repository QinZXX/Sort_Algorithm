#include"sort.h"
#include<iostream>
using namespace std;

int main() {
	int a[10]={3,7,0,4,8,34,12,78,65,47};
	size_t n = sizeof(a) / sizeof(int);
	
	

	
	//MergeSort(a,n);
	cout << "Begin to sort:" << endl;
	qSort(a, n);

	cout << "Result£º" << endl;
	for (int k = 0; k < n; k++) {
		cout << a[k] << " ";
	}
	cout << endl;
	

	
	


	return 0;
}