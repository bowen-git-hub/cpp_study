/**
 * ============================================================================
 * 学生成绩管理系统 - 综合示例
 * 涵盖《C++ Programming: An Object-Oriented Approach》第1-10章所有知识点
 * # 使用g++编译
 * g++ -o test test.cpp -std=c++11
 * ============================================================================
 * 
 * 知识点覆盖清单：
 * 
 * 第1章：计算机与编程语言
 *   - 算法设计（解决问题的方法）
 *   - 程序开发流程
 * 
 * 第2章：C++编程基础
 *   - 变量、常量、数据类型
 *   - cin/cout输入输出
 *   - 命名空间
 *   - 注释
 * 
 * 第3章：表达式与语句
 *   - 算术/关系/逻辑表达式
 *   - 类型转换（隐式/显式）
 *   - 运算符优先级
 *   - 格式化输出（setw, setprecision, fixed）
 *   - 复合语句
 * 
 * 第4章：选择控制
 *   - if/if-else语句
 *   - switch语句
 *   - 逻辑运算符（&&, ||, !）
 *   - 条件运算符（?:）
 * 
 * 第5章：循环控制
 *   - while循环
 *   - for循环
 *   - do-while循环
 *   - 嵌套循环
 *   - break/continue
 * 
 * 第6章：函数
 *   - 函数定义/声明/调用
 *   - 传值与传引用
 *   - 函数重载
 *   - 默认参数
 *   - 作用域（局部/全局/静态）
 *   - 库函数（cmath, cstdlib, ctime）
 * 
 * 第7章：类与面向对象
 *   - 类定义（数据成员+成员函数）
 *   - 构造函数（默认/参数化/拷贝）
 *   - 析构函数
 *   - 访问修饰符（private/public）
 *   - 访问器(getter)/修改器(setter)
 *   - 静态成员
 *   - this指针
 *   - const成员函数
 *   - 类不变量（验证）
 * 
 * 第8章：数组
 *   - 一维数组
 *   - 多维数组（二维）
 *   - 数组作为函数参数
 *   - 并行数组
 *   - 频数数组
 * 
 * 第9章：引用、指针与内存管理
 *   - 引用变量
 *   - 指针变量
 *   - new/delete动态内存分配
 *   - 数组与指针关系
 *   - 指针运算
 *   - 内存泄漏预防
 * 
 * 第10章：字符串
 *   - C风格字符串（字符数组）
 *   - C++ string类
 *   - 字符串操作（连接、查找、子串）
 * 
 * ============================================================================
 */

#include <iostream>     // 第2章：cin/cout输入输出流
#include <iomanip>      // 第3章：格式化输出（setw, setprecision等）
#include <string>       // 第10章：C++ string类
#include <cstring>      // 第10章：C风格字符串函数
#include <cmath>        // 第6章：数学库函数
#include <cstdlib>      // 第6章：随机数、系统函数
#include <ctime>        // 第6章：时间函数
#include <cassert>      // 第7章：断言（类不变量验证）

using namespace std;    // 第2章：使用命名空间

// ============================================================================
// 第6章：全局常量与全局变量（作用域演示）
// ============================================================================
const int MAX_STUDENTS = 50;        // 第2章：常量，第8章：数组容量
const double PASSING_SCORE = 60.0;  // 第2章：常量
static int totalObjectsCreated = 0; // 第6章：静态全局变量

// ============================================================================
// 第7章：Student类 - 面向对象编程核心
// ============================================================================
class Student {
private:
    // 第7章：私有数据成员（封装）
    int id;                 // 学生ID
    string name;            // 第10章：C++ string类
    double scores[5];       // 第8章：一维数组存储5门课成绩
    double average;         // 平均分
    char grade;             // 等级（A/B/C/D/F）
    static int nextId;      // 第7章：静态数据成员（自动生成ID）
    
    // 第7章：私有辅助函数（类不变量验证）
    bool isValidScore(double score) const {
        return (score >= 0.0 && score <= 100.0);
    }
    
    // 第7章：私有辅助函数（计算等级）
    char calculateGrade(double avg) const {
        // 第4章：if-else if多路选择
        if (avg >= 90) return 'A';
        else if (avg >= 80) return 'B';
        else if (avg >= 70) return 'C';
        else if (avg >= 60) return 'D';
        else return 'F';
    }
    
public:
    // ========================================================================
    // 第7章：构造函数（重载）
    // ========================================================================
    
    // 第7章：默认构造函数
    Student() : id(0), name("Unknown"), average(0.0), grade('F') {
        // 第3章：复合语句
        for (int i = 0; i < 5; i++) {   // 第5章：for循环
            scores[i] = 0.0;
        }
        totalObjectsCreated++;          // 第6章：静态变量
        cout << "[DEBUG] 默认构造函数被调用，ID=" << id << endl;
    }
    
    // 第7章：参数化构造函数（使用初始化列表）
    Student(int studentId, const string& studentName, const double s[5]) 
        : id(studentId), name(studentName) {
        
        // 第7章：this指针（区分参数与成员）
        // 第5章：for循环遍历数组
        double sum = 0.0;
        for (int i = 0; i < 5; i++) {
            // 第4章：if语句验证成绩有效性
            if (isValidScore(s[i])) {
                this->scores[i] = s[i];     // 第7章：this指针
                sum += s[i];
            } else {
                cout << "警告：成绩无效，已设置为0" << endl;
                this->scores[i] = 0.0;
            }
        }
        
        // 第3章：算术表达式和类型转换（隐式转换int→double）
        this->average = sum / 5.0;
        this->grade = calculateGrade(this->average);
        
        totalObjectsCreated++;
        cout << "[DEBUG] 参数化构造函数被调用，ID=" << id << ", 姓名=" << name << endl;
    }
    
    // 第7章：拷贝构造函数
    Student(const Student& other) {
        // 第9章：深拷贝（逐成员复制）
        this->id = other.id;
        this->name = other.name;
        this->average = other.average;
        this->grade = other.grade;
        for (int i = 0; i < 5; i++) {
            this->scores[i] = other.scores[i];
        }
        totalObjectsCreated++;
        cout << "[DEBUG] 拷贝构造函数被调用，ID=" << id << endl;
    }
    
    // 第7章：析构函数
    ~Student() {
        totalObjectsCreated--;
        cout << "[DEBUG] 析构函数被调用，ID=" << id << "，姓名=" << name << endl;
    }
    
    // ========================================================================
    // 第7章：访问器（getter）- const成员函数
    // ========================================================================
    int getId() const { return id; }
    string getName() const { return name; }
    double getAverage() const { return average; }
    char getGrade() const { return grade; }
    
    // 第7章：获取单科成绩（带边界检查）
    double getScore(int index) const {
        // 第4章：条件运算符（?:）
        return (index >= 0 && index < 5) ? scores[index] : -1.0;
    }
    
    // ========================================================================
    // 第7章：修改器（setter）- 非const成员函数
    // ========================================================================
    void setName(const string& newName) { name = newName; }
    
    // 更新单科成绩并重新计算平均分和等级
    void setScore(int index, double newScore) {
        // 第4章：if-else验证
        if (index >= 0 && index < 5 && isValidScore(newScore)) {
            scores[index] = newScore;
            
            // 重新计算平均分
            double sum = 0.0;
            for (int i = 0; i < 5; i++) {
                sum += scores[i];
            }
            average = sum / 5.0;
            grade = calculateGrade(average);
        } else {
            cout << "错误：无效的索引或成绩！" << endl;
        }
    }
    
    // ========================================================================
    // 第7章：静态成员函数
    // ========================================================================
    static int getTotalObjectsCreated() {
        return totalObjectsCreated;
    }
    
    // ========================================================================
    // 第7章：打印学生信息（使用const保证不修改）
    // ========================================================================
    void print() const {
        // 第3章：格式化输出（fixed, setprecision, setw）
        cout << left << setw(8) << id
             << setw(15) << name
             << fixed << setprecision(1);
        
        // 第5章：for循环打印5门成绩
        for (int i = 0; i < 5; i++) {
            cout << setw(8) << scores[i];
        }
        
        cout << setw(8) << average
             << setw(6) << grade << endl;
    }
    
    // 第6章：函数重载 - 打印简要信息
    void print(bool detailed) const {
        if (detailed) {
            print();  // 调用详细版本
        } else {
            // 第3章：条件运算符（?:）
            cout << "ID:" << id << " | " << name 
                 << " | 平均分:" << average 
                 << " | " << ((average >= PASSING_SCORE) ? "通过" : "不及格") << endl;
        }
    }
};

// 第7章：静态数据成员必须在类外初始化
int Student::nextId = 1000;

// ============================================================================
// 第6章：全局函数 - 各种工具函数
// ============================================================================

// 第6章：函数重载 - 求最大值（不同参数类型）
int maxValue(int a, int b) {
    return (a > b) ? a : b;
}

double maxValue(double a, double b) {
    return (a > b) ? a : b;
}

// 第6章：默认参数
void printSeparator(char ch = '-', int length = 50) {
    for (int i = 0; i < length; i++) {
        cout << ch;
    }
    cout << endl;
}

// 第6章：传值 vs 传引用（演示区别）
void incrementByValue(int x) {
    x++;    // 只修改局部副本
}

void incrementByReference(int& x) {
    x++;    // 修改原变量
}

// 第9章：指针作为函数参数
void swapByPointer(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 第8章：数组作为函数参数
double calculateAverage(const double arr[], int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

// 第8章：二维数组处理（计算每行平均值）
void calculateRowAverages(const int matrix[][4], int rows, double averages[]) {
    for (int i = 0; i < rows; i++) {
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            sum += matrix[i][j];
        }
        averages[i] = static_cast<double>(sum) / 4;  // 第3章：显式类型转换
    }
}

// 第10章：C风格字符串处理
void reverseCString(char* str) {
    int len = strlen(str);  // 第10章：strlen函数
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

// 第10章：C++ string处理 - 统计元音字母个数
int countVowels(const string& str) {
    int count = 0;
    // 第10章：string::size()成员函数
    for (size_t i = 0; i < str.size(); i++) {
        char ch = tolower(str[i]);  // 第6章：库函数tolower
        // 第4章：switch语句
        switch (ch) {
            case 'a': case 'e': case 'i': case 'o': case 'u':
                count++;
                break;
            default:
                break;
        }
    }
    return count;
}

// ============================================================================
// 第8章：频数数组 - 统计成绩分布（第8章程序设计）
// ============================================================================
void printGradeDistribution(const Student students[], int size) {
    // 第8章：频数数组（10个区间：0-9, 10-19, ..., 90-100）
    int distribution[11] = {0};  // 第8章：数组初始化全为0
    
    // 第5章：for循环统计
    for (int i = 0; i < size; i++) {
        int avg = static_cast<int>(students[i].getAverage());
        int index = avg / 10;
        if (index >= 0 && index <= 10) {
            distribution[index]++;
        }
    }
    
    cout << "\n========== 成绩分布直方图 ==========" << endl;
    // 第5章：嵌套循环打印直方图
    for (int i = 0; i <= 10; i++) {
        cout << setw(8) << (i * 10) << "-" << setw(3) << (i * 10 + 9) << " | ";
        // 第5章：内层循环打印星号
        for (int j = 0; j < distribution[i]; j++) {
            cout << "*";
        }
        cout << " (" << distribution[i] << "人)" << endl;
    }
    printSeparator('=', 50);
}

// ============================================================================
// 第5章：递归函数（阶乘）- 第5章扩展
// ============================================================================
long long factorial(int n) {
    // 第4章：if-else作为递归基例
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);  // 递归调用
}

// ============================================================================
// 第9章：动态数组类（演示new/delete和内存管理）
// ============================================================================
class DynamicArray {
private:
    int* data;      // 第9章：指针，指向堆内存
    int size;       // 数组大小
    
public:
    // 第7章：构造函数 - 动态分配内存
    DynamicArray(int s) : size(s) {
        data = new int[size];  // 第9章：new运算符
        cout << "[DEBUG] 动态数组已创建，大小=" << size << endl;
    }
    
    // 第7章：析构函数 - 释放内存
    ~DynamicArray() {
        delete[] data;  // 第9章：delete[]运算符
        cout << "[DEBUG] 动态数组已销毁" << endl;
    }
    
    // 第7章：访问器（返回引用，可作为左值）
    int& operator[](int index) {
        // 第4章：断言验证索引有效性
        assert(index >= 0 && index < size);
        return data[index];
    }
    
    // 第9章：指针运算演示
    void print() const {
        int* ptr = data;  // 第9章：指针指向数组首元素
        for (int i = 0; i < size; i++) {
            cout << *ptr << " ";  // 第9章：间接寻址
            ptr++;  // 第9章：指针运算（移动到下一个元素）
        }
        cout << endl;
    }
};

// ============================================================================
// 第2章：主函数 - 程序入口
// ============================================================================
int main() {
    // ========================================================================
    // 第1-2章：程序开始，显示标题
    // ========================================================================
    cout << "\n╔══════════════════════════════════════════════════════════════╗" << endl;
    cout << "║          学生成绩管理系统 - 综合示例                          ║" << endl;
    cout << "║    涵盖《C++ Programming》第1-10章全部知识点                  ║" << endl;
    cout << "╚══════════════════════════════════════════════════════════════╝" << endl;
    printSeparator('=', 70);
    
    // ========================================================================
    // 第3章：基本数据类型与表达式演示
    // ========================================================================
    cout << "\n【第3章：基本数据类型与表达式】" << endl;
    
    int a = 10, b = 20;
    double x = 3.14, y = 2.71;
    
    // 算术表达式
    cout << "10 + 20 = " << a + b << endl;
    cout << "3.14 * 2.71 = " << x * y << endl;
    cout << "10 / 3 = " << 10 / 3 << " (整数除法截断)" << endl;
    cout << "10.0 / 3.0 = " << 10.0 / 3.0 << " (浮点除法)" << endl;
    
    // 关系表达式
    cout << "10 > 20? " << (a > b) << " (0=false, 1=true)" << endl;
    
    // 逻辑表达式
    cout << "(10 > 5) && (20 < 30) = " << ((a > 5) && (b < 30)) << endl;
    cout << "(10 > 20) || (20 < 30) = " << ((a > b) || (b < 30)) << endl;
    
    // 第3章：类型转换演示
    int intDiv = 10 / 3;
    double doubleDiv = static_cast<double>(10) / 3;  // 显式转换
    cout << "显式类型转换: static_cast<double>(10)/3 = " << doubleDiv << endl;
    
    // 第3章：赋值表达式（复合赋值）
    int counter = 5;
    cout << "初始值: counter = " << counter << endl;
    counter += 3;  // 等价于 counter = counter + 3
    cout << "counter += 3 → " << counter << endl;
    counter *= 2;  // 等价于 counter = counter * 2
    cout << "counter *= 2 → " << counter << endl;
    
    printSeparator();
    
    // ========================================================================
    // 第4章：选择控制演示
    // ========================================================================
    cout << "\n【第4章：选择控制语句】" << endl;
    
    // if-else语句
    int testScore = 85;
    cout << "测试分数: " << testScore << endl;
    if (testScore >= 60) {
        cout << "  → 通过考试" << endl;
    } else {
        cout << "  → 未通过考试" << endl;
    }
    
    // switch语句
    int dayOfWeek = 3;
    cout << "星期数: " << dayOfWeek << " → ";
    switch (dayOfWeek) {
        case 1: cout << "星期一"; break;
        case 2: cout << "星期二"; break;
        case 3: cout << "星期三"; break;
        case 4: cout << "星期四"; break;
        case 5: cout << "星期五"; break;
        case 6: cout << "星期六"; break;
        case 7: cout << "星期日"; break;
        default: cout << "无效";
    }
    cout << endl;
    
    // 条件运算符（三元运算符）
    int age = 18;
    string status = (age >= 18) ? "成年人" : "未成年人";
    cout << "年龄 " << age << " → " << status << endl;
    
    printSeparator();
    
    // ========================================================================
    // 第5章：循环控制演示
    // ========================================================================
    cout << "\n【第5章：循环控制语句】" << endl;
    
    // while循环
    cout << "while循环 (1-5): ";
    int i = 1;
    while (i <= 5) {
        cout << i++ << " ";
    }
    cout << endl;
    
    // do-while循环（至少执行一次）
    cout << "do-while循环: ";
    int j = 5;
    do {
        cout << j-- << " ";
    } while (j > 0);
    cout << endl;
    
    // for循环
    cout << "for循环计算1+2+...+10 = ";
    int sum = 0;
    for (int k = 1; k <= 10; k++) {
        sum += k;
    }
    cout << sum << endl;
    
    // 嵌套循环（打印乘法表）
    cout << "嵌套循环 - 乘法表(5x5):" << endl;
    for (int row = 1; row <= 5; row++) {
        for (int col = 1; col <= 5; col++) {
            cout << setw(4) << row * col;
        }
        cout << endl;
    }
    
    // break和continue演示
    cout << "break示例 (遇到3停止): ";
    for (int k = 1; k <= 5; k++) {
        if (k == 3) break;
        cout << k << " ";
    }
    cout << endl;
    
    cout << "continue示例 (跳过3): ";
    for (int k = 1; k <= 5; k++) {
        if (k == 3) continue;
        cout << k << " ";
    }
    cout << endl;
    
    // 递归函数调用（阶乘）
    cout << "5! = " << factorial(5) << " (递归计算)" << endl;
    
    printSeparator();
    
    // ========================================================================
    // 第6章：函数演示（传值/传引用/函数重载/默认参数）
    // ========================================================================
    cout << "\n【第6章：函数】" << endl;
    
    // 函数重载
    cout << "max(10, 20) = " << maxValue(10, 20) << endl;
    cout << "max(3.14, 2.71) = " << maxValue(3.14, 2.71) << endl;
    
    // 默认参数
    printSeparator('*', 30);
    
    // 传值 vs 传引用
    int val = 5;
    cout << "传值演示: 原值=" << val;
    incrementByValue(val);
    cout << " → 调用后=" << val << " (不变)" << endl;
    
    incrementByReference(val);
    cout << "传引用演示: 原值=5 → 调用后=" << val << " (改变)" << endl;
    
    // 传指针
    int p1 = 10, p2 = 20;
    cout << "交换前: p1=" << p1 << ", p2=" << p2 << endl;
    swapByPointer(&p1, &p2);
    cout << "交换后: p1=" << p1 << ", p2=" << p2 << endl;
    
    // 库函数演示
    srand(time(0));  // 随机数种子
    int randomNum = rand() % 100 + 1;
    cout << "随机数(1-100): " << randomNum << endl;
    cout << "sqrt(16) = " << sqrt(16) << " (cmath库)" << endl;
    
    printSeparator();
    
    // ========================================================================
    // 第7章：类与对象演示
    // ========================================================================
    cout << "\n【第7章：类与对象】" << endl;
    
    // 创建学生成绩数据
    double scores1[5] = {85.5, 90.0, 78.5, 92.0, 88.0};
    double scores2[5] = {65.0, 70.5, 58.0, 72.0, 68.0};
    double scores3[5] = {95.0, 98.5, 94.0, 96.0, 97.0};
    double scores4[5] = {45.0, 52.0, 48.5, 55.0, 50.0};
    
    // 第7章：对象实例化（调用参数化构造函数）
    Student students[4] = {
        Student(1001, "张三", scores1),
        Student(1002, "李四", scores2),
        Student(1003, "王五", scores3),
        Student(1004, "赵六", scores4)
    };
    
    // 第7章：拷贝构造函数演示
    Student studentCopy = students[0];
    cout << "\n拷贝构造的学生: ";
    studentCopy.print(false);
    
    // 第7章：静态成员函数调用
    cout << "当前已创建的学生对象总数: " << Student::getTotalObjectsCreated() << endl;
    
    // 第7章：修改器(setter)演示
    cout << "\n修改李四的第3门成绩(原=58.0 → 新=75.0):" << endl;
    students[1].setScore(2, 75.0);
    
    // 第7章：访问器(getter)演示
    cout << "张三的平均分: " << students[0].getAverage() << endl;
    cout << "张三的第2门成绩: " << students[0].getScore(1) << endl;
    
    printSeparator();
    
    // ========================================================================
    // 第8章：数组演示
    // ========================================================================
    cout << "\n【第8章：数组】" << endl;
    
    // 打印学生信息表头
    cout << left << setw(8) << "学号"
         << setw(15) << "姓名"
         << setw(8) << "语文"
         << setw(8) << "数学"
         << setw(8) << "英语"
         << setw(8) << "物理"
         << setw(8) << "化学"
         << setw(8) << "平均分"
         << "等级" << endl;
    printSeparator('-', 80);
    
    // 第5章：for循环遍历数组
    for (int i = 0; i < 4; i++) {
        students[i].print();
    }
    
    // 第8章：频数数组（成绩分布统计）
    printGradeDistribution(students, 4);
    
    // 第8章：二维数组演示
    cout << "\n二维数组示例 (3x4矩阵):" << endl;
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
    
    // 第8章：二维数组传递给函数
    double rowAverages[3];
    calculateRowAverages(matrix, 3, rowAverages);
    cout << "各行平均值: ";
    for (int i = 0; i < 3; i++) {
        cout << rowAverages[i] << " ";
    }
    cout << endl;
    
    printSeparator();
    
    // ========================================================================
    // 第9章：指针与动态内存演示
    // ========================================================================
    cout << "\n【第9章：指针与动态内存】" << endl;
    
    // 第9章：指针基本操作
    int num = 42;
    int* ptr = &num;  // 指针指向num的地址
    cout << "变量值: " << num << endl;
    cout << "变量地址: " << &num << endl;
    cout << "指针的值(地址): " << ptr << endl;
    cout << "指针解引用: " << *ptr << endl;
    
    // 第9章：指针运算
    int arr[5] = {10, 20, 30, 40, 50};
    int* arrPtr = arr;  // 数组名即指针
    cout << "通过指针访问数组: ";
    for (int i = 0; i < 5; i++) {
        cout << *(arrPtr + i) << " ";  // 指针运算
    }
    cout << endl;
    
    // 第9章：动态内存分配
    DynamicArray dynArr(5);
    for (int i = 0; i < 5; i++) {
        dynArr[i] = (i + 1) * 10;
    }
    cout << "动态数组内容: ";
    dynArr.print();
    
    printSeparator();
    
    // ========================================================================
    // 第10章：字符串演示
    // ========================================================================
    cout << "\n【第10章：字符串】" << endl;
    
    // 第10章：C风格字符串
    char cstr1[] = "Hello";
    char cstr2[20];
    
    cout << "C风格字符串操作:" << endl;
    cout << "  strcpy复制: ";
    strcpy(cstr2, cstr1);
    cout << cstr2 << endl;
    
    cout << "  strlen长度: " << strlen(cstr1) << endl;
    cout << "  strcat连接: ";
    strcat(cstr2, " World");
    cout << cstr2 << endl;
    
    char toReverse[] = "ABCDEFG";
    cout << "  反转前: " << toReverse << endl;
    reverseCString(toReverse);
    cout << "  反转后: " << toReverse << endl;
    
    // 第10章：C++ string类
    string cppStr1 = "Hello";
    string cppStr2 = "World";
    string cppStr3 = cppStr1 + " " + cppStr2;  // 字符串连接
    
    cout << "\nC++ string类操作:" << endl;
    cout << "  连接结果: " << cppStr3 << endl;
    cout << "  字符串长度: " << cppStr3.size() << endl;
    cout << "  查找'World': 位置=" << cppStr3.find("World") << endl;
    cout << "  提取子串(0-4): " << cppStr3.substr(0, 5) << endl;
    cout << "  元音字母个数: " << countVowels(cppStr3) << endl;
    
    // 第10章：string输入（演示）
    string inputName;
    cout << "\n请输入一个学生姓名测试输入: ";
    cin >> inputName;
    cout << "你输入了: " << inputName << endl;
    
    printSeparator('=', 70);
    
    // ========================================================================
    // 程序总结
    // ========================================================================
    cout << "\n╔══════════════════════════════════════════════════════════════╗" << endl;
    cout << "║  程序运行完成！                                              ║" << endl;
    cout << "║  已演示第1-10章全部核心知识点：                              ║" << endl;
    cout << "║    ✓ 第1章：算法设计                                         ║" << endl;
    cout << "║    ✓ 第2章：变量/常量/数据类型/cin/cout                      ║" << endl;
    cout << "║    ✓ 第3章：表达式/运算符/类型转换/格式化输出                ║" << endl;
    cout << "║    ✓ 第4章：if/switch/逻辑运算符/条件运算符                  ║" << endl;
    cout << "║    ✓ 第5章：while/for/do-while/嵌套循环/break/continue       ║" << endl;
    cout << "║    ✓ 第6章：函数/重载/传值传引用/默认参数/作用域             ║" << endl;
    cout << "║    ✓ 第7章：类/对象/构造析构/封装/静态成员/this指针          ║" << endl;
    cout << "║    ✓ 第8章：一维/二维数组/数组函数/频数数组                  ║" << endl;
    cout << "║    ✓ 第9章：指针/引用/动态内存/new-delete/指针运算           ║" << endl;
    cout << "║    ✓ 第10章：C字符串/C++ string类/字符串操作                 ║" << endl;
    cout << "╚══════════════════════════════════════════════════════════════╝" << endl;
    
    return 0;  // 第3章：return语句
}

// ============================================================================
// 第6章：全局作用域演示（变量和函数已在前文定义）
// ============================================================================