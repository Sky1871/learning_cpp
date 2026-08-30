#include <iostream>

class Vector2D {
public:
  double x;
  double y;

  Vector2D(double x_val, double y_val) {
    x = x_val;
    y = y_val;
  }
  Vector2D operator+(const Vector2D& other) const {
    double new_x = this->x + other.x;
    double new_y = this->y + other.y;

    return Vector2D(new_x, new_y);
  }
};

std::ostream& operator<<(std::ostream& os, const Vector2D vec) {
  os << "(" << vec.x << ", " << vec.y << ")";
  return os;
}

int main() {
  Vector2D v1(2.5, 3.0);
  Vector2D v2(1.5, 4.0);

  Vector2D v3 = v1 + v2;

  std::cout << "v1: " << v1 << "\n";
  std::cout << "v2: " << v2 << "\n";
  std::cout << "v1 + v2 = " << v3 << "\n";

  return 0;
}
