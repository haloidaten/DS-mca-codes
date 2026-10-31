#include <stdio.h>
int search(int arr[], int size, int target, int searchType) {
if (searchType == 1)
{
for (int i = 0; i < size; i++)
{
if (arr[i] == target)
{
return i;
}
}
return -1;
} else if (searchType == 2)
{
int left = 0, right = size - 1;
while (left <= right) {
int mid = left + (right - left) / 2;
if (arr[mid] == target)
{
return mid;
}
if (arr[mid] < target)
{
left = mid + 1;
} else {
right = mid - 1;
}
}
return -1;
}
return -1;
}
void bubbleSort(int arr[], int size)
{
for (int i = 0; i < size - 1; i++)
{
for (int j = 0; j < size - i - 1; j++)
{
if (arr[j] > arr[j + 1])
{
int temp = arr[j];
arr[j] = arr[j + 1];
arr[j + 1] = temp;
}
}
}
}
int main()
{
int size, target, searchType;
printf("Enter the number of elements in the array: ");
scanf("%d", &size);
if (size <= 0) {
printf("Invalid array size. Size should be greater than 0.\n");
return 1;
}
int arr[size];
printf("Enter the elements of the array: ");
for (int i = 0; i < size; i++) {
scanf("%d", &arr[i]);
}
printf("Enter the target value to search for: ");
scanf("%d", &target);
printf("Enter search type (1 for Linear Search, 2 for Binary Search): ");
scanf("%d", &searchType);
if (searchType == 2)
{
printf("Sorting array for Binary Search...\n");
bubbleSort(arr, size);
printf("Sorted array: ");
for (int i = 0; i < size; i++) {
printf("%d ", arr[i]);
}
printf("\n");
} else if (searchType != 1)
{
printf("Invalid search type. Choose 1 or 2.\n");
return 1;
}
int result = search(arr, size, target, searchType);
if (result != -1)
{
printf("Element found at index: %d\n", result);
} else {
printf("Element not found.\n");
}
}