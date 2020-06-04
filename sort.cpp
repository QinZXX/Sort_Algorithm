#include"sort.h"
#include<vector>
#include<algorithm>

void SelectionSort(int *a, const size_t& n) {
	for (int i = 0; i < n-1; i++) {
		int min = i;
		for (int j = i+1; j < n; j++) {
			if (a[j] < a[min]) {
				min = j;
			}
		}
		int temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}

	/*cout << "The result of SelectionSort��" << endl;
	for (int k = 0; k < n; k++) {
		cout << a[k] << " ";
	}
	cout << endl;*/
}

void InsertionSort(int *a, const size_t& n){
	for (int i = 1; i < n; i++) {
		int temp = a[i];
		int j = i - 1;
		for (; j >= 0; j--) {
			if (a[j] > temp) 
				a[j + 1] = a[j ];
			else 
				break;
		}
		a[j+1] = temp;
	}

	/*cout << "The result of SelectionSort��" << endl;
	for (int k = 0; k < n; k++) {
		cout << a[k] << " ";
	}
	cout << endl;  */   
}

void BubbleSort(int *a, const size_t& n) {
	for (int i = n-1; i >= 1; i--) {
		bool isChange = false;
		for (int j = 0; j <i; j++) {
			if (a[j] > a[j + 1]) {
				int temp=a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				isChange = true;
			}
		}
		if (!isChange)
			break;
	}

	/*cout << "The result of BubbleSort��" << endl;
	for (int k = 0; k < n; k++) {
		cout << a[k] << " ";
	}
	cout << endl;*/
}

void stdBubbleSort(int *a, const size_t &n) {
	for (int i = 0; i < n; i++) {
		bool isChange = false;
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j + 1] < a[j]) {
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
		if (!isChange)
			break;
	}
}

void ShellSort(int *a, size_t &n) {
	int d = n / 2;
	while (d >= 1) {
		for (int i = d; i < n; i++) {
			int value = a[i];
			for (int j = i - d; j >= 0;j-=d) {
				if (a[j] > value)
					a[j + d] = a[j];
				else
					break;
			}
		}
		d/=2;
	}
}

void merge(int* arr, int left, int mid, int right) {
	//����һ����ʱ��������Ǻϲ���������
	int* a = new int[right - left + 1];
	int i = left;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= right) {
		if (arr[i] < arr[j]) {
			a[k++] = arr[i++];
		}
		else {
			a[k++] = arr[j++];
		}
	}
	while (i <= mid) a[k++] = arr[i++];
	while (j <= right) a[k++] = arr[j++];
	// ����ʱ���鸴�Ƶ�ԭ����
	for (i = 0; i < k; i++) {
		arr[left++] = a[i];
	}
	delete[] a;
}

void MergeSort(int *arr,size_t n) {
	// ������Ĵ�С�ֱ�Ϊ1��2��4��8...
	// �տ�ʼ�ϲ��������С��1��������2������4....
	for (int i = 1; i < n;i<<=1) {//λ����(i+=i)
		//����������л���
		int left = 0;
		int mid = left + i - 1;
		int right = mid + i;
		//���кϲ����������СΪ i ��������������ϲ�
		while (right < n) {
			// �ϲ�����
			merge(arr, left, mid, right);
			left = right + 1;
			mid = left + i - 1;
			right = mid + i;
		}
		// ����һЩ����©������û�ϲ�
		// ��Ϊ������ÿ��������Ĵ�С���պ�Ϊ i
		if (left < n && mid < n) {
			merge(arr, left, mid, n - 1);
		}
	}
}


int partition(int* a, int left, int right){
	int pivot = a[right];
	int i = left;
	for (int j = left; j <right; j++){
		if (a[j] <= pivot){//����һ��С�ڵ���pivot��Ԫ�أ��ͽ�����a[i]������i++��һ�η���ǰ�������λ�á�
			int t = a[i];
			a[i] = a[j];
			a[j] = t;
			i++;
		}
	}
	int t = a[i];//pivot�ŵ��м�ȥ
	a[i]=a[right];
	a[right] = t;;
	return i;//��������Ԫ��λ��
}
void quickSort(int *a, int left, int right){
	if (left < right){
		int mid = partition(a, left, right);//�ź�pivotλ�ã�����ֵΪ����Ԫ��λ��
		quickSort(a, left, mid - 1);
		quickSort(a, mid + 1, right);
	}
}
void qSort(int *a,size_t n){
	quickSort(a, 0, n - 1);
}

int partition2(int* a, int left, int right) {//��ʽ2��˫��ɨ��
	int pivot = a[left];//��ߵ�һ��Ԫ����Ϊpivot
	int i = left+1;
	int j = right + 1;
	while (true){
		//���ұ���ɨ��
		while (i <= j && a[i] <= pivot) i++;
		//�������ɨ��
		while (i<= j && a[j] >= pivot) j--;
		if (i >= j)
			break;
		//����
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	//a[j]����ߵ�Ԫ�ؾ�С�ڵ���pivot��a[i]���ұߵ�Ԫ�ؾ����ڵ���pivot
	//��a[j]��pivot����(��Ȼ����a[i]����Ҳ����)
	a[left] = a[j];
	a[j] = pivot;
	return j;
}

void CountingSort(int *a, size_t n) {
	int max = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	int *b = new int[max + 1]();

	for (int j = 0; j < n; j++) {
		b[a[j]]++;
	}
	
	int k = 0;
	//����ʱ����ͳ�ƺõ����ݻ��ܵ�ԭ����
	for (int i = 0; i <= max; i++) {
		for (int j = b[i]; j > 0; j--) {
			b[k++] = i;
		}
	}
	delete[]b;
}

void betterCountingSort(int *a, size_t n) {//���ȶ��汾  ��ֻ�ܶ� ��Ȼ������ ����
	int max = a[0];
	int min = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
			continue;
		}
		if (a[i] < min) 
			min = a[i];
	}
	int sz = max - min + 1;
	int *b = new int[sz]();
	for (int j = 0; j < n; j++) {
		b[(a[j]-min)]++;
	}
	int k = 0;
	//����ʱ����ͳ�ƺõ����ݻ��ܵ�ԭ����
	for (int i = 0; i < sz; i++) {
		for (int j = b[i]; j > 0; j--) {
			a[k++] = i + min;
		}
	}
	delete[]b;
}

void stableCountingSort(int *a, size_t n) {
	int max = a[0];
	int min = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
			continue;
		}
		if (a[i] < min) {
			min = a[i];
		}
	}
	int sz = max - min + 1;
	int *b = new int[sz]();
	for (int j = 0; j < n; j++) {
		b[(a[j] - min)]++;
	}
	//��ͳ������������
	int sum = 0;
	for (int i = 0; i<sz; i++) {
		sum += b[i];
		b[i] = sum;
	}
	//����ȱ���ԭʼ���У���ͳ�������ҵ���ȷλ�ã���������������
	for (int i = sz-1; i<=0; i--) {
		a[b[a[i]-min]];
	}
	delete[]b;
}



