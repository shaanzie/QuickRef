#include<bits/stdc++.h>

using namespace std;

class Philosopher {
public:
    int id;
    int position;
    bool eat;
    bool think;
    bool done;
    bool hungry;

    Philosopher(){
        id = -1;
        position = -1;
        think = true;
    }

    void state(){
        if (eat){
            cout<<endl<<"Philosopher "<<id<<" is eating";
        } else if (think){
           cout<<endl<<"Philosopher "<<id<<" is thinking";
        }
        if (!hungry){
            cout<<" and is not hungry";
        } if (done && !eat){
            cout<<" and have eaten";
        }
        cout<<endl;
    }
};

class DP {
public:
    vector<Philosopher> philosopher;
    int total_philosophers;
    int hungry_philosophers;
    bool done;

    DP(){
        philosopher.clear();
        total_philosophers = 0;
        hungry_philosophers = 0;
    }

    void one_at_a_time(){
        for (int i = 0; i < philosopher.size(); i++){
            for (int curr = 0; curr < total_philosophers; curr++){
                int adj = curr+1; 
                if (adj >= hungry_philosophers){
                    adj -= adj;
                }
                if (philosopher.at(curr).position == i){
                   if (philosopher.at(curr).hungry){
                        if(philosopher.at(curr).think && philosopher.at(adj).think && !(philosopher.at(curr).done))
                        {

                            philosopher.at(curr).think = false;
                            
                            philosopher.at(curr).eat = true;
                            
                            philosopher.at(curr).done = true;
                            
                            stateShow();
                         }
                        philosopher.at(curr).think = true;
                        philosopher.at(curr).eat = false;
                    }
                    adj++;
                }
            }
        }
    }

    void stateShow(){
        for(int i = 0; i < philosopher.size(); i++){
        for(int j = 0; j <total_philosophers; j++){
            if (philosopher.at(j).position == i){
                philosopher.at(j).state();
            }
        }
        }
        cout<<endl;
    }

    void init(Philosopher p){
        bool valid, valid_position;

        cout<<"Total number of Philosophers (min. of 5): ";
        cin >> total_philosophers;
        cout<<"Number of hungry Philosophers: ";

        do{
            cin >> hungry_philosophers;
            if(hungry_philosophers > total_philosophers){
                cout<<endl<<"The hungry philosophers should be less than the total number of philosophers"<<endl;
            } else {
                valid = true;
            }
        } while(!valid);

        cout<<endl;

        for (int i = 0; i <total_philosophers; i++){
            p.id = i;

            if (i < hungry_philosophers){
                do{
                    cout<<"Position for Hungry Philosopher "<<i<<": ";
                    cin >> p.position;

                    if (p.position >= total_philosophers){
                        cout<<"NOTE:\nThe position should be less than number of total philosophers."<<endl;
                        cout<<"Range of 0-"<<total_philosophers-1<<endl<<endl;
                    } else {
                        valid_position = true;
                        p.hungry = true;
                    }
                } while (!valid_position);
            } else {
                p.hungry = false;
            }

            philosopher.push_back(p);
            valid_position = false;
        }
    }
    // end of init()

};

int main(){
    DP philosophers;
    Philosopher p;

    int hungry_p, total_p;
    philosophers.init(p);
    philosophers.stateShow();
    philosophers.one_at_a_time();
    philosophers.stateShow();

return 0;
}