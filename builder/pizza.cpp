#include <string>
#include <iostream>
#include <memory>

using namespace std;

class Pizza
{
    public:
        void setDough(const string &dough)
        {
            _dough = dough;
        }

        void setSauce(const string &sauce)
        {
            _sauce = sauce;
        }

        void setTopping(const string &topping)
        {
            _topping = topping;
        }

        void open() const
        {
            cout << "Pizza with " << _dough << " dough, " << _sauce << " sauce and "
                << _topping << " topping. Mmm." << endl;
        }
    private:
        string _dough;
        string _sauce;
        string _topping;
};

class PizzaBuilder
{
    public:
        virtual ~PizzaBuilder() {}

        Pizza* getPizza()
        {
            return _pizza.release();
        }

        void createNewPizzaProduct()
        {
            _pizza = make_unique<Pizza>();
        }

        virtual void buildDough() = 0;
        virtual void buildSauce() = 0;
        virtual void buildTopping() = 0;
    protected:
        unique_ptr<Pizza> _pizza;
};

class HawaiianPizzaBuilder : public PizzaBuilder
{
    public:
        virtual ~HawaiianPizzaBuilder() {}

        virtual void buildDough()
        {
            _pizza->setDough("cross");
        }

        virtual void buildSauce()
        {
            _pizza->setSauce("mild");
        }

        virtual void buildTopping()
        {
            _pizza->setTopping("ham+pipeapple");
        }
};

class SpicyPizzaBuilder : public PizzaBuilder
{
    public:
        virtual ~SpicyPizzaBuilder() {}

        virtual void buildDough()
        {
            _pizza->setDough("pan baked");
        }

        virtual void buildSauce()
        {
            _pizza->setSauce("hot");
        }

        virtual void buildTopping()
        {
            _pizza->setTopping("peperoni+sal");
        }
};

class Cook
{
    public:
        void openPizza()
        {
            _pizzaBuilder->getPizza()->open();
        }
        void makePizza(PizzaBuilder *pb)
        {
            _pizzaBuilder = pb;
            _pizzaBuilder->createNewPizzaProduct();
            _pizzaBuilder->buildDough();
            _pizzaBuilder->buildSauce();
            _pizzaBuilder->buildTopping();
        }
    private:
        PizzaBuilder *_pizzaBuilder;
};

int main()
{
    Cook cook;
    HawaiianPizzaBuilder hawaiianPIzzaBuilder;
    SpicyPizzaBuilder spicyPizzaBuilder;

    cook.makePizza(&hawaiianPIzzaBuilder);
    cook.openPizza();

    cook.makePizza(&spicyPizzaBuilder);
    cook.openPizza();

    return 0;
}
