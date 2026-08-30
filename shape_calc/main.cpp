#include <iostream>
#include <vector>
#include <memory>

class Shape {
public:
  virtual ~Shape() = default;
  virtual double getArea() const = 0;
};

class Rectangle : public Shape {
private:
  double width;
  double height;
public:
  Rectangle(double w, double h) {
    width = w;
    height = h;
  }

  double getArea() const override {
    return width * height;
  }
};

class Circle : public Shape {
private:
  double radius;

public:
  Circle(double r) { radius = r; }

  double getArea() const override {
    return 3.14159 * radius * radius;
  }
};

int main() {
  std::vector<std::unique_ptr<Shape>> shapes;

  shapes.push_back(std::make_unique<Rectangle>(4.0, 5.0));
  shapes.push_back(std::make_unique<Circle>(3.0));

  for (const auto& shape : shapes) {
    std::cout << "Shape area: " << shape->getArea() << "\n";
  }
  return 0;
}
