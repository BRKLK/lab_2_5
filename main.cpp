#include<iostream>
#include<vector>
#include<cmath>


class MyVector
{
private:

    int* arr;
    int len;
    int cap;

    int nextPowerOfTwo(int n)
    {
        return pow(2, ceil(log2(n)));
    }

public:
    MyVector() : arr(nullptr), len(0), cap(0) {}

    MyVector(int n, int value)
    {
        len = n;
        cap = nextPowerOfTwo(n);
        arr = new int[cap];

        for(int i = 0; i < n; i++) arr[i] = value;
    }

    MyVector(MyVector& other)
    {
        len = other.len;
        cap = other.cap;
        arr = new int[cap];

        for (int i = 0; i < other.len; i++) {arr[i] = other.arr[i];}
    }

    int size() const
    {
        return len;
    }

    int capacity() const
    {
        return cap;
    }
    
    ~MyVector()
    {
        delete[] arr;
    }

    int& operator[](int index)
    {
        return arr[index];
    }

    void resize(int new_size, int value = 0)
    {
        if (new_size == len)
        {
            return;
        }
        

        cap = nextPowerOfTwo(new_size);
        int* new_arr = new int[cap];

        for(int i = 0; i < len && i < new_size; i++)
            new_arr[i] = arr[i];


        if (new_size > len)
            for(int i = len; i < new_size; i++) {new_arr[i] = value;}
        

        delete[] arr;
        arr = new_arr;
        len = new_size;
    }

    void reserve(int new_cap)
    {
        if(new_cap <= cap)
        {
            return;
        }

        cap = nextPowerOfTwo(new_cap);
    }

    void shrink_to_fit()
    {
        int* new_arr = new int[len];
        cap = len;

        for(int i = 0; i < len; i++) {new_arr[i] = arr[i];}

        delete arr;
        arr = new_arr;
    }

    void push_back(int value)
    {
        len++;
        int new_cap = nextPowerOfTwo(len);

        if(new_cap == cap)
        {
            arr[len-1] = value;
            return;
        }
        else
        {
            cap = new_cap;
            int* new_arr = new int[new_cap];

            for(int i = 0; i < len-1; i++) {new_arr[i] = arr[i];}

            new_arr[len-1] = value;

            delete arr;
            arr = new_arr;
        }
    }

    int& front()
    {
        return arr[0];
    }
};





int main ()
{
//   std::vector<int> myvector;

//   // set some content in the vector:
//   for (int i=0; i < 1; i++) myvector.push_back(i);

//   std::cout << "size: " << (int) myvector.size() << '\n';
//   std::cout << "capacity: " << (int) myvector.capacity() << '\n';
//   std::cout << "max_size: " << (int) myvector.max_size() << '\n';
    
    MyVector vec;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    vec[0] = 5;

    for(int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << std::endl;
    }

    // std::cout << std::endl << "Vector size: " << vec.size() << '\n';
    // std::cout << "Vector capacity: " << vec.capacity() << '\n';
    // std::cout << std::endl << "Capacity: " << vec.capacity() << std::endl;
    // std::cout << "Reserving..." << std::endl;
    // vec.reserve(4);
    // std::cout << "New capacity: " << vec.capacity() << std::endl;

    return 0;
}