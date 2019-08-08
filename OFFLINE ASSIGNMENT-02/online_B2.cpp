/***********************1505107******************************
************************Sec. B2*******************************
*******Implementing some basic operations of the string class********/

#include<iostream>
#include<cstring>

using namespace std;

class MyString
{
    char *value;
    int len;

public:

    MyString()
    {
        value=new char[200];
    }

    MyString(char *s)
    {
        value=new char[200];
        strcpy(value,s);
        len=strlen(value);
    }

    //'+' overloaded
    friend MyString operator+(MyString o1,MyString o2)
    {
        MyString temp;

        strcpy(temp.value,o1.value);
        strcat(temp.value,o2.value);

        temp.len=strlen(temp.value);

        return temp;
    }

    //'*' overloaded
    friend MyString operator*(MyString o1,int x)
    {
        MyString temp;

        strcpy(temp.value,o1.value);
        for(int i=1;i<x;i++)
        {
            strcat(temp.value,o1.value);
        }

        temp.len=strlen(temp.value);

        return temp;
    }

    //'-' overloaded
    friend MyString operator- (MyString o1,MyString o2)
    {
        MyString temp;
        char src[100];
        char cut[100];

        strcpy(src,o1.value);
        strcpy(cut,o2.value);

        int count=0;
        int idx,i,j,k;

        for(i=0;i<strlen(src);i++)
        {
            count=0;
            k=i;
            for(j=0;j<strlen(cut);j++)
            {
                if(src[k]==cut[j])
                {
                    cout<<src[k]<<"  "<<cut[j]<<endl;
                    count++;
                    k++;
                    continue;
                }

                else
                    break;
            }

            if(count==strlen(cut))
            {
                idx=j;
                int l=strlen(cut)+j;
                int rd=0;
                char t1[50],t2[50];

                //cout<<idx<<"  "<<l<<endl;
                for(k=0;k<j;k++)
                {
                    t1[k]=src[k];
                }

                for(k=l;k<strlen(src);k++)
                {
                    t2[rd]=src[k];
                    rd++;
                }

                //cout<<t1<<"  "<<t2<<endl;
                memset(src,0,sizeof(src));
                strcpy(src,t1);
                strcat(src,t2);

                break;
            }
        }

        strcpy(temp.value,src);
        temp.len=strlen(temp.value);

        return temp;
    }

    //'==' overloaded
    friend bool operator==(MyString o1,MyString o2)
    {
        if(strcmp(o1.value,o2.value)==0)
            return true;
        else
            return false;
    }

    //'[]' overloaded
    char operator[] (int x)
    {
        if(x<0 || x>len)
            return '0';
        else
            return value[x-1];
    }

    //'<' overloaded
    bool operator<(const MyString o2)
    {
        int sum1=0,sum2=0;

        for(int i=0;i<len;i++)
            sum1+=value[i];

        for(int i=0;i<o2.len;i++)
            sum2+=o2.value[i];

        if(sum1<sum2)
            return true;
        else
            return false;
    }

    void display()
    {
        if(len==0)
        {
            cout<<"\n String is Empty \n";
        }
        else
        {
            cout<<value<<"\n";
        }
    }

};

int main()
{
    MyString str1("xxxyyyzzz");

    MyString str2("abc");

    MyString str3("yyy");

    //Output of the display functions
    str1.display();
    str2.display();
    str3.display();

    MyString str4;

    // + operator
    str4 = str1+str2;
    cout<<"The output of + operator"<<endl;
    str4.display();

    //- operator
    str4 = str1-str3;
    cout<<"The output of - operator"<<endl;
    str4.display();

    //* operator
    str4 = str2*3;
    cout<<"The output of * operator"<<endl;
    str4.display();

    //[] operator
    cout<<"Character at index 3 of str1: ";
    cout<<str1[3]<<endl;
    cout<<"Character at index 50 of str1: ";
    cout<<str1[50]<<endl;

    //==operator
    MyString strtemp("abc");
    if(str2==strtemp)
    {
        cout<<"Both Strings are equal"<<endl;
    }

    //< operator
    if(str2<str1)
    {
        cout<<"str2 is less than str1"<<endl;
    }
    else
    {
        cout<<"str2 is not less than str1"<<endl;
    }

    return 0;
}
