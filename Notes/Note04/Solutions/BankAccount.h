#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream> //ostream, cout 
#include <iomanip> //setprecision(), fixed()
#include <string> //string
#include <sstream> //stringstream
#include <cstdlib> //rand() 
#include <ctime> //time()

namespace dsn
{
    //Create an Account class that contain:
    //fields: amount: double, number: string, count: int, acct_num_seq : int
    //methods: withdraw(), deposit(), balance(), accounts(), toString()
    //friends: operator<<()

    class Account 
    {
        private:
        double amount;
        std::string number;
        static int count;
        static int acct_num_seq;

        static std::string GenerateAccountNumber()
        {
            std::string a = "9";
            a += std::to_string((rand() % 10));
            a += std::to_string((rand() % 10));
            a += std::to_string((rand() % 10));
            a += "6";          
            a += std::to_string((rand() % 10));
            a += std::to_string((rand() % 10));
            a += std::to_string((rand() % 10));
            a += std::to_string(acct_num_seq);
            acct_num_seq += 1;
            return a;
        }

        public:
        //Default Constructor
        Account() : Account(0.0) 
        {
            std::cout << "default constructor called\nfor account " + number << "\n";
        }

        //Copy Constructor
        Account(const Account& obj) 
        {
            this->number = GenerateAccountNumber();
            amount = obj.amount;
            count += 1;
            std::cout << "copy constructor called\nfor account " + number << "\n";
        }

        //Assignment Operator
        Account& operator=(const Account& rhs)
        {
            if(this != &rhs)
            {
                amount = rhs.amount;
                std::cout << "assignment operator called\nfor account " + number << "\n";
            }
            return *this;
        }

        //Destructor
        ~Account() 
        {
            count -= 1;
            std::cout << "destructor called\nfor account " + number << "\n";
        }

        //Overloaded Constructor
        Account(double balance) : amount(balance)
        {
            if(amount < 0.0)
            {
                amount = 0.0;
            }
            number = GenerateAccountNumber();
            count += 1;
            std::cout << "overloaded constructor called\nfor account " + number << "\n";
        }
        
        //Instance Methods
        bool withdraw(double amount)
        {
            if(amount > 0.0 && this->amount > amount)
            {
                this->amount -= amount;
                return true;
            }
            return false;
        } 

        bool deposit(double amount)
        {
            if(amount > 0.0)
            {
                this->amount += amount;
                return true;
            }
            return false;
        }
        
        //Constant Methods
        double balance() const {return amount;}

        std::string accountNumber() const {return number;} 

        std::string toString() const
        {
            std::stringstream out;

            out << number << "\n" << std::fixed << std::setprecision(2) << amount << " USD";
            return out.str();
        }
        
        //Static Method
        static int accounts() {return count;}

        //Friends
        friend std::ostream& operator<<(std::ostream& out,const Account& obj)
        {
            out << obj.toString();
            return out;
        }
    };

    //Initialize Static Fields
    int Account::count = 0;
    int Account::acct_num_seq = 1000;
}

#endif