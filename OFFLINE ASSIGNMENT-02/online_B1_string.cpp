/***********************1505107******************************
************************Sec. B2*******************************
*******Implementing some basic operations of the string class********/

#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

class String
{
    private:
        char *s;
        int len;
    public:
        String()
        {
            s=new char[100];
            len=0;
        }

        String(char *p)
        {
            s=new char[100];
            strcpy(s,p);
            len=strlen(s);
        }

        //getstring to print
        char *getString()
        {
            return s;
        }

        //overloading '+' operator v1.0
        friend String operator+(String o1,String o2)
        {
            String temp;

            strcpy(temp.s,o1.s);
            strcat(temp.s,o2.s);

            temp.len=strlen(temp.s);

            return temp;
        }

        //overloading '+' operator v2.0
        friend String operator+(String o1,int x)
        {
            String temp;
            char ts[50];
            strcpy(temp.s,o1.s);
            strcat(temp.s,itoa(x,ts,10));

            temp.len=strlen(temp.s);

            return temp;
        }

        //overloading '-'  as reverse
        friend String operator-(String o1)
        {
            String temp;

            strcpy(temp.s,strrev(o1.s));

            temp.len=strlen(temp.s);

            return temp;
        }

        //overloading '*' operator
        friend String operator*(String o1,int x)
        {
            String temp;

            strcpy(temp.s,o1.s);

            for(int i=1;i<x;i++)
            {
                strcat(temp.s,o1.s);
            }

            temp.len=strlen(temp.s);

            return temp;
        }

};
int main()
{
        String s("BUET");
        String s1,s2;

        cout<<s.getString()<<endl;

        // Should concat "CSE" at the end of "BUET"
        s = s+"CSE";
        cout<<s.getString()<<endl;

        // Should concat "108" at the end of "BUETCSE"
        s1= s+108;
        cout<<s1.getString()<<endl;

        // Should reverse "BUETCSE108" and make it “801ESCTUEB”
        s= - s;
        cout<<s.getString()<<endl;

        // s1 should be concatenated 3 times and stored in s2. If s1 contains “abc”, s2 should now contain “abcabcabc”
        s2=s1*3;
        cout<<s2.getString()<<endl;

		cin.get();
        return 0 ;
}
