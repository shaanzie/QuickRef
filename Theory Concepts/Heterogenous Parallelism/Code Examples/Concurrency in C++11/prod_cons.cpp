#include<bits/stdc++.h>

using namespace std;

vector<int> buffer;
int flag = 0;
mutex flag_mutex;
mutex buffer_lock;


int main()
{
    thread reporter([&](){
        for(int i = 0; i<100; i++)
        {
            buffer_lock.lock();
            buffer.push_back(i);
            buffer_lock.unlock();
        }
        flag_mutex.lock();
        flag = 1;
        flag_mutex.unlock();
    });

    thread assigner([&](){

        while(flag == 0)
        {
            while(!buffer.empty())
            {
                buffer_lock.lock();
                buffer.erase(buffer.begin());
                buffer_lock.unlock();
            }
        }
        
    });
    reporter.join();
    assigner.join();

    cout<<"Size of Buffer: "<<buffer.size()<<endl;

    return 0;
}