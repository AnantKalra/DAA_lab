#include<iostream>
#include<vector>

using namespace std;

int linear_search(vector<int>arr,int data){
    int len=arr.size();

    for(int i=0;i<=len-1;i++)
    {
        if(arr[i]==data){
            cout<<"Element found";
            return i;
            }
        else{
            cout<<"item not found";
            return 0;
        }

    }}
int main(){
    vector<int> array={24,56,71,45,78,13,67,1,23,82};
    int Number;
    cout<<"Enter the number yo find";
    cin>>Number;

    int index=linear_search(array,Number);

    cout<<"the index at which the number was present"<<index;

}
