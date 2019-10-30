#include<iostream>
#include<string.h>

using namespace std;

//The template class definition for smart pointer
template<class T>
class AUTO_PTR 
{
    public:
        // typedef T element_type;
        //ctor
        explicit AUTO_PTR(T *pVal = 0) throw()
        {
            if(pVal)
                m_AutoPtr = pVal;
            else
                m_AutoPtr = NULL;
        }
        //copy ctor
        AUTO_PTR(const AUTO_PTR<T>& ptrCopy) throw()
        {
            if(ptrCopy.m_AutoPtr != NULL)
                m_AutoPtr = ptrCopy.m_AutoPtr;
            else
                m_AutoPtr = 0;
        }
        //overloading = operator
        AUTO_PTR<T>& operator=(AUTO_PTR<T>& ptrCopy) throw()
        {
            if(ptrCopy)
                m_AutoPtr = &ptrCopy;
            else
                m_AutoPtr = 0;
            return m_AutoPtr;
        }
        //dtor
        ~AUTO_PTR()
        {
            if(m_AutoPtr)
            {
                delete m_AutoPtr;
            }
        }
        //overloading * operator
        T& operator*() const throw()
        {
            return *m_AutoPtr;
        }
        //overloading -> operator
        T *operator->() const throw()
        {
            return m_AutoPtr;
        }
        //function to get the pointer to the class
        T *get() const throw()
        {
            return m_AutoPtr;
        }
    private:
        T *m_AutoPtr;
};

class MyClass
{
    public:
        //ctor
        MyClass()
        {
            str=new char[255];
            cout<<"Memory allocated"<<endl;
        }
        //dtor
        ~MyClass()
        {
            delete[] str;
            cout<<"Memory deallocated"<<endl;
        }
        //Function to display the string
        void display()
        {
            strcpy(str,"This is a test string");
            cout<<str<<endl;
        }
    private:
        char* str;
};

int main()
{
    //Allocate memory to the class MyClass using the template
    AUTO_PTR<MyClass> b=AUTO_PTR<MyClass>(new MyClass);

    //Get the pointer and call the display function
    b.get()->display();

    return 0;
}