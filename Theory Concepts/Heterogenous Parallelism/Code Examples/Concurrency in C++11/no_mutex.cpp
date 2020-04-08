#include<bits/stdc++.h>
#include<thread>

using namespace std;

void func(int x) {
    cout<<"Inside thread"<<x<<endl;

}

int main() {
    thread th(&func, 100);
    th.join();
    cout<<"Outside thread"<<endl;
    return 0;
}