# Lambda function definition.

In c++11 return type needs to be mentioned.
type LamdaFunction = []( type arg )-> returnType;

In c++14 or up. The return type does not need to be mentioned.
type LamdaFunction = []( type arg );

# Rvalue and lvalue reference using function overloading.
int function(int &data); // lvalue reference
int function(int &&data); // rvalue reference

# std::move() and rvalue move
std::move() from #include Utilities.
For example:

    std::string mystring("hi");
    std::string mvstring = static_cast<std::string&&>(mystring);
    std::cout << " mystring = "<< mystring <<"\n";
    std::cout << " mvstring = "<< mvstring <<"\n";

expected result = 
    mystring =
    mvstring = hi

# smart pointers from #include <memory>
## unique_ptr

    Takes care of the resources allocated in the heap, and there is no need for using the delete keyword.
    memory gets dealocated once the object goes out of scope or the program ends.

    in c++11 

    std::unique_ptr<int> ptr(new int(42)); // Not as safe

    in c++14

    std::unique_ptr<int> ptr = std::make_unique<int>(42);


