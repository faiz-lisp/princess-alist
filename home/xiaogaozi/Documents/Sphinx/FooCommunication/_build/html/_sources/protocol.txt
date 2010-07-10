========
通信协议
========

:Authors: 高昌健
:Contact: gaochangjian@gmail.com
:Date: 2010-06-22

协议头部设计
============

::

    0              7             15                           31
    +--------------+--------------+----------------------------+
    |              |              |                            |
    |     type     |     urge     |      sequence number       |
    |              |              |                            |
    +--------------+--------------+----------------------------+
    |                                                          |
    |                       data length                        |
    |                                                          |
    +----------------------------------------------------------+
    |                                                          |
    |                      data (if any)                       |
    |                                                          |
    +----------------------------------------------------------+

#. type：标示数据类型，文字为1，图片为2，GPS为3，确认信息为4。
#. urge：标示是否为紧急信息（即命令信息），1为真，0为假。
#. sequence number：序号，用来绑定表单与图片。
#. data length：数据部分的总长度，不包含头部。

C语言实现参考：

.. code-block:: c

    struct gdphdr
    {
        unsigned char type,
        unsigned char urge;
        unsigned short seq;
        unsigned int len;
    };
