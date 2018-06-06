#include <iostream>
#include <memory>

using namespace std;

class Singleton {
    private:
        static shared_ptr<Singleton> instance;
        Singleton(){}
        Singleton(const Singleton &);
        Singleton& operator=(const Singleton&);
    public:
        static shared_ptr<Singleton> getInstance() {
            if(!instance) {
                instance = shared_ptr<Singleton>(new Singleton());
            }
            return instance;
        }
};
shared_ptr<Singleton> Singleton::instance = NULL;

int main() {
    shared_ptr<Singleton> s0 = Singleton::getInstance();
    shared_ptr<Singleton> s1 = Singleton::getInstance();

    cout << s0 << endl;
    cout << s1 << endl;
}