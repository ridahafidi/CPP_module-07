#include <exception>

template <typename T> class Array
{
    private:
        unsigned int length;
        T *a;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &other);
        Array &operator=(const Array &other);
        ~Array();
        T& operator[](unsigned int index);
        unsigned int size () const;
        class OutOfRange : public std::exception {
            public:
                const char* what() const throw();
        };
};

template <typename T>
unsigned int Array<T>::size() const
{
    return (length);
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= length)
        throw OutOfRange();
    return (a[index]);
}

template <typename T>
const char* Array<T>::OutOfRange::what() const throw()
{
    return "Index is out of range";
}

template <typename T>
Array<T>::Array():length(0), a(nullptr)
{}

template <typename T>
Array<T>::Array(unsigned int n):length(n), a(new T[length])
{
    unsigned int i = 0;
    while (i < length)
    {
        a[i] = T();
        i++;
    }
}
template <typename T>
Array<T>::Array(const Array &other) : length(other.length), a(new T[other.length]) {
    unsigned int i = 0;
    while (i < length)
    {
        a[i] = other.a[i];
        i++;
    }
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
    if (this != &other)
    {
        delete[] a;
        length = other.length;
        a = new T[length];
        unsigned int i = 0;
        while (i < length)
        {
           a[i] = other.a[i];
           i++;
        }
    }
    return (*this);
}

template <typename T>
Array<T>::~Array()
{
    delete[] a;
}


