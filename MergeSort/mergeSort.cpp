#include<iostream>
#include<vector>
using namespace std;


void merge(int arr[], int left, int mid, int right)
{
	int lSize = (mid - left + 1);	int rSize = right - mid;
	//Declare Arr with variable size is not permittable after C98
	//int lArr[lSize]; 	int rArr[rSize];
	vector<int> lArr(lSize,0); vector<int>rArr(rSize, 0);
	int i, j, k;
	for (i = 0; i < lSize; i++) lArr[i] = arr[left + i];
	for (j = 0; j < rSize; j++) rArr[j] = arr[mid + 1 + j];

	i = 0; j = 0; k = left;
	while (i < lSize && j < rSize)
	{
		if (lArr[i] < rArr[j])	{ arr[k++] = lArr[i++]; }
		else					{	arr[k++] = rArr[j++];	}
	}

	while (i < lSize) { arr[k++] = lArr[i++]; }
	while (j < rSize) { arr[k++] = rArr[j++]; }

}
void mergeSort(int arr[], int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

int main() {
	int arr[] = { 1,4,3,2,5 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	mergeSort(arr, 0, arr_size-1);
	for (int i = 0; i < arr_size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}