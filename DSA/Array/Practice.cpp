### Problem: Find the Second Largest Element in a Vector
#include<bits/stdc++.h>
using namespace std;

int secondLargest(vector<int>& arr){
    int first=INT_MIN,sec=INT_MIN;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>first){
            sec=first;
            first=arr[i];
        }
        else if(arr[i]<first && arr[i]>sec){
            sec=arr[i];
        }
    }
    return sec;
}

int main() {
    vector<int> vec = {5, 2, 9, 1, 7, 9};
    cout << "Second largest: " << secondLargest(vec) << endl;
    return 0;
}

### Easy: Remove Duplicates from Sorted Vector ***************************************************************************************************
### Given a sorted vector, remove duplicates in-place and return new size
#include<bits/stdc++.h>
using namespace std;

int removeDuplicateSize(vector<int>& arr){
    int j=0;
    for(int i=1;i<arr.size();i++){
        if(arr[j]!=arr[i]){
            j++;
            arr[j]=arr[i];
        }
    }
    return j+1;
}

int main() {
    // vector<int> vec = {1, 2, 3, 4, 5};
    vector<int> vec = {7, 7, 7, 7, 7};
    cout << "Second largest: " << removeDuplicateSize(vec) << endl;
    return 0;
}

### Medium: Rotate Vector by K Steps ***************************************************************************************************
Rotate the vector to the right by `k` steps.
#include<bits/stdc++.h>
using namespace std;

void rotateByK(vector<int>& arr,int k){
    reverse(arr.begin(),arr.end());
    reverse(arr.begin(),arr.begin()+k);
    reverse(arr.begin()+k,arr.end());
}

void printVec(vector<int>& arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    // vector<int> vec = {1, 2, 3, 4, 5};
    // int k = 2;
    // vector<int> vec = {10, 20, 30, 40, 50};
    // int k = 7;
    vector<int> vec = {6, 7, 8, 9};
    int k = 4;  // Rotating by size results in the same array
    k = k % vec.size(); 
    printVec(vec);
    rotateByK(vec,k);
    cout << "Rotate by k : " << endl;
    printVec(vec);
    
    return 0;
}

### Hard: Maximum Sum Subarray (Kadane's Algorithm) ***************************************************************************************************
Find the contiguous subarray with the largest sum.

#include <bits/stdc++.h>
using namespace std;

void kadaneWithIndices(vector<int> &arr){
    int max_sum = INT_MIN,curr_sum=0;
    int start=0,end=0,tempStart=0;
    for(int i=0;i<arr.size();i++){
        curr_sum += arr[i];
        if(curr_sum>max_sum){
            max_sum = curr_sum;
            start = tempStart;
            end=i;
        }
        if(curr_sum<0){
            curr_sum=0;
            tempStart=i+1;
        }
    }
    cout<<"Max Sum : "<<max_sum<<endl;
    cout<<"[";
    for(int i=start;i<=end;i++){
        cout<<arr[i]<<(i==end?"":" ");
    }
    cout<<"]";
}

int main() {
    // vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    // vector<int> nums = {-2, -1, -3, -4, -1};
    // vector<int> nums = {-5};
    vector<int> nums = {-1, -2, 3, -1};
    kadaneWithIndices(nums);
    return 0;
}
