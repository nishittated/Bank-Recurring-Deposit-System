#include <iostream> 
#include <fstream>
#include <cstdlib>    
#include <stdio.h>  
#include <conio.h>
#include <iomanip> 
 
using namespace std;
class Account
{
    public:
        virtual void login() =0;
        virtual void init()=0;
        virtual void show_account()=0;
        virtual void deposit() =0;
        virtual void withdraw() =0;
        virtual void ministatement() =0;
        virtual void balance_enquiry() =0;
        virtual void find_Maturity() =0;
        virtual void modify_account()=0;
        virtual void deposit_funds()=0;
        virtual void draw_funds() =0;
        virtual void get_report () =0;
        virtual int return_accountnumber() =0;
        virtual int return_funds() =0;
        virtual char accounttype() =0;
};
class Recurring : public Account 
{
public:
    void login();
    void init();
    void show_account();
    void deposit();
    void withdraw();
    void ministatement();
    void balance_enquiry();
    void find_Maturity();
    void modify_account();
    void deposit_funds();
    void draw_funds();
    void get_report ();
    int retrun_accountnumber();
    int return_funds();
    char accounttype();
};
class Bank              //Class definition Starts
{
   private:
        char ac_name[50], ac_type;
        int ac_no ,dep , wit, balance;

   public:
    void login()                 //function to login for creating an account
    {
        string pass;
        cout << "Enter the Password for Login : ";
        cin  >> pass;   
    }                     
    void init()                //function to create an account
    {
        cout << "Enter the Account Holder's Name :";
        cin >>ac_name;
        cout << "Enter the Account Holder's Number :";
        cin >>ac_no;

        cout << "Enter the Account Holder's Type  S for SAVING & C for CURRENT :";
        cin >>ac_type;
        cout << "Enter the Initial Amount : ";
        cin >> balance;

        cout<<"\n\n Congrats!! Account Has Been Created..";
    }
    void show_account() const   //function which displays customer's  account details
    {
        cout<<"\nAccount Number : "<<ac_no;
        cout<<"\nAccount Holder Name : " << ac_name;
        cout<<"\nType of Account : "<<ac_type;
        cout<<"\nBalance amount : "<< balance;
    }
    void deposit()               //function for depositing money in account
    {
        cout << "Enter the Amount : ";
        cin >> dep;
        balance=balance+dep;
    }
    void withdraw()           //function for withdrawing money in account
    {
        int  penalty;
        cout <<"Enter the amount you want to withdraw :\n";
        cin>>wit;
        balance=balance-wit;

        if(balance < 500)
        {
                penalty=(500-balance)/10;
                balance=balance-penalty;
                cout<<"\nBalance after deducting penalty : "<<balance;
        }
        else if(wit > balance)
        {
                cout<<"\n\nYou have to take permission for Bank Overdraft Facility\n";
                balance=balance+wit;
        }
    }
    void ministatement()         //function for displaying Mini-statement in account
    {
         cout << "\nYour banking details are ";
         cout << "\n Deposit = " <<dep;
         cout << "\n Withdraw = " << wit;
         cout << "\n Balance = " << balance;
    }
    void balance_enquiry()         //function for balance inquiry
    {
        char ch;
        cout << ch;
    }
    void find_Maturity()        //function for RECURRING DEPOSIT
    {
            double i,j,k,l;
            cout << "\n Enter monthly Deposits : ";
            cin>>j;

            cout << "\n Enter No of Quarters (months) : ";
            cin>>k;
            cout << "\n Enter Rate of Interest : ";
            cin>>l;

            l=(l/400)+1;
            i=(j*((i,k)-1))/(1-((l,(double)(-0.333333))));
            cout << "\n\n Maturity Amount :: "<<i;
    }
    void modify_account()         //function to Modify account details
    {
        cout<<"\nAccount Number: ";
        cin >> ac_no;
        cout<<"Account Holder Name: ";
        cin >> ac_name;
        cout<<"Type of Account: ";
        cin>>ac_type;
        cout<<"Balance amount: ";
        cin>>dep;
    }
    void deposit_funds(int z)      //function which accepts deposit amount
    {
        dep+=z;
    }
    void draw_funds(int z)        //function for subtracting withdrawal amount
    {
        dep-=z;
    }
    void get_report()        //function which shows data in Tabular format
    {
        cout<<"\n\t  "<<setw(10)<<ac_no<<"  "<<setw(10)<<ac_name<<setw(10)<<ac_type<<" "<<setw(7)<< balance<<endl;
    }
    int return_accountnumber() const         //for returning an account number
    {
        return ac_no;
    }
    int return_funds() const                  //for returning balance amount
    {
        return dep;
    }
    char accounttype() const
    {
        return ac_type;
    }
};            // Class definition ends
class Loan                  //  Another Class Definition starts
{
	double monthlyPayment ,balance ,interestRate ,interestPaid ,initialBalance;
	double termOfLoan ,month = 1;
public:
    void decimal()          //Function for lines forcing currency format in output to 2 decimal points
    {
            cout.setf(ios::fixed);
            cout.setf(ios::showpoint);
            cout.precision(2);
	}
	void get_data()                 // To get data from user
	{
            cout << "\nEnter the current balance of your loan : ";
            cin >> balance;
            cout << "Enter the interest rate (compounded monthly) : ";
            cin >> interestRate;
            cout << "Enter the desired monthly payment : ";
            cin >> monthlyPayment;
	}
	void calculate()                // Function for calculating Loan for user
	{
            initialBalance = balance;
            while (interestRate >= 1)       /*Converts the interest rate to a decimal if the user inputs                                                      in percentage form*/
            {
                    interestRate = interestRate / 100;
            }
            balance = balance * (1 + interestRate / 12) - monthlyPayment;
            cout << "\nAfter month 1 your balance is " << balance << endl;
            while (balance > 0)
            {
                    if (balance < monthlyPayment)
                    {
                                balance = balance - balance;
                    }
                    else
                    {
                                balance = balance * (1 + interestRate / 12) - monthlyPayment;
                    }
                    month = month++;
                    cout << "After month " << month << ", your balance is : " << balance << endl;
            }
            cout << "\nCongratulations! You have paid off the loan at this point. " << endl;
            termOfLoan = month;

            interestPaid = (monthlyPayment * termOfLoan) - initialBalance;
            cout << "\nYou paid a total amount of " << interestPaid << " in interest." << endl;
	}
};

class Customer : public Loan         // class which will access the data of Loan Class
{
public:
    void run()
    {
            Loan :: decimal();
            Loan :: get_data();
            Loan :: calculate();
    }
    void feedback()
    {
            char atms[95], service[3], staff[65], sug[70];
            cout << "\nHow would you like to describe our Bank's Atmosphere : " <<endl;
            cin >> atms;

            cout << "\nHow would you like to tell us about the Services of our Bank " <<endl;
            cout << "Press F-Fast , S-Slow or M-Medium : ";
            cin >> service;
            cout << "\nAny review on our Staff Members (Describe within  2-3 words) : ";
            cin >> staff;

            cout << "Your any Valuable Suggestions (Please tell us to improve ourself) : ";
            cin >> sug;

            cout << "\n\tYour all valuable suggestions are accepted & will take a deep note of your review & will improve ourself..";
            cout <<"\n Thanks for being with us..Stay Tuned ..Come again Soon !!";
    }
    void write_account();         //function for writing record in binary file
    void display_sp(int);         //function for displaying account details given by user
    void modify_acc(int);         //function for modifying record of file
    void delete_acc(int);         //function for deleting record of file
    void display_all();           //function for displaying all account details
};
int main()                  // main function
{
        Bank b;                 // Bank Class having an object named b
        Customer r;              // Customer Class having an object named r
        int c,npt,ch, num;
        npt:
            system("CLS");          //To clear the screen

        cout <<"\t\t\tWelcome to the Bank Of Galaxy\n";
        cout <<"Enter 1 for Account Creation : \nEnter 2 for Deposit : \nEnter 3 for Withdraw : \nEnter 4 for Balance Inquiry : \nEnter 5 for Mini-statement : \n";
        cout <<"Enter 6 for Modify Account : \nEnter 7 for Recurring Deposit  : \nEnter 8 for Complete Account's Holder List : \n";
        cout <<"Enter 9 for Closing an Account : \nEnter 10 for Loan : \nEnter 11 for Customer's Feedback : \nEnter 12 for Exit : " << endl;
        cin >>ch;

        switch(ch)
        {
        case 1:
                {
                        b.login();
                        r.write_account();
                        cout <<"\nWant to continue Y-YES or N-NO";
                        if(getch()=='y'||getch()=='Y')
                        {
                                goto npt;
                        }
                        else
                        {
                                cout <<"\n Thanks for being with us..Stay Tuned ..Come again Soon !!";
                        }
                        break;
                }
        case 2:
                {
                        b.deposit();
                        cout <<"\nWant to continue Y-YES or N-NO";
                        if(getch()=='y'||getch()=='Y')
                        {
                                goto npt;
                        }
                        else
                        {
                                cout <<"\n Thanks for being with us..Stay Tuned ..Come again Soon !!";
                        }
                        break;
                }
        case 3:
                 {
                        b.withdraw();
                        cout <<"\nWant to continue Y-YES or N-NO";
                        if(getch()=='y'||getch()=='Y')
                        {
                                goto npt;
                        }
                        else
                        {
                                cout <<"\n Thanks for being with us..Stay Tuned ..Come again Soon !!";
                        }
                        break;
                }
        case 4:
                 {
                        cout<<"\n\n\tEnter The Account Number : ";
                        cin>>num;
                        r.display_sp(num);

                        cout <<"\nWant to continue Y-YES or N-NO";
                        if(getch()=='y'||getch()=='Y')
                        {
                                goto npt;
                        }
                        else
                        {
                                cout <<"\n Thanks for being with us..Stay Tuned ..Come again Soon !!";
                        }
                        break;
                }
        case 5:
                 {
                        b.ministatement();
                        cout <<"\nWant to continue Y-YES or N-NO";
                        if(getch()=='y'||getch()=='Y')
                        {
                                goto npt;
                        }
                        else
                        {
                                cout <<"\n Thanks for being with us..Stay Tuned ..Come again Soon !!";
                        }
                        break;
                }
        case 6:
                {
                        cout<<"\n\n\tEnter The Account Number : ";
                        cin>>num;
                        r.modify_acc(num);

                        cout <<"\nWant to continue Y-YES or N-NO";
                        if(getch()=='y'||getch()=='Y')
                        {
                                goto npt;
                        }
                        else
                        {
                                cout <<"\n Thanks for being with us..Stay Tuned ..Come again Soon !!";
                        }
                        break;
                }
        case 7:
                {
                        b.find_Maturity();
                        cout <<"\nWant to continue Y-YES or N-NO";
                        if(getch()=='y'||getch()=='Y')
                        {
                               goto npt;
                        }
                        else
                        {
                               cout <<"\n Thanks for being with us..Stay Tuned ..Come again Soon !!";
                        }
                        break;
                }
        case 8:
                {
                        r.display_all();
                        cout <<"\nWant to continue Y-YES or N-NO";
                        if(getch()=='y'||getch()=='Y')
                        {
                               goto npt;
                        }
                        else
                        {
                               cout <<"\n Thanks for being with us..Stay Tuned ..Come again Soon !!";
                        }
                        break;
                }
        case 9:
                {
                        cout<<"\n\n\tEnter The Account Number : ";
                        cin>>num;
                        r.delete_acc(num);
                        cout <<"\nWant to continue Y-YES or N-NO";
                        if(getch()=='y'||getch()=='Y')
                        {
                               goto npt;
                        }
                        else
                        {
                               cout <<"\n Thanks for being with us..Stay Tuned ..Come again Soon !!";
                        }
                        break;
                }
        case 10:
                {
                        r.run();
                        cout <<"\nWant to continue Y-YES or N-NO";
                        if(getch()=='y'||getch()=='Y')
                        {
                               goto npt;
                        }
                        else
                        {
                               cout <<"\n Thanks for being with us..Stay Tuned ..Come again Soon !!";
                        }
                        break;
                }
        case 11:
                {
                        r.feedback();
                        cout <<"\nWant to continue Y-YES or N-NO";
                        if(getch()=='y'||getch()=='Y')
                        {
                               goto npt;
                        }
                        else
                        {
                               cout <<"\n Thanks for being with us..Stay Tuned ..Come again Soon !!";
                        }
                        break;
                }
        case 12:
                {
                        cout <<"\n Thanks for being with us..Stay Tuned ..Come again Soon !!";
                        exit(0);
                        break;
                }
        default:
                {
                        cout <<"\n Entered value is not valid please enter a valid data ";
                        system("pause");            // To pause the screen for few seconds
                        system("CLS");              // To clear the screen
                        goto npt;
                }
        }
}               // main function ends
void Customer :: write_account()                 //function to write account data's to .dat file
{
    Bank ac;
    ofstream z;
    z.open("Info.dat",ios::binary|ios::app);
    ac.init();
    z.write(reinterpret_cast<char *> (&ac), sizeof(Bank));
    z.close();
}
void Customer :: display_sp(int n)      //function to retrieve a record from file stored
{
    Bank ac;
    bool flag=false;
    ifstream z;
    z.open("Info.dat",ios::binary);
    if(!z)
    {
        cout<<"File could not be opened!! Press any Key to exit...";
        return;
    }
    cout<<"\nACCOUNT HOLDER'S & BALANCE DETAILS\n";

    while(z.read(reinterpret_cast<char *> (&ac), sizeof(Bank)))
    {
        if(ac.return_accountnumber()==n)
        {
            ac.show_account();
            flag=true;
        }
    }
    z.close();
    if(flag==false)
    cout<<"\n\nAccount number does not exist";
}
void Customer :: modify_acc(int n)                  //function for modifying record which is stored in a file
{
    bool found=false;
    Bank ac;
    fstream z;
    z.open("Info.dat",ios::binary|ios::in|ios::out);
    if(!z)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    while(!z.eof() && found==false)
    {
        z.read(reinterpret_cast<char *> (&ac), sizeof(Bank));
        if(ac.return_accountnumber()==n)
        {
            ac.show_account();
            cout<<"\n\nEnter The New Details of account"<<endl;
            ac.modify_account();
            int pos=(-1)*static_cast<int>(sizeof(Bank));
            z.seekp(pos,ios::cur);
            z.write(reinterpret_cast<char *> (&ac), sizeof(Bank));
            cout<<"\n\n\t Record Updated";
            found=true;
        }
    }
    z.close();
    if(found==false)
        cout<<"\n\n Record Not Found ";
}
void Customer :: delete_acc(int n)                  //function to delete a record from file
{
    Bank ac;
    ifstream z;
    ofstream y;
    z.open("Info.dat",ios::binary);
    if(!z)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    y.open("Temp.dat",ios::binary);
    z.seekg(0,ios::beg);
    while(z.read(reinterpret_cast<char *> (&ac), sizeof(Bank)))
    {
        if(ac.return_accountnumber()!=n)
        {
            y.write(reinterpret_cast<char *> (&ac), sizeof(Bank));
        }
    }
    z.close();
    y.close();
    remove("Info.dat");
    rename("Temp.dat","Info.dat");
    cout<<"\n\n\tRecord Deleted ..";
}

void Customer :: display_all()          // function which displays account details from the stored file
{
    Bank ac;
    ifstream z;
    z.open("Info.dat",ios::binary);
    if(!z)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
    cout<<"\n====================================================\n";
    cout<<"\n\tA/c no.      \tNAME       \tType    Balance\n";
    cout<<"\n====================================================\n";
    while(z.read(reinterpret_cast<char *> (&ac), sizeof(Bank)))
    {
        ac.get_report();
    }
    z.close();
}
