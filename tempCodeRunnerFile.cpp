#include <iostream>
#include <string>
using namespace std;
class Company
{
private:
    string name;
    string location;
    int numEmployees;
    Company *next;

public:
    // Constructor to initialize the company
    Company(string name, string location, int numEmployees)
    {
        this->name = name;
        this->location = location;
        this->numEmployees = numEmployees;
        this->next = nullptr;
    }
    // Getter and setter methods
    string getName()
    {
        return name;
    }
    string getLocation()
    {
        return location;
    }
    int getNumEmployees()
    {
        return numEmployees;
    }
    Company *getNext()
    {
        return next;
    }
    void setNext(Company *nextCompany)
    {
        next = nextCompany;
    }
};
// Function to append a new company to the list
void appendCompany(Company *&head, string name, string location, int numEmployees)
{
    Company *newCompany = new Company(name, location, numEmployees);
    if (head == nullptr)
    {
        head = newCompany;
        return;
    }
    Company *temp = head;
    while (temp->getNext() != nullptr)
    {
        temp = temp->getNext();
    }
    temp->setNext(newCompany);
}
// Function to add a company to the beginning of the list
void addCompanyToBeginning(Company *&head, string name, string location, int numEmployees)
{
    Company *newCompany = new Company(name, location, numEmployees);
    newCompany->setNext(head);
    head = newCompany;
}
// Function to find the number of employees if the company name is specified
int findNumEmployees(Company *head, string name)
{
    Company *temp = head;
    while (temp != nullptr)
    {
        if (temp->getName() == name)
        {
            return temp->getNumEmployees();
        }
        temp = temp->getNext();
    }
    return -1; // Company not found
}
// Function to find the location if the company name is specified
string findLocation(Company *head, string name)
{
    Company *temp = head;
    while (temp != nullptr)
    {
        if (temp->getName() == name)
        {
            return temp->getLocation();
        }
        temp = temp->getNext();
    }
    return "Company not found"; // Company not found
}
// Function to create a list of N companies
void createListOfCompanies(Company *&head, int n)
{
    for (int i = 0; i < n; i++)
    {
        string name, location;
        int numEmployees;
        cout << "Enter details for company " << i + 1 << ":\n";
        cout << "Name: ";
        cin >> name;
        cout << "Location: ";
        cin >> location;
        cout << "Number of Employees: ";
        cin >> numEmployees;
        appendCompany(head, name, location, numEmployees);
    }
}
// Function to display the list of companies
void displayCompanies(Company *head)
{
    Company *temp = head;
    while (temp != nullptr)
    {
        cout << "Name: " << temp->getName() << ", Location: " << temp->getLocation() << ", Number of Employees: " << temp->getNumEmployees() << endl;
        temp = temp->getNext();
    }
}
// Main function with menu-driven interface
int main()
{
    Company *head = nullptr;
    int choice;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Create a list of N companies\n";
        cout << "2. Append a new company to the list\n";
        cout << "3. Add a company to the beginning of the list\n";
        cout << "4. Find number of employees by company name\n";
        cout << "5. Find location by company name\n";
        cout << "6. Display all companies\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int n;
            cout << "Enter the number of companies: ";
            cin >> n;
            createListOfCompanies(head, n);
            break;
        }
        case 2:
        {
            string name, location;
            int numEmployees;
            cout << "Enter details for the new company:\n";
            cout << "Name: ";
            cin >> name;
            cout << "Location: ";
            cin >> location;
            cout << "Number of Employees: ";
            cin >> numEmployees;
            appendCompany(head, name, location, numEmployees);
            break;
        }
        case 3:
        {
            string name, location;
            int numEmployees;
            cout << "Enter details for the new company:\n";
            cout << "Name: ";
            cin >> name;
            cout << "Location: ";
            cin >> location;
            cout << "Number of Employees: ";
            cin >> numEmployees;
            addCompanyToBeginning(head, name, location, numEmployees);
            break;
        }
        case 4:
        {
            string name;
            cout << "Enter the company name to find the number of employees: ";
            cin >> name;
            int numEmployees = findNumEmployees(head, name);
            if (numEmployees != -1)
            {
                cout << "Number of Employees in " << name << ": " << numEmployees << endl;
            }
            else
            {
                cout << "Company not found.\n";
            }
            break;
        }
        case 5:
        {
            string name;
            cout << "Enter the company name to find the location: ";
            cin >> name;
            string location = findLocation(head, name);
            if (location != "Company not found")
            {
                cout << "Location of " << name << ": " << location << endl;
            }
            else
            {
                cout << "Company not found.\n";
            }
            break;
        }
        case 6:
            displayCompanies(head);
            break;
        case 7:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 7);
    // Free memory allocated for the linked list
    while (head != nullptr)
    {
        Company *temp = head;
        head = head->getNext();
        delete temp;
    }
    return 0;
}