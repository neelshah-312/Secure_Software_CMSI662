# Secure_Software_CMSI662
A simple and efficient C++ ShoppingCart system with item management, cost calculation, and customer ID validation.
ShoppingCart System

# ShoppingCart System

## Overview
This is a simple C++ implementation of a ShoppingCart system that supports:
- Adding and removing items
- Calculating the total cost
- Validating customer IDs
- Generating a unique cart ID
- Running unit tests to verify functionality

## Features
- **Immutable Cart ID**: Each cart is assigned a unique UUID.
- **Customer ID Validation**: Ensures customer ID follows a specific format.
- **Item Catalog**: Predefined item list with prices.
- **Item Management**: Add, update, and remove items.
- **Total Cost Calculation**: Computes the total price of items in the cart.
- **Unit Tests**: Verifies functionality using assertions.

## Prerequisites
- C++ compiler supporting C++11 or later (e.g., GCC, Clang, MSVC)

## How to Compile and Run

### Compile
```sh
g++ -o ShoppingCart main.cpp
```

### Run
```sh
./ShoppingCart
```

## Expected Output
```sh
Calculated total: <computed_total>
Expected total: <expected_total>
All tests passed successfully!
```
## Screenshot of the output
Below is a screenshot of the expected output when running the program:

<img width="1470" alt="Screenshot 2025-01-31 at 1 05 59 PM" src="https://github.com/user-attachments/assets/e8d86527-9a9e-4e86-97ed-189f5c41f7b7" />

## File Structure
- `main.cpp`: Contains the ShoppingCart class implementation and test cases.
- `README.md`: This file containing documentation.

## Code Explanation
- `ShoppingCart`: Implements shopping cart functionality.
- `generateUUID()`: Generates a unique ID for each cart.
- `isValidCustomerID()`: Validates customer ID format.
- `addItem()`: Adds an item with a specific quantity.
- `removeItem()`: Removes an item from the cart.
- `getTotalCost()`: Calculates the total cart cost.
- `testShoppingCart()`: Runs unit tests to verify correctness.

## Assistance and Effort
I have worked hard on this code and taken assistance from ChatGPT to improve and refine the implementation.

