#include <string>
#include <iostream>

using namespace std;

class Car
{
    protected:
        string str;
    
    public:
        Car()
        {
            str = "Unknown Car";
        }

        virtual string getDescription()
        {
            return str;
        }

        virtual double getCost() = 0;

        virtual ~Car()
        {
            cout << "~Car()" << endl;
        }
};

class OptionsDecorator : public Car
{
    public:
        virtual string getDescription() = 0;

        virtual ~OptionsDecorator()
        {
            cout << "~OptionsDecorator()" << endl;
        }
};

class CarModel1 : public Car
{
    public:
        CarModel1()
        {
            str = "CarModel1";
        }

        virtual double getCost()
        {
            return 2344221.11;
        }

        ~CarModel1()
        {
            cout << "~CarModel1()" << endl;
        }
};

class Navigation : public OptionsDecorator
{
    Car *_b;

    public:
        Navigation(Car *b)
        {
            _b = b;
        }

        string getDescription()
        {
            return _b->getDescription() + ", Navigation";
        }

        double getCost()
        {
            return 200.45 + _b->getCost();
        }

        ~Navigation()
        {
            cout << "~Navigation()" << endl;
            delete _b;
        }
};

class PremiumSoundSystem : public OptionsDecorator
{
    Car *_b;

    public:
        PremiumSoundSystem(Car *b)
        {
            _b = b;
        }

        string getDescription()
        {
            return _b->getDescription() + ", PreiumSoundSystem";
        }

        double getCost()
        {
            return 0.3 + _b->getCost();
        }

        ~PremiumSoundSystem()
        {
            cout << "~PreiumSoundSystem()" << endl;
            delete _b;
        }
};

class ManualTransmission : public OptionsDecorator
{
    Car *_b;
    public:
        ManualTransmission(Car *b)
        {
            _b = b;
        }

        string getDescription()
        {
            return _b->getDescription() + ", ManualTransmission";
        }

        double getCost()
        {
            return 0.30 + _b->getCost();
        }

        ~ManualTransmission()
        {
            cout << "~ManualTransmission()" << endl;
            delete _b;
        }
};

int main()
{
    Car *b = new CarModel1();

    cout << "Base model of " << b->getDescription() << 
     " costs $" << b->getCost() << endl;

    b = new Navigation(b);
    cout << b->getDescription() << " will cost you $" << b->getCost() << endl;
    b = new PremiumSoundSystem(b);
    b = new ManualTransmission(b);
    cout << b->getDescription() << " will cost you $" << b->getCost() << endl;

    delete b;
    return 0;
}