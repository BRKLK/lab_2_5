#include<iostream>
#include<vector>
#include<cmath>


template <typename T>
class MyVector
{
private:

    T* arr;
    int len;
    int cap;

    int nextPowerOfTwo(int n)
    {
        return pow(2, ceil(log2(n)));
    }

public:
    MyVector() : arr(nullptr), len(0), cap(0) {}

    MyVector(int n, T value)
    {
        len = n;
        cap = nextPowerOfTwo(n);
        arr = new T[cap];

        for(int i = 0; i < n; i++) arr[i] = value;
    }

    MyVector(MyVector& other)
    {
        len = other.len;
        cap = other.cap;
        arr = new T[cap];

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
        int* new_arr = new T[cap];

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
        T* new_arr = new T[len];
        cap = len;

        for(int i = 0; i < len; i++) {new_arr[i] = arr[i];}

        delete arr;
        arr = new_arr;
    }

    void push_back(T value)
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
            T* new_arr = new T[new_cap];

            for(int i = 0; i < len-1; i++) {new_arr[i] = arr[i];}

            new_arr[len-1] = value;

            delete arr;
            arr = new_arr;
        }
    }

    void insert(int index, T value)
    {
        len++;
        T new_cap = nextPowerOfTwo(len);

        if(new_cap == cap)
        {
            for(int i = len-1; i > index; i--) {arr[i] = arr[i-1];}

            arr[index] = value;
        }
        else
        {
            T* new_arr = new T[new_cap];
            cap = new_cap;

            for(int i = 0; i < index; i++) {new_arr[i] = arr[i];}

            new_arr[index] = value;

            for(int i = index; i < len-1; i++) {new_arr[i+1] = arr[i];}

            delete arr;
            arr = new_arr;
        }
    }

    void erase(int pos)
    {
        len--;
        int new_cap = nextPowerOfTwo(len);

        if(new_cap == cap)
        {
            for(int i = pos; i < len+1; i++) {arr[i] = arr[i+1];}
        }
        else
        {
            T* new_arr = new T[new_cap];
            cap = new_cap;

            for(int i = 0; i < pos; i++) {new_arr[i] = arr[i];}

            for(int i = pos+1; i < len+1; i++) {new_arr[i-1] = arr[i];}

            delete arr;
            arr = new_arr;
        }
    }

    void erase(int first, int last)
    {
        int new_len = len - (last - first) - 1;
        int new_cap = nextPowerOfTwo(new_len);

        if(new_cap == cap)
        {
            for(int i = 0; (last + i + 1) < len; i++)
            {
                arr[first+i] = arr[last + i + 1];
            }

            len = new_len;
        }
        else
        {
            T* new_arr = new T[new_cap];
            cap = new_cap;

            for(int i = 0; i < first; i++) {new_arr[i] = arr[i];}

            for(int i = last + 1; i < len; i++) {new_arr[i - 1 - (last - first)] = arr[i];}

            len = new_len;
            delete arr;
            arr = new_arr;
        }

    }

    int& front() {return arr[0];}
    int& back() {return arr[len-1];}

    bool empty() {return len == 0;}

};





int main ()
{
    
    MyVector<int> vec;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(7);
    vec.push_back(8);
    vec.push_back(9);
    vec.push_back(10);

    for(int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << std::endl;
    } 

    std::cout << "Front" << vec.front();
    std::cout << "Back: " << vec.back();
    std::cout << "Is empty: " << vec.empty();
    std::cout << std::endl << "Vector size: " << vec.size() << '\n';
    std::cout << "Vector capacity: " << vec.capacity() << '\n';
    std::cout << "Reserving..." << std::endl;
    vec.reserve(4);
    std::cout << "New capacity: " << vec.capacity() << std::endl;

    std::cout << "Inserting..." << '\n';
    vec.insert(2, 123);

    for(int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << std::endl;
    }
    
    
    std::cout << "Resizing..." << '\n';
    vec.resize(8);

    for(int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << std::endl;
    }


    std::cout << "Erasing..." << '\n';
    vec.erase(2, 5);

    for(int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << std::endl;
    }

    return 0;
}