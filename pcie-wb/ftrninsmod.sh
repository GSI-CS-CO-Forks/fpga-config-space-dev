#!/bin/bash

echo "###################################################################"
echo "Removing FTRN kernel modules"
rmmod pcie_wb
sleep 1s
rmmod wishbone
sleep 1s

echo "-------------------------------------------------------------------"
echo "Inserting FTRN kernel modules"
insmod wishbone.ko
sleep 0.5s
insmod pcie_wb.ko pmcintx=1 debug=0

echo "Checking FTRN kernel modules"
echo "-------------------------------------------------------------------"
lsmod | grep wb
echo "-------------------------------------------------------------------"
ls -l /dev | grep wb
echo "-------------------------------------------------------------------"
cat /proc/interrupts | grep wb
echo "-------------------------------------------------------------------"
dmesg -c | grep pcie_wb
echo "-------------------------------------------------------------------"
eb-info dev/wbm0
echo "###################################################################"

