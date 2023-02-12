#include<bits/stdc++.h>

using namespace std;

void display(int arr[], int index, int n){
    // Base Case
    if(index==n)return;
     display(arr,index+1,n);
    cout<<arr[index]<<" ";
   
}
int main(){
    int arr[]={10,12,23,45,56};
    int n=5;

    display(arr,0,n);

}