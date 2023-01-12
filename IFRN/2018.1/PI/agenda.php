<?php
	$servidor = "localhost";
	$usuario = "root";
	$password = "";
	$bd = "contato";

	$conn = new mysqli($servidor, $usuario,$password,$bd);

	if ($conn->connect_error){
		die("Connection failed:".$conn->connect_error);
	}
	echo"Connected successfully";
	
	$nome = $_POST['nome'];
	$idade = $_POST['idade'];
	$telefone = $_POST['telefone'];
	$email = $_POST['email'];
	$endereco = $_POST['endereco'];
	
	$sql = "INSERT INTO cadastro(nome,idade, telefone, email, endereco) VALUES ('$nome', '$idade', '$telefone', '$email', '$endereco' )";
	
	if ($conn->query($sql) === TRUE){
		echo "New record created successfully";
	}else{
		echo "Error: ".$sql."<br>".$conn->error;
	}
	
	$conn->close();
?>