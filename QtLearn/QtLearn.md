Qt: main(int argc,char \*argv[])
argc 参数数量，argv 命令数组

```c++
#include <QPushButton> // 控件的头文件
//创建按钮
QPushButton *ButtonSecond =new QPushButton(this);
//为按钮创建名字
ButtonSecond->setText("第二个按钮");
//设置按钮的位置
ButtonSecond->move(100,100);
//可视化窗口
ButtonSecond->show();
//设置世界窗口的名字
setWindowTitle("第一个窗口");
//固定世界窗口大小
setFixedSize(600,400);
//类的一个成员函数，设置当前类窗口的宽高
this->resize(100,100);
```
对象树：
Qt中写一个新的类设置它的父亲，就无需担心内存泄漏问题，这是对象树。

Qt坐标系：
以左上方为0，0点

信号和槽：
点击后，便可以执行相应操作

connect(按钮，信号，this,槽)