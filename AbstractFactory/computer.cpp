#include <iostream>
#include <string>

using namespace std;

class Computer
{
    public:
        virtual void run() = 0;
        virtual void stop() = 0;

        virtual ~Computer() {};
};

class Laptop : public Computer
{
    public:
        void run() override {_hibernating = false;}
        void stop() override {_hibernating = true;}
        virtual ~Laptop() {};
};

class Desktop : public Computer
{
    public:
        void run() override {_on = true;}
        void stop() override {_on = false;}
        virtual ~Desktop() {};
    private:
        bool _on;
}