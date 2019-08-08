#include<iostream>
#include<cstdlib>
#define size 10
using namespace std;

template<class T>
class Queue
{
    private:
        T *arr;
        int head,tail;
        int capacity;

    public:
        //constructor
        Queue()
        {
            arr=(T*)malloc(size*sizeof(T));
            head=0;
            tail=0;
            capacity=size;
        }

        //overloaded constructor
        Queue(int n)
        {
            capacity=n;
            arr=(T*)malloc(capacity*sizeof(T));
            head=0;
            tail=0;
        }

        void enQueue( T c )
        {
            if(!(tail<capacity))
            {
                cout<<"out of memory";
            }

            else
            {
                arr[tail]=c;
                tail++;
            }
        }

        void deQueue()
        {
            for(int i=head;i<tail-1;i++)
            {
                arr[i]=arr[i+1];
            }

            tail--;
        }

        T front()
        {
            return arr[head];
        }

        void print()
        {
            for(int i=0;i<tail;i++)
                cout<<arr[i];
        }

        ~Queue()
        {
            free(arr);
        }

};

int main()
{
        Queue<char> x;

        x.enQueue('c');
        x.enQueue('a');
        x.enQueue('t');
        x.enQueue(' ');
        x.enQueue('d');

        cout<<x.front()<<endl;

        x.deQueue();
        x.print();

        return 0;
}
