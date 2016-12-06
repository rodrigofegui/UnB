package bancoDados;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import utilitario.Erro;


/**
 * Classe responsável pela comunicação com o Banco de Dados 
 * @author	Rodrigo Guimarães
 * @version	1.0
 * @since	27/11/2016
 */
public abstract class Conexao{
	private static final String SERVIDOR = "localhost:3306";
	private static final String NOME = "t3_si";
	private static final String SSL_ERROR = "?autoReconnect=true&useSSL=false";
	private static final String URL = "jdbc:mysql://" + SERVIDOR + "/" + NOME + SSL_ERROR;
	private static final String USUARIO = "estudante";
	private static final String SENHA = "T3si@senha";
	private static final String DRIVER = "com.mysql.jdbc.Driver";
	

	
	/**
	 * Tentativa de iniciar uma comunicação com o BD, conforma a URL, usuário e senha
	 * @return Conexão estabelecida ou não com o BD
	 */
	public static Connection iniciarConexao (){
		try {
			Class.forName(DRIVER);
			 
			return DriverManager.getConnection(URL, USUARIO, SENHA);

		}catch (ClassNotFoundException e){
			System.out.println(Erro.abrirConexao(true));
			return null;
			
		}catch ( SQLException e) {
			System.out.println(Erro.abrirConexao(false));
			return null;
		}
	}
	
	/**
	 * Encerrar conexão existente com o BD
	 * @param conexao Conexão a ser encerrada
	 */
	public static void encerrarConexao (Connection conexao){		
		try{
			if (conexao != null)
				conexao.close();


        }catch (SQLException e) {
        	System.out.println(Erro.encerrarConexao());
			e.printStackTrace();
        }
	}
	
	/**
	 * Encerrar conexão existente com o BD, coexistindo uma declaração
	 * @param conexao Conexão a ser encerrada
	 * @param declaracao Declaração a ser encerrada
	 */
	public static void encerrarConexao (Connection conexao, PreparedStatement declaracao){
		encerrarConexao(conexao);
			
		try {
			if (declaracao != null)
				declaracao.close();

        } catch (SQLException e) {
        	System.out.println(Erro.encerrarConexao());
			e.printStackTrace();
        }
	}
	
	/**
	 * Encerrar conexão existente com o BD, coexistindo uma declaração e um grupo
	 * de resultado
	 * @param conexao Conexão a ser encerrada
	 * @param declaracao Declaração a ser encerrada
	 * @param resultados Grupo de resultados a ser encerrado
	 */
	public static void encerrarConexao (Connection conexao, PreparedStatement declaracao, ResultSet resultados){
		encerrarConexao(conexao, declaracao);
			
		try {
			if (resultados != null)
				resultados.close();

        } catch (SQLException e) {
        	System.out.println(Erro.encerrarConexao());
			e.printStackTrace();
        }
	}

	/**
	 * Reiniciar uma comunicação com o BD, ou seja, encerra e inicia a comunicação
	 * @param conexao Conexão a ser reiniciada
	 * @return Conexão reestabelecida ou não com o BD
	 */
	public static Connection reinicarConexao (Connection conexao){
		encerrarConexao(conexao);
		
		return iniciarConexao();
	}
}
