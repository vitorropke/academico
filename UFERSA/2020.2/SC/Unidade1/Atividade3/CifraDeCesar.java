public class CifraDeCesar {

    private int chave;
    private static StringBuilder textoCifrado = null;
    private static StringBuilder textoDecifrado = null;

    public CifraDeCesar(){}

    public static String encriptar(int chave, String texto) {

        textoCifrado = clearStringBuilder(textoCifrado);

        for (int x = 0; x < texto.length(); x++) {
            int letraCifradaASCII = (((int) texto.charAt(x)) + chave);
            textoCifrado.append((char) letraCifradaASCII);
        }
        return textoCifrado.toString();
    }

    public static String decriptar(int chave, String texto) {

        textoDecifrado = clearStringBuilder(textoDecifrado);

        chave *= -1;

        for (int x = 0; x < texto.length(); x++) {
            int letraDecifradaASCII = (((int) texto.charAt(x)) + chave);
            textoDecifrado.append((char) letraDecifradaASCII);
        }

        return textoDecifrado.toString();
    }

    /* Características StringBuilder
    *Armazena caracteres especificados pela sua capacidade, caso ela seja excedida,
     é aumentada para acomodar os caracteres adicionais;
    *Não precisa alocar novos objetos quando realiza uma concatenação;
    *Não são sincronizadas;
    *Não são seguras para threads;
    *
    * Uma vantagem sobre a classe String é a concatenação de strings.
    * Pois quando concatena strings com StringBuilder é invocado o método append.
    * Esse método aloca novas strings concatenadas para o mesmo objeto,
        ou seja, cada vez que concatena strings não são criadas cópias dos objetos
        como é realizado pelo método concat da classe String, contribuindo para um melhor desempenho do sistema. */
    //verifica se a variavel ja foi iniciada se ja limpa a memoria usada
    //pela variavel para ser usada novamente

    public static StringBuilder clearStringBuilder(StringBuilder variavelStringBuilder) {
        if (variavelStringBuilder == null) {
            variavelStringBuilder = new StringBuilder();
        } else {
            variavelStringBuilder.delete(0, variavelStringBuilder.length());
        }
        return variavelStringBuilder;
    }
}