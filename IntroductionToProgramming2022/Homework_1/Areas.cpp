#include <cmath>
#include <iostream>
using namespace std;

double RoundNumber(double value, unsigned int prec);

unsigned int const Prec = 3;
int const CircleRadius = 4;
double const CircleTriangleLength =
    RoundNumber(sqrt(pow(CircleRadius, 2) / 2), Prec);
int const RectangleMinX = -2, RectangleMaxX = 2;
int const RectangleMinY = -7, RectangleMaxY = -6;

bool IsPointInGrayArea(double x, double y) {
    return x >= RectangleMinX && x <= RectangleMaxX && y >= RectangleMinY &&
           y <= RectangleMaxY;
}

bool IsPointInPurpleArea(double x, double y) {
    return x > CircleTriangleLength && x <= CircleRadius;
}

bool IsPointInBlueArea(double x, double y) {
    return x > -CircleTriangleLength && x < 0 && y > -CircleRadius && y < 0 &&
           x > y;
}

bool IsPointInRedArea(double x, double y) {
    return x > -CircleTriangleLength && x < 0 && y > 0 && y < CircleRadius &&
           abs(x) < abs(y);
}

bool IsPointInGreenArea(double x, double y) {
    return x > 0 && x < CircleTriangleLength && y > 0 && y < CircleRadius &&
           abs(x) < abs(y);
}

bool IsPointInPinkArea(double x, double y) {
    return x >= -CircleTriangleLength && x < 0 && abs(y) < abs(x);
}

bool IsPointInYellowArea(double x, double y) {
    return x > 0 && x < CircleTriangleLength &&
           (y < 0 || (y > 0 && y <= CircleTriangleLength && y < x));
}

bool IsPointInCircleArea(double x, double y) {
    return x >= -CircleTriangleLength && x <= CircleRadius &&
           y >= -CircleRadius && y <= CircleRadius &&
           sqrt(pow(x, 2) + pow(y, 2)) <= CircleRadius;
}

double RoundNumber(double value, unsigned int prec) {
    double powNumber = pow(10.0f, prec);
    return round(value * powNumber) / powNumber;
}

int main() {
    double x, y;
    std::cout << "Input point coordinates (x, y):" << std::endl;
    std::cin >> x >> y;
    x = RoundNumber(x, Prec);
    y = RoundNumber(y, Prec);
    if (IsPointInGrayArea(x, y)) {
        std::cout << "Point is in gray area.";
    } else if (IsPointInCircleArea(x, y)) {
        if (IsPointInPurpleArea(x, y)) {
            std::cout << "Point is in purple area.";
        } else if (IsPointInBlueArea(x, y)) {
            std::cout << "Point is in blue area.";
        } else if (IsPointInGreenArea(x, y)) {
            std::cout << "Point is in green area.";
        } else if (IsPointInRedArea(x, y)) {
            std::cout << "Point is in red area.";
        } else if (IsPointInPinkArea(x, y)) {
            std::cout << "Point is in pink area.";
        } else if (IsPointInYellowArea(x, y)) {
            std::cout << "Point is in yellow area.";
        } else {
            std::cout << "Point is not in any area.";
        }
    } else {
        std::cout << "Point is not in any area.";
    }
}