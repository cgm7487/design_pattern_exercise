#include <iostream>
#include <memory>

using namespace std;

class Animal {
    public:
        virtual ~Animal(){}
        virtual void makeSound() const = 0;
};

class Dog : public Animal {
    public:
        void makeSound() const {
            cout << "Bark" << endl;
        }

};

class Cat : public Animal {
    public:
        void makeSound() const {
            cout << "Meow" << endl;
        }
};

class AnimalFactory {
    public:
        static unique_ptr<Animal> create_animal(const string &animalType) {
            if (animalType == "Dog") {
                return unique_ptr<Animal>(new Dog());
            } else if(animalType == "Cat") {
                return unique_ptr<Animal>(new Cat());
            } else {
                throw invalid_argument("Invalid animal type");
            }
        }
};

int main() {

    unique_ptr<Animal> dog = AnimalFactory::create_animal("Dog");
    unique_ptr<Animal> cat = AnimalFactory::create_animal("Cat");

    dog->makeSound();
    cat->makeSound();

    return 0;
}


