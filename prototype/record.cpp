#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>

using namespace std;

class Record
{
    public:
        virtual ~Record() {}
        virtual void print() = 0;
        virtual unique_ptr<Record> clone() = 0;
};

class CarRecord : public Record
{
    private:
        string _carName;
        int _id;

    public:
        CarRecord(string carName, int id) : _carName(carName), _id(id)
        {
        }

        void print() override
        {
            cout << "Car Record" << endl
                << "Name : " << _carName << endl
                << "Number: " << _id << endl << endl;
        }

        unique_ptr<Record> clone() override
        {
            return make_unique<CarRecord>(*this);
        }
};

class BikeRecord : public Record
{
    private:
        string _bikeName;
        int _id;

    public:
        BikeRecord(string bikeName, int id) : _bikeName(bikeName), _id(id)
        {
        }

        void print() override
        {
            cout << "Bike Record" << endl
                << "Name : " << _bikeName << endl
                << "Number : " << _id << endl << endl;
        }

        unique_ptr<Record> clone() override
        {
            return make_unique<BikeRecord>(*this);
        }
};

class PersonRecord : public Record
{
    private:
        string _personName;
        int _age;

    public:
        PersonRecord(string personName, int age) : _personName(personName), _age(age)
        {
        }

        void print() override
        {
            cout << "Person Record" << endl
                << "Name : " << _personName << endl
                << "Age : " << _age << endl << endl;
        }

        unique_ptr<Record> clone() override
        {
            return make_unique<PersonRecord>(*this);
        }
};

enum RecordType
{
    CAR,
    BIKE,
    PERSON
};

class RecordFactory
{
    private:
        unordered_map<RecordType, unique_ptr<Record>, hash<int> > _records;
    public:
        RecordFactory()
        {
            _records[CAR] = make_unique<CarRecord>("Ferrai", 5050);
            _records[BIKE] = make_unique<BikeRecord>("Yamaha", 2525);
            _records[PERSON] = make_unique<PersonRecord>("Tom", 25);
        }

        unique_ptr<Record> createRecord(RecordType recordType)
        {
            return _records[recordType]->clone();
        }
};

int main()
{
    RecordFactory recordFactory;

    auto record = recordFactory.createRecord(CAR);
    record->print();

    record = recordFactory.createRecord(BIKE);
    record->print();

    record = recordFactory.createRecord(PERSON);
    record->print();
}