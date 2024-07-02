#include <iostream>
#include <cmath>

using namespace std;

class ComplexNum
{
    private:
        double real,
               imag;
        char symbol;

    public:
        void Input();
        void Output();
        void Assign(double real, double imag, char symbol = 'i');
        void Assign(ComplexNum x);
        ComplexNum Add(ComplexNum x);
        ComplexNum Subtract(ComplexNum x);
        ComplexNum Multiply(ComplexNum x);
        ComplexNum Divide(ComplexNum x);
        bool IsEqual(ComplexNum x);
        double Magnitude();
        ComplexNum Conjugate();
};

void ComplexNum::Input()
{
    char plus_minus;
    cin >> real
        >> plus_minus
        >> imag
        >> symbol;
    if (plus_minus == '-')
    {
        imag = -imag;
    }
    return;
}

void ComplexNum::Output()
{
    cout << real;
    if (fabs(imag) > 0)
    {
        cout << ((imag > -1) ? ('+') : ('-'))
             << fabs(imag)
             << symbol;
    }
    return;
}

void ComplexNum::Assign(double a, double b, char i)
{
    real = a;
    imag = b;
    symbol = i;
    return;
}

void ComplexNum::Assign(ComplexNum y)
{
    real = y.real;
    imag = y.imag;
    symbol = y.symbol;
    return;
}

bool ComplexNum::IsEqual(ComplexNum y)
{
    return ((real == y.real) && 
            (imag == y.imag) && 
            (symbol == y.symbol));
}

ComplexNum ComplexNum::Add(ComplexNum y)
{
    ComplexNum z;
    z.real = real + y.real;
    z.imag = imag + y.imag;
    z.symbol = y.symbol;
    return z;
}

ComplexNum ComplexNum::Subtract(ComplexNum y)
{
    ComplexNum z;
    z.real = real - y.real;
    z.imag = imag - y.imag;
    z.symbol = y.symbol;
    return z;
}

ComplexNum ComplexNum::Multiply(ComplexNum y)
{
    ComplexNum z;
    z.real = (real * y.real) + (imag * y.imag);
    z.imag = imag * y.imag;
    z.symbol = y.symbol;
    return z;
}

ComplexNum ComplexNum::Divide(ComplexNum y)
{
    ComplexNum z;
    z.real = (real * y.real + imag * y.imag) / 
           (y.real * y.real + y.imag * y.imag);
    z.imag = -(real * y.real - imag * y.imag) / 
            (y.real * y.real + y.imag * y.imag);
    z.symbol = y.symbol; 
    return z;
}

double ComplexNum::Magnitude()
{
    return sqrt(real * real + imag * imag);
}

ComplexNum ComplexNum::Conjugate()
{
    ComplexNum z;
    z.real = real;
    z.imag = -imag;
    z.symbol = symbol;
    return z;
}

int main()
{
    cout << "\n\nPlease enter \'x\', a complex number of the form a + bi, \n"
            "where a and b are real numbers and i is the square root of -1:\n";
    ComplexNum complex_num_x;
    complex_num_x.Input();

    cout << "\n\nYou entered: \'";
    complex_num_x.Output();
    cout << "\'";

    cout << "\n\nPlease enter \'y\', a complex number of the form a + bi, \n"
            "where a and b are real numbers and i is the square root of -1:\n";
    ComplexNum complex_num_y;
    complex_num_y.Input();

    ComplexNum complex_num_z;

    cout << "\n\nYou entered: \'";
    complex_num_y.Output();

    char choice;

    cout << "\n\nEnter 'a' to add x and y,\n"
            "'b' to subtract x from y,\n"
            "'m' to multiply x by y,\n"
            "'d' to divide x by y,\n"
            "'mag' to get the magnitudes of x and y,\n"
            "or 'conj' to get the conjugates of x and y:\n";

    cin >> choice;

    cout << "\n";

    switch(choice)
    {
        case 'a':
            complex_num_z = complex_num_x.Add(complex_num_y);
            cout << "\n";
            complex_num_z.Output();
            break;
        case 'b':
            complex_num_z = complex_num_x.Subtract(complex_num_y);
            cout << "\n";
            complex_num_z.Output();
            break;
        case 'm':
            complex_num_z = complex_num_x.Multiply(complex_num_y);
            cout << "\n";
            complex_num_z.Output();
            break;
        case 'd':
            complex_num_z = complex_num_x.Divide(complex_num_y);
            cout << "\n";
            complex_num_z.Output();
            break;
        case 'g':
            cout << complex_num_x.Magnitude();
            cout << "\n";
            cout << complex_num_y.Magnitude();
            cout << "\n";
            break;
        case 'j':
            complex_num_z = complex_num_x.Conjugate();
            cout << "\n";
            complex_num_z.Output();
            complex_num_z = complex_num_y.Conjugate();
            cout << "\n";
            complex_num_z.Output();
            break;
    }

    cout << "\n\n";
}
