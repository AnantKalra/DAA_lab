#include<iostream>
#include<vector>

using namespace std;


void merge(vector<int> &A,int low,int mid,int high){  //O(n)
    int i,j;
    vector<int> temp;
    i=low;
    j=mid+1;
    while (i<=mid && j<=high){
        if (A[i]<A[j]){
            temp.push_back(A[i]);
            i++;}
        else {
            temp.push_back(A[j]);
            j++;
        }

    }
    while(i<=mid){
        temp.push_back(A[i]);
        i++;

    }
    while(j<=high){
        temp.push_back(A[j]);
        j++;

    }
    for(int index=0;index<temp.size();index++){
        A[low+index]=temp[index];
    }
            }

void merge_sort(vector<int>&A,int l,int r){
    if(l<r){ // Base case = l<r

    int mid=l+(r-l)/2;   //this is better formnula for big integers OR simple formula is (l+r)/2
    merge_sort(A,l,mid);
    merge_sort(A,mid+1,r);
    merge(A,l,mid,r);
    }

    }
int main(){
    vector<int>arr={11,34,56,22,89,67,43,9};
    cout<<"Original Array \n";
    for(int val:arr){

        cout<<val<<",";

    }
    merge_sort(arr,0,arr.size()-1);
    cout<<"\n";
    cout<<"Sorted array \n";
    for(int val:arr){
            cout<<val<<",";

    }

    }
