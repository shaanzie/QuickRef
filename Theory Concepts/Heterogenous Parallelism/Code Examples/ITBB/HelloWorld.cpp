#include "tbb/tbb.h"
#include<bits/stdc++.h>

using namespace tbb;
using namespace std;

class first_task : public task { 
    public:
        task* execute() {
            cout<<"Hello World!\n";
            return NULL;
        }
};

int main() {
    task_scheduler_init init(task_scheduler_init::automatic);
    first_task& f1 = *new(tbb::task::allocate_root()) first_task();
    tbb::task::spawn_root_and_wait(f1);
}