<?php
	$numero = 6;
	
	echo "Os divisores de $numero sao: ";
	
	for($contador = 1; $contador <= $numero; $contador++){
		if($numero % $contador == 0){
			echo "$contador ";
		}
	}
?>