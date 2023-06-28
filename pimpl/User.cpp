#include "User.h"
#include <iostream>

using namespace std;

struct User::Impl {
    Impl(string name)
        : name(move(name))

    ~Impl();

    void welcomeMessage() {
        cout << "Welecome, "
            << name << endl;
    }

    string name;
    int salary = -1;
}

User::User(string name)
    : pimpl(new Impl(move(name))) {
    
    pimpl->welcomeMessage();

}

User::~User() = default;

User::User(const User& other)
    : pimpl(new Impl(*other.pimpl)) {
}

User& User::operator=(User rhs) {
    swap(pimpl, rhs.pimpl);
    return *this;
}

int User::getSalary() {
    return pimpl->salary;
}

void User::setSalary(int salary) {
    pimpl->salary = salary;
    cout << "Salary set to " << salary << endl;
}