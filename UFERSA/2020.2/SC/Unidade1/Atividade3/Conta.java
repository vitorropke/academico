public class Conta extends Banco{
    private String      login;
    private String      senha;
    private Pessoa      titular;
    private int         numero;
    private double      saldo;

    public Conta(String login, String senha, Pessoa titular, int numero) {
        setLogin(login);
        setSenha(senha);
        this.saldo = 0;
        this.titular = titular;
        this.numero = numero;
    }

    public void autenticar(String senha, String chaveSenha) {
        senha = CifraDeVernam.decriptar(senha, chaveSenha);

        if (senha.equals(getSenha())) {
            System.out.println("Acesso garantido!\n");
        } else {
            System.out.println("Acesso negado!");
            System.exit(0);
        }
    }
    
    public void sacar(String valor){
        double valord = Double.parseDouble(valor);
        if(this.saldo >= valord){
            this.saldo -= valord;
            System.out.println("Valor sacado: "+ valord);
            System.out.println("Novo saldo: "+ this.saldo);
        }  else {
            System.out.println("Saldo insuficiente");
        }
    }

    public void solicitarDeposito(String valor){
        int chave = this.titular.getIdade();
        String crip = CifraDeCesar.encriptar(chave, valor);
        try {
            double aux = Double.parseDouble(valor);
        } catch (NumberFormatException e) {
            System.out.println("Numero com formato errado!");
        }
        System.out.println("******************\n" +
                            "Solicitação de Deposita enviada\n" +
                            "Valor: "+ crip +
                            "\n******************");
        this.depositar(crip);
    }

    private void depositar(String valor){
        int chave = this.titular.getIdade();
        String decrip = CifraDeCesar.decriptar(chave,valor);
        System.out.println("******************\n" +
                            "Solicitação de Deposito recebida\n" +
                            "Valor: R$" + decrip +
                            "\n******************" );
        double valord = Double.parseDouble(decrip);
        this.saldo += valord;
        System.out.print("Depositado:  R$");
        System.out.printf("%.2f", valord);
        System.out.println();
        System.out.print("Novo: saldo: R$");
        System.out.printf("%.2f", this.saldo);
        System.out.println();
    }

    public void transferir(Conta conta, String valor){
        double valord = Double.parseDouble(valor);
        if(this.saldo >= valord){
            conta.setSaldo(valord);
            this.saldo -= valord;
            System.out.print("Transferido: R$");
            System.out.printf("%.2f", valord);
            System.out.print(" para conta "+ conta.numero);
            System.out.println();
        } else {
            System.out.println("Saldo insuficiente");
        }
    }

    public void simularRendimento() {
        System.out.println();
        System.out.print("Rendimento em 3 meses:  R$");
        System.out.printf("%.2f", this.saldo * 0.05 * 3);
        System.out.println();
        System.out.print("Rendimento em 6 meses:  R$");
        System.out.printf("%.2f", this.saldo * 0.05 * 6);
        System.out.println();
        System.out.print("Rendimento em 12 meses: R$");
        System.out.printf("%.2f", this.saldo * 0.05 * 12);
        System.out.println();
    }

    public String getLogin() {
        return login;
    }
    public void setLogin(String login) {
        if ((login != null) && (login != "")) {
            this.login = login;
        } else {
            System.out.println("Login nao pode ser vazio!");
        }
    }
    
    public String getSenha() {
        return senha;
    }
    public void setSenha(String senha) {
        if ((senha != null) && (senha != "")) {
            this.senha = senha;
        } else {
            System.out.println("Senha nao pode ser vazia!");
        }
    }

    public Pessoa getTitular() {
        return titular;
    }

    public void setTitular(Pessoa titular) {
        this.titular = titular;
    }

    public int getNumero() {
        return numero;
    }

    public void setNumero(int numero) {
        this.numero = numero;
    }

    public double getSaldo() {
        return saldo;
    }

    public void setSaldo(double saldo) {
        this.saldo = saldo;
    }

    @Override
    public String toString() {
        return "Conta{" +
                "titular=" + titular +
                ", numero=" + numero +
                ", saldo=" + saldo +
                '}';
    }
}
