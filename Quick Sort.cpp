#include<iostream>
#include<vector>

using namespace std;

int partition(vector <int> &arr,int str,int end){
    int index=str-1,pivot=arr[end];

    for(int j=str;j<end;j++){
        if(arr[j]<=pivot){
            index++;
            swap(arr[j],arr[index]);

        }
    }
    index++;
    swap(arr[end],arr[index]);
    return index;

    }
void quick_sort(vector <int> &arr,int str,int end){
    if (str<end){
        int piv_index=partition(arr,str,end);
        quick_sort(arr,str,piv_index-1);
        quick_sort(arr,piv_index+1,end);}
    }


int main()
{
    vector <int> array={5,4,6,2,7,9,23,563,2452,245,24,8,1};

    quick_sort(array,0,array.size()-1);

    for(int val:array )
        cout<<val<<" ";
        cout<<endl;
}
