#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Shape {
    public:
        virtual void whichShape() = 0;
};

class Rectangle : public Shape {
    public:
        void whichShape() override {cout << "This is Rectangle" << endl;}
};

class Circle : public Shape {
    public:
        void whichShape() override {cout << "This is Circle" << endl;}
};

class ShapeFactory {
    public:
        virtual shared_ptr<Shape> getShape() = 0;
        static shared_ptr<ShapeFactory> createFactory(const string s); 

};

class RectFactory : public ShapeFactory {
    public:
        shared_ptr<Shape> getShape() override {return shared_ptr<Shape>(new Rectangle());}
};

class CircFactory : public ShapeFactory {
    public:
        shared_ptr<Shape> getShape() override {return shared_ptr<Shape>(new Circle());}
};

shared_ptr<ShapeFactory> ShapeFactory::createFactory(const string s) {
    if(s == "Rectangle") {
        return shared_ptr<ShapeFactory>(new RectFactory());
    }
    else if(s == "Circle") {
        return shared_ptr<ShapeFactory>(new CircFactory());
    }
}

int main(int argc, char* argv[])
{
    shared_ptr<ShapeFactory> factory = ShapeFactory::createFactory("Rectangle");

    factory->getShape()->whichShape();

    factory = ShapeFactory::createFactory("Circle");

    factory->getShape()->whichShape();

    return 0;
}
