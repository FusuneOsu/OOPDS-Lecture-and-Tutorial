#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int SIZE = 5;

struct Point{
    int x;            //4 bytes
    int y;            //4 bytes   
    char name[20];    //20 bytes
};

void writeArray(Point arr[], string name){
    fstream outfile(name, ios::out|ios::binary);

    for (int i=0; i<SIZE; i++){
        char *buffer = reinterpret_cast<char*>(&arr[i]);
        outfile.write(buffer, sizeof(arr[i]));
    }

    outfile.close();
}

void printFile(string name){
    fstream infile(name, ios::in|ios::binary);

    char buffer[sizeof(Point)];
    while (infile.read(buffer, sizeof(Point)))
    {
        Point *pt = reinterpret_cast<Point*>(buffer);
        cout << pt->x << ":"
             << pt->y << ":"
             << pt->name << endl;
    }

    infile.close();
}


void readArray(Point arr[], string name){
    fstream infile(name, ios::in|ios::binary);

    char buffer[sizeof(Point)];
    int i = 0;
    while (infile.read(buffer, sizeof(Point)))
    {
        Point *pt = reinterpret_cast<Point*>(buffer);

        arr[i].x = pt->x;
        arr[i].y = pt->y;
        memcpy(arr[i].name, pt->name, sizeof(pt->name));

        i++;
    }

    infile.close();
}

int getFileSize(string name){
    fstream infile(name, ios::in|ios::binary);
    infile.seekg(0, ios::end); // move the read head to the end
                               // the file (last byte in the file)
    int length = infile.tellg(); // tell me which byte is this
    infile.close();

    return length;
}


Point readFileItem(string name, int num)
{
    fstream infile(name, ios::in|ios::binary);

    // jump to the start of the 3rd block
    // in the file (move the read head)
    infile.seekg(num*sizeof(Point)); 

    // perform the reading of 28 bytes
    char buffer[sizeof(Point)];
    infile.read(buffer, sizeof(Point));

    infile.close();

    // convert the buffer into a Point object
    // pointed at by p (pointer)
    Point *p = reinterpret_cast<Point*>(buffer);

    return *p;   // return the object pointed at by p
}

int main()
{
    Point p[SIZE] {
        {10, 20, "A"},
        {2, 11, "B"},
        {6, 5, "C"},
        {8, 4, "D"},
        {2, 9, "E"},
    };

    writeArray(p, "data.bin");

    printFile("data.bin");

    Point dd[SIZE];
    readArray(dd, "data.bin");

    for (auto pp : dd)
        cout << pp.x << ":"
             << pp.y << ":"
             << pp.name << endl;

    int fsize = getFileSize("data.bin");
    cout << "file size in bytes = " << fsize << endl 
         << "It contains " << (fsize/sizeof(Point))
         << " Point objects" << endl;

    Point ptp = readFileItem("data.bin", 3);
    cout << ptp.x << ":"
             << ptp.y << ":"
             << ptp.name << endl;
    return 0;
}