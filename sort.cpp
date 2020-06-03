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
		//����a[min]��a[i]��ʹ�õ�ǰ��Χ��ǰ��������a[i]����С��
		int temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}

	cout << "ѡ����������" << endl;
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
//					a[k] = a[k - 1];//����ĺ���  //���հ�ԭ����a[j+1]��ֵ����a[j+2]  ��a[j+2]=a[j+1]
//					//a[j+1]��ֵ=a[i]��temp
//				}
//				a[j + 1] = temp;
//				break;
//			}
//			//���������a[i]�����еĶ�С�����������?�����������Ҫд�������ҵ������û�취����������
//		}
//	}
//
//	cout << "ѡ����������" << endl;
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
		//�ڳ�λ�ò��ȥ,Ҫ���λ���� k + 1;
		for (int j = i; j > k + 1; j--)
			a[j] = a[j - 1];
		//���ȥ
		a[k + 1] = temp;
	}

	cout << "ѡ����������" << endl;
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

	cout << "ð����������" << endl;
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

	cout << "��׼ð����������" << endl;
	for (int k = 0; k < n; k++) {
		cout << a[k] << " ";
	}
	cout << endl;
}

//�Ż�ð������
//����ӿ�ʼ�ĵ�һ�Ե���β�����һ�ԣ����ڵ�Ԫ��֮�䶼û�з��������Ĳ���������ζ���ұߵ�Ԫ�����Ǵ��ڵ�����ߵ�Ԫ�أ���ʱ��
//�����Ѿ���������ˣ����������ٶ�ʣ���Ԫ���ظ��Ƚ���ȥ�ˡ�
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
		//һ�������Ƿ���λ�ý���
		if (flag)
			break;
	}

	cout << "�Ż�ð����������" << endl;
	for (int k = 0; k < n; k++) {
		cout << a[k] << " ";
	}
	cout << endl;

}


//Ϊ�˼ӿ��ٶȼ򵥵ظĽ��˲������򣬽��������ڵ�Ԫ���Զ�����ľֲ���������
//ϣ�������˼���ǲ��ò�������ķ���������������������Ϊ h ��Ԫ�����򣬸տ�ʼ h �Ĵ�С������ h = n / 2, ������ h = n / 4��
//�� h һֱ��С���� h = 1 ʱ��Ҳ���Ǵ�ʱ������������Ϊ1��Ԫ�����򣬴�ʱ���������������ˡ�
void Shell(int *a, size_t &n) {
	//TODO��


	cout << "ϣ����������" << endl;
	for (int k = 0; k < n; k++) {
		cout << a[k] << " ";
	}
	cout << endl;
}

int * Merge(int *arr,int left, int right) {//�ݹ�ʽ
	// ��� left == right����ʾ����ֻ��һ��Ԫ�أ����õݹ�����
	if (left < right) {
		// �Ѵ������ָ�����������
		int mid = (left + right) / 2;//��������ö��ַ��Ľ�
		// ����벿�ֽ�������
		arr = Merge(arr, left, mid);
		// ���Ұ벿�ֽ�������
		arr = Merge(arr, mid + 1, right);
		//������������кϲ�
		merge(arr, left, mid, right);
	}
	return arr;
}
void merge(int *arr, int left, int mid, int right) {
	//����һ����ʱ��������Ǻϲ���������
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
	while (i <= mid) a[k++] = arr[i++];//�ұ����꣬��߻�û����
	while (j <= right) a[k++] = arr[j++];//������꣬�ұ߻�û����
	// ����ʱ���鸴�Ƶ�ԭ����
	for (i = 0; i < k; i++) {
		arr[left++] = a[i];
	}
	delete []a;
}

void Merge2(int *arr,size_t n) {//�ǵݹ�ʽ
	// ������Ĵ�С�ֱ�Ϊ1��2��4��8...
	// �տ�ʼ�ϲ��������С��1��������2������4....
	for (int i = 1; i < n;i<<=1) {//λ������죬���Ըĳ�
		//����������л���
		int left = 0;
		int mid = left + i - 1;
		int right = mid + i;
		//���кϲ����������СΪ i ��������������ϲ�
		while (right < n) {
			// �ϲ������͵ݹ�ʽ�ĺϲ�����һ��
			merge(arr, left, mid, right);
			left = right + 1;
			mid = left + i - 1;
			right = mid + i;
		}
		// ����һЩ����©������û�ϲ���ǧ�������
		// ��Ϊ������ÿ��������Ĵ�С���պ�Ϊ i
		if (left < n && mid < n) {
			merge(arr, left, mid, n - 1);
		}
	}

	cout << "���ǵݹ�ʽ���鲢��������" << endl;
	for (int k = 0; k < n; k++) {
		cout << arr[k] << " ";
	}
	cout << endl;
}

int* quickSort(int* arr, int left, int right) {
	if (left < right) {
		//��ȡ����Ԫ��������λ��
		int mid = partition(arr, left, right);
		//���зָ�
		arr = quickSort(arr, left, mid - 1);
		arr = quickSort(arr, mid + 1, right);
	}
	return arr;
}

int partition(int* arr, int left, int right) {
	//ѡȡ����Ԫ��
	int pivot = arr[left];
	int i = left + 1;
	int j = right;
	while (true) {
		// �����ҵ���һ��С�ڵ��� pivot ��Ԫ��λ��
		while (i <= j && arr[i] <= pivot) i++;
		// �����ҵ���һ�����ڵ��� pivot ��Ԫ��λ��
		while (i <= j && arr[j] >= pivot) j--;
		if (i >= j)
			break;
		//��������Ԫ�ص�λ�ã�ʹ����ߵ�Ԫ�ز�����pivot,�ұߵĲ�С��pivot
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	arr[left] = arr[j];
	// ʹ����Ԫ�ش��������λ��
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

	return i;//���ص�ǰ������λ��λ�ã����ڵ�����һ��

	//��ֹ������ʲô��left=right
}

void Count(int *a, size_t n) {//���ȶ��汾  ��ֻ�ܶ� ��Ȼ������ ����
	int max = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	/*int *b = new int[max+1];
	for (int i = 0; i <=max; i++)
		b[i] = 0;*/  //�ɺϲ�Ϊ��һ��
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

	cout << "������������" << endl;
	for (int k = 0; k < n; k++) {
		cout << a[k] << " ";
	}
	cout << endl;
}
//����ֻ�����ֵ��ȷ��ͳ������b�ĳ��ȡ���������ɴ����ռ��˷�
//���� 95,94,91,98,99,90,91  ��ô��0��89�Ŀռ䶼�˷���

//��������ĸĽ���������������Сֵ�Ĳ���Ϊͳ������ĳ��ȣ�min��Ϊһ��ƫ�������Ժ�����
/*��һ���棺��û�����������򡣱�������ʵҵ���У���ѧ���ķ���������ͬ�ķ����ͻ�ֲ���˭��˭
�����ȶ����򣩣�����һ��ѧ���ĳɼ���Ҫ�󰴳ɼ��ӵ͵�����������ɼ���ͬ������ѭԭ�����˳��
*/

void betterCount(int *a, size_t n) {//���ȶ��汾  ��ֻ�ܶ� ��Ȼ������ ����
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
		b[i] = 0;*/  //�ɺϲ�Ϊ��һ��
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

	cout << "�Ż�������������" << endl;
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
		b[i] = 0;*/  //�ɺϲ�Ϊ��һ��
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

	cout << "�ȶ��Ż�������������" << endl;
	for (int k = 0; k < n; k++) {
		cout << a[k] << " ";
	}
	cout << endl;
}