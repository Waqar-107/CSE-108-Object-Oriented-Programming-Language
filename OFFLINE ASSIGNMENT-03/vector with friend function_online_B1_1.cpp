/***********************1505107******************************
************************Sec. B2*******************************
********Implementing geometrical vector using friend function********/

#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;

class Vector
{
    private:
        double x,y,z;
    public:
        //default constructor
        Vector()
         {

         }

         //overloaded constructor
        Vector(double x,double y,double z)
        {
            this->x=x;
            this->y=y;
            this->z=z;
        }

        // overload '>>'
         friend istream &operator>>(istream &vitor,Vector &v)
        {
            vitor>>v.x>>v.y>>v.z;
            return vitor;
        }

        // overload '<<'
        friend ostream &operator<<(ostream &bahir,Vector &v)
        {
            bahir<<v.x<<"  "<<v.y<<"  "<<v.z<<endl;
            return bahir;
        }

        //overload '*'
        friend Vector operator*(int m,Vector o1)
        {
            Vector temp;

            temp.x=m*o1.x;
            temp.y=m*o1.y;
            temp.z=m*o1.z;

            return temp;
        }
};
int main()
{
        Vector v,mult;

        // Overload >> operator to take Vector input
        cin>>v;

        // Perform scalar multiplication of v and store it into mult
        // v should be unchanged after multiplication.
        mult=5*v;

        // Overload << operator to perform Vector output.
        cout<<v;
        cout<<mult;

        return 0;
}
