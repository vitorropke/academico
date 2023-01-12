import java.util.ArrayList;
import java.util.Optional;
import java.util.Random;

public class Banco {
    private String tipoBanco;
    private ArrayList<Conta> contasAssociadas = new ArrayList<>();
    public Banco() {
    }

    public Banco setTipoBanco(String tipoBanco) {
        this.tipoBanco = tipoBanco;
        return this;
    }

    public void criarConta(String login, String senha, Pessoa p){
        Random rand = new Random();
        var novaConta = new Conta(login, senha, p, rand.nextInt(1000));
        contasAssociadas.add(novaConta);
        //return novaConta;
    }


    
    public Optional<Conta> buscarConta(Pessoa p){
        return contasAssociadas.stream().filter(conta -> conta.getTitular().equals(p)).findFirst();
    }

    public Optional<Conta> buscarConta(String log){
        return contasAssociadas.stream().filter(conta -> conta.getLogin().equals(log)).findFirst();
    }
}
