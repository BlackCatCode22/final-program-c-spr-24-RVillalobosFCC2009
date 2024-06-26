#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Contact {
private:
    string name;
    string phoneNumber;
    string email;

public:
    Contact(string name, string phoneNumber, string email)
    : name(move(name)), phoneNumber(move(phoneNumber)), email(move(email)) {}

    const string& getName() const {
        return name;
    }

    void setName(const string& newName) {
        name = newName;
    }

    const string& getPhoneNumber() const {
        return phoneNumber;
    }

    void setPhoneNumber(const string& newPhoneNumber) {
        phoneNumber = newPhoneNumber;
    }

    const string& getEmail() const {
        return email;
    }

    void setEmail(const string& newEmail) {
        email = newEmail;
    }

    friend ostream& operator<<(ostream& os, const Contact& contact) {
        os << "Contact{name='" << contact.name << "', phoneNumber='" << contact.phoneNumber << "', email='" << contact.email << "'}";
        return os;
    }
};

// Linear Search Function
int linearSearch(const vector<Contact>& contacts, const string& target) {
    int iterations = 0;
    for (size_t i = 0; i < contacts.size(); ++i) {
        iterations++;
        if (contacts[i].getName() == target) {
            cout << "Linear search iterations: " << iterations << " out of " << contacts.size() << endl;
            return i;
        }
    }
    cout << "Linear search iterations: " << iterations << " out of " << contacts.size() << endl;
    return -1;
}

// Binary Search Function
int binarySearch(const vector<Contact>& contacts, const string& target) {
    int left = 0;
    int right = contacts.size() - 1;
    int iterations = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        iterations++;

        if (contacts[mid].getName() == target) {
            cout << "Binary search iterations: " << iterations << " out of " << contacts.size() << endl;
            return mid;
        }

        if (contacts[mid].getName() < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << "Binary search iterations: " << iterations << " out of " << contacts.size() << endl;
    return -1;
}

int main() {
    vector<Contact> contacts;
    contacts.emplace_back("Patsy", "098-277-2407", "patsy@email.com");
    contacts.emplace_back("John", "555-260-5785", "john@email.com");
    contacts.emplace_back("Gary", "998-512-559", "gary@email.com");

    string targetName;
    cout << "Enter the name to search: ";
    getline(cin, targetName);

    cout << "\nTarget name is: " << targetName << endl;

    // Perform Linear Search
    int resultLinear = linearSearch(contacts, targetName);
    if (resultLinear != -1) {
        cout << "Contact found by linear search at index: " << resultLinear << endl;
    } else {
        cout << "Contact not found by linear search." << endl;
    }

    // Perform Binary Search
    int resultBinary = binarySearch(contacts, targetName);
    if (resultBinary != -1) {
        cout << "Contact found by binary search at index: " << resultBinary << endl;
    } else {
        cout << "Contact not found by binary search." << endl;
    }

    return 0;
}
