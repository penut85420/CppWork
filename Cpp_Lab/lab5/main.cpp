#include <stdio.h>
#include <stdlib.h>

void printContent(void *ptr, int length) {
	int i;
	unsigned char *dataArray = (unsigned char *) ptr;
	for (i = 0; i < length; i++)
		printf("%.2d: %.2X\n", i, dataArray[i]);
}

struct DataRecord {
	double x;
	int y[4];
	char z[5];
};

void main() {
	DataRecord data;
	int i;

	data.x = 123.456;
	for (i = 0; i < 4; i++)
		data.y[i] = 123 + i;
	for (i = 0; i < 5; i++)
		data.z[i] = 'a' + i;
	// ...
	printContent(&data, sizeof(data));
	system("PAUSE");
}