// cl -GX testCtor1.cpp

#include <iostream>
#include <iomanip>
using namespace std;

class ArrayAccessViolation
{
public:
    ArrayAccessViolation(int index, int size);
    void printError();

private:
    int m_index;
    int m_size;
};

ArrayAccessViolation::ArrayAccessViolation(int index, int size)
    : m_index(index), m_size(size)
{
}

void ArrayAccessViolation::printError()
{
    cout << "ArrayAccessViolation::" << endl;
    cout << "Try to access the " << m_index+1 <<
            "-th element of a " << m_size << "-element vector\n";
}

class Vector
{
public:
    Vector(int size);
	Vector(Vector&);
    ~Vector();
    int &operator[](int index);
    void print();
private:
    int *m_data;
    int m_size;
};

Vector::Vector(int size)
    : m_size(size), m_data(0)
{
    if (m_size>0)
    {
        m_data = new int[m_size];
        for (int i=0; i<m_size; i++)
            m_data[i] = 0;
    }
    else
        m_size = 0;
}

Vector::Vector(Vector &v)
{
	m_size = v.m_size;
    m_data = new int[m_size];
    for (int i = 0; i < m_size; i++)
		m_data[i] = v.m_data[i];
}

Vector::~Vector()
{
    delete[] m_data;
}

int& Vector::operator[](int index)
{
    if ((index < m_size)&&(index>=0))
        return m_data[index];
    throw ArrayAccessViolation(index, m_size);
}

void Vector::print()
{
    int i;
    cout << "    ============================\n   m_size=";
    cout << m_size << endl;
    for (i=0; i<m_size; i++)
    {
        cout << setw(6) << m_data[i];
        if (i%8 == 7)
            cout << endl;
    }
    if (i%8 != 7) cout << endl;
}

void doSomething(Vector data)
{
    cout << "entering function doSomething()...\n";
    data.print();
    cout << "leaving function doSomething()\n\n";
}

void doIrrelevantThings()
{
    int i;
    cout << "entering function doIrrelevantThings()...\n";
    int *ptr=new int[20];
    for (i=0; i<20; i++)
        ptr[i] = 1000 + i;
    delete[] ptr;
    cout << "leaving function doIrrelevantThings()\n\n";
}

int main()
{
    try
    {
        int i;
        Vector dataHolder(20);
        for (i=0; i<20; i++)
            dataHolder[i] = 2*i;
        dataHolder.print();

        doSomething(dataHolder);

        doIrrelevantThings();

        dataHolder.print();
    }
    catch (ArrayAccessViolation e)
    {
        e.printError();
    }
	system("PAUSE");
	return 0;
}
