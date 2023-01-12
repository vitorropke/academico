#!/bin/bash

hostname
echo
hostname -I
echo
arp | awk '{print $3}'
