package repeticao;
public class Repeticao {
    public static void main(String[] args) {
        // exemplo usando WHILE (enquanto)
        // escrever de 1 a 100 na tela
        int x = 1;
        while (x <= 100){
            System.out.print(x + " ");
            x = x + 1;
            // x += 1
            // x++;
        }//while
        
        System.out.println("\n\n");
        
        for (x = 100; x >= 1; x--){
            System.out.print(x + " ");
            
        }//for
        
    }
}
