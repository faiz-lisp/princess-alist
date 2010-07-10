.. ChartServer documentation master file, created by
   sphinx-quickstart on Mon May 31 10:46:18 2010.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

====================
ChartServer 模块说明
====================

:Authors: 高昌健
:Contact: gaochangjian@gmail.com
:Date: 2010-05-31
:Version: 1.0

.. contents:: 目录

目录结构及文件说明
==================

::

    ChartServer
    |-- Makefile
    |-- chart.png                     # 最终生成的图片文件
    |-- chartserver
    |   |-- BarChart.java             # 用于生成柱状图
    |   |-- ChartGenException.java    # 生成图片时可能产生的异常类
    |   |-- ChartServer.java          # 服务器主程序
    |   `-- PieChart.java             # 用于生成饼图
    `-- docs                          # 说明文档
        |-- _images
        |   |-- bar_chart.png
        |   `-- pie_chart.png
        |-- _sources
        |   `-- index.txt
        |-- _static
        |   |-- bar_chart.png
        |   |-- basic.css
        |   |-- default.css
        |   |-- doctools.js
        |   |-- file.png
        |   |-- jquery.js
        |   |-- minus.png
        |   |-- pie_chart.png
        |   |-- plus.png
        |   |-- pygments.css
        |   `-- searchtools.js
        |-- genindex.html
        |-- index.html                # 说明文档主页
        |-- objects.inv
        |-- search.html
        `-- searchindex.js

编译前的准备工作
================

本模块使用Java语言进行编写，且依赖 `JFreeChart <http://www.jfree.org/jfrechart>`_ 包，因此需要JDK及JFreeChart的相关文件。Ubuntu 9.10系统（10.04官方源不提供JDK）可以使用以下命令安装：

.. code-block:: bash

    $ sudo apt-get install sun-java6-jdk libjfreechart-java

编译步骤
========

请先确保当前目录为 **ChartServer** 目录：

.. code-block:: bash

    $ pwd
    /home/xiaogaozi/ChartServer

接着输入以下命令进行编译：

.. code-block:: bash

    $ javac -classpath "/usr/share/java/*:." chartserver/ChartServer.java

"``/usr/share/java/``"为JFreeChart的安装目录，请根据实际情况修改。

上面的编译命令也已经在 ``Makefile`` 文件中定义。

运行程序
========

同样是在 **ChartServer** 目录中，输入以下命令：

.. code-block:: bash

    $ java -classpath "/usr/share/java/*:." chartserver.ChartServer

服务器默认的监听端口为8181，发送特定的字符串就可以生成图片。

示例
====

生成饼图
--------

   发送以下字符串：

   ::
   
       1:浏览器市场占有率:Firefox,Internet Explorer:80,20:600,400

   以上各部分由":"分隔，每一部分的含义为：

   - **1** ：生成图片的类型，"1"为饼图，"2"为柱状图。
   - **浏览器市场占有率** ：图片的标题
   - **Firefox,Internet Explorer** ：图片中的标签名，逗号分隔。
   - **80,20** ：与标签名相对应的值，逗号分隔。
   - **600,400** ：图片的宽度与高度，逗号分隔。

   最终生成的图片效果：

   .. image:: _static/pie_chart.png

生成柱状图
----------

   发送以下字符串：

   ::
   
       2:浏览器市场占有率,浏览器,市场占有率:Firefox,Internet Explorer:80,20:600,400

   以上各部分由":"分隔，每一部分的含义为：

   - **2** ：生成图片的类型，"1"为饼图，"2"为柱状图。
   - **浏览器市场占有率,浏览器,市场占有率** ：图片的标题，横坐标标签及纵坐标标签。
   - **Firefox,Internet Explorer** ：图片中的标签名，逗号分隔。
   - **80,20** ：与标签名相对应的值，逗号分隔。
   - **600,400** ：图片的宽度与高度，逗号分隔。

   最终生成的图片效果：

   .. image:: _static/bar_chart.png

服务器返回值说明
================

**OK**
    图片生成成功

**messages too few**
    客户端发送给服务器端的字符串一共被":"分割为5个部分，如果不等于5，则返回此错误提示。

**titles too short**
    当生成柱状图时，字符串的第2个字段一共有3部分：图片标题，横坐标标签以及纵坐标标签，如果不等于3，则返回此错误提示。

**labels and values aren't equal in length**
    标签名（第3个字段）的个数与值（第4个字段）的个数必须相等，否则返回此错误提示。

此外还可能返回 ``IOException`` 类型的异常。
