#!/bin/bash

cd /home/xiaogaozi/Pictures/paste  # 截图保存的文件夹
sleep 2  # 2秒后开始截图
scrot -sb -e '/home/xiaogaozi/Document/Perl/paste.pl $f'

exit 0
