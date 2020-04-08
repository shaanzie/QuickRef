#include<bits/stdc++.h>

using namespace std;

int customerID = 0;
deque<int> WR;			
thread threadArr[1000];			
int i = 1;
int capacity;
int interval;

int print_WR();
int service(int custID);
int barberCall();
int custAdd(int custID);
int cust2wait();
 
int service (int custID) 
{
    cout<<"Barber is cutting hair of customer "<<custID<<endl;
    return 0;
}
 
int barberCall () 
{
    while (true)
    {  
        if (WR.size () > 0)
        {	  
            print_WR ();
            thread t5 (service, WR[0]); 
            interval = (rand () % 5) + 1;
            this_thread::sleep_for (chrono::milliseconds (interval)); 	  
            t5.join (); 
            WR.pop_front ();
        }
        else
	    {	  
            this_thread::sleep_for (chrono::milliseconds (2000));
            cout<<"Barber is sleeping"<<endl;
        }    
    }   
}
 
int custAdd (int customer_id) 
{
    WR.push_back (customer_id);  
    return 0;
}

int print_WR () 
{  
    cout<<"Waiting room: ";  
    for (int k = 0; k < WR.size (); k++)
    {
        cout<<WR[k]<<" ";
    } 
    cout<<endl;
    return 0;
}
 
int cust2wait () 
{
    while (i > 0)
    {
        i = i + 1;
        customerID = customerID + 1;
        if (WR.size () < capacity)
        {
            threadArr[i] = thread (custAdd, customerID);
            this_thread::sleep_for (chrono::milliseconds (3000));
            threadArr[i].join ();							
            print_WR ();
        }
        else
        {
            cout<<"Customer "<<customerID<<" exit"<<endl;  
            print_WR ();
        }
        this_thread::sleep_for (chrono::milliseconds (1000));
    }
    return 0;
}

int main () 
{
    cout<<"Enter N: "<<endl;
    cin >> capacity;
    thread t1 = thread (cust2wait);
    thread t2 = thread (barberCall);	
    t1.join ();	
    t2.join ();
    return 0; 
}