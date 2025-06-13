#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <numeric>

using namespace std;

struct Item {
    string name;
    double price;
    int quantity;
    int sold;
};

class Manage {
private:
    vector<Item> products;
    vector<int> salesHistory;
    int totalExpenses;
    int budgetLeft;
    int totalBudget;
    int water, electricity, transportation, equipment, capital;
    char choice1;

public:
    Manage() : totalExpenses(0), budgetLeft(0), totalBudget(0), water(0), electricity(0), transportation(0), equipment(0), capital(0) {}

    void manageExpenses() {
        int option2;
        cout << "\nTOTAL BUDGET" << endl;
        cout << "Enter budget: ";
        cin >> totalBudget;

        do {
            cout << "\nSelect the expense category:" << endl;
            cout << "\n1. Water Bill" << endl;
            cout << "2. Electricity Bill" << endl;
            cout << "3. Transportation" << endl;
            cout << "4. Equipment" << endl;
            cout << "5. Product Capital" << endl;
            cin >> option2;

            int amount;
            switch (option2) {
            case 1:
                cout << "\nWater Bill: ";
                cout << "\nEnter amount: ";
                cin >> amount;
                water += amount;
                totalExpenses += amount;
                break;
            case 2:
                cout << "\nElectricity Bill: ";
                cout << "\nEnter amount: ";
                cin >> amount;
                electricity += amount;
                totalExpenses += amount;
                break;
            case 3:
                cout << "\nTransportation: ";
                cout << "\nEnter amount: ";
                cin >> amount;
                transportation += amount;
                totalExpenses += amount;
                break;
            case 4:
                cout << "\nEquipment: ";
                cout << "\nEnter amount: ";
                cin >> amount;
                equipment += amount;
                totalExpenses += amount;
                break;
            case 5:
                cout << "\nProduct Capital: ";
                cout << "\nEnter amount: ";
                cin >> amount;
                capital += amount;
                totalExpenses += amount;
                break;
            default:
                cout << "\nInvalid Input!" << endl;
            }
            cout << "Do you want to input another? (Y/N) ";
            cin >> choice1;
        } while (choice1 != 'N' && choice1 != 'n');

    }

    void budgetStatus() {
        cout << "     EXPENSES                      AMOUNT" << endl;
        cout << " Water Bill                         " << water << endl;
        cout << " Electricity Bill                   " << electricity << endl;
        cout << " Transportation                     " << transportation << endl;
        cout << " Equipment                          " << equipment << endl;
        cout << " Product Capital                    " << capital << endl;

        budgetLeft = totalBudget - totalExpenses;

        cout << "\nTotal Budget: " << totalBudget << endl;
        cout << "Total Expenses: " << totalExpenses << endl;
        cout << "Remaining Budget: " << budgetLeft << endl;
    }

    void add(string name, double price, int quantity) {
        Item newProduct = {name, price, quantity, 0};
        products.push_back(newProduct);
        capital += price * quantity;
        totalExpenses += price * quantity;

        cout << "\nProduct added to the store." << endl;
    }

    void display() {
        cout << "\nProducts in the store:" << endl;
        for (const auto& product : products) {
            cout << "\nName: " << product.name << ", Price: Php " << product.price << ", Quantity: " << product.quantity << ", Sold: " << product.sold << endl;
        }
    }

    void sellProduct(string name, int quantity) {
        for (auto& product : products) {
            if (product.name == name) {
                if (product.quantity >= quantity) {
                    product.quantity -= quantity;
                    product.sold += quantity;
                    salesHistory.push_back(quantity);
                    cout << quantity << " " << name << "(s) sold." << endl;
                    return;
                } else {
                    cout << "Not enough " << name << " in stock." << endl;
                    return;
                }
            }
        }
        cout << "Product not found in the store." << endl;
    }

    double calculateTotalSales() {
        double totalSales = 0;
        for (const auto& product : products) {
            totalSales += product.price * product.sold;
        }
        return totalSales;
    }

    double calculateTotalProfit() {
        return calculateTotalSales() - totalExpenses;
    }

    double calculateSavings() {
        return calculateTotalProfit() + budgetLeft;
    }

    void predictSales(int days) {
        if (salesHistory.empty()) {
            cout << "No sales data available to make a prediction." << endl;
            return;
        }

        double averageSales = static_cast<double>(accumulate(salesHistory.begin(), salesHistory.end(), 0)) / salesHistory.size();
        double predictedSales = averageSales * days;

        cout << "\nPredicted sales for the next " << days << " day(s): " << predictedSales << " items." << endl;
    }
};

int main() {
    Manage store;
    int choice, input, quantity, option, days;
    string name;
    char input1;
    double price;

    do {
        cout << "\n------------------------------------------------------" << endl;
        cout << "\t***** *****     *      ***** *   *" << endl;
        cout << "\t*       *     *   *    *     *   *" << endl;
        cout << "\t*****   *    *******   ***** *****" << endl;
        cout << "\t    *   *   *       *      * *   *" << endl;
        cout << "\t*****   *  *         * ***** *   *" << endl;
        cout << "------------------------------------------------------" << endl;
        cout << "\t     GOOD DAY, WELCOME TO STASH!" << endl;
        cout << "------------------------------------------------------" << endl;
        cout << "\n1. Expense Tracking\n2. Inventory\n3. Sales Tracking\n4. Financial Planning\n5. Predictive Sales\nEnter your choice: ";
        cin >> input;

        switch (input) {
            case 1:
                cout << "\n------------------------------------------------------" << endl;
                cout << "\t\tEXPENSE TRACKING" << endl;
                cout << "------------------------------------------------------" << endl;
                cout << "\nSelect the feature you want to perform:" << endl;
                cout << "1. Manage Expenses" << endl;
                cout << "2. Budget Status" << endl;
                cout << "3. Exit\nEnter your choice: ";
                cin >> option;

                switch (option) {
                    case 1:
                        store.manageExpenses();
                        break;
                    case 2:
                        store.budgetStatus();
                        break;
                    case 3:
                        cout << "Exiting expense tracking." << endl;
                        break;
                    default:
                        cout << "Invalid option selected." << endl;
                        break;
                }
                break;

            case 2:
                cout << "------------------------------------------------------" << endl;
                cout << "\t\tINVENTORY" << endl;
                cout << "------------------------------------------------------" << endl;
                cout << "\n1. Add Product\n2. Display Products\nEnter your choice: ";
                cin >> choice;

                switch (choice) {
                    case 1:
                        cout << "\nEnter product name: ";
                        cin >> name;
                        cout << "Enter product price: ";
                        cin >> price;
                        cout << "Enter product quantity: ";
                        cin >> quantity;
                        store.add(name, price, quantity);
                        break;
                    case 2:
                        store.display();
                        break;
                    default:
                        cout << "Invalid choice!" << endl;
                }
                break;

            case 3:
                cout << "------------------------------------------------------" << endl;
                cout << "\t\tSALES TRACKING" << endl;
                cout << "------------------------------------------------------" << endl;
                cout << "Enter product name to sell: ";
                cin >> name;
                cout << "Enter quantity to sell: ";
                cin >> quantity;

                store.sellProduct(name, quantity);
                break;

            case 4:
                {
                    double totalProfit = store.calculateTotalProfit();
                    double totalSales = store.calculateTotalSales();
                    double savings = store.calculateSavings();

                    cout << "------------------------------------------------------" << endl;
                    cout << "\t\tFINANCIAL SUMMARY" << endl;
                    cout << "------------------------------------------------------" << endl;
                    cout << "Total Sales: Php " << totalSales << endl;
                    cout << "Total Profit: Php " << totalProfit << endl;
                    cout << "Savings: Php " << savings << endl;
                }
                break;

            case 5:
                cout << "------------------------------------------------------" << endl;
                cout << "\t\tPREDICTIVE SALES" << endl;
                cout << "------------------------------------------------------" << endl;
                cout << "Enter the number of days for prediction: ";
                cin >> days;
                store.predictSales(days);
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

        cout << "\nDo you want to try again? (Y/N) ";
        cin >> input1;
    } while (input1 != 'N' && input1 != 'n');

    return 0;
}
