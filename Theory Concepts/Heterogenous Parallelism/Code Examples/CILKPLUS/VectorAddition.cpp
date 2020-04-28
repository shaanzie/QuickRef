#include <bits/stdc++.h>
#include<cilk/cilk.h>
 
using namespace std;

void add(vector<int> nums) {
    int sum = 0;
    cilk_for(int i = 0; i<nums.size(); i++) {
        sum += nums[i];
    }
    cout<<"Sum: "<<sum<<endl;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    add(nums);
    return 0;
}