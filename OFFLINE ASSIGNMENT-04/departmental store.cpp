/*************DEPARTMENTAL STORE**************
*********************1505107***********************
*******************OFFLINE B2*******************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>

using namespace std;

class Product
{
    private:
        int id;
        string name;
        static int counter;

    protected:
        double price;
        Product *products[100];
        int freeNo;
        int productNo;

    public:

        Product()
        {
            id=0;
            counter=0;
        }

        Product(string name,double price)
        {
            this->name=name;
            this->price=price;

            counter++;
            id=counter;

            freeNo=0;       //counting the number of free products

        }

        addFreeProduct(Product *ptr)
        {
            products[freeNo]=ptr;
            freeNo++;
        }

        int passFreeNo()
        {
            return freeNo;
        }

        int passID()
        {
            return id;
        }

        double passPrice()
        {
            return price;
        }

       virtual double passTax()
        {
            return 0;
        }

        string passName()
        {
            return name;
        }

        void printFree()
        {
            double dam,totalFree;
            if(freeNo!=0)
            {
                for(int j=0;j<freeNo;j++)
                    totalFree+=(products[j]->passPrice())+(products[j]->passTax());

                cout<<endl<<"Total Free:"<<totalFree<<endl<<endl;
            }

            for(int i=0;i<freeNo;i++)
            {
                dam=(products[i]->passPrice())+(products[i]->passTax());
                cout<<"-->"<<products[i]->passName()<<"("<<products[i]->passID()<<"):"<<dam<<endl;
            }
            cout<<endl;
        }


};
int Product::counter=0;


class Phones : public Product
{
    private:
        static double tax;
    public:
        Phones(string name,double price) : Product(name,price)
        {

        }

        static setTax(double t)
        {
            tax=t;
        }

        double passTax()
        {
            return (price*tax*0.01);
        }
};

//override methods
class Foods : public Product
{
    private:
        static double tax;
    public:
        Foods(string name,double price) : Product(name,price)
        {

        }

        static setTax(double t)
        {
            tax=t;
        }

        double passTax()
        {
            return (price*tax/100);
        }

};

class Cart
{
        double totalPrice;
        Product *products[100];
        int itemNo;

    public:
        Cart()
        {
            itemNo=0;
        }

        void addToCart(Product *ptr)
        {
            products[itemNo]=ptr;
            itemNo++;
        }

        void showCartDetails()
        {
            for(int i=0;i<itemNo;i++)
            {
                cout<<"------------------"<<endl;

                int realPrice,pr,tx;
                pr=products[i]->passPrice();
                tx=products[i]->passTax();
                realPrice=pr+tx;

                cout<<products[i]->passName()<<"("<<products[i]->passID()<<"):"<<realPrice<<endl;
                products[i]->printFree();
            }
        }
};

double Foods::tax=0;
double Phones::tax=0;

int main()
{
    Phones::setTax(15);                                     // set  15% VAT on phones
    Foods::setTax(5);                                        // set 5% VAT on Foods
    Cart myCart;

    Foods mango("Rajshahir mango",500);
    Foods pithaPuli("Chitoi pitha",200);

    Foods hilsha("Ilish",1000);
    Product vrset("Virtual Reality Headset",10000);

    Phones samsungGalaxy("Samsung Galaxy S7",75000);
    Phones nokia("Nokia 1100",2000);

    samsungGalaxy.addFreeProduct(&vrset);
    samsungGalaxy.addFreeProduct(&hilsha);

    //addToCart add product to Cart
    myCart.addToCart(&samsungGalaxy);
    myCart.addToCart(&mango);
    myCart.addToCart(&pithaPuli);
    myCart.addToCart(&nokia);


    //showCartDetails show products and their price
    myCart.showCartDetails();

    cout<<endl<<"**********After Tax Change*********"<<endl<<endl;

    Phones::setTax(10);
    Foods::setTax(7);

    myCart.showCartDetails();

    return 0;
}
