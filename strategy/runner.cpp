#include <iostream>
#include <string>

using namespace std;

class RunStrategyInterface 
{
    public:
        virtual void run(const string &name) = 0;
};

class Jog : public RunStrategyInterface
{
    public:
        void run(const string &name) {
            cout << name + " is now jogging at a comfortable pace." << endl;
        }
};

class Sprint : public RunStrategyInterface
{
    public:
        void run(const string &name) {
            cout << name + " is now sprint full speed!" << endl;
        }
};

class Marathon : public RunStrategyInterface
{
    public:
        void run(const string &name) {
            cout << name + " is now running at a steady pace." << endl;
        }
};

class Runner
{
    public:
        Runner(const string &name, RunStrategyInterface *strategy):
            name(name),
            strategy(strategy) 
        {
        }

        void run() {
            strategy->run(name);
        }

    private:
        string name;
        RunStrategyInterface *strategy;
};

int main()
{
    Runner *ruby = new Runner("Ruby", new Jog());
    Runner *tom = new Runner("Tom", new Sprint());
    Runner *mark = new Runner("Mark", new Marathon());

    ruby->run();
    tom->run();
    mark->run();

    return 0;
}