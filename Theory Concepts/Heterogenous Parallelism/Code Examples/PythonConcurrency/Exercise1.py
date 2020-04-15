import _thread
import time
import sys

class Bank_Account: 
    def __init__(self): 
        
        self.balance = 0
  
    def deposit(self, threadName, amount): 
        
        self.balance += amount 
        print("\n" + threadName + " Deposited:",amount) 
  
    def withdraw(self, threadName, amount): 

        if self.balance >= amount: 
            self.balance-=amount 
            print("\n " + threadName + " Withdrew:", amount) 
        
        else: 
            print("\n Insufficient balance  ") 
  
s = Bank_Account() 
   
try:
    _thread.start_new_thread(s.deposit, ("Consumer", int(sys.argv[1]), ))
    _thread.start_new_thread(s.withdraw, ("Producer", int(sys.argv[2]), ))
    _thread.start_new_thread(s.deposit, ("Consumer", int(sys.argv[1]), ))
    _thread.start_new_thread(s.withdraw, ("Producer", int(sys.argv[2]), ))    
except:
    print("Error")

while 1:
    pass