* 编译运行方法
1. 直接点击右上角
2. 配置settings.json
3. g++ ./print.cpp -o ./print.exe 生成可执行文件

* 多文件编译方法
1. 对每个cpp文件进行：
g++ -c main.cpp
g++ -c aaa.cpp
2. link每个.o文件
g++ -o main.exe a.o main.o
3. 运行.exe文件
./main.exe

* todo
1. 函数的传参类型
