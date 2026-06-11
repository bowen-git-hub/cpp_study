#include <iostream>
#include <string>
using namespace std;

// 定义结构体
struct Student {
    string name;    // 姓名
    int age;        // 年龄
    double score;   // 成绩
    int id;         // 学号
};

// 定义结构体：点
struct Point {
    int x;
    int y;
};

int main() {
    cout << "=== C++ 结构体演示 ===" << endl;
    
    // 方式1：声明并初始化结构体
    Student student1 = {"张三", 18, 95.5, 001};
    cout << "学生1信息：" << endl;
    cout << "  姓名: " << student1.name << endl;
    cout << "  年龄: " << student1.age << endl;
    cout << "  成绩: " << student1.score << endl;
    cout << "  学号: " << student1.id << endl;
    
    cout << "\n";
    
    // 方式2：声明然后赋值
    Student student2;
    student2.name = "李四";
    student2.age = 19;
    student2.score = 88.0;
    student2.id = 002;
    
    cout << "学生2信息：" << endl;
    cout << "  姓名: " << student2.name << endl;
    cout << "  年龄: " << student2.age << endl;
    cout << "  成绩: " << student2.score << endl;
    cout << "  学号: " << student2.id << endl;
    
    cout << "\n";
    
    // 结构体数组
    Student students[3] = {
        {"王五", 20, 92.0, 003},
        {"赵六", 18, 87.5, 004},
        {"孙七", 19, 91.0, 005}
    };
    
    cout << "班级学生信息：" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "学生 " << i + 1 << ": " << students[i].name 
             << " (成绩: " << students[i].score << ")" << endl;
    }
    
    cout << "\n";
    
    // 结构体指针
    Student *pStudent = &student1;
    cout << "使用指针访问结构体：" << endl;
    cout << "  姓名: " << pStudent->name << endl;
    cout << "  成绩: " << pStudent->score << endl;
    
    cout << "\n";
    
    // 嵌套结构体（简单示例）
    struct Rectangle {
        Point topLeft;      // 左上角
        Point bottomRight;  // 右下角
    };
    
    Rectangle rect;
    rect.topLeft.x = 0;
    rect.topLeft.y = 10;
    rect.bottomRight.x = 5;
    rect.bottomRight.y = 0;
    
    cout << "矩形信息：" << endl;
    cout << "  左上角: (" << rect.topLeft.x << ", " << rect.topLeft.y << ")" << endl;
    cout << "  右下角: (" << rect.bottomRight.x << ", " << rect.bottomRight.y << ")" << endl;
    
    return 0;
}
