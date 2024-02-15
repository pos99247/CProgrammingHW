// Brian Nam U08673167
// nam.bbrian@gmail.com
// CSE - 40478 C/C++ Programming IV
// HW 2

#include <cassert>
#include <iostream>
using namespace std;

template <typename T>
class Queue
{
public:
    Queue(); // Construct empty queue
    ~Queue(); // Destructor
    Queue(const Queue &); // Copy constructor
    Queue &operator=(const Queue &); // Copy assignment operator
    void push(const T &); // Add elem to back of queue
    void pop(); // Remove front elem from queue
    T &front(); // Return ref to front elem in queue
    const T &front() const; // Return ref to front elem in queue
    bool empty() const; // Return whether queue is empty
    size_t size() const; // Return # of elems in queue
private:
    T *v_; // Elems in queue
    size_t vsize_;
    size_t vused_;
    size_t front_;
    size_t back_;
};

template <typename T>
Queue<T>::Queue()
    : v_(0),
    vsize_(10),
    vused_(0),
    front_(0),
    back_(0)
{
    v_ = new T[vsize_];
}

template <typename T>
Queue<T>::~Queue()
{
    delete[] v_;
}

template <typename T>
T *
newCopy(const T *src, size_t srcsize, size_t destsize)
{
    assert(destsize >= srcsize);
    T *dest = new T[destsize];
    try
    {
        copy(src, src + srcsize, dest);
    }
    catch (...)
    {
        delete[] dest;
        throw;
    }
    return dest;
}

template <typename T>
Queue<T>::Queue(const Queue &other)
    : v_(newCopy(other.v_,
        other.vused_,
        other.vsize_)),
    vsize_(other.vsize_),
    vused_(other.vused_),
    front_(other.front_),
    back_(other.back_)
{

}

template <typename T>
Queue<T> &
Queue<T>::operator=(const Queue<T> &other)
{
    if (this != &other)
    {
        T *v_new = newCopy(other.v_,
                           other.vused_,
                           other.vsize_);
        delete[] v_;
        v_ = v_new;
        vsize_ = other.vsize_;
        vused_ = other.vused_;
        front_ = other.front_;
        back_ = other.back_;
    }
    return *this;
}

template <typename T>
void
Queue<T>::push(const T &value)
{
    if (vused_ == vsize_)
    {
        size_t vsize_new = vsize_ * 2 + 1;
        T *v_new = newCopy(v_, vsize_, vsize_new);
        delete[] v_;
        v_ = v_new;
        vsize_ = vsize_new;
        front_ = 0;
        back_ = vused_;
    }
    v_[back_] = value;
    back_ = (back_ + 1) % vsize_;
    ++vused_;
}

template <typename T>
void
Queue<T>::pop()
{
    if (vused_ == 0)
    {
        throw logic_error("pop from empty stack");
    }
    else
    {
        front_ = (front_ + 1) % vsize_;
        --vused_;
    }
}

template <typename T>
T &
Queue<T>::front()
{
    if (vused_ == 0)
    {
        throw logic_error("pop from empty stack");
    }
    else
    {
        return v_[front_];
    }
}

template <typename T>
const T &
Queue<T>::front() const
{
    if (vused_ == 0)
    {
        throw logic_error("pop from empty stack");
    }
    else
    {
        return v_[front_];
    }
}

template <typename T>
bool
Queue<T>::empty() const
{
    return vused_ == 0;
}

template <typename T>
size_t
Queue<T>::size() const
{
    return vused_;
}

void testQueueConstructAndDestruct()
{
    Queue<int> q;
    assert(q.empty());

    cout << "testQueueConstructAndDestruct PASSED" << '\n';
}

void testQueueCopyConstruct()
{
    Queue<int> q1;
    q1.push(1);
    q1.push(2);

    Queue<int> q2(q1);       // Copy constructor
    assert(q2.size() == 2);  // check if q2 size = q1 size
    assert(q2.front() == 1); // Check if first element is same as q1, 1 here

    cout << "testQueueCopyConstruct PASSED" << '\n';
}

void testQueueCopyAssignment()
{
    Queue<int> q1;
    q1.push(1);
    q1.push(2);

    Queue<int> q2;
    q2 = q1;                 // Copy assignment
    assert(q2.size() == 2);  // check if q2 size = q1 size
    assert(q2.front() == 1); // Check if first element is same as q1, 1 here

    cout << "testQueueCopyAssignment PASSED" << '\n';
}

void testQueuePushAndPop()
{
    Queue<int> q;
    q.push(1);
    q.push(2);

    assert(q.size() == 2);  // Check size to confirm push is working
    cout << "testQueuePush PASSED" << '\n';

    q.pop();
    assert(q.front() == 2); // Check front element after pop
    cout << "testQueuePop PASSED" << '\n';
}

void testQueueFront()
{
    Queue<int> q;
    q.push(1);
    q.push(2);

    assert(q.front() == 1);
    cout << "testQueueFront PASSED" << '\n';

    const Queue<int> constQ = q;
    assert(constQ.front() == 1);
    cout << "testQueueFront for const PASSED" << '\n';
}

void testQueueEmptyAndSize()
{
    Queue<int> q;
    assert(q.empty());       // Check if empty
    cout << "testQueueEmpty PASSED" << '\n';

    q.push(1);
    assert(q.size() == 1);   // Check if size is 1 after pushing 1 element
    cout << "testQueueSize PASSED" << '\n';
}

int main()
{
    testQueueConstructAndDestruct();
    testQueueCopyConstruct();
    testQueueCopyAssignment();
    testQueuePushAndPop();
    testQueueFront();
    testQueueEmptyAndSize();
}
