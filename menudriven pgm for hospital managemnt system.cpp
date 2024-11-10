#include <iostream>
#include <string>
using namespace std;

// Base class Hospital
class Hospital {
protected:
    string name;
    int numDoctors;

public:
    Hospital() : name("Unnamed"), numDoctors(0) {}  // Default constructor
    Hospital(string n, int d) : name(n), numDoctors(d) {}  // Parameterized constructor

    virtual ~Hospital() {}  // Virtual destructor

    virtual void serviceType() const {  // Virtual function
        cout << "General hospital services." << endl;
    }

    void display() const {
        cout << "Hospital Name: " << name << ", Number of Doctors: " << numDoctors << endl;
    }

    friend ostream& operator<<(ostream& out, const Hospital& h) {
        out << "Hospital: " << h.name << ", Doctors: " << h.numDoctors;
        return out;
    }

    friend istream& operator>>(istream& in, Hospital& h) {
        cout << "Enter hospital name: ";
        in >> ws;  // To ignore leading whitespace
        getline(in, h.name);
        cout << "Enter number of doctors: ";
        in >> h.numDoctors;
        return in;
    }
};

// Derived class for multilevel inheritance
class GeneralHospital : public Hospital {
public:
    GeneralHospital(string n, int d) : Hospital(n, d) {}
    void serviceType()const override {
        cout << "Provides general healthcare services." << endl;
    }
};

// Another base class for multiple inheritance
class SpecializedService {
public:
    void specializedService() const {
        cout << "Provides specialized healthcare services." << endl;
    }
};

// Hybrid inheritance combining multilevel and multiple inheritance
class TeachingHospital : public GeneralHospital, public SpecializedService {
public:
    TeachingHospital(string n, int d) : GeneralHospital(n, d) {}

    void serviceType() const override {
        cout << "Teaching hospital with both general and specialized services." << endl;
    }
};

int main() {
    Hospital* hospital = new Hospital("City Hospital", 500);
    int choice;

    do {
        cout << "\nHospital Management System\n";
        cout << "1. Display Hospital Information\n";
        cout << "2. Display Service Type\n";
        cout << "3. Use Teaching Hospital (Multiple and Multilevel Inheritance)\n";
        cout << "4. Input Hospital Details\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << *hospital << endl;
                break;
            case 2:
                hospital->serviceType();
                break;
            case 3: {
                TeachingHospital th("University Hospital", 300);
                th.display();
                th.serviceType();
                th.specializedService();
                break;
            }
            case 4: {
                Hospital newHospital;
                cin >> newHospital;
                cout << "New Hospital Details: " << newHospital << endl;
                break;
            }
            case 5:
                cout << "Exiting program.\n";
                delete hospital;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

