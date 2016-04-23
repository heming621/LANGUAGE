#include <iostream>
#include <string.h>
using namespace std;
void print(int* arr, int n);
int partition(int*, int, int);
void quickSort(int*, int, int);
int main()
{

    int arr[10] = {5,23,9,1234,234,87,1,88,999,1234};
    quickSort(arr, 0, end(arr)-begin(arr)-1); //like quickSort(arr, low, high); quickSort(arr, 0, n-1);
    print(arr, end(arr)-begin(arr));
    return 0;
}
int partition(int *arr, int low, int high)    // int arr[]; deliver parameter: arr, begin(arr)-end(arr)
{
    int pivotKey = arr[low];  //if: int pivotKey = arr[0]; die矣!
    int temp;
    while(low<high)
    {
        while(low<high && arr[high]>=pivotKey)--high;
        temp = arr[high];
        arr[high] = arr[low];
        arr[low] = temp;
        
	while(low<high && arr[low]<=pivotKey)++low;
        temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
    }
    return low;
}

void quickSort(int *arr, int low, int high) // int arr[]; deliver parameter: arr, begin(arr)-end(arr)
{
    //递归在本质上就是一个栈结构；每一次partition返回一个枢轴，将其两边有序；多次递归......
    //每一次递归，出一次栈，返回一个枢纽值与进行其两边的排序
    if(low<high)
    {
	int pivotLoc = partition(arr, low, high);
	quickSort(arr, low, pivotLoc-1);
	quickSort(arr, pivotLoc+1, high);
    }
}

void print(int* arr, int n)
{
    //for(int* begin = arr; begin!=end(arr); begin++)
    //	cout<<*begin++<<" ";
    for(int i = 0; i<n; i++)
	cout<<arr[i]<<" ";
    cout<<endl;

}
