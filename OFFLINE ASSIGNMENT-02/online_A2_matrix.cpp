/************1505107**************
*************Sec. B2***************
*******Implementing a matrix********/

#include<iostream>
#include<cmath>

using namespace std;

class Matrix
{
    private:
        int row;
        int column;
        int a[20][20];
        bool x;
    public:

        //constructor
        Matrix(int r,int c)
        {
            row=r;
            column=c;
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<column;j++)
                {
                    a[i][j]=0;
                }
            }

            x=true;
        }

        //buildup the matrix
        void SetRow(int rowId, int val[])
        {
            for(int i=0;i<column;i++)
            {
                a[rowId][i]=val[i];
            }
        }

         //addition
         friend  Matrix operator+(Matrix o1,Matrix o2)
        {
            Matrix temp(o1.row,o1.column);

            if(o1.row==o2.row && o1.column==o2.column)
            {
                for(int i=0;i<o1.row;i++)
                {
                    for(int j=0;j<o1.column;j++)
                    {
                        temp.a[i][j]=o1.a[i][j]+o2.a[i][j];
                    }
                }

                temp.x=true;
                return temp;
            }

            else
            {
                temp.x=false;
                cout<<"Addition not possible"<<endl;
            }
        }

        //subtract
         friend  Matrix operator-(Matrix o1,Matrix o2)
        {
            Matrix temp(o1.row,o1.column);

            if(o1.row==o2.row && o1.column==o2.column)
            {
                for(int i=0;i<o1.row;i++)
                {
                    for(int j=0;j<o1.column;j++)
                    {
                        temp.a[i][j]=o1.a[i][j]-o2.a[i][j];
                    }
                }

                temp.x=true;
                return temp;
            }

            else
            {
                temp.x=false;
                cout<<"Subtraction not possible"<<endl;
            }
        }

        //negation
        friend Matrix operator-(Matrix o1)
        {
            Matrix temp(o1.row,o1.column);

            for(int i=0;i<o1.row;i++)
            {
                for(int j=0;j<o1.column;j++)
                {
                    temp.a[i][j]=(-1)*o1.a[i][j];
                }
            }

            temp.x=true;
            return temp;
        }

        //multiplication
        friend  Matrix operator*(Matrix o1,Matrix o2)
        {
            Matrix temp(o1.row,o2.column);
            int sum=0;

            if(o1.row==o2.column)
            {
                for(int i=0;i<o1.row;i++)       //row of 1st matrix
                {
                    for(int j=0;j<o2.column;j++)    //column of  2nd matrix
                    {
                        for(int k=0;k<o2.row;k++)   //row of 2nd matrix
                        {
                            sum+=o1.a[i][k]*o2.a[k][j];
                        }

                        temp.a[i][j]=sum;
                        sum=0;
                    }
                }

                temp.x=true;
                return temp;
            }

            else
            {
                temp.x=false;
                cout<<"Multiplication not possible"<<endl;
            }
        }

        //print
        void Print()
        {

            if((row==0 || column==0) || x==false)
            {
                cout<<"Invalid Matrix\n"<<endl;
            }

            else
            {
                cout<<"Row = "<<row<<" "<<"Column = "<<column<<endl<<endl;

                for(int i=0;i<row;i++)
                {
                    for(int j=0;j<column;j++)
                    {
                        cout<<a[i][j]<<"  ";
                    }

                    cout<<endl<<endl;
                }

                cout<<"---------------------------------"<<endl;
            }
        }
};

int main()
{

        int x[][3]=
        {
            1, 2, 3,
            4, 5, 6
        };

        int y[][3]=
        {
            7, 8, 9,
            10, 11, 12
        };

        int z[][2]=
        {
            7, 8,
            9, 10,
            11, 12
        };

        Matrix a(2, 3);
        a.SetRow(0, x[0]);
        a.SetRow(1, x[1]);

        Matrix b(2, 3);
        b.SetRow(0, y[0]);
        b.SetRow(1, y[1]);

        Matrix c(3, 2);
        c.SetRow(0, z[0]);
        c.SetRow(1, z[1]);
        c.SetRow(2, z[2]);

        cout << "A:\n" << endl;
        a.Print();

        cout << "-A:\n" << endl;
        (-a).Print();

        cout << "B:\n" << endl;
        b.Print();

        cout << "C:\n" << endl;
        c.Print();

        cout << "A + B:" << endl;
        (a + b).Print();

        cout << "A + C:" << endl;
        (a + c).Print();

        cout << "A - B:" << endl;
        (a - b).Print();

        cout << "A * C:" << endl;
        (a * c).Print();


        return 0;
}
