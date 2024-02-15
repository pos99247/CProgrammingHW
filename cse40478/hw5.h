// Brian Nam U08673167
// nam.bbrian@gmail.com
// CSE - 40478 C/C++ Programming IV
// HW 4
// hw5.h

#ifndef HW5_H
#define HW5_H

template <typename X>
class auto_ptr
{
    X *ptr;

public:
    // Constructors
    explicit auto_ptr(X *p = 0) throw() : ptr(p)
    {

    }

    auto_ptr(auto_ptr &a) throw() : ptr(a.release())
    {

    }

    template <typename Y> auto_ptr(auto_ptr<Y> &a) throw() : ptr(a.release())
    {

    }

    // Destructor
    ~auto_ptr()
    {
        delete ptr;
    }

    // Access
    X *get() const throw()
    {
        return ptr;
    }

    X &operator*() const throw()
    {
        return *ptr;
    }

    X *operator->() const throw()
    {
        return ptr;
    }

    // Assignment
    auto_ptr &operator=(auto_ptr &a) throw()
    {
        if (this != &a)
        {
            delete ptr;
            ptr = a.release();
        }
        return *this;
    }

    template <typename Y> auto_ptr &operator=(auto_ptr<Y> &a) throw()
    {
        if (ptr != a.get())
        {
            delete ptr;
            ptr = a.release();
        }
    }

    // Release & Reset
    X *release() throw()
    {
        X *tmp = ptr;
        ptr = 0;
        return tmp;
    }

    void reset(X *p = 0) throw()
    {
        if (ptr != p)
        {
            delete ptr;
            ptr = p;
        }
    }
};

#endif // !HW5_H
