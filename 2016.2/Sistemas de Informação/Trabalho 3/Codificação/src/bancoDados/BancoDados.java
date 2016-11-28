package bancoDados;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

/**
 * Classe responsável pela implementação lógica de um gerenciador de Banco de Dados 
 * @author	Rodrigo Guimarães
 * @version	1.0
 * @since	27/11/2016
 */
public class BancoDados{
	private String servidor;
	private String nome;
	private String url;
	private String usuario;
	private String senha;
	private String driver;
	private Connection conexao;
	private String status;
	
	
	
	
	/**
	 * Construção de um Banco de Dados, por maneira default
	 */
	public BancoDados (){
		setServidor("");
		
		setNome("");
		
		setUrl("");
		
		setUsuario("");
		
		setSenha("");
		
		setDriver("");
		
		setConexao(null);
		
		setStatus("Não conectado");
	}
	
	
	
	
	/**
	 * Valor atribuído ao servidor do BD
	 * @return Nome do servidor do BD
	 */
	public String getServidor() {
		return servidor;
	}
	
	/**
	 * Atribui valor ao servidor do BD
	 * @param servidor Valor a ser atribuído
	 */
	public void setServidor(String servidor) {
		this.servidor = servidor;
	}
	
	/**
	 * Valor atribuído ao nome do BD
	 * @return Nome do BD
	 */
	public String getNome() {
		return nome;
	}

	/**
	 * Atribui valor ao nome do BD
	 * @param nome Valor a ser atribuído
	 */
	public void setNome(String nome) {
		this.nome = nome;
	}

	
	/**
	 * Valor atribuído ao link de conexão do BD
	 * @return Link de conexão do BD
	 */
	public String getUrl() {
		return url;
	}
	
	/**
	 * Atribui valor ao link de comunicação do BD
	 * @param url Valor a ser atribuído
	 */

	public void setUrl(String url) {
		this.url = url;
	}

	
	/**
	 * Valor atribuído ao usuário do BD
	 * @return Usuário do BD
	 */
	public String getUsuario() {
		return usuario;
	}
	
	/**
	 * Atribui valor ao usuário do BD
	 * @param usuario Valor a ser atribuído
	 */

	public void setUsuario(String usuario) {
		this.usuario = usuario;
	}

	/**
	 * Valor atribuído à senha do usuário do BD
	 * @return Senha do usuário do BD
	 */
	public String getSenha() {
		return senha;
	}

	/**
	 * Atribui valor à senha do usuário do BD
	 * @param senha Valor a ser atribuído
	 */
	public void setSenha(String senha) {
		this.senha = senha;
	}

	/**
	 * Valor atribuído ao driver de comunicação com o BD
	 * @return Driver de comunicação com o BD
	 */
	public String getDriver() {
		return driver;
	}
	
	/**
	 * Atribui valor ao driver de comunicação com o BD
	 * @param driver Valor a ser atribuído
	 */

	public void setDriver(String driver) {
		this.driver = driver;
	}
	

	/**
	 * Valor atribuído à conexão com o BD
	 * @return Conexão com o BD
	 */
	public Connection getConexao() {
		return conexao;
	}

	/**
	 * Verificando se há conexão ativa com o BD
	 * @return Se houver conexão, retorna true;
	 * caso contrário, false
	 */
	public boolean isConectado(){
		if (getConexao() == null)
			return false;
		
		return true;
	}
	
	/**
	 * Atribui valor à conexão com o BD
	 * @param conexao Valor a ser atribuído
	 */
	public void setConexao(Connection conexao) {
		this.conexao = conexao;
	}

	
	/**
	 * Valor atribuído ao status da conexão com o BD
	 * @return Status do BD
	 */
	public String getStatus() {
		return status;
	}
	
	/**
	 * Atribui valor ao stats conexão com o BD
	 * @param status Valor a ser atribuído
	 */
	public void setStatus(String status) {
		this.status = status;
	}
	
	
	
	
	/**
	 * Inicialização do BD específico para o desenvolvimento do trabalho 3
	 */
	public void inicializacaoEspecifica (){
		setServidor("localhost:3306");
		
		setNome("t3_si");
		
		setUrl("jdbc:mysql://" + getServidor() + "/" + getNome());
		
		setUsuario("estudante");
		
		setSenha("t3si_");
		
		setDriver("com.mysql.jdbc.Driver");
	}
	
	
	
	
	/**
	 * Tentativa de iniciar uma comunicação com o BD, conforma a URL, usuário e senha;
	 * configurando o status conforme o resultado da tentativa de comunicação
	 */
	public void iniciarConexao (){
		try {
			Class.forName(getDriver());
			 
			setConexao(DriverManager.getConnection(getUrl(), getUsuario(), getSenha()));
			
			if (isConectado())
				setStatus("STATUS -> Conectado com sucesso!");
			else
				setStatus("STATUS -> Não foi possível realizar conexão");
			
		}catch (ClassNotFoundException e) {
			System.out.println("O driver expecificado não foi encontrado.");
			e.printStackTrace();
		} catch (SQLException e) {
			System.out.println("Na tentativa de inicialização, não foi possível conectar ao Banco de Dados.");
			e.printStackTrace();
		}
	}
	
	/**
	 * Encerrar conexão existente com o BD
	 */
	public void encerrarConexao (){
		if (isConectado()){
			try {
				 
	            getConexao().close();
	 
	            setStatus("STATUS -> Conexão encerrada com sucesso.");
	 
	        } catch (SQLException e) {
	        	System.out.println("Na tentativa de encerramento, não foi possível conectar ao Banco de Dados.");
				e.printStackTrace();
	        }
		}
	}

	/**
	 * Reiniciar uma comunicação com o BD, ou seja, encerra e inicia a comunicação
	 */
	public void reinicarConexao (){
		encerrarConexao();
		
		iniciarConexao();
	}
}
