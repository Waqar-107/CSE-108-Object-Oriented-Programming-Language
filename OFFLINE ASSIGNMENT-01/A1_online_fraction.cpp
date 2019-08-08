/**********1505107**********
***********Sec.B2***********
**********Fraction**********/

#include<bits/stdc++.h>
using namespace std;

class fraction
{
    private:
        int den;
        int num;
        bool z;
    public:
        //constructor
        fraction()
        {
            den=1;
            num=0;
            z=true;        // if z is true then the number is zero
        }

        //setting numerator and denominator
        Set(int a, int b)
        {
            num=a;
            den=b;

            if(num!=0 && den!=1)
            {
                z=false;
            }
        }

        //pass the value of numerator when needed
        int pass_num()
        {
            return num;
        }

        //pass the value of denominator when needed
        int pass_den()
        {
            return den;
        }

        bool Equals()
        {
            if(z==true)
                return true;
            else
                return false;
        }

        //magnitude- returning the value in double precision
        double Magnitude()
        {
            return (double)num/den;
        }

        fraction Add(fraction ob)
        {
            fraction a;

            num=(ob.pass_den()*num) + (ob.pass_num()*den);
            den=den*ob.pass_den();

            //divide them with a particular integer if possible
            int x=__gcd(num,den);
            num=num/x;
            den=den/x;

            a.Set(num,den);
            return a;  //as result is an object, inside the functions we better create an object and then return
        }

        fraction Subtract(fraction ob)
        {
            fraction s;

            num=(ob.pass_den()*num) - (ob.pass_num()*den);
            den=den*ob.pass_den();

            //divide them with a particular integer if possible
            int x=__gcd(num,den);
            num=num/x;
            den=den/x;

            s.Set(num,den);
            return s;
        }

        fraction Multiply(fraction ob)
        {
            fraction m;

            num*=ob.pass_num();
            den*=ob.pass_den();

            //divide them with a particular integer if possible
            int x=__gcd(num,den);
            num=num/x;
            den=den/x;

            m.Set(num,den);
            return m;
        }

        fraction Divide(fraction ob)
        {
            fraction d;

            num*=ob.pass_den();
            den*=ob.pass_num();

            //divide them with a particular integer if possible
            int x=__gcd(num,den);
            num=num/x;
            den=den/x;

            d.Set(num,den);
            return d;
        }

        void Print()
        {
            cout<<num<<"/"<<den<<endl;
        }

        ~fraction()
        {

        }

};

int main()
{
        int i;
        int a, b;
        char cmd[20];
        fraction frac[2];
        fraction zero;
        fraction result;

        while (EOF != scanf("%s", cmd))
        {
            for (i = 0; i < 2; i++)
            {
                scanf("%d%d", &a, &b);

                // Sets the num and den fields based on fraction (a/b).
                // The actual values stored must be in line with the constraints
                // mentioned in the question.
                frac[i].Set(a, b);
                if (frac[i].Equals())
                {
                    cout << "You entered a zero fraction" << endl;
                }
                else
                {
                    // prints the fraction as a double precision floating point.
                    cout << "You entered a fraction of "
                    << frac[i].Magnitude() << " magnitude" << endl;
                }
            }

            cout << "Result of "  << cmd << " operation is: ";

            if (strcmp(cmd, "add")==0)
                result=frac[0].Add(frac[1]);

            else if  (strcmp(cmd, "subtract")==0)
                result=frac[0].Subtract(frac[1]);

            else if  (strcmp(cmd, "multiply")==0)
                result=frac[0].Multiply(frac[1]);

            else if  (strcmp(cmd, "divide")==0)
                result=frac[0].Divide(frac[1]);

            // Prints the vector as "(num/den)"
            result.Print();
        }

        return 0;
}
/*
int gcd(int a, int b)
{
        return a ? gcd(b%a, a): b;
}

int lcm(int a, int b)
{
        return a / gcd(a, b) * b;
}
*/
