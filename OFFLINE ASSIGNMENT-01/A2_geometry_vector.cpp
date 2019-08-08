/***********1505107**********
************Sec. B2***********
*******Vector in geometry*******/

#include<bits/stdc++.h>
using namespace std;

class Vector
{
    private:
        double x;
        double y;
        double z;
        double mag;

    public:

        //constructor
        Vector()
        {
            x=0;
            y=0;
            z=0;

            mag=0;  //setting the magnitude initially 0
        }

        //set the values of x,y,z
        void Set(double i,double j,double k)
        {
            x=i;
            y=j;
            z=k;

            mag=sqrt(x*x+y*y+z*z);
        }

        //passing the values of x,y,z
        double getX()
        {
            return x;
        }

        double getY()
        {
            return y;
        }

        double getZ()
        {
            return z;
        }

        //check if the magnitude is 0
        bool Equals()
        {
                if(mag==0)
                    return true;
                else
                    return false;
        }

        //magnitude
        double Magnitude()
        {
            return mag;
        }

        //dot product
        double Dot(Vector ob)
        {
            double dot=(x*ob.getX())+(y*ob.getY())+(z*ob.getZ());
            return dot;
        }

        //cross product: (u2.v3 - u3.v2, u3.v1 - u1.v3, u1.v2 - u2.v1)
        Vector Cross(Vector ob)
        {
            Vector cross;
            double a,b,c;
            a=y*ob.getZ() - z*ob.getY();
            b=z*ob.getX() - x*ob.getZ();
            c=x*ob.getY() - y*ob.getX();

            cross.Set(a,b,c);
            return cross;
        }

        //add
        Vector Add(Vector ob)
        {
            Vector add;
            double a,b,c;

            a=x+ob.getX();
            b=y+ob.getY();
            c=z+ob.getZ();;

            add.Set(a,b,c);
            return add;
        }

        //subtract
        Vector Subtract(Vector ob)
        {
            Vector sub;
            double a,b,c;

            a=x+ob.getX()*(-1);
            b=y+ob.getY()*(-1);
            c=z+ob.getZ()*(-1);

             sub.Set(a,b,c);

             return sub;
        }


        //print
        void print()
        {
            cout<<x<<","<<y<<","<<z<<endl;
        }

};

int main()
{
        int i;
        char cmd[20];
        Vector v[2], result, zero;
        double a, b, c;

        while (scanf("%s", cmd)!=EOF)
        {
            for (i = 0; i < 2; i++)
            {
                scanf("%lf%lf%lf", &a, &b, &c);

                // Sets the strength of v[i] along x, y and z axises
                // to a, b, c respectively.
                v[i].Set(a, b, c);

                if (v[i].Equals())
                {
                    cout << "You entered a zero vector" << endl;
                }
                else
                {
                    // prints the magnitude of vector[i]
                    cout << "You entered a vector of  ";
                    cout<< v[i].Magnitude() << " magnitude" << endl;
                }
            }

            cout << "Result of "  << cmd << " operation is: ";

            if (strcmp(cmd, "dot")==0)
            {
                cout << v[0].Dot(v[1]) << endl;
                continue;
            }

            else if (strcmp(cmd, "add")==0)
            {
                result = v[0].Add(v[1]);
            }

            else if  (strcmp(cmd, "subtract")==0)
            {
                result = v[0].Subtract(v[1]);
            }

            else if  (strcmp(cmd, "cross")==0)
            {
                result = v[0].Cross(v[1]);
            }

            // Prints the vector as “(u1, u2, u3)”, where u1, u2, u3
            // are respectively the strength of the vector along x, y, z axes
            result.print();
        }

        return 0;
}
