#include <iostream>
#include <string>
#include <unordered_map>
#include <regex>
#include <stdexcept>
#include <random>
#include <sstream>
#include <cmath>
#include <cassert>

using namespace std;

class ShoppingCart {
private:
    const string id;              // Immutable UUID for the cart
    const string customer_id;      // Immutable customer ID
    unordered_map<string, int> items;  // Items with quantities

    // Helper function to generate a UUID
    static string generateUUID() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, 15);
        uniform_int_distribution<> dis2(8, 11);

        stringstream ss;
        ss << hex;
        for (int i = 0; i < 8; ++i) ss << dis(gen);
        ss << "-";
        for (int i = 0; i < 4; ++i) ss << dis(gen);
        ss << "-4";  // UUID version 4
        for (int i = 0; i < 3; ++i) ss << dis(gen);
        ss << "-";
        ss << dis2(gen);  // UUID variant
        for (int i = 0; i < 3; ++i) ss << dis(gen);
        ss << "-";
        for (int i = 0; i < 12; ++i) ss << dis(gen);
        return ss.str();
    }

    // Helper function to validate customer ID format
    static bool isValidCustomerID(const string& customer_id) {
        const regex pattern("^[A-Z]{3}[0-9]{5}[A-Z]{2}[-][AQ]$");
        return regex_match(customer_id, pattern);
    }

    // Catalog of valid items and their prices
    unordered_map<string, double> catalog;

public:
    // Constructor
    ShoppingCart(const string& customer_id) 
        : id(generateUUID()), customer_id(customer_id) {
        
        // Initialize the catalog
        catalog["item1"] = 10.99;
        catalog["item2"] = 5.49;
        catalog["item3"] = 20.00;

        if (!isValidCustomerID(customer_id)) {
            throw invalid_argument("Invalid customer ID format.");
        }
    }

    // Getters
    string getId() const {
        return id;
    }

    string getCustomerId() const {
        return customer_id;
    }

    unordered_map<string, int> getItems() const {
        return items;
    }

    // Add or update an item
    void addItem(const string& item, int quantity) {
        if (catalog.find(item) == catalog.end()) {
            throw invalid_argument("Item not found in catalog.");
        }
        if (quantity <= 0 || quantity > 100) {
            throw invalid_argument("Quantity must be between 1 and 100.");
        }
        items[item] = quantity;
    }

    // Remove an item
    void removeItem(const string& item) {
        if (items.find(item) == items.end()) {
            throw invalid_argument("Item not found in the cart.");
        }
        items.erase(item);
    }

    // Get total cost of the cart
    double getTotalCost() const {
        double total = 0.0;
        for (unordered_map<string, int>::const_iterator it = items.begin(); it != items.end(); ++it) {
            string item = it->first;
            int quantity = it->second;
            total += catalog.at(item) * quantity;
        }
        return total;
    }
};

// Unit tests
void testShoppingCart() {
    try {
        ShoppingCart cart("ABC12345XY-A");

        // Test adding valid items
        cart.addItem("item1", 2);
        cart.addItem("item2", 5);

        // Test total cost
        double total = cart.getTotalCost();
        double expected_total = 2 * 10.99 + 5 * 5.49;
        cout << "Calculated total: " << total << "\n";
        cout << "Expected total: " << expected_total << "\n";
        assert(fabs(total - expected_total) < 1e-4);  // Use a small tolerance for comparison

        // Test removing an item
        cart.removeItem("item1");
        assert(cart.getItems().size() == 1);

        // Test invalid customer ID
        try {
            ShoppingCart invalidCart("INVALID");
        } catch (const invalid_argument& e) {
            assert(string(e.what()) == "Invalid customer ID format.");
        }

        // Test invalid item addition
        try {
            cart.addItem("nonexistent", 1);
        } catch (const invalid_argument& e) {
            assert(string(e.what()) == "Item not found in catalog.");
        }

        // Test invalid quantity
        try {
            cart.addItem("item1", 0);
        } catch (const invalid_argument& e) {
            assert(string(e.what()) == "Quantity must be between 1 and 100.");
        }

        cout << "All tests passed successfully!\n";

    } catch (const exception& e) {
        cerr << "Test failed: " << e.what() << '\n';
    }
}

int main() {
    testShoppingCart();
    return 0;
}
