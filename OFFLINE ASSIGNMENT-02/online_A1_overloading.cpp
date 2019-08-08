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
        //constructor
        String()
        {
            s=new char[256];
            len=0;
        }

        String(char *p)
        {
            s=new char[256];

            strcpy(s,p);
            len=strlen(s);
        }

        //'+' overloading

        String operator+(const String o2)
        {
            String temp;

            strcpy(temp.s,s);
            strcat(temp.s,o2.s);

            temp.len=strlen(temp.s);

            return temp;
        }

        //'*' overloaded
        String operator*(int x)
        {
            String temp;

            strcpy(temp.s,s);

            for(int i=1;i<x;i++)
            {
                strcat(temp.s,s);
            }

            temp.len=strlen(temp.s);

            return temp;

        }

        //'=='
        bool operator==(String o2)
        {
            if(strcmp(o2.s,s)==0)
                return true;
            else
                return false;
        }

        //'!='
        bool operator!= (String o2)
        {
            if(strcmp(o2.s,s)==0)
                return false;
            else
                return true;
        }

        //'<'
        bool operator<(String o2)
        {
            int sum1=0,sum2=0;

            for(int i=0;i<len;i++)
                sum1+=s[i];

            for(int i=0;i<strlen(o2.s);i++)
                sum2+=s[i];

            if(sum1<sum2)
                return true;
            else
                return false;
        }

        //'>'
        bool operator>(String o2)
        {
            int sum1=0,sum2=0;

            for(int i=0;i<len;i++)
                sum1+=s[i];

            for(int i=0;i<strlen(o2.s);i++)
                sum2+=s[i];

            if(sum1>sum2)
                return true;
            else
                return false;
        }

        //'<='
        bool operator<=(String o2)
        {
            int sum1=0,sum2=0;

            for(int i=0;i<len;i++)
                sum1+=s[i];

            for(int i=0;i<strlen(o2.s);i++)
                sum2+=s[i];

            if(sum1<=sum2)
                return true;
            else
                return false;
        }

        //'>='
        bool operator>=(String o2)
        {
            int sum1=0,sum2=0;

            for(int i=0;i<len;i++)
                sum1+=s[i];

            for(int i=0;i<strlen(o2.s);i++)
                sum2+=s[i];

            if(sum1>=sum2)
                return true;
            else
                return false;
        }

        //print
        void Print()
        {
            cout<<s<<endl;
        }

};

int main()
{
        String s1("baby");
        String s2("babies");
        String s3=s2;
        String s4;

        if (s1 > s2)
        {
            s1.Print();
        }

        else
        {
            s2.Print();
        }

        s4 = (s1 + s2) * 5;

        s4.Print();

        (s1 + s2).Print();

        s3 = (s1 + s2);
        s3.Print();

        return 0;
}

