#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>

#define M_PI 3.14159265358979323846

using namespace std;

/* For debugging perposes
 * true =>  cout to console class variables on change
 * false => do nothing
*/
bool DEBUG = true;

/* Input and output file names
 * IN_FILE  ("inData.txt")
 * OUT_FILE ("outData.txt")
*/
string IN_FILE = "inData.txt";
string OUT_FILE = "outData.txt";

/*
 * Purpose:
 * - handle the totals from all inputed rectangles.
 * - print to outData.txt when input loop is finished
*/
class Rectangles
{
public:
	// Handle a new rectangle
	void NewRectangle(float w, float l, float a, float p);
	// Set all totals to 0
	void Init();
private:
	float total_widths;
	float total_lengths;
	float total_area;
	float total_perimeter;
	// add w to total widths
	void AddWidth(float w);
	// add l to total lengths
	void AddLength(float l);
	// add a to total area
	void AddArea(float a);
	// add p to total perimeter
	void AddPerimeter(float p);
	// handle debugging
	void Debug();
};

/*
 * Purpose:
 * - handle individual rectangles
 * - calculate area
 * - calculate perimeter
 * - send final values to Rectangles
*/
class Rectangle
{
public:
	// handle new rectangle
	void Init(float w, float l, Rectangles* controller);
private:
	float width;
	float length;
	float area;
	float perimeter;
	// set width to w
	void SetWidth(float w);
	// set length to l
	void SetLength(float l);
	// set area to a
	void SetArea(float a);
	// set perimeter to p
	void SetPerimeter(float p);
	// calculate area
	float CalcArea();
	// calculate perimeter
	float CalcPerimeter();
	// handle debugging
	void Debug();
};

/*
 * Purpose:
 * - handle the totals from all inputed circles
 * - print to outData.txt when input loop is finished
*/
class Circles
{
public:
	void Init();
	void AddCircle(float a, float c, float r);
private:
	float total_radius;
	float total_area;
	float total_circumfrance;
	void AddRadius(float r);
	void AddArea(float a);
	void AddCircumfrance(float c);
	void Debug();
};

class Circle
{
public:
	void Init(float r, Circles* controller);
private:
	float radius;
	float area;
	float circumfrance;
	void SetRadius(float r);
	void SetArea(float a);
	void SetCircumfrance(float c);
	float CalcArea();
	float CalcCircumfrance();
	void Debug();
};

class Persons
{
public:
	void Init();
	void AddPerson(int a, float s);
private:
	int counter;
	int total_ages;
	float total_salaries;
	void AddAge(int a);
	void AddSalary(float s);
	void Debug();
};

class Person
{
public:
	void Init(int a, float s, Persons* controller);
private:
	int age;
	float savings;
	void SetAge(int a);
	void SetSavings(float s);
	void Debug();
};

int main()
{
	Rectangles rectangleController;
	rectangleController.Init();
	Rectangle rectangle;

	Circles circleController;
	circleController.Init();
	Circle circle;

	Persons personController;
	personController.Init();
	Person person;

	ifstream inFile;
	ofstream outFile;

	inFile.open(IN_FILE);

	double length = 0.0;
	double width = 0.0;
	double radius = 0.0;
	double totlength = 0, totwidth = 0, totarea = 0, totperimeter = 0;
	double totradius = 0, totareacir = 0, totcircum = 0;

	string firstName = "", lastName = "";
	int age = 0;
	int savings = 0;
	int i = 1;

	string strLength, strWidth, strRadius, strAge, strSaving, line;

	while (getline(inFile, line))
	{
		istringstream iss(line);
		switch (i)
		{
		case 1:
			if (!(iss >> strLength >> strWidth)) { break; }
			else
			{
				length = atof(strLength.c_str());
				width = atof(strWidth.c_str());
				rectangle.Init(width, length, &rectangleController);
				i++;
			}
			break;
		case 2:
			if (!(iss >> strRadius)) { break; }
			else
			{
				radius = atof(strRadius.c_str());
				circle.Init(radius, &circleController);
				i++;
			}
			break;
		case 3:
			if (!(iss >> firstName >> lastName >> strAge)) { break; }
			else
			{
				age = atof(strAge.c_str());
				i++;
			}
			break;
		case 4:
			if (!(iss >> strSaving)) { break; }
			else
			{
				savings = atof(strSaving.c_str());
				i = 1;
			}
			break;
		}

		rectangle.Init(length, width, &rectangleController);
		circle.Init(radius, &circleController);
		person.Init(age, savings, &personController);

	}

	system("PAUSE");
	return 0;
}

void Rectangles::AddWidth(float w) { total_widths += w; }
void Rectangles::AddLength(float l) { total_lengths += l; }
void Rectangles::AddArea(float a) { total_area += a; }
void Rectangles::AddPerimeter(float p) { total_perimeter += p; }
void Rectangles::NewRectangle(float w, float l, float a, float p)
{
	AddWidth(w);
	AddLength(l);
	AddArea(a);
	AddPerimeter(p);
	if (DEBUG) { Debug(); }
}
void Rectangles::Debug()
{
	cout << endl << "--- Rectangles Controller ---" << endl;
	cout << "Total widths:     " << total_widths << endl;
	cout << "Total lengths:    " << total_lengths << endl;
	cout << "Total areas:      " << total_area << endl;
	cout << "Total perimeters: " << total_perimeter << endl;
	cout << "--- END ---" << endl;
}
void Rectangles::Init()
{
	total_widths = 0;
	total_lengths = 0;
	total_area = 0;
	total_perimeter = 0;
}

void Rectangle::SetWidth(float w) { width = w; }
void Rectangle::SetLength(float l) { length = l; }
void Rectangle::SetArea(float a) { area = a; }
void Rectangle::SetPerimeter(float p) { perimeter = p; }
float Rectangle::CalcArea() { return width * length; }
float Rectangle::CalcPerimeter() { return (2 * width) + (2 * length); }
void Rectangle::Debug()
{
	cout << endl << "--- Rectangle ---" << endl;
	cout << "Width:     " << width << endl;
	cout << "Length:    " << length << endl;
	cout << "Area:      " << area << endl;
	cout << "Perimeter: " << perimeter << endl;
	cout << "--- End ---" << endl;
}
void Rectangle::Init(float w, float l, Rectangles* controller)
{
	SetWidth(w);
	SetLength(l);
	SetArea(CalcArea());
	SetPerimeter(CalcPerimeter());
	controller->NewRectangle(width, length, area, perimeter);
	if (DEBUG) { Debug(); }
}

void Circles::AddArea(float a) { total_area += a; }
void Circles::AddCircumfrance(float c) { total_circumfrance += c; }
void Circles::AddRadius(float r) { total_radius += r; }
void Circles::AddCircle(float a, float c, float r)
{
	AddArea(a);
	AddCircumfrance(c);
	AddRadius(r);
	if (DEBUG) { Debug(); }
}
void Circles::Debug()
{
	cout << endl << "--- Circles Controller ---" << endl;
	cout << "Total Area:         " << total_area << endl;
	cout << "Total Circumfrance: " << total_circumfrance << endl;
	cout << "Total Radius:       " << total_radius << endl;
	cout << endl << "--- END ---" << endl;
}
void Circles::Init()
{
	total_area = 0;
	total_circumfrance = 0;
	total_radius = 0;
}

void Circle::SetRadius(float r) { radius = r; }
void Circle::SetCircumfrance(float c) { circumfrance = c; }
void Circle::SetArea(float a) { area = a; }
float Circle::CalcArea() { return M_PI * radius * radius; }
float Circle::CalcCircumfrance() { return M_PI * (radius * 2); }
void Circle::Debug()
{
	cout << endl << "--- New Circle ---" << endl;
	cout << "Radius:       " << radius << endl;
	cout << "Circumfrance: " << circumfrance << endl;
	cout << "Area:         " << area << endl;
	cout << endl << "--- END ---" << endl;
}
void Circle::Init(float r, Circles* controller)
{
	SetRadius(r);
	SetArea(CalcArea());
	SetCircumfrance(CalcCircumfrance());
	controller->AddCircle(area, circumfrance, radius);
	if (DEBUG) { Debug(); }
}

void Persons::AddAge(int a) { total_ages += a; }
void Persons::AddSalary(float s) { total_salaries += s; }
void Persons::AddPerson(int a, float s)
{
	AddAge(a);
	AddSalary(s);
	counter++;
	if (DEBUG) { Debug(); }
}
void Persons::Debug()
{
	cout << endl << "--- Person Controller ---" << endl;
	cout << "Total ages:        " << total_ages << endl;
	cout << "Total salaries:    " << total_salaries << endl;
	cout << "Number of persons: " << counter << endl;
	cout << endl << "--- END ---" << endl;
}
void Persons::Init()
{
	total_ages = 0;
	total_salaries = 0;
	counter = 0;
}

void Person::SetAge(int a) { age = a; }
void Person::SetSavings(float s) { savings = s; }
void Person::Debug()
{
	cout << endl << "--- New Person ---" << endl;
	cout << "Age:     " << age << endl;
	cout << "Savings: " << savings << endl;
	cout << endl << "--- END ---" << endl;
}
void Person::Init(int a, float s, Persons* controller)
{
	SetAge(a);
	SetSavings(s);
	controller->AddPerson(age, savings);
	if (DEBUG) { Debug(); }
}
