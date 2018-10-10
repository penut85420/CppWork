#include <iostream>
#include <cstring>
using namespace std;

template <class Type>
class int_array_cell {
public:
    // ctor
    int_array_cell(Type* ptr) {
        _memory = ptr;
        _counter = 1;
        cout << "int_array_cell is allocated\n";
    }

    // When a pointer leave
    void release() {
        _counter--;
        if (!_counter) {
            delete _memory;
            cout << "int_array_cell counter 0: deleted\n";
        } else
            cout << "int_array_cell counter is decreased: counter "
                    << _counter << endl;
    }

    // When a pointer join
    void add() {
        cout << "int_array_cell counter is increased: counter "
                << ++_counter << endl;
    }

    // Get how many pointers point to this memory
    int getCounter() { return _counter; }

    // Use when a operator[] is called
    Type& get(int i) {
        return _memory[i];
    }

private:
	int _counter;
	Type * _memory;
};

template <class Type>
class counter_ptr {
public:
    // ctor with a memory
    counter_ptr(const char* name, Type* ptr) {
        _name = new char(sizeof(*name));
        strcpy(_name, name);
        _cell_ptr = new int_array_cell<Type>(ptr);
        print();
    }

    // ctor without memory
    counter_ptr(const char* name) {
        _name = new char(sizeof(*name));
        _cell_ptr = NULL;
        strcpy(_name, name);
        print();
    }

    // dtor
    ~counter_ptr() {
        cout << "counter_ptr " << _name << " is deleted\n";
        if (_cell_ptr != NULL)
            _cell_ptr->release();
    }

    // When assign a new memory
    void operator=(Type* ptr) {
        _cell_ptr->release();
        if (!_cell_ptr->getCounter()) delete _cell_ptr;
        _cell_ptr = new int_array_cell<Type>(ptr);
        print();
    }

    // When assign another counter_ptr
    counter_ptr& operator=(const counter_ptr& rhs) {
        this->_cell_ptr = rhs._cell_ptr;
        if (this->_cell_ptr != NULL)
            this->_cell_ptr->add();
        this->print();
        return *this;
    }

    // Get the i'th element
    Type& operator[](int i) {
        return _cell_ptr->get(i);
    }

    // To remove the holding of the memory
    void release() {
        _cell_ptr->release();
        if (!_cell_ptr->getCounter()) delete _cell_ptr;
        _cell_ptr = NULL;
        print();
    }

private:
	char * _name;
	int_array_cell<Type> * _cell_ptr;

	// Display the statue of the instance
	void print() {
	    if (_cell_ptr != NULL) {
            cout << "counter_ptr " << _name
                    << " is assigned to an int_array_cell: counter "
                    << _cell_ptr->getCounter() << endl;
	    } else {
            cout << "counter_ptr " << _name << " is not assigned to an int_array_cell\n";
	    }
	}
};



int main() {

// PART 一
    counter_ptr<int> b("b", new int[10]);
    // stdout 輸出: int_array_cell is allocated
    // stdout 輸出: counter_ptr b is assigned to an int_array_cell: counter 1
    cout << endl;
    {
        b = new int[100];
        // stdout 輸出: int_array_cell counter 0: deleted
        // stdout 輸出: int_array_cell is allocated
        // stdout 輸出: counter_ptr b is assigned to an int_array_cell: counter 1
        cout << endl;
        counter_ptr<int> a("a");
        // stdout 輸出: counter_ptr a is not assigned to an int_array_cell
        cout << endl;
        a = b;
        // stdout 輸出: int_array_cell counter is increased: counter 2
        // stdout 輸出: counter_ptr a is assigned to an int_array_cell: counter 2
        cout << endl;
    }

    // a leaves it scope:
    // stdout 輸出: counter_ptr a is deleted
    // stdout 輸出: int_array_cell counter is decreased: counter 1


// PART 二

    for (int i = 0; i < 10; i++)
        b[i] = i;

    for (int i = 0; i < 10; i++)
        cout << b[i] << ' ';
        cout << endl;
    // stdout 輸出: 0 1 2 3 4 5 6 7 8 9

    counter_ptr<int> c("c");
    // stdout 輸出: counter_ptr c is not assigned to an int_array_cell
    cout << endl;

    c = b;
    // stdout 輸出: int_array_cell counter is increased: counter 2
    // stdout 輸出: counter_ptr c is assigned to an int_array_cell: counter 2
    cout << endl;

    b.release();
    // stdout 輸出: int_array_cell counter is decreased: counter 1
    // stdout 輸出: counter_ptr b is not assigned to an int_array_cell
    cout << endl;

    return 0;
}

			// stdout 輸出: counter_ptr c is deleted
			// stdout 輸出: int_array_cell counter 0: deleted
			// stdout 輸出: counter_ptr b is deleted
