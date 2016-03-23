struct SaleItem {
	int size;
	void (*print)(SaleItem*);
	unsigned char data[1];
};

struct Book {
	int size;
	void (*print)(SaleItem*);
	char  title[80];
    char author[30];
    char publisher[30];
    char year[5];
    double price;
};

struct Magazine {
	int size;
	void (*print)(SaleItem *);
	char title[80];
	char issue[10];
	char year[5];
	char month[3];
	char publisher[30];
	double price;
};

struct VCD {
	int size;
	void (*print)(SaleItem *);
	char title[80];
	char seriesTitle[80];
	char casts[60];
	char year[5];
	char producer[30];
	double price;
};

void printBook(struct SaleItem*);
void printMagazine(struct SaleItem*);
void printVCD(struct SaleItem*);
void initialize(int*, struct SaleItem*[]);