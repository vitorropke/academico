#!/bin/bash

echo "Digite um valor qualquer"
read valor

for ((i=1; i<= valor; i++))
	do
		mkdir pasta$i;
	done
