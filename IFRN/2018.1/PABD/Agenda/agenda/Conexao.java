package agenda;
import java.sql.*;
public class Conexao {
    static Connection conexao;
    
    static Connection getConexao(){
        String driver = "com.mysql.jdbc.Driver";
        String banco = "agenda";
        String host = "LocalHost";
        String porta = "3306";
        String usuario = "root";
        String senha = "";
        
        String caminho = "jdbc:mysql://" + host + ":" + porta + "/" + banco;
        try{
            Class.forName(driver); //carrega o driver
            conexao = DriverManager.getConnection(caminho, usuario, senha); //conecta
            System.out.println("Conectado ao BD.");
            
        }catch(Exception e){
            System.out.println("Erro ao conectar.");
            e.printStackTrace(); //detalhes do erro
        }//catch
        return conexao;
    }//getConexao
}//conexao
