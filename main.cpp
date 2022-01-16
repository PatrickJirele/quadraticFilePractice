// Patrick Jirele
// quadraticFilePractice

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void readFile(double&, double&, double&, ifstream&);
double disc(double, double, double);
double calcRoot1(double, double, double);
double calcRoot2(double, double, double);

void greeting()
{
	cout << "Welcome to Quadratic Program" << endl;
	cout << endl;
}

int main()
{
	greeting();

	double a, b, c;
	double root1, root2;

	ifstream theFile("data.txt");


	while (!theFile.eof())
	{
		readFile(a, b, c, theFile);
		if (disc(a, b, c) >= 0)
		{

			root1 = calcRoot1(a, b, c);
			root2 = calcRoot2(a, b, c);

			cout << "The roots are: " << root1 << ", " << root2 << endl;
		}
		else
		{
			cout << "No real roots " << endl;
		}
	} // end while

	theFile.close();

} // end main

void readFile(double& x, double& y, double& z, ifstream& theFile)
{
	theFile >> x >> y >> z;
} // end readFile

double disc(double x, double y, double z)
{
	return (y * y - 4 * x * z);
} // end disc

double calcRoot1(double x, double y, double z)
{
	return (-y + sqrt(y * y - 4 * x * z)) / (2 * x);
} // end root1

double calcRoot2(double x, double y, double z)
{
	return (-y - sqrt(y * y - 4 * x * z)) / (2 * x);
} // end root2
