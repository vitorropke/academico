<html>
	<head>
		<title> Tudo </title>
	</head>
	<body>
		<?php
			//código;
			//código;
			//código;
		?>
		
		<?php
			//echo "a";
			# echo "a";
			/*echo "a";
			echo "b";
			*/
		?>
		
		<?php
			/*
			*Classe para auxiliar cálculos matemáticos
			*
			*@author Pedro Baesse
			*@version 1.0
			*
			*/
		?>
		
		<?php
			//Define o nome da variável
			
			$variavel = "nome";
		?>
		
		<?php
			echo "a", "b", "c<br/>";
			echo "ABC";
		?>
		
		<?php
			echo "<h2 align='CENTER'>
				O meu primeiro programa <br/>
				Meu programa <br/>
				</h2>"
		?>
		
		<br/>
		
		<?php
			$var = 'Bob';
			$Var = 'Joe';
			echo "$var, $Var"; // exibe "Bob, Joe"
			
			$site = 'not yet';	// inválido; começa com um número
			$_site = 'not yet'; // válido; começa com um sublinhado
			$täite = 'mansikka'; // válido; 'ä' é um caracter ASCII (extendido) 228
		?>
		
		<br/>
		
		<?php
			echo $var;
			echo "<br/>";
			print($var);
			print_r($obj);
		?>
		
		<p> Hello World!
		<?php $nome = "Ines"; ?>
		<p> Hello World again!
		<?php echo $nome; ?>
		
		<br/>
		
		<?php
			$numero = 10;
			$string = "Leandro";
			$pi = 3 + 0.14159;
		?>
		
		<?php
			$foo = 'Bob'; // Atribui o valor 'Bob' a variável $foo
			$bar = &$foo; // Referecia $foo através de $bar.
			$bar = "My name is $bar"; // Altera $bar...
			echo $bar;
			echo "<br/>";
			echo $foo; // $foo é alterada também.
		?>
		
		<br/>
		
		<?php
			$a_bool = TRUE; // um booleano
			$a_str = "foo"; // uma string
			$a_str2 = 'foo'; // uma string
			$an_int = 12; // um inteiro
			
			echo gettype($a_bool); // mostra: booleana
			echo "<br/>";
			echo gettype($a_str); // mostra: string
			
			// Se ele é um inteiro, incrementa-o com quatro
			if(is_int($an_int)){
				$an_int += 4;
			}
			
			// Se $a_bool é uma string, mostre-a
			// (não imprime nada)
			if(is_string($a_bool)){
				echo "String: $a_bool";
			}
		?>
		
		<br/>
		
		<?php
			$sub_string = substr(12345, 2, 2);
			print ("sub_string é = $sub_string");
			
			echo "<br/>";
			
			$int_var = 123456;
			$int_exp = -156 + 156; // a variável terá valor 0
			
			$int_base_10 = 1000; // 1000
			$int_base_8 = -01000; // -512
			$int_base_16 = 0x1000; // 4096
			
			$pri_doble = 15.789;
			$seg_doble = 0.456;
			$ter_doble = 5.0;
			$resultado = $ter_doble + 3;
			
			$valor_1 = 2.28888;
			$valor_2 = 2.21112;
			$resultado = $valor_1 + $valor_2;
			print ("$valor_1 + $valor_2 = $resultado");
			
			echo "<br/>";
			
			$num = 0;
			if($num == 0)
				$num = 10;
			else
				$num = 20;
			print("Número = $num");
			
			$string_1 = "Leandro";
			$string_2 = 'Leandro';
			$string_0 = "";
		?>
		
		<br/>
		
		<?php
			//Imprimindo meu vetor usando var_dump
			
			$vetor = array('Palio','Gol','Fiesta','Corsa');
			var_dump($vetor);
		?>
		
		<br/>
		
		<?php
			//Imprimindo meu vetor usando print_r
			
			$vetor = array('Palio','Gol','Fiesta','Corsa');
			print_r($vetor);
		?>
		
		<br/>
		
		<?php
			//Define o nome da variável
			
			$variavel = "nome";
		?>
		
		<?php
			//comandos
		?>
		
		<script language=”php”>
			//comandos
		</script>
		
		<?
			//comandos
		?>
		
		<%
			comandos
		%> /*REMOVIDA DO PHP */
		
		<br/>
		
		<?php
			//Função usada para definir fuso horário padrão
			date_default_timezone_set('America/Los_Angeles');
			
			//Manipulando  HMTL  e  PHP
			$data_hoje  =  date  ("d/m/Y",  time());
		?>
		
		<p  align="center">  Hoje  é  dia <?php  echo  $data_hoje  ;  ?>  </p>
		
		<br/>
		
		<?php
			$cidade = "Natal";
			$estado = "RN";
			$idade = 400;
			
			$frase_capital = "A cidade $cidade é a capital do $estado";
			$frase_idade = "$cidade tem mais de $idade anos";
			
			echo "<h3> $frase_capital </h3>";
			echo "<h4> $frase_idade </h4>";
		?>
		
		<br/>
		
		<?php
			//Declara variável com valor TRUE
			$exibirFrase = TRUE;
			
			//Testa se $exibirFrase é veradeiro (TRUE)
			if($exibirFrase)
			{
				echo "A variável booleana é VERDADEIRA!";
			}
		?>
		
		<br/>
		
		<?php
			//Declara variável numérica
			$umidade = 91;
			
			//Testa se $umidade maior que 90. Retorna um boolean
			$vaiChover = ($umidade > 90);
			
			//Testa se $vaiChover é verdadeiro
			if($vaiChover)
			{
				echo "Vai chover com toda certeza absoluta da Terra!";
			}
		?>
		
		<br/>
		
		<?php
			//Número Inteiro
			$num = 537;
			echo $num, " = Número Inteiro <br> <br>";
			
			//Número Negativo
			$num = -13;
			echo $num, " = Número Negativo <br> <br>";
			
			//Número Octal(Equivalente a 83 em decimal)
			$num = 0123;
			echo $num, " = Número Octal <br> <br>";
			
			//Número Hexadecimal(Equivalente a 26 em decimal)
			$num = 0x1A;
			echo $num, " = Número Hexadecimal <br> <br>";
			
			//Ponto Fluatuante
			$num = 1.234;
			echo $num, " = Número Flutuante <br> <br>";
			
			//Notação Científica
			$num = 4e23;
			echo $num, " = Número Científica <br> <br>";
		?>
		
		<br/>
		
		<?php
			$string = 'Esse texto foi armazenado usando uma variável do tipo string com aspas simples <br>';
			
			echo $string;
			
			$string = "Essa string foi armazenada usando aspas duplas"; echo $string;
		?>
		
		<br/>
		
		<?php
			//Criação do Array
			$carros = array('Palio', 'Corsa', 'Gol', "siena" => "Siena");
			
			echo $carros[1]."<br>";       //Resultado Corsa
			echo $carros["siena"]."<br>"; //Resultado Siena
		?>
		
		<br/>
		
		<?php
			//Adicionando novos elementos
			$carros[4] = "Clio";
			$carros[11] = "Versa";
			$carros[ ] = "Sandero";

			echo $carros[4] . "<br>";	//Resultado Clio 
			echo$carros[5] . "<br>";	//Sem Resultado 
			echo $carros[11] . "<br>";	//Resultado Versa
			echo $carros[12] . "<br>";	//Resultado Sandero
			
			$carros["popular"] = "Fusca";
			$carros["quantidade"] = 7;
			
			echo $carros["popular"] . "<br>";	//Resultado Fusca
			echo $carros["quantidade"] . " carros no array <br>";//Resultado 7
			
			$brasil["RN"][1] = "Natal";
			$brasil["RN"][2] = "Caicó";
			$brasil["RN"][3] = "Pau do Ferros";
			$brasil["PB"][1] = "João Pessoa";
			$brasil["PB"][2] = "Campina Grande";
			$brasil["MG"][1] = "Belo Horizonte";
			$brasil["MG"][2] = "Araguari";
			$brasil["GO"][1] = "Goiânia";
			
			echo $brasil["RN"][1] . "<br>"; //Resultado Natal
			echo $brasil["MG"][2] . "<br>"; //Resultado Araguari
			echo $brasil["GO"][1] . "<br>"; //Resultado Goiânia
			
			class Computador
			{
				var $cpu;
				
				function ligar()
				{
					echo "Ligando computador a {$this->cpu}...";
				}
			}
			
			$obj = new Computador;
			$obj->cpu = "500Mhz";
			$obj->ligar();
			
			echo "<br/>";
			
			//Define o valor máximo de clientes
			define("MAXIMO_CLIENTE",100);
			
			echo MAXIMO_CLIENTE;
			
			echo "<br/>";
			
			$num = 5000;
			
			function escopo_funcao()
			{
				$num = 999;
				
				echo $num."<br>";
			}
			
			echo $num."<br>";
			
			escopo_funcao();
			
			$num = 5000;
			
			function escopo_global()
			{
				global $num;
				
				$num+=999;
				
				echo $num . "<br>";
			}
			
			echo $num . "<br>"; escopo_global();
			
			$num = 5000;
			
			function escopo_global_array()
			{
				echo $GLOBALS["num"]."<br>";
				
				$GLOBALS["num"]++;
			}
			
			escopo_global_array();
			
			echo $num."<br>";
			
			$x = 50;
			$y = 2.35;
			$soma = (int) $y + $x; echo	$soma . "<br>";
			$soma = (float)($y + $x);
			
			echo	$soma . "<br>";
			
			$cidade = "Pau dos Ferros";
			$regiao = "Alto Oeste";
			$estado = "Rio Grande do Norte";
			
			echo "A cidade de $cidade fica no $regiao do $estado";
			
			$p = "Penta";
			
			echo "O Brasil é $pcampeão<br>";
			echo "O Brasil é ${p}campeão<br>";
			echo "O Brasil é ".$p."campeão<br>";
			
			$texto = "Natal";
			$futuro_identificador = "cidade";
			$$futuro_identificador = $texto;
			
			echo "$cidade é no litoral do RN";
			
			echo "<h3>Pós-incremento</h3>";
			$a = 5;
			echo "Deve ser 5: " . $a++ . "<br />\n"; echo "Deve ser 6: " . $a . "<br />\n";

			echo "<h3>Pré-incremento</h3>";
			$a = 5;
			echo "Deve ser 6: " . ++$a . "<br />\n"; echo "Deve ser 6: " . $a . "<br />\n";

			echo "<h3>Pós-decremento</h3>";
			$a = 5;
			echo "Deve ser 5: " . $a-- . "<br />\n";
			echo "Deve ser 4: " . $a . "<br />\n";

			echo "<h3>Pré-decremento</h3>";
			$a = 5;
			echo "Deve ser 4: " . --$a . "<br />\n"; echo "Deve ser 4: " . $a . "<br />\n";
			
			$soma = ($valor1 = 4) + 5; // $soma é igual a 9 agora e $valor1 foi configurado como 4.
			$valor2 = 20;
			$valor3 = 30;

			$soma += 1; //$soma fica com 10
			$soma += $valor2; //$soma fica com 10+20=30
			$soma *= $valor3; //$soma fica com 30*30=900
			$soma %= 100;
			
			$saudacao = "Bom Dia!";
			
			// configura $saudacao para "Bom Dia!", como em $saudacao = $saudacao . "Dia!";
			
			echo $saudacao . " Hoje vai ter " . $soma . " % tristeza!";
			
			echo "<br/>";
			
			var_dump(0 == "a"); // 0 == 0 -> true
			var_dump("1" == "01"); // 1 == 1 -> true
			var_dump("1" == "1e0"); // 1 == 1 -> true
			
			// foo() nunca será chamada como estes operadores são short-circuit
			$a = (false  && foo());
			$b = (true  || foo());
			$c = (false  and foo());
			$d = (true  or  foo());
			
			// "||" tem maior precedência que "or"
			$e = false || true; // $e vai receber (false || true) que é verdadeiro
			$f = false  or true; // $f vai receber falso var_dump($e, $f);
			
			// "&&" tem maior precedência que "and"
			$g = true && false; // $g vai receber (true && false) que é falso
			$h = true and false; // $h vai receber verdadeiro var_dump($g, $h);
			
			echo "<br/>";
			
			if(empty($nome) OR empty($email) OR empty($cpf)){
				echo "Você deve preencher os campos nome, e-mail e CPF!";
				//exit;
			}
			
			echo "<br/>";
			
			$nota = 8;
			
			if($nota>=6){
				echo "Você passou por média!";
			}else{
				echo "Você ficou de recuperação...!";
			}
			
			echo "<BR><BR> Mesma verificação usano o operador ternário <BR><BR>";
			
			echo ($nota>=6) ? "Você passou por média!" : "Você ficou de recuperação...!";
			
			echo "<br/>";
			
			$prova1 = 7;
			$prova2 = 5;
			$nota = ($prova1 + $prova2) / 2;

			if($nota<3)
			$desempenho ="PÉSSIMO";
			elseif($nota<5)
			$desempenho ="RUIM"; 
			elseif($nota<7)
			$desempenho ="MÉDIO";
			elseif($nota<8)
			$desempenho ="BOM";
			else
			$desempenho ="EXCELENTE";

			echo "O seu desempenho foi $desempenho";
			
			echo "<br/>";
			
			$numero = 2;
			
			if($numero == 0){
				echo "O número é 0 <br/>";
			}
			elseif($numero == 1){
				echo "O número é 1 <br/>";
			}
			elseif($numero == 2){
				echo "O número é 2 <br/>";
			}
			
			$numero = 2;
			
			switch($numero)
			{
				case 0:
					echo "O número é 0 <br/>";
					break;
				case 1:
					echo "O número é 1 <br/>";
					break;
				case 2:
					echo "O número é 2 <br/>";
					break;
			}
			
			$opcao = "";
			
			switch($opcao)
			{
				case 's':
					echo "Voce escolheu SIM!";
					break;
				case 'n':
					echo "Voce escolheu NÃO!";
					break;
				default:
					echo "Opção inválida";
					break;
			}
			
			echo "<br/>";
			
			$cont=1;
			
			while($cont<100){
				echo "O valor atual do contador é $cont <br>";
				$cont++;
			}
			
			$numero = 1;

			do
			{
				echo "O valor atual do contador é $numero <br>";
				$numero++;
				
			}while($numero<15);
		?>
		
		<br/>
		
		<?php
			/*while($cont!=0)
			{
				echo "O valor atual do contador é $cont <br>";
				$cont++;
			};
			*/
		?>
		
		<br/>
		
		<?php
			$i=0; $f=99;
            
			while($i < $f)
			{
				$i++;
				$f--;
				
				echo "I = $i   F = $f<br>";
			}
			
			echo "Contagem Progressiva <br> <br>";
			
			for($cont=0;$cont<10;$cont++){
				echo "A variável \$cont vale $cont <br>";
			}
			
			echo "<br> Contagem Regressiva <br> <br>"; 
			
			for($cont=13;$cont>0;$cont--){
				echo "A variável \$cont vale $cont <br>";
			}
		?>
		
		<br/>
		
		<?php
			echo "fazendo uma contagem regressiva";
            
            for ($numero = 15 ; $numero >= 0; $numero--){
                echo $numero .", ";
            }
            
            echo "...final";
			
			$vetor[0][0] = "elemento00";
			$vetor[0][1] = "elemento01";
			$vetor[1][0] = "elemento10";
			$vetor[1][1] = "elemento11";
			for($contI=0;$contI<2;$contI++){ 
				for($contJ=0;$contJ<2;$contJ++){
					echo "O valor do vetor é " . $vetor[$contI][$contJ]; echo "<br>";
				}
			}
			
			$vetor = array (1,2,3,4,5);
			
			foreach($vetor as $v)
			{
				print "O valor atual do vetor é $v. <br>";
			}

			$a = array ("um"=>1, "dois"=>2, "tres"=>3);
			
			foreach($a as $chave => $valor)
			{
				print("\$a[$chave] => $valor.<br>");
			}
		?>
		
		<br/>
		
		<?php
			ini_set('default_charset','charset=iso-8859-1');
            $vetor = array ("SP"=>"São Paulo","PE"=>"Recife","AM"=>"Manaus",); 
			
			foreach($vetor as $estado => $capital)
			{
				print "A Capital de $estado é $capital. <br>";
			}
			
			$vetor = array (1,2,3,4,5,6,7,8,9,10);
			
			$k = 0;

			while($k < 10)
			{
				if($vetor[$k]=="sair")
				{
					break;
				}
			
			echo $vetor[$k] . "<br>";

			$k++;
			}
			
			$k = 0;
			
			$i = 0;
			
			while($k < 10)
			{
				$i++; $k++;
				
				while($i<20)
				{
					if($i==10)
					{
						echo "Encerrando o primeiro while <br>"; break;
						echo "Essa linha nunca vai ser impressa";
					}
					elseif($i==15)
					{
						echo "Encerrando os 2 whiles..."; break 2;
					}
					$i++;
				}
			}
			
			echo "<br/>";
			
			$vetor = array (1,3,5,7,8,11,12,15,20);
			
			for($i=0; $i<sizeof($vetor);$i++)
			{
				// é impar
				if($vetor[$i]%2 != 0)
				{
					continue;
				}
				
				echo "O número " . $vetor[$i] . " é par.<br>";
			}
         ?>
	</body>
</html>