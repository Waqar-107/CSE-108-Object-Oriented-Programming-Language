#include<bits/stdc++.h>
using namespace std;

class cricketer
{
    private:
        int matchPlayed;
        char *name;
        int age;
    public:
        //default
        cricketer()
        {

        }

        //overloaded
        cricketer(char *s,int a,int m)
        {
            name=new char[200];
            strcpy(name,s);
            matchPlayed=m;
            age=a;
        }

        char *getName()
        {
            return name;
        }

        int getAge()
        {
            return age;
        }

        int getMatchPlayed()
        {
            return matchPlayed;
        }

};

class batsman : virtual public cricketer
{
    private:
        int runScored;
    public:
        batsman()
        {

        }

        batsman(char *s,int a,int m,int runScored) : cricketer(s,a,m)
        {
            this->runScored=runScored;
        }

        double computeBattingAverage()
        {
            return (double)runScored/getMatchPlayed();
        }

};

class bowler : virtual public cricketer
{
    private:
        int wicketsTaken;
        int runGiven;
    public:
        bowler()
        {

        }

        bowler(char *s,int a,int m,int wicketsTaken,int runGiven) : cricketer(s,a,m)
        {
            this->wicketsTaken=wicketsTaken;
            this->runGiven=runGiven;
        }

        double computeWicketAverage()
        {
            return (double)wicketsTaken/getMatchPlayed();
        }

        double computeAverageRunPerMatch()
        {
            return (double)runGiven/getMatchPlayed();
        }
};

class allrounder : public batsman, public bowler
{
    private:
        int i;
    public:
        allrounder()
        {

        }

         allrounder(char *s,int a,int m,int runScored,int runGiven) : batsman(s,a,m,runScored)
        {

        }
};

int main()
{

        allrounder a("Shakib",28,200,5000,400);

        cout<<a.getName()<<" "<<a.computeAverageRunPerMatch()<<" "<<a.computeBattingAverage()<<endl;
        return 0;
}
