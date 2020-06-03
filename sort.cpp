#include"sort.h"
#include<vector>

void Choose(int *a, const size_t& n) {
	for (int i = 0; i < n; i++) {
		int min = i;
		for (int j = i; j < n; j++) {
			if (a[j] < a[min]) {
				min = j;
			}
		}
		//交换a[min]和a[i]，使得当前范围最前面索引的a[i]是最小的
		int temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}

	cout << "选择排序结果：" << endl;
	for (int k = 0; k < n; k++) {
		cout << a[k] << " ";
	}
	cout << endl;
}

//void Insert(int *a, const size_t& n) {
//	for (int i = 1; i < n; i++) {
//		for (int j = i - 1; j >= 0; j--) {
//			if (a[j] <= a[i]) {
//				int temp = a[i];
//				for (int k = i; k >= (j + 2); k--) {
//					a[k] = a[k - 1];//其余的后移  //最终把原来的a[j+1]的值给了a[j+2]  即a[j+2]=a[j+1]
//					//a[j+1]的值=a[i]即temp
//				}
//				a[j + 1] = temp;
//				break;
//			}
//			//特例情况，a[i]比所有的都小，放在最左边?这种情况不需要写吗？所以我的这个就没办法处理这个情况
//		}
//	}
//
//	cout << "选择排序结果：" << endl;
//	for (int k = 0; k < n; k++) {
//		cout << a[k] << " ";
//	}
//	cout << endl;
//}

void Insert(int *a, const size_t& n){
	for (int i = 1; i < n; i++) {
		int temp = a[i];
		int k = i - 1;
		while (k >= 0 && a[k] > temp)
			k--;
		//腾出位置插进去,要插的位置是 k + 1;
		for (int j = i; j > k + 1; j--)
			a[j] = a[j - 1];
		//插进去
		a[k + 1] = temp;
	}

	cout << "选择排序结果：" << endl;
	for (int k = 0; k < n; k++) {
		cout << a[k] << " ";
	}
	cout << endl;
         
       
}

void Bubble(int *a, const size_t& n) {
	for (int i = n-1; i >= 1; i--) {
		for (int j = 0; j <i; j++) {
			if (a[j] > a[j + 1]) {
				int temp=a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}

	cout << "冒泡排序结果：" << endl;
	for (int k = 0; k < n; k++) {
		cout << a[k] << " ";
	}
	cout << endl;
}

void objBubble(int *a, const size_t &n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j + 1] < a[j]) {
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}

	cout << "标准冒泡排序结果：" << endl;
	for (int k = 0; k < n; k++) {
		cout << a[k] << " ";
	}
	cout << endl;
}

//优化冒泡排序
//假如从开始的第一对到结尾的最后一对，相邻的元素之间都没有发生交换的操作，这意味着右边的元素总是大于等于左边的元素，此时的
//数组已经是有序的了，我们无需再对剩余的元素重复比较下去了。
void betterBubble(int *a, size_t &n) {
	for (int i = 0; i < n; i++) {
		bool flag = true;
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j + 1] < a[j]) {
				flag = false;
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
		//一趟下来是否发生位置交换
		if (flag)
			break;
	}

	cout << "优化冒泡排序结果：" << endl;
	for (int k = 0; k < n; k++) {
		cout << a[k] << " ";
	}
	cout << endl;

}


//为了加快速度简单地改进了插入排序，交换不相邻的元素以对数组的局部进行排序。
//希尔排序的思想是采用插入排序的方法，先让数组中任意间隔为 h 的元素有序，刚开始 h 的大小可以是 h = n / 2, 接着让 h = n / 4，
//让 h 一直缩小，当 h = 1 时，也就是此时数组中任意间隔为1的元素有序，此时的数组就是有序的了。
void Shell(int *a, size_t &n) {
	//TODO：


	cout << "希尔排序结果：" << endl;
	for (int k = 0; k < n; k++) {
		cout << a[k] << " ";
	}
	cout << endl;
}

int * Merge(int *arr,int left, int right) {//递归式
	// 如果 left == right，表示数组只有一个元素，则不用递归排序
	if (left < right) {
		// 把大的数组分隔成两个数组
		int mid = (left + right) / 2;//这里可以用二分法改进
		// 对左半部分进行排序
		arr = Merge(arr, left, mid);
		// 对右半部分进行排序
		arr = Merge(arr, mid + 1, right);
		//把两个数组进行合并
		merge(arr, left, mid, right);
	}
	return arr;
}
void merge(int *arr, int left, int mid, int right) {
	//先用一个临时数组把他们合并汇总起来
	int* a = new int[right - left + 1];//delete []a
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
	while (i <= mid) a[k++] = arr[i++];//右边排完，左边还没放入
	while (j <= right) a[k++] = arr[j++];//左边排完，右边还没放入
	// 把临时数组复制到原数组
	for (i = 0; i < k; i++) {
		arr[left++] = a[i];
	}
	delete []a;
}

void Merge2(int *arr,size_t n) {//非递归式
	// 子数组的大小分别为1，2，4，8...
	// 刚开始合并的数组大小是1，接着是2，接着4....
	for (int i = 1; i < n;i<<=1) {//位运算更快，所以改成
		//进行数组进行划分
		int left = 0;
		int mid = left + i - 1;
		int right = mid + i;
		//进行合并，对数组大小为 i 的数组进行两两合并
		while (right < n) {
			// 合并函数和递归式的合并函数一样
			merge(arr, left, mid, right);
			left = right + 1;
			mid = left + i - 1;
			right = mid + i;
		}
		// 还有一些被遗漏的数组没合并，千万别忘了
		// 因为不可能每个字数组的大小都刚好为 i
		if (left < n && mid < n) {
			merge(arr, left, mid, n - 1);
		}
	}

	cout << "（非递归式）归并排序结果：" << endl;
	for (int k = 0; k < n; k++) {
		cout << arr[k] << " ";
	}
	cout << endl;
}

int* quickSort(int* arr, int left, int right) {
	if (left < right) {
		//获取中轴元素所处的位置
		int mid = partition(arr, left, right);
		//进行分割
		arr = quickSort(arr, left, mid - 1);
		arr = quickSort(arr, mid + 1, right);
	}
	return arr;
}

int partition(int* arr, int left, int right) {
	//选取中轴元素
	int pivot = arr[left];
	int i = left + 1;
	int j = right;
	while (true) {
		// 向右找到第一个小于等于 pivot 的元素位置
		while (i <= j && arr[i] <= pivot) i++;
		// 向左找到第一个大于等于 pivot 的元素位置
		while (i <= j && arr[j] >= pivot) j--;
		if (i >= j)
			break;
		//交换两个元素的位置，使得左边的元素不大于pivot,右边的不小于pivot
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	arr[left] = arr[j];
	// 使中轴元素处于有序的位置
	arr[j] = pivot;
	return j;
}

int qinkuai(int *arr, int left, int right) {
	int i  = left;
	int j = left;
	int temp = arr[right];
	for (;j<=right-1;j++) {
		if (arr[j]<temp) {
			int t = arr[j];
			arr[j] = arr[i];
			arr[i] = t;
			i++;
		}
	}
	{
		int t = arr[i];
		arr[i] = arr[right];
		arr[right] = t;
	}

	qinkuai(arr, left, i - 1);
	qinkuai(arr, i + 1, right);

	return i;//返回当前的中轴位置位置，用于迭代下一次

	//终止条件是什么？left=right
}

void Count(int *a, size_t n) {//非稳定版本  ，只能对 自然数序列 排序
	int max = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	/*int *b = new int[max+1];
	for (int i = 0; i <=max; i++)
		b[i] = 0;*/  //可合并为下一行
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

	cout << "计数排序结果：" << endl;
	for (int k = 0; k < n; k++) {
		cout << a[k] << " ";
	}
	cout << endl;
}
//这里只以最大值来确定统计数组b的长度。但可能造成大量空间浪费
//比如 95,94,91,98,99,90,91  那么从0到89的空间都浪费了

//对于这个的改进：可以用最大和最小值的差作为统计数组的长度，min作为一个偏移量来对号入座
/*另一方面：并没有真正的排序。比如在现实业务中，给学生的分数排序，相同的分数就会分不清谁是谁
（非稳定排序）：给定一个学生的成绩表，要求按成绩从低到高排序，如果成绩相同，则遵循原表固有顺序。
*/

void betterCount(int *a, size_t n) {//非稳定版本  ，只能对 自然数序列 排序
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
	/*int *b = new int[max+1];
	for (int i = 0; i <=max; i++)
		b[i] = 0;*/  //可合并为下一行
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

	cout << "优化计数排序结果：" << endl;
	for (int k = 0; k < n; k++) {
		cout << a[k] << " ";
	}
	cout << endl;
}

void stableCount(int *a, size_t n) {
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
	/*int *b = new int[max+1];
	for (int i = 0; i <=max; i++)
		b[i] = 0;*/  //可合并为下一行
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

	cout << "稳定优化计数排序结果：" << endl;
	for (int k = 0; k < n; k++) {
		cout << a[k] << " ";
	}
	cout << endl;
}