///////////////////////////////////////////////////////////////////////////////
// Demo: CPP-02.01D - Memory Leak                                            //
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main()
{
    char* pbuffer = 0;

    for (int i=0; i<10; i++)
    {
        // allocate buffer
        cout << "Allocating 4KB ..." << endl;
        pbuffer = new char[4096]; // 1 char = 1 Byte, 1024 = 1K
        cin.get(); // Get unformatted data from input stream (extracts a character).

        // use buffer ...
    }

    // delete buffer
    delete[] pbuffer;

    cout << "Allocation completed" << endl;
    cin.get();

    return 0;
}
