<html>
	<head>
		<title>Questão 4</title>
	</head>
	<body>
		<?php
			$numero1 = 3;
			$numero2 = 1;
			$divisao = $numero1 / $numero2;
			
			if ($divisao == false)
				echo "Impossível fazer divisão por zero";
			if ($divisao == true)
				echo "Resultado da divisão $divisao";
		?>
	</body>
</html>