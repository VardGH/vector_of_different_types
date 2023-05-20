#include <iostream>
#include <vector>
#include <string>

class Base
{
public:
    virtual void print() = 0;
    virtual ~Base() {}
};

class Char : public Base
{
public:
    Char(char val)
       : m_val(val)
    {
    }

public:
    void print() override { 
        std::cout << "char elem" << std::endl; 
    }

private:
    char m_val;
};

class Int : public Base
{
public:
    Int(int val)
        : m_val(val)
    {
    }

public:
    void print() override { 
        std::cout << "int elem" << std::endl; 
    }
private:
    int m_val;
};

class Double : public Base
{
public:
    Double(float val)
       : m_val(val)
    {
    }

public:
    void print() override { 
        std::cout << "double elem" << std::endl; 
    }
private:
    double m_val;
};

class String : public Base
{
public:
    String(const std::string& val)
       : m_val(val)
    {
    }

public:
    void print() override { 
        std::cout << "stirng elem" << std::endl; 
    }
private:
    std::string m_val;
};


int main()
{
    std::vector<Base*> vec;

    vec.push_back(new Char('a'));
    vec.push_back(new Int(13));
    vec.push_back(new Double(3.14));
    vec.push_back(new String("I'll be back"));

    for (const auto& elem : vec) {
        elem->print();
    }

    // free memory 
    for(auto& elem : vec) {
        delete elem;
    }
    vec.clear();

    return 0;
}