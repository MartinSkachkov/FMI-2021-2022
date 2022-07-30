#include <cmath>
#include <iostream>
using namespace std;

double fahrenheit_to_celsius(double temperature);
double fahrenheit_to_kelvin(double temperature);

void temperature_conversion(double temperature) {
    cout << "Celsius: " << fahrenheit_to_celsius(temperature) << endl;
    cout << "Kelvin: " << fahrenheit_to_kelvin(temperature) << endl;
}

int main() {
    double fahrenheitTemperature;
    cout << "Fahrenheit temp: ";
    cin >> fahrenheitTemperature;
    cout << "fahrenheit_to_celsius: " << fahrenheit_to_celsius(fahrenheitTemperature) << endl;
    cout << "fahrenheit_to_kelvin: " << fahrenheit_to_kelvin(fahrenheitTemperature) << endl;
    cout << "==================" << endl;
    temperature_conversion(fahrenheitTemperature);
    return 0;
}

double fahrenheit_to_celsius(double temperature) {  // it creates a copy (pass-by-value)
    return round((5.0 / 9.0) * (temperature - 32));
}

double fahrenheit_to_kelvin(double temperature) {
    return round ((5.0/9.0) * (temperature - 32) + 273);
}