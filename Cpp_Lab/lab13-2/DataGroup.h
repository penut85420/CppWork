#include <cstring>

class DataGroup
{
public:
    DataGroup(int numberOfNames, char *names[], 
                int sizeOfArray, 
                int numberOfData, double dataArray[]);
    virtual ~DataGroup();
    void serialize(bool bOutput=true);
	void freeMemory();
private:
    virtual void openStream(bool bOutput) = 0;
    virtual void closeStream(bool bOutput) = 0;
    virtual void writeByte(unsigned char data) = 0;
	virtual unsigned char readByte() = 0;
    char  **m_names;
    int     m_numberOfNames;
    double *m_dataArray;
    int     m_dataArraySize;
    int     m_numberOfData;
};