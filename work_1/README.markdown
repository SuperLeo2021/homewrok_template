# 实验一：分治算法

## 学号：20201120486

>无

## 实验目的：
通过排序算法的程序实现和执行时间测试，与理论上的结论进行对比分析，
深入理解算法时间复杂度渐进性态和和增长率的概念；理解分治算法设计的基本
思想、递归程序实现的基本方法，加深对分治算法设计与分析思想的理解。


## 实验原理

对列表元素做一次遍历，使用一个全局变量Max来记录到当前的最大值，此变量初始化为一个负数，如果当前元素大于Max，那么令Max等于当前元素，然后进行查看下一个元素.


## 实验输入数据集

文本数据集：5,1,2,3,7,14,6  
文件数据集：![数据集](./work_1/图片/1_1.png)

## 实验内容

1. [max.py](./max.py) 算法实现的python版本
1. [max.c](max.c) 算法实现的C语言版本
1. [max.java](max.java) 算法实现的java版本

## 实验预期结果与实际结果
+ 实验预期结果：14

实验过程及实验结果（Java版）

```bash
gitpod /workspace/homewrok_template (main) $ javac Max.java
Picked up JAVA_TOOL_OPTIONS:  -Xmx3435m
gitpod /workspace/homewrok_template (main) $ java Max
Picked up JAVA_TOOL_OPTIONS:  -Xmx3435m
14

```

实验过程及实验结果（C版）

```bash
gitpod /workspace/homewrok_template (main) $ gcc -o max.exe max.c
gitpod /workspace/homewrok_template (main) $ ./max.exe 
14

```

实验过程及实验结果（Python版）

```bash
gitpod /workspace/homewrok_template (main) $ python max.py 
14

```