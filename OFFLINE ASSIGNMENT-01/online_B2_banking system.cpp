/***********1505107**********
************Sec. B2***********
********Banking system********/

#include<iostream>
#include<string>
using namespace std;

class Transaction
{
    private:
        int fromBankAccountNo;
        int toBankAccountNo;
        double transactionAmount;
    public:
        //default constructor
        Transaction()
        {
            transactionAmount=0.0;
        }

        //overloaded constructor
        Transaction(int fromBankAccountNo,int toBankAccountNo,double transactionAmount)
        {
            this->fromBankAccountNo=fromBankAccountNo;
            this->toBankAccountNo=toBankAccountNo;
            this->transactionAmount=transactionAmount;
        }

        //pass account no. from which money will be transferred
        int get_fromBankAccountNo()
        {
            return fromBankAccountNo;
        }

         //pass account no. to which money will be transferred
        int get_toBankAccountNo()
        {
            return toBankAccountNo;
        }

         //pass amount of money that will be transferred
        int get_transactionAmount()
        {
            return transactionAmount;
        }

};

class Client
{
    private:
        int bankAccountNo;
        string name;
        //Transaction transactions[20];
        int transactionNo;
        double balance;

    public:
        //constructor
        Client()
        {

        }

        //overloaded constructor
        Client(int id,string nam,double taka)
        {
            balance=taka;
            bankAccountNo=id;
            name=nam;
        }

        //pass the bank account number
        int getID()
        {
            return bankAccountNo;
        }

        //pass name
        string getName()
        {
            return name;
        }

        //pass balance
        double getBalance()
        {
            return  balance;
        }

        //increase balance
        int addBalance(double b)
        {
            balance+=b;
        }

        //decrease balance
        int subBalance(double b)
        {
            balance-=b;
        }

        void printClientInfo()
        {
            cout<<"--------------"<<endl;
            cout<<bankAccountNo<<", "<<name<<", "<<balance<<"."<<endl;
            cout<<"--------------"<<endl;
        }

};

class Bank
{
    private:
        int maxCapacity;
        int numberOfClients;
        Client *clients;

    public:
        //construct
        Bank(int n)
        {
            maxCapacity=n;
            clients = new Client[n];
            numberOfClients=0;
        }

        //add
        bool addClient(Client obj)
        {
            if(maxCapacity==numberOfClients)
            {
                cout<<"Max capacity reached for  ID "<<obj.getID()<<", "<<obj.getName()<<endl;
                return false;
            }

            for(int i=0;i<numberOfClients;i++)
            {
                if(obj.getID()==clients[i].getID())
                {
                    cout<<"ID already exists, please try a different name."<<endl;
                    return false;
                }
            }

            clients[numberOfClients]=obj;
            numberOfClients++;
            return true;

        }

        //remove by id
        bool removeClient(int id)
        {
            for(int i=0;i<numberOfClients;i++)
            {
                if(clients[i].getID()==id)
                {
                    for(int j=i;j<numberOfClients-1;j++)
                    {
                        clients[j]=clients[j+1];
                    }
                    numberOfClients--;
                    return true;
                }
            }

            return false;
        }

        //overloaded removal
        bool removeClient(Client obj)
        {
            removeClient(obj.getID());
        }

        bool makeTransaction(int from,int to,double balance)
        {
                bool flag1=false;
                bool flag2=false;
                int rdx;
                int tdx;

                if(from==to)
                {
                    cout<<"Invalid transaction"<<endl;
                    return false;
                }

                for(int i=0;i<numberOfClients;i++)
                {
                    if(clients[i].getID()==from)
                    {
                        flag1=true;
                        rdx=i;
                        break;
                    }
                }

                for(int i=0;i<numberOfClients;i++)
                {
                    if(clients[i].getID()==to)
                    {
                        flag2=true;
                        tdx=i;
                        break;
                    }
                }

                if(flag1==true && flag2==true && clients[rdx].getBalance()>=balance)
                {
                    clients[rdx].subBalance(balance);
                    clients[tdx].addBalance(balance);
                }

                else
                    return false;

        }


        void printClients()
        {
                cout<<"-------------------------------------------"<<endl;
                for(int i=0;i<numberOfClients;i++)
                {
                    clients[i].printClientInfo();
                }
                cout<<"-------------------------------------------"<<endl;
        }


};


int main()
{

    Bank sonaliBank(3); ///Create Bank object with capacity 3. allocate memory for this clients.

    Client anik(1,"Anik Ahmed",5000); ///Create appropriate constructor for creating object
    Client azad(2,"Abul kalam Azad",5000);
    Client azad2(2,"Abul kalam Azad2",5000);
    Client tanvir(3,"Tanvir Hossain",5000);
    Client anonto(4,"Anonto Ghosh",5000);
    Client minhaz(5,"Minhazul Rahman",5000);
    Client sakib(6,"Sakib Khan",5000);


    ///addClient function will add an object to clients return true if successful otherwise
    ///If capacity reached show appropriate message return false
    ///if same account already exists show message return false

    sonaliBank.addClient(anik);
    sonaliBank.addClient(azad);
    sonaliBank.addClient(azad2);
    sonaliBank.addClient(tanvir);
    sonaliBank.addClient(anonto);
    sonaliBank.addClient(minhaz);
    sonaliBank.addClient(sakib);

    cout<<"After adding"<<endl;
    sonaliBank.printClients();  ///print detail information of clients


    ///remove client with bank account no.
    ///if that account exists remove it return true else return false

    sonaliBank.removeClient(3);

    ///if that object exists. you can think of it as if this person's id is already exists like previous
    sonaliBank.removeClient(anonto);

    cout<<"After Removing"<<endl;
    sonaliBank.printClients();

    sonaliBank.addClient(minhaz);
    sonaliBank.addClient(sakib);
    cout<<"After Adding new clients"<<endl;
    sonaliBank.printClients();


    ///Make transaction will transfer money from fromAccount to toAccount
    ///if anyone of the id is invalid i mean not exists in list clients return false
    ///if fromAccount balance is less than amount no transation can be made return false
    ///if same account no given return false
    ///otherwise makeTransaction and put an entry into transactions

    sonaliBank.makeTransaction(1,1,2000);
    sonaliBank.makeTransaction(1,2,10000);
    sonaliBank.makeTransaction(1,2,3000);
    sonaliBank.makeTransaction(2,5,3000);
    sonaliBank.makeTransaction(1,5,3000);
    sonaliBank.makeTransaction(5,3,3000);

    sonaliBank.printClients();


    return 0;
}
