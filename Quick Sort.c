#include<iostream>
#include<vector>

using namespace std;

void quick_sort(vector <int> &arr,int str,int end){
    if (str<end){
        piv_index=partition(arr,str,end);
        quick_sort(arr,str,piv_index-1);
        quick_sort(arr,piv_index+1,end);}
    }

void partition(vector <int> &arr,int str,int end){
    int index=str-1,pivot=arr[end];

    for(int j=0;j<end;j++){
        if(arr[j]<=pivot){
            index++;
            swap(arr[j],arr[index]);

        }
    }
    index++;
    swap(arr[end],arr[index]);
    return index;

    }
int main()
{
    vector <int> array={5,4,6,2,7,8,1}

    quick_sort(array,0,arr.size()-1);

    for(int val:array )
        cout<<val;
}
