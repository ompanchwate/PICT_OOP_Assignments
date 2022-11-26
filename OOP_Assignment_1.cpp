/*Implement a class Complex which represents the Complex Number data type. 
Implement the following 
1. Constructor (including a default constructor which creates the complex number 0+0i). 
2. Overload operator+ to add two complex numbers. 
3. Overload operator* to multiply two complex numbers. 
4. Overload operators << and >> to print and read Complex Numbers.
*/
#include<iostream>
using namespace std;

class Complex
{	
	private : 
		int real;
		int img;
		
	public:
		
		// Constructor
		Complex(int r = 0, int i=0)
		{
			real = r;
			img = i;
		}
		
		// Overloading + Operator	
		Complex operator +(Complex c2)
		{
			Complex op;
			op.real = real + c2.real;
			op.img = img + c2.img;
			
			return op;
		}
		
		// Overloading * Operator
		Complex operator *(Complex c2)
		{
			Complex op;
			op.real = real * c2.real;
			op.img = img * c2.img;
			
			return op;
		}
		
		// Declaring >> and << operators as friend function to access the private data members of Complex class
		friend istream& operator >>(istream& input, Complex& value);
		friend ostream & operator <<(ostream &out, const Complex &c);		
		
};


// Overloading >> Operator to take input 
istream& operator >>(istream& input, Complex& value)
{
	cout<<"Enter the real part : ";
	input >> value.real;
	cout<<"Enter the img part : ";
	input >> value.img;
	
	return input ;
}

// Overloading << Operator to display output
ostream & operator << (ostream &out, const Complex &value)
{
    out <<value.real<< " + " << value.img << "i" << endl;
    return out;
}

// Main Function
int main()
{
	Complex c1, c2, c3;  // Creating Objects

	// taking Input directly into an object using >> operator overloading
	cin >> c1;  
	cin >> c2; 
	
	// Printing the values of objects using << operator overloading
	cout << c1;
	cout << c2;


	// MENU	
	bool exit = false;
	
	while(exit != true)
	{
		cout<<"------------MENU------------------"<<endl;
		cout<<"1) Adding two Complex Numbers"<<endl;
		cout<<"2) Multiplying two Cmplex Numbers"<<endl;
		cout<<"3) Exit"<<endl;
		cout<<"----------------------------------"<<endl;
		
		int choice;
		cout<<"Enter your Choice :";
		cin >> choice;
		
		switch(choice)
		{
			case 1: cout<<"Sum = ";
					c3 = c1 + c2;  // Using + operator overloading
					cout << c3;  // Printing the output using << operator overlaoding 
					break;
			
			case 2: cout<<"Product = ";
					c3 = c1 * c2; // Suing * operator overlaoding
					cout << c3; // Printing the output using  << Operator overloading
					break;
					
			case 3: exit = true;
					break;
			
			default:
				cout<<"Invalid Input!";
				break;
		}
	}
}
