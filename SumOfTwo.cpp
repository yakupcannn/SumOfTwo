#include<iostream>
#include<unordered_set>
using namespace std;
//Brute Force O(N^2)
int* findSumOfTwo(const int *arr,int size,int value)
{
	int temp[2];
	for (int i = 0; i < size; i++)
	{
		for (int  j = 1; j < size; j++)
		{
			if (arr[i] + arr[j] == value)
			{
				temp[0] = i;
				temp[1] = j;
				return temp;
			}
		}
	}
	return NULL;
}
//O(N) solution using hash set
int* findSumOfTwo1(const int* arr, int size, int value)
{
	unordered_set<int> complements;
	int temp[2];
	for (int i = 0; i < size; i++)
	{
		complements.insert(value - arr[i]);
	}
	for (int i = 0; i < size; i++)
	{
		unordered_set<int>::iterator it=complements.find(arr[i]);
		if (it != complements.end())
		{
			
			temp[0] = i;
			temp[1] = value-arr[i];
			break;
		}
		else
		{
			return NULL;
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (temp[1] == arr[i])
			temp[1] = i;
	}
	return temp;
}
int main()
{
	int arr[6] = { 2,5,4,3,7,8 };
	//int arr[1] = {1};
	//int arr[1] = {};
	//int* result = findSumOfTwo(arr, 6, 9);
	int* result = findSumOfTwo1(arr, 6, 9);
	//int* result = findSumOfTwo(arr, 1, 3);
	//int* result = findSumOfTwo1(arr, 1, 3);
	if (result == NULL)
		cout << "Convenient indexes can not be found"<<endl;
	else
	cout<<"Indexes: { "<<result[0]<<","<< result[1]<<" }"<<endl;

	return 0;
}