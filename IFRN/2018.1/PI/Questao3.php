<html>
	<head>
		<title>Questão 3</title>
	</head>
	<body>
		<?php
			$A = 3;
			$B = 1;
			$C = 2;
			$D = 4;
			$somaAC = $A + $C;
			$multiplicacaoBD = $B * $D;
			
			if ($somaAC > $multiplicacaoBD)
				echo "A+C é maior que B*D <br/>";
			if ($somaAC == $multiplicacaoBD)
				echo "A+C é igual a B*D <br/>";
			if ($somaAC < $multiplicacaoBD)
				echo "A+C é menor que B*D <br/>";
		?>
	</body>
</html>