package padroes.comportamentais.command;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		boolean stayOnLoop = true;
		do {
			System.out.println();
			System.out.println("CALCULADORA");
			System.out.println();
			System.out.println("1 - Adicao");
			System.out.println("2 - Subtracao");
			System.out.println("3 - Multiplicacao");
			System.out.println("4 - Divisao");
			System.out.println();
			System.out.print("O que voce quer fazer: ");
			int operation = scanner.nextInt();
			scanner.nextLine();

			Receiver receiver = new Receiver();
			Command command;
			Invoker invoker = new Invoker();
			double number1;
			double number2;

			switch (operation) {
			case 1:
				System.out.println();
				System.out.print("Digite a primeira parcela: ");
				number1 = scanner.nextDouble();
				scanner.nextLine();
				System.out.print("Digite a segunda parcela: ");
				number2 = scanner.nextDouble();
				scanner.nextLine();
				System.out.println();

				command = new AddCommand(receiver, number1, number2);
				invoker.setCommand(command);
				invoker.executeCommand();

				break;
			case 2:
				System.out.println();
				System.out.print("Digite o minuendo: ");
				number1 = scanner.nextDouble();
				scanner.nextLine();
				System.out.print("Digite o subtraendo: ");
				number2 = scanner.nextDouble();
				scanner.nextLine();
				System.out.println();

				command = new SubCommand(receiver, number1, number2);
				invoker.setCommand(command);
				invoker.executeCommand();

				break;
			case 3:
				System.out.println();
				System.out.print("Digite o multiplicando: ");
				number1 = scanner.nextDouble();
				scanner.nextLine();
				System.out.print("Digite o multiplicador: ");
				number2 = scanner.nextDouble();
				scanner.nextLine();
				System.out.println();

				command = new MulCommand(receiver, number1, number2);
				invoker.setCommand(command);
				invoker.executeCommand();

				break;
			case 4:
				System.out.println();
				System.out.print("Digite o dividendo: ");
				number1 = scanner.nextDouble();
				scanner.nextLine();
				System.out.print("Digite o divisor: ");
				number2 = scanner.nextDouble();
				scanner.nextLine();
				System.out.println();

				command = new DivCommand(receiver, number1, number2);
				invoker.setCommand(command);
				invoker.executeCommand();

				break;
			default:
				System.out.println();
				System.out.println("Tchau");

				stayOnLoop = false;

				break;
			}
		} while (stayOnLoop);

		scanner.close();
	}

}
