#include<bits/stdc++.h>

using namespace std;

atomic<int> accum(0);

void square(int x) {
    accum += x*x;
}

int main() {
    vector<thread> ths;
    for(int i = 1; i<=20; i++)
    {
        ths.push_back(thread(&square, i));
    }
    for(auto& th: ths) 
    {
        th.join();
    }
    cout<<"Accum: "<<accum<<endl;
    return 0;
}