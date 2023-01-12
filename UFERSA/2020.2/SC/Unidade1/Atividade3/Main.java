import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Stream;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
/*
        int chave = 102;

        Pessoa aleff = new Pessoa(23,"Aleff","01766325580", "Rua Farias, 163","a@a.com");

        Conta conta1 = new Conta(aleff,123);

        conta1.solicitarDeposito("150");
        conta1.solicitarDeposito("300");

        //CifradeVigenere c2 = new CifradeVigenere();
        String key = "POI";
        String msg = "ABC";
        String crip = CifraDeVernam.encriptar(msg,key);
        System.out.println(crip);

        System.out.println(CifraDeVernam.decriptar(crip, key));
        */
        Scanner entradaUsuario = new Scanner(System.in);
        String login;
        String senha, chaveSenha;
        
        Banco b = new Banco().setTipoBanco("Banco do Brasil");

        Pessoa aleff = new Pessoa(23,"Aleff","01766325580", "Rua Boston, 163","a@a.com");
        //Pessoa ropke = new Pessoa(21, "Bilbo", "09000000000", "Av Roberto Martins, 54", "vitor@hotmail.com");
        
        /*Conta conta1 = new Conta("a", "a", aleff, 123);
        Conta conta2 = new Conta("abc", "abc", ropke, 154);
        Conta conta3 = new Conta("0", "0", aleff, 3);*/

        Pessoa p = new Pessoa(21, "asas", "123", "Maria Salem Duarte", "tt@hotmail");
        Pessoa p2 = new Pessoa(25, "asd", "456", "Maria Salem asd", "42@sds");

        b.criarConta("a", "a", aleff);
        b.criarConta("abc", "abc", p);
        b.criarConta("def", "def", p2);
        
        // Autentica o cliente
        System.out.println("Login: ");
        login = entradaUsuario.nextLine();

        Conta conta = b.buscarConta(login).get();
        
        System.out.println("Senha: ");
        senha = entradaUsuario.nextLine();
        chaveSenha = CifraDeVernam.gerarChave(senha);
        senha = CifraDeVernam.encriptar(senha, chaveSenha);

        conta.autenticar(senha, chaveSenha);

        int     comando;
        String  saqueSolicitado, depositoSolicitado, valorTransferencia, loginContaDestino;
        Conta   contaDestino;
        while (true) {
            System.out.println();
            System.out.println("1: Sacar");
            System.out.println("2: Depositar");
            System.out.println("3: Transferir");
            System.out.println("4: Consultar saldo");
            System.out.println("5: Simular rendimento");
            System.out.print("Digite o comando a ser executado: ");
            comando = entradaUsuario.nextInt();
            entradaUsuario.nextLine();

            switch (comando) {
                case 1:
                    System.out.print("\nDigite o valor do saque: ");
                    saqueSolicitado = entradaUsuario.nextLine();

                    conta.sacar(saqueSolicitado);
                    break;
                case 2:
                    System.out.print("\nDigite o valor do deposito: ");
                    depositoSolicitado = entradaUsuario.nextLine();

                    conta.solicitarDeposito(depositoSolicitado);
                    break;
                case 3:
                    System.out.print("\nDigite a conta destino usando o login PIX: ");
                    loginContaDestino = entradaUsuario.nextLine();

                    contaDestino = b.buscarConta(loginContaDestino).get();

                    System.out.print("\nDigite o valor de transferencia: ");
                    valorTransferencia = entradaUsuario.nextLine();

                    conta.transferir(contaDestino, valorTransferencia);
                    break;
                case 4:
                    System.out.print("\nSeu saldo é " + conta.getSaldo());
                    break;
                case 5:
                    conta.simularRendimento();
                    break;
                default:
                    System.exit(0);
                    break;
            }
        }
        
        /*
        String chave = CifraDeVernam.gerarChave(3);
        chave = "abc";

        CifraDeCesar c1 = new CifraDeCesar();
        String crip = c1.encriptar(chave, "896");
        System.out.println(crip);

        String decrip = c1.decriptar(chave,crip);
        System.out.println(decrip);
        int valor = Integer.parseInt(decrip);
        System.out.println(valor);

        */

    }

}
