#include<bits/stdc++.h>

using namespace std;

int accum = 0;

// void square(int x) {
//     accum += x*x;
// }

mutex accum_mutex;
void square(int x) {
    int temp = x * x;
    accum_mutex.lock();
    accum += temp;
    accum_mutex.unlock();
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