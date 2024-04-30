#!/bin/bash
echo " "
echo "printing OS, version, release number and kernel version:-"
echo " "
echo "Operating System: $(uname -s)"
echo "OS Version: $(lsb_release -d | cut -f2)"
echo "Release number: $(lsb_release -r | cut -f2)"
echo "Kernel Version: $(uname -r)"
echo " "
echo "printing all available shells"
echo " "
cat /etc/shells
echo " "
echo "printing computer CPU informations:-"
echo ""
cat /proc/cpuinfo
echo ""
echo "memory infdormation: "
echo ""
cat /proc/meminfo
echo ""
echo "hard disk information: "
echo ""
lsblk
echo ""
echo "file system(mounted): "
echo ""
df -h



