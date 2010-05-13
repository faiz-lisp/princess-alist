=========
Go-Getter
=========

:Authors: 小高子
:Contact: gaochangjian@gmail.com
:Date: 2010-04-08
:Version: 1

题目说明
--------

这是一道程序接力题目，初始文件为Python程序，运行会生成Shell Script程序，
然后这样依次生成，具体的生成顺序为：

1. Python
2. Shell Script
3. C
4. C++
5. JavaScript
6. Java
7. LaTeX

最后通过LaTeX文件生成PDF，key为PDF中的红色字母加上其中数学公式的计算结果。

测试方法
--------

运行

::

    $ make

中途会提示到浏览器中运行JavaScript程序，将运行结果复制下来，保存为"GoGetter.java"
文件，继续执行 ``make`` 程序，最后得到PDF文件。

答案
----

Key: uougeRlte524288n
