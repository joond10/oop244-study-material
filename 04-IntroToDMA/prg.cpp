#include <iostream>

using namespace std;

int main() {
    /*
    int a[6] = { 1, 2, 3, 4, 5, 6 };
    int* p = &a[2];
    cout << *p << endl;         // Outputs the value at index 2, which is 3

    for (int i = 0; i < 4; i++) {
        cout << p[i] << endl;   // Accesses the values at where p is now pointing to and moves through the subsequent elements
    }

    /*
    You are iterating through the array of integers pointed to by p, 
    and using p[i] correctly accesses the values at successive indices. 
    The key is to think of it as moving i steps from the starting point p in terms of memory locations.
    */

    int cnt{};           // Notice we don't need assignment operator, this sets value to 0 in C++
    int* nums = nullptr; // Notice how we use nullptr instead of NULL

    // We don't know how many integers are going to be entered so the system doesn't know
    // at compile time how much memory to allocate. It must be dynamically allocated during
    // runtime. cnt will be used to size.
    
    //A pointer to type int called nums initalized to a safe state (nullptr)

    //When do we need DMA
    //1. When you don't know how much memory you want 
    cout << "Reverser!" << endl;
    cout << "Enter the number of integers: ";
    cin >> cnt;

    // The pointer is saying give me new memory of type int for as many as what the user enters for cnt!
    nums = new int[cnt];// new is a call to the OS to give you new memory of specified type and how many
    // nums is being initailized as an array in this line and we can use it as such!

    if (nums == nullptr) { //If there is not enough memory to allocate, it will stay nullptr
        cout << "Not enough memory!" << endl;
    }
    else {  //else if there was memory to allocate, nums will become the address of the first element in cnt[]
        int i;
        cout << "Enter the numbers: " << endl; // Getting inpput
        for (i = 0; i < cnt; i++) {
            cout << (i + 1) << "> ";
            cin >> nums[i];
        }
        for (i = cnt - 1; i >= 0; i--) {      // Displaying input
            cout << nums[i] << " ";
        }
        cout << endl;
    }

    delete[] nums;      // To ensure no memory leaks, we delete the way we allocate
    //2. 
    return 0;
}
