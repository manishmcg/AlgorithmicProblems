#include<iostream>
using namespace std;

void swap(int arr[], int first, int second)
{
	int temp = arr[first];
	arr[first] = arr[second];
	arr[second] = temp;
}

int partition(int arr[], int start, int end)
{
	int pivot = arr[end];
	int i = start, c = start;
	for (; c < end; c++)
	{
		if (arr[c] < pivot)
		{
			swap(arr, i, c);
			i++;
		}
	}
	swap(arr, i, end);
	return i;
}

void quickSort(int arr[], int start, int end)
{
	if (start > end)
		return;
	int pivot = partition(arr, start, end);
	quickSort(arr, start, pivot - 1);
	quickSort(arr, pivot + 1, end);
}

int main()
{
	int arr[] = { 3,1,4,5,2 };
	quickSort(arr, 0, 4);
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}