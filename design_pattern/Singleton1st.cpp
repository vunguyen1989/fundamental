#include <iostream>

using namespace std;

class Singleton {
   static Singleton *instance;
   int data;
 
   // Private constructor so that no objects can be created.
   Singleton() {
      data = 0;
   }
   Singleton(const Singleton& s); // copy constructor prototype ClassName (const ClassName &old_obj);
   Singleton& operator=(const Singleton&);


   public:
   static Singleton *getInstance() {
      if (!instance)
          instance = new Singleton;
      return instance;
   }

   int getData() {
      return this -> data;
   }

   void setData(int data) {
      this -> data = data;
   }
};

//Initialize pointer to zero so that it can be initialized in first call to getInstance
Singleton *Singleton::instance = 0;

int main(){
   Singleton *s = s->getInstance();
   cout << s->getData() << endl;
   s->setData(100);
   cout << s->getData() << endl;

   // Singleton x(*s);
   // Singleton y = x;
   return 0;
}