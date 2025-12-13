# Car Dealership Program 

## Description

This C++ program simulates a car dealership system using object-oriented programming (OOP) concepts. It demonstrates the implementation of class member functions, operator overloading, and friend functions. The program includes:
- A `car` class with member functions to set and get car details, calculate car purchase totals (including tax), and generate a random ID for each car.
- Overloaded operators for calculating the average price of two cars and comparing their prices.
- An interactive menu where users can select a car, input the quantity to purchase, and view the purchase details.

This project builds on concepts from previous assignments, with the addition of operator overloads and friend functions to modify and interact with private data members.

## Features

- **Car Class**: Represents a car with attributes such as brand, model, price, and year.
- **Constructors**: Includes both a default constructor and an explicit value constructor to initialize car objects.
- **Random ID Generation**: Each car object receives a unique ID, randomly generated between 1 and 10,000.
- **Purchase Calculation**: Calculates the total cost, including sales tax (6%), for a specified quantity of cars.
- **Operator Overloading**: Implements the following operator overloads:
  - `+`: Calculates the average price of two cars.
  - `<`: Compares the prices of two cars to determine which is cheaper.
- **Friend Functions**: Provides access to private data members for the purpose of operator overloading
