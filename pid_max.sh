#!/bin/bash
pid_max=$(cat /proc/sys/kernel/pid_max)
echo "Maximimum Pid Value is $pid_max"
