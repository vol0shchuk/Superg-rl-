// Superg!rl​.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Shape {
public:
    virtual double calculateArea() const = 0;
};

class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    double calculateArea() const override {
        return 0.5 * base * height;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double calculateArea() const override {
        return 3.14 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double calculateArea() const override {
        return width * height;
    }
};

int main() {
    Triangle triangle(5, 4);
    Circle circle(3);
    Rectangle rectangle(6, 8);

    vector<Shape*> shapes;

    shapes.push_back(&triangle);
    shapes.push_back(&circle);
    shapes.push_back(&rectangle);

    double totalArea = 0;
    for (const auto& shape : shapes) {
        totalArea += shape->calculateArea();
    }

    cout << "Total area of all shapes: " << totalArea << endl;

    for (const auto& shape : shapes) {
        delete shape;
    }
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
