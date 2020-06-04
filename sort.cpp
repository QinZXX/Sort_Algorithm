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

	/*cout << "The result of SelectionSort：" << endl;
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

	/*cout << "The result of SelectionSort：" << endl;
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

	/*cout << "The result of BubbleSort：" << endl;
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
	//先用一个临时数组把他们合并汇总起来
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
	// 把临时数组复制到原数组
	for (i = 0; i < k; i++) {
		arr[left++] = a[i];
	}
	delete[] a;
}

void MergeSort(int *arr,size_t n) {
	// 子数组的大小分别为1，2，4，8...
	// 刚开始合并的数组大小是1，接着是2，接着4....
	for (int i = 1; i < n;i<<=1) {//位运算(i+=i)
		//进行数组进行划分
		int left = 0;
		int mid = left + i - 1;
		int right = mid + i;
		//进行合并，对数组大小为 i 的数组进行两两合并
		while (right < n) {
			// 合并函数
			merge(arr, left, mid, right);
			left = right + 1;
			mid = left + i - 1;
			right = mid + i;
		}
		// 还有一些被遗漏的数组没合并
		// 因为不可能每个字数组的大小都刚好为 i
		if (left < n && mid < n) {
			merge(arr, left, mid, n - 1);
		}
	}
}


int partition(int* a, int left, int right){
	int pivot = a[right];
	int i = left;
	for (int j = left; j <right; j++){
		if (a[j] <= pivot){//遇到一个小于等于pivot的元素，就将其与a[i]交换，i++。一次放入前面的数组位置。
			int t = a[i];
			a[i] = a[j];
			a[j] = t;
			i++;
		}
	}
	int t = a[i];//pivot放到中间去
	a[i]=a[right];
	a[right] = t;;
	return i;//返回中轴元素位置
}
void quickSort(int *a, int left, int right){
	if (left < right){
		int mid = partition(a, left, right);//排好pivot位置，返回值为中轴元素位置
		quickSort(a, left, mid - 1);
		quickSort(a, mid + 1, right);
	}
}
void qSort(int *a,size_t n){
	quickSort(a, 0, n - 1);
}

int partition2(int* a, int left, int right) {//方式2：双向扫描
	int pivot = a[left];//左边第一个元素作为pivot
	int i = left+1;
	int j = right + 1;
	while (true){
		//向右遍历扫描
		while (i <= j && a[i] <= pivot) i++;
		//向左遍历扫描
		while (i<= j && a[j] >= pivot) j--;
		if (i >= j)
			break;
		//交换
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	//a[j]及左边的元素均小于等于pivot；a[i]及右边的元素均大于等于pivot
	//把a[j]和pivot交换(当然，跟a[i]交换也可以)
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
	//把临时数组统计好的数据汇总到原数组
	for (int i = 0; i <= max; i++) {
		for (int j = b[i]; j > 0; j--) {
			b[k++] = i;
		}
	}
	delete[]b;
}

void betterCountingSort(int *a, size_t n) {//非稳定版本  ，只能对 自然数序列 排序
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
	//把临时数组统计好的数据汇总到原数组
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
	//对统计数组做处理
	int sum = 0;
	for (int i = 0; i<sz; i++) {
		sum += b[i];
		b[i] = sum;
	}
	//倒序比遍历原始序列，从统计数组找到正确位置，输出到结果数组中
	for (int i = sz-1; i<=0; i--) {
		a[b[a[i]-min]];
	}
	delete[]b;
}



