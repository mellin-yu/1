#!/bin/bash 
echo "学生信息:"
cat ../../operation.log | grep "新增" | echo "新增:" `wc -l`
cat ../../operation.log | grep "修改" | echo "修改:" `wc -l`
cat ../../operation.log | grep "删除" | echo "删除:" `wc -l`

echo "课程信息:"
cat ../../operation.log | grep "新增" | echo "新增:" `wc -l`
cat ../../operation.log | grep "修改" | echo "修改:" `wc -l`
cat ../../operation.log | grep "删除" | echo "删除:" `wc -l`

read -p "输入学号:" num
cat ../../operation.log |grep -v "查看" | grep "$num" | i=`wc -l`
if [ $i -eq 0 ];then
echo "no"
else 
echo "yes"
fi

read -p "输入编号:" num
cat ../../operation.log |grep -v "查看" | grep "$num" | i=`wc -l`
if [ $i -eq 0 ];then
echo "no"
else 
echo "yes"
fi
