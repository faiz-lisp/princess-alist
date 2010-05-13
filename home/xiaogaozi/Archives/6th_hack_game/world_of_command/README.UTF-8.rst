================
World of Command
================

:Authors: 小高子
:Contact: gaochangjian@gmail.com
:Date: 2010-04-11
:Version: 1

对于 ``unixkcd`` 的改进及新增功能
---------------------------------

#. 修改命令提示符为"``guest@syclover:~$``".
#. ``Filesystem`` 添加下列文件及目录: "``.``", "``..``", "``.hint``", 删除"``blog``"等文件夹, 重命名"``welcome.txt``"及"``license.txt``"为"``WELCOME``"、"``LICENSE``".
#. 添加 ``Filesystem`` 结构的 ``/tmp`` 目录, 默认包含两个文件: "``alist.cpp``", "``Makefile``"
#. 改进 ``ls`` 命令, 增加"``-a``"与"``-A``"选项的判断, 当目录名为"``/tmp``"或"``/tmp/``"时显示特定内容.
#. 修改 ``cd`` 命令, 当目录名为"``/tmp``"或"``/tmp/``"时不提示错误.
#. 修改 ``cat`` 命令, 当文件名为"``/tmp/Makefile``"时显示Makefile的内容.
#. 修改 ``rm`` 命令, 现在还可以删除 ``/tmp`` 目录中的文件.
#. 增加 ``make`` 命令, 可以对于各种规则给出提示.
#. 修改 ``apt-get`` 命令, 增加"``install``"选项, 现在只能安装 ``g++``.
#. 增加 ``g++`` 命令, 不做任何输出.
#. 增加 ``/tmp/alist`` 命令.
#. 修改默认IRC服务器为 `Freenode <http://freenode.net/>`_, 设置默认频道为 ``#ubuntu-cn``.
#. 改进 ``wget`` 命令, 自动判断网址是否以"``http://``"或"``https://``"开头, 若不是, 则自动在最前面添加"``http://``".

答案
----

Key: awesome
