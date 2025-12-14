#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Global variable to store the admin password
const string ADMIN_PASSWORD = "admin123"; // Change this to any password you want

class car {
public:
    // Default constructor
    car();

    // Explicit value constructor
    explicit car(string brand, string model, double price, int year, int id, string color = "Unknown", double MPG = 0.0, double GasPrice = 0.0);

    // Mutator functions
    void SetBrand(string);
    void SetModel(string);
    void SetPrice(double);
    void SetYear(int);
    void SetID(int);
    void SetMPG(double);
    void SetGasPrice(double);
    void SetColor(string);

    // Accessor functions
    string GetBrand() const;
    string GetModel() const;
    string GetColor() const;
    double GetPrice() const;
    double GetMPG() const;
    double GetGasPrice() const;
    int GetYear() const;
    int GetID() const;
    

    // Member function for calculating purchase details
    void CalculatePurchase();
    void AddWarranty(double warrantyCost);  // Function to add warranty cost

    friend double operator + (const car& car2, const car& car3);
    friend bool operator < (const car& car1, const car& car2);

private:
    string brand;
    string model;
    string color;
    double price;
    double MPG;
    double GasPrice;
    double warrantyCost;  // Variable to store the cost of warranty
    int year;
    int id;
};

// Default constructor
car::car() {
    model = "Elantra";
    brand = "Hyundai";
    price = 25460.43;
    year = 2023;
    id = 1;
    warrantyCost = 0.0;  // Default to no warranty
    color = "White";
    MPG = 30.0;
    GasPrice = 3.50;
}

// Explicit value constructor (parameter order matches declaration: brand, model, price, year, id)
car::car(string b, string m, double p, int y, int i, string col, double mpg, double gasP) {
    brand = b;
    model = m;
    price = p;
    year = y;
    id = i;
    warrantyCost = 0.0;  // Default to no warranty
    color = col;
    MPG = mpg;
    GasPrice = gasP;
}

// Mutator function definitions
void car::SetBrand(string b) {
    brand = b;
}

void car::SetModel(string m) {
    model = m;
}

void car::SetPrice(double p) {
    price = p;
}

void car::SetYear(int y) {
    year = y;
}

void car::SetID(int i) {
    id = i;
}

void car::SetMPG(double mpg) {
    MPG = mpg;
}

void car::SetGasPrice(double gasP) {
    GasPrice = gasP;
}

void car::SetColor(string c) {
    color = c;
}

// Accessor function definitions
string car::GetBrand() const {
    return brand;
}

string car::GetModel() const {
    return model;
}

double car::GetPrice() const {
    return price;
}

int car::GetYear() const {
    return year;
}

int car::GetID() const {
    return id;
}

string car::GetColor() const {
    return color;
}

double car::GetMPG() const {
    return MPG;
}

double car::GetGasPrice() const {
    return GasPrice;
}

// Function to add warranty cost to the car
void car::AddWarranty(double warrantyCost) {
    this->warrantyCost = warrantyCost;  // Store the warranty cost
}

// Modify CalculatePurchase to include warranty
void car::CalculatePurchase() {
    double taxRate = 0.06;
    double taxAmount, total, taxTotal;

    cout << "\nModel: " << model << " | Brand: " << brand << endl;
    cout << "Price: $" << price << endl;

    taxAmount = price * taxRate;
    taxTotal = price + taxAmount;
    // Add warranty cost if selected
    total = taxTotal + warrantyCost;

    cout << fixed;
    cout.precision(2);

    cout << "\nSubtotal: $" << price;
    cout << "\nSales Tax (6%): $" << taxAmount;
    cout << "\nSubtotal (With Taxes): " << taxTotal;
    cout << "\nWarranty: $" << warrantyCost;
    cout << "\nTotal Cost (With warranty and taxes): $" << total << "\n";
}

// Function to display detailed car info
void detail(const car& selectedCar) {
    cout << "\n---- Car Details ----\n";
    cout << "ID: " << selectedCar.GetID() << endl;
    cout << "Brand: " << selectedCar.GetBrand() << endl;
    cout << "Model: " << selectedCar.GetModel() << endl;
    cout << "Year: " << selectedCar.GetYear() << endl;
    cout << "Price: $" << selectedCar.GetPrice() << endl;
    cout << "Color: " << selectedCar.GetColor() << endl;
    cout << "MPG: " << selectedCar.GetMPG() << endl;
    cout << "Gas Price: $" << selectedCar.GetGasPrice() << endl;
}

// Display all cars in the inventory
void DisplayCars(vector<car>& inventory) {
    if (inventory.empty()) {
        cout << "No cars in inventory.\n";
        return;
    }
    cout << "\n--- Inventory ---\n";
    for (size_t i = 0; i < inventory.size(); ++i) {
        cout << "[" << i + 1 << "] "
             << "ID: " << inventory[i].GetID()
             << " | Brand: " << inventory[i].GetBrand()
             << " | Model: " << inventory[i].GetModel()
             << " | Year: " << inventory[i].GetYear()
             << " | Price: $" << inventory[i].GetPrice()
             << "\n";
    }

    char choice;
    cout << "\nWould you like to view more details of a car? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        int id;
        cout << "Enter the ID of the car: ";
        cin >> id;
        for (const auto& c : inventory) {
            if (c.GetID() == id) {
                detail(c);
                return;
            }
        }
        cout << "Car not found.\n";
    }
}

// Add car to inventory
void AddCar(vector<car>& inventory) {
    string brand, model, color;
    double price = 0.0, MPG = 0.0, GasPrice = 0.0;
    int year = 0;
    int id = 0;

    cout << "Enter Brand: ";
    cin.ignore();
    getline(cin, brand);

    cout << "Enter Model: ";
    getline(cin, model);

    cout << "Enter Color: ";
    getline(cin, color);

    cout << "Enter Price: ";
    cin >> price;

    cout << "Enter Year: ";
    cin >> year;

    cout << "Enter MPG: ";
    cin >> MPG;

    cout << "Enter Gas Price: ";
    cin >> GasPrice;

    cout << "Enter ID: ";
    cin >> id;

    inventory.emplace_back(brand, model, price, year, id, color, MPG, GasPrice);
    cout << "Car added to inventory\n";
}

// Delete car from inventory
void DeleteCar(vector<car>& inventory) {
    int id;
    cout << "Enter car ID to delete: ";
    cin >> id;

    for (size_t i = 0; i < inventory.size(); ++i) {
        if (inventory[i].GetID() == id) {
            inventory.erase(inventory.begin() + i);
            cout << "Car with ID " << id << " has been deleted.\n";
            return;
        }
    }
    cout << "Car not found in inventory.\n";
}

// Print car info
void PrintCarInfo(const car& car) {
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2); //use any number here for the number of decimal places
    cout << "\n\n------Printing Car info-----\n\n";
    cout << "ID : " << car.GetID() << endl;
    cout << "Car Brand: " << car.GetBrand() << endl;
    cout << "Car Model: " << car.GetModel() << endl;
    cout << "Car Price: $" << car.GetPrice() << endl;
    cout << "Car Year: " << car.GetYear() << endl;
}

// Friend function to compare car prices
bool operator < (const car& car1, const car& car2) {
    return car1.price < car2.price;
}

// Friend function to calculate average price of two cars
double operator + (const car& car2, const car& car3) {
    return (car2.price + car3.price) / 2;
}

// Warranty function
void warranty(car &selectedCar) {
    int warrantyChoice;
    double warrantyCost = 0.0;

    // Display warranty options
    cout << "\n---- Warranty Options ----\n";
    cout << "1. Basic Warranty - $500\n";
    cout << "2. Extended Warranty - $1000\n";
    cout << "3. Premium Warranty - $1500\n";
    cout << "4. No warranty\n";
    cout << "\nEnter your choice (1-4): ";
    cin >> warrantyChoice;

    // Set warranty cost based on the choice
    switch (warrantyChoice) {
        case 1:
            warrantyCost = 500;
            break;
        case 2:
            warrantyCost = 1000;
            break;
        case 3:
            warrantyCost = 1500;
            break;
        case 4:
            cout << "No warranty selected.\n";
            break;
        default:
            cout << "Invalid choice. No warranty selected.\n";
            break;
    }

    // Add warranty cost to the selected car
    selectedCar.AddWarranty(warrantyCost);
}

void PurchaseCar(vector<car>& inventory) {
    int id;
    cout << "\nEnter the ID of the car you would like to purchase: ";
    cin >> id;

    // Find the car by ID
    for (auto& c : inventory) {
        if (c.GetID() == id) {
            c.CalculatePurchase();  // Display purchase details without warranty
            warranty(c);  // Call the warranty function to add a warranty if chosen
            c.CalculatePurchase();  // Recalculate and show final total with warranty
            return;
        }
    }
    cout << "Car not found in inventory.\n";
}

// Function to handle login for admin
bool AdminLogin() {
    string password;
    string username;
    cout << "Enter Admin Username: ";
    cin >> username;
    cout << "Enter Admin Password: ";
    cin >> password;

    if (username == "admin" && password == "password123") {
        return true; // Login successful
    } else {
        cout << "Incorrect password. Access denied.\n";
        return false; // Login failed
    }
}

// Function to display customer menu
void CustomerMenu(vector<car>& inventory) {
    int choice;
    cout << "\n---- Customer Menu ----" << endl;
    cout << "1. Display cars" << endl;
    cout << "2. Purchase car" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            DisplayCars(inventory); // Display cars function
            CustomerMenu(inventory);
            break;
        case 2:
            DisplayCars(inventory);
            PurchaseCar(inventory); // Purchase car function
            break;
        case 3:
            cout << "Exiting customer view...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
    }
}

// Function to display admin menu
void AdminMenu(vector<car>& inventory) {
    int choice;
    cout << "\n---- Admin Menu ----" << endl;
    cout << "1. Add car" << endl;
    cout << "2. Delete car" << endl;
    cout << "3. Display cars" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            AddCar(inventory);  // Add car function
            AdminMenu(inventory);
            break;
        case 2:
            DeleteCar(inventory); // Delete car function
            AdminMenu(inventory);
            break;
        case 3:
            DisplayCars(inventory); // Display cars function
            AdminMenu(inventory);
            break;
        case 4:
            cout << "Exiting admin view...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
    }
}

void addreview(vector<car>& inventory) {
    int id;
    int rating;
    string review;
    cout << "Enter the ID of the car you want to review: ";
    cin >> id;
    cout << "Enter your rating (1-5): ";
    cin >> rating;
    cout << "Enter your review: ";
    cin.ignore();
    getline(cin, review);

    for(auto& c : inventory) {
        if(c.GetID() == id){
            cout << "Thanks for leaving a review for " << c.GetBrand() << ", " << c.GetModel() << "!\n";
            cout << "Rating: " << rating << "/5\n";
            cout << "Review: " << review << "\n";  
        }   
    }
}
int main() {
    vector<car> inventory;
    car car1;
    car car2("Ford", "F-150", 45540.42, 2022, 2, "White", 20.0, 3.80);
    car car3("Honda", "Accord", 12105.53, 2014, 3, "Grey", 25.0, 2.86);

    inventory.push_back(car1);
    inventory.push_back(car2);
    inventory.push_back(car3);

    int userType;

    // Ask if the user is an admin or a customer
    cout << "Are you an admin or a customer? (1 for Admin, 2 for Customer): ";
    cin >> userType;

    if (userType == 1) {  // Admin access
        if (AdminLogin()) {
            AdminMenu(inventory);
        } else {
            cout << "Admin access denied.\n";
        }
    } else if (userType == 2) {  // Customer access
        CustomerMenu(inventory);
        addreview(inventory);
    } else {
        cout << "Invalid choice.\n";
    }

    return 0;
}
