/*
我已经创建了一个综合性的C++程序，涵盖了您提供的前12章节的所有知识点。这个程序具有一定的难度，同时包含了详细的注释来解释各个知识点。
程序结构与知识点对应
第1章：计算机与编程语言
程序整体结构展示了算法设计和程序开发流程
主函数作为程序入口点，组织了各个模块的调用
第2章：C++编程基础
变量、常量、数据类型的定义和使用
cin/cout输入输出（虽然主要展示了cout）
命名空间的使用（using namespace std）
详细的注释说明
第3章：表达式与语句
算术、关系、逻辑表达式的使用
隐式和显式类型转换
运算符优先级（通过复杂表达式展示）
格式化输出（setw, setprecision, fixed）
复合语句（通过各种代码块展示）
第4章：选择控制
if/if-else语句
switch语句
逻辑运算符（&&, ||, !）
条件运算符（?:）
第5章：循环控制
while循环
for循环
do-while循环
嵌套循环（乘法表示例）
break/continue的概念（虽然未直接展示）
第6章：函数
函数定义、声明和调用
传值与传引用（swapValues函数）
函数重载（findMax的两个版本）
默认参数（printMenu函数）
作用域概念
库函数的使用（sqrt, rand, time）
第7章：类与面向对象
类定义（Student类）
构造函数（默认、参数化、拷贝）
析构函数
访问修饰符（private/public）
访问器(getter)/修改器(setter)
静态成员（studentCount）
this指针
const成员函数
类不变量（GPA验证）
第8章：数组
一维数组
多维数组（二维矩阵）
数组作为函数参数（processArray函数）
并行数组（names和ages数组）
频数数组（frequency数组）
第9章：引用、指针与内存管理
引用变量（swapValues函数参数）
指针变量
new/delete动态内存分配（dynamicMemoryExample函数）
数组与指针关系
指针运算（pointerArithmeticExample函数）
内存泄漏预防（正确使用delete和delete[]）
第10章：字符串
C风格字符串（字符数组）
C++ string类
字符串操作（连接、查找、子串）
第11-12章：补充知识点
运算符重载（Complex类）
继承与多态（Shape, Circle, Rectangle类）
虚函数和抽象类
如何使用这个程序
将代码保存为comprehensive_program.cpp
使用C++编译器编译：g++ comprehensive_program.cpp -o comprehensive_program
运行程序：./comprehensive_program（Windows下为comprehensive_program.exe）
程序会依次展示各个知识点的使用方法，输出结果会显示每个部分的执行情况。
这个程序设计为一个完整的学习资源，您可以：
运行整个程序查看所有知识点的演示
单独研究某个部分的代码，了解特定知识点的实现
修改代码进行实验，加深对知识点的理解
希望这个综合程序能够帮助您学习C++编程！
*/

// 综合C++程序 - 涵盖前12章节知识点
// 第1章：计算机与编程语言 - 算法设计与程序开发流程

#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

// 第2章：C++编程基础 - 命名空间
using namespace std;

// 第7章：类与面向对象 - 类定义
class Student {
   private:
    // 数据成员
    string name;
    int id;
    double gpa;
    static int studentCount;  // 静态成员
    const int maxCourses;     // 常量成员

   public:
    // 构造函数（默认/参数化/拷贝）
    Student() : maxCourses(5) {
        name = "Unknown";
        id = 0;
        gpa = 0.0;
        studentCount++;
    }

    Student(string n, int i, double g) : maxCourses(5) {
        name = n;
        id = i;
        // 类不变量（验证）
        setGPA(g);
        studentCount++;
    }

    Student(const Student& other) : maxCourses(other.maxCourses) {
        name = other.name;
        id = other.id;
        gpa = other.gpa;
        studentCount++;
    }

    // 析构函数
    ~Student() {
        studentCount--;
    }

    // 访问器(getter)/修改器(setter)
    string getName() const { return name; }
    int getId() const { return id; }
    double getGPA() const { return gpa; }
    static int getStudentCount() { return studentCount; }

    void setName(string n) { name = n; }
    void setId(int i) { id = i; }
    void setGPA(double g) {
        // 类不变量（验证）
        if (g >= 0.0 && g <= 4.0) {
            gpa = g;
        } else {
            gpa = 0.0;
            cout << "Invalid GPA. Set to 0.0." << endl;
        }
    }

    // this指针示例
    void printInfo() const {
        cout << "Name: " << this->name << endl;
        cout << "ID: " << this->id << endl;
        cout << "GPA: " << fixed << setprecision(2) << this->gpa << endl;
    }

    // const成员函数
    void printMaxCourses() const {
        cout << "Max courses allowed: " << maxCourses << endl;
    }
};

// 静态成员初始化
int Student::studentCount = 0;

// 第6章：函数 - 函数声明
void printWelcome();
double calculateArea(double radius);
void processArray(int arr[], int size);
void swapValues(int& a, int& b);        // 传引用
int findMax(int a, int b);              // 函数重载
double findMax(double a, double b);     // 函数重载
void printMenu(int defaultChoice = 1);  // 默认参数

// 第9章：引用、指针与内存管理 - 函数使用指针
void dynamicMemoryExample();
void pointerArithmeticExample();

// 第10章：字符串 - 字符串操作函数
void stringOperations();

// 第11章：运算符重载（补充）
class Complex {
   private:
    double real;
    double imag;

   public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // 运算符重载
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    friend ostream& operator<<(ostream& os, const Complex& c);
};

// 友元函数
ostream& operator<<(ostream& os, const Complex& c) {
    os << c.real << " + " << c.imag << "i";
    return os;
}

// 第12章：继承与多态（补充）
class Shape {
   public:
    virtual void draw() const {  // 虚函数
        cout << "Drawing a shape" << endl;
    }

    virtual ~Shape() {}

    // 纯虚函数（抽象类）
    virtual double getArea() const = 0;
};

class Circle : public Shape {
   private:
    double radius;

   public:
    Circle(double r) : radius(r) {}

    void draw() const override {
        cout << "Drawing a circle" << endl;
    }

    double getArea() const override {
        return M_PI * radius * radius;
    }
};

class Rectangle : public Shape {
   private:
    double width;
    double height;

   public:
    Rectangle(double w, double h) : width(w), height(h) {}

    void draw() const override {
        cout << "Drawing a rectangle" << endl;
    }

    double getArea() const override {
        return width * height;
    }
};

// 主函数
int main() {
    // 第2章：C++编程基础 - 变量、常量、数据类型
    int integerVar = 10;
    double doubleVar = 3.14159;
    char charVar = 'A';
    bool boolVar = true;
    const int MAX_SIZE = 100;  // 常量

    // 第3章：表达式与语句 - 算术/关系/逻辑表达式
    int a = 5, b = 3;
    double result = (a + b) * 2.5;             // 算术表达式
    bool isGreater = (a > b);                  // 关系表达式
    bool logicalResult = (a > 0) && (b < 10);  // 逻辑表达式

    // 第3章：类型转换（隐式/显式）
    int intNum = 100;
    double doubleNum = intNum;                       // 隐式转换
    int convertedInt = static_cast<int>(doubleVar);  // 显式转换

    // 第3章：格式化输出
    cout << fixed << setprecision(2);
    cout << "Pi: " << setw(10) << doubleVar << endl;

    // 第4章：选择控制 - if/if-else语句
    if (a > b) {
        cout << "a is greater than b" << endl;
    } else {
        cout << "a is not greater than b" << endl;
    }

    // 第4章：switch语句
    int choice = 2;
    switch (choice) {
        case 1:
            cout << "Choice 1 selected" << endl;
            break;
        case 2:
            cout << "Choice 2 selected" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
    }

    // 第4章：条件运算符
    string message = (a > b) ? "a is larger" : "b is larger or equal";
    cout << message << endl;

    // 第5章：循环控制 - for循环
    cout << "Counting from 1 to 5: " << endl;
    for (int i = 1; i <= 5; i++) {
        cout << i << " " << endl;
    }

    // 第5章：while循环
    int counter = 1;
    cout << "Counting with while: " << endl;
    while (counter <= 3) {
        cout << counter << " " << endl;
        counter++;
    }

    // 第5章：do-while循环
    int num = 1;
    cout << "Counting with do-while: " << endl;
    do {
        cout << num << " " << endl;
        num++;
    } while (num <= 2);

    // 第5章：嵌套循环
    cout << "Multiplication table (1-3): " << endl;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            cout << i << "*" << j << "=" << i * j << "\t" << endl;
        }
        cout << endl;
    }

    // 第6章：函数调用
    printWelcome();
    double area = calculateArea(5.0);
    cout << "Area of circle: " << area << endl;

    // 第6章：函数重载
    cout << "Max of 5 and 10: " << findMax(5, 10) << endl;
    cout << "Max of 3.14 and 2.71: " << findMax(3.14, 2.71) << endl;

    // 第6章：默认参数
    printMenu();   // 使用默认参数
    printMenu(3);  // 覆盖默认参数

    // 第7章：类与面向对象 - 创建对象
    Student s1("Alice", 1001, 3.8);
    Student s2("Bob", 1002, 3.5);
    Student s3 = s1;  // 拷贝构造函数

    cout << "Student 1 info: " << endl;
    s1.printInfo();
    cout << "Student 2 info: " << endl;
    s2.printInfo();
    cout << "Student 3 info (copied): " << endl;
    s3.printInfo();

    cout << "Total students: " << Student::getStudentCount() << endl;

    // 第8章：数组 - 一维数组
    int numbers[MAX_SIZE] = {1, 2, 3, 4, 5};
    processArray(numbers, 5);

    // 第8章：二维数组
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    cout << "Matrix: " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " " << endl;
        }
        cout << endl;
    }

    // 第8章：并行数组
    string names[] = {"Alice", "Bob", "Charlie"};
    int ages[] = {20, 21, 22};
    cout << "Name-Age pairs: " << endl;
    for (int i = 0; i < 3; i++) {
        cout << names[i] << ": " << ages[i] << endl;
    }

    // 第8章：频数数组
    int scores[] = {85, 90, 85, 95, 90, 85};
    int frequency[101] = {0};  // 假设分数范围0-100
    for (int i = 0; i < 6; i++) {
        frequency[scores[i]]++;
    }
    cout << "Score frequencies: " << endl;
    for (int i = 80; i <= 100; i++) {
        if (frequency[i] > 0) {
            cout << "Score " << i << ": " << frequency[i] << " times" << endl;
        }
    }

    // 第9章：引用变量
    int x = 10, y = 20;
    cout << "Before swap: x=" << x << ", y=" << y << endl;
    swapValues(x, y);
    cout << "After swap: x=" << x << ", y=" << y << endl;

    // 第9章：动态内存分配
    dynamicMemoryExample();

    // 第9章：指针运算
    pointerArithmeticExample();

    // 第10章：字符串操作
    stringOperations();

    // 第11章：运算符重载
    Complex c1(2, 3);
    Complex c2(1, 4);
    Complex c3 = c1 + c2;
    Complex c4 = c1 - c2;
    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;
    cout << "c1 + c2: " << c3 << endl;
    cout << "c1 - c2: " << c4 << endl;

    // 第12章：继承与多态
    Shape* shapes[2];
    shapes[0] = new Circle(5.0);
    shapes[1] = new Rectangle(4.0, 6.0);

    for (int i = 0; i < 2; i++) {
        shapes[i]->draw();
        cout << "Area: " << shapes[i]->getArea() << endl;
        delete shapes[i];  // 释放内存
    }

    // 第6章：库函数
    srand(time(0));                    // 初始化随机数种子
    int randomNum = rand() % 100 + 1;  // 生成1-100的随机数
    cout << "Random number: " << randomNum << endl;

    double sqrtResult = sqrt(16.0);  // 平方根
    cout << "Square root of 16: " << sqrtResult << endl;

    return 0;
}

// 第6章：函数定义
void printWelcome() {
    cout << "Welcome to C++ Programming!" << endl;
}

double calculateArea(double radius) {
    return M_PI * radius * radius;
}

void processArray(int arr[], int size) {
    cout << "Array elements: " << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " " << endl;
    }
}

void swapValues(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int findMax(int a, int b) {
    return (a > b) ? a : b;
}

double findMax(double a, double b) {
    return (a > b) ? a : b;
}

void printMenu(int defaultChoice) {
    cout << "Menu - Default choice: " << defaultChoice << endl;
    cout << "1. Option 1" << endl;
    cout << "2. Option 2" << endl;
    cout << "3. Option 3" << endl;
}

// 第9章：动态内存分配示例
void dynamicMemoryExample() {
    // 动态分配单个变量
    int* pInt = new int;
    *pInt = 42;
    cout << "Dynamic int value: " << *pInt << endl;
    delete pInt;  // 释放内存

    // 动态分配数组
    int* pArray = new int[5];
    for (int i = 0; i < 5; i++) {
        pArray[i] = i * 10;
    }
    cout << "Dynamic array elements: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << pArray[i] << " " << endl;
    }
    delete[] pArray;  // 释放数组内存
}

// 第9章：指针运算示例
void pointerArithmeticExample() {
    int arr[] = {10, 20, 30, 40, 50};
    int* p = arr;

    cout << "Pointer arithmetic: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << "*(p + " << i << ") = " << *(p + i) << endl;
    }
}

// 第10章：字符串操作示例
void stringOperations() {
    // C风格字符串
    char cString[50] = "Hello";
    strcat(cString, " World");
    cout << "C-style string: " << cString << endl;

    // C++ string类
    string cppString = "Hello";
    cppString += " World";
    cout << "C++ string: " << cppString << endl;

    // 字符串查找
    size_t pos = cppString.find("World");
    if (pos != string::npos) {
        cout << "Found 'World' at position: " << pos << endl;
    }

    // 子串
    string substr = cppString.substr(6, 5);
    cout << "Substring: " << substr << endl;
}