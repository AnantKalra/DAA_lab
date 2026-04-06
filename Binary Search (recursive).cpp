#include<iostream>
#include<vector>
using namespace std;

int binary_search(vector<int>&arr,int low,int high,int data){
    if(low>high){
        return -1;}
    int mid = (low + (high-low))/2;
    if (arr[mid] == key)
        return mid;
    else if (arr[mid] < key)
        return binary_search(arr, mid + 1, high, key);
    else
        return binary_search(arr, low, mid - 1, key);
    }

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 15};
    int key;

    cout << "Enter element to search: ";
    cin >> key;

    int index = binary_search(arr, key);
    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
