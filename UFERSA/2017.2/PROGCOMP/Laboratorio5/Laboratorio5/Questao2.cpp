#include <iostream>
using namespace std;

float celsiusParaFahrenheit(float);

int main()
{
	float temperaturaCelsius;

	cout << "Digite uma temperatura em graus Celsius: ";
	cin >> temperaturaCelsius;
	cout << temperaturaCelsius << " graus Celsius equivalem a "
		<< celsiusParaFahrenheit(temperaturaCelsius) << " graus Fahrenheit.\n";

	system("pause");
	return 0;
}

float celsiusParaFahrenheit(float celsius)
{
	return 1.8 * celsius + 32.0;
}