# c-student-score

C 语言课程项目：控制台学生成绩录入与查询系统。

## 功能

- **1. 录入学生信息**：输入学号、姓名、C 语言成绩、数学成绩，自动计算平均分
  - 学号查重：重复学号不允许录入
  - 成绩校验：成绩必须在 0~100 之间
- **2. 显示全部学生信息**
- **3. 按学号查询学生成绩**
- **0. 退出程序**

## 数据结构

使用结构体 `struct Student` 保存学生信息（学号、姓名、C 语言成绩、数学成绩、平均分），
数据保存在内存数组中，最多支持 `MAX_STU`（50）名学生。

## 编译运行

使用 gcc 编译（Dev-C++ 自带 TDM-GCC）：

```
gcc main.c -o main.exe
```

运行：

```
main.exe
```

## 使用示例

```
===== Student Score System =====
1. Add student info
2. Show all students
3. Search student by ID
0. Exit
Please select option: 1
Please input student id: 2024001
Please input student name: Alice
Please input C score (0-100): 85
Please input Math score (0-100): 92
Add success!
```

## 项目结构

- `main.c` — 全部源代码
- `README.md` — 项目说明
