1) git clone https://github.com/qt/qtftp.git
2) cd qtftp, 修改qtftp.pro, 注释掉如下
#           module_qtftp_examples \
#           module_qtftp_tests \
3) cd qtftp; qmake; make
