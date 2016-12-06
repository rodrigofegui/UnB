package bancoDados.manipulacao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.LinkedList;

import bancoDados.Conexao;
import bancoDados.tabelas.DecimoTerceiro;
import bancoDados.tabelas.Disciplina;
import utilitario.Erro;

/**
 * Classe responsável pela manipulação da tabela Disciplina no Banco de Dados 
 * @author	Rodrigo Guimarães
 * @version	1.0
 * @since	29/11/2016
 */
public abstract class DisciplinaM {
	/**
	 * Criação de uma instância da tabela Disciplina no BD
	 * @param disciplina Instância a ser registrada no BD
	 */
	public static void inserir (Disciplina disciplina){
		Connection conexao = Conexao.iniciarConexao();
		PreparedStatement declaracao = null;
		String instrucao = "INSERT INTO Disciplina (descricao"; 
		String interrogacao = "";
	
		if (disciplina.getCodigo() != -1){
			instrucao += ", codigo)";
			interrogacao = "?, ?";
		
		}else{
			instrucao += ")";
			interrogacao = "?";
		}
		
		instrucao += " VALUES (" + interrogacao + ")";
		
		try{
			declaracao = conexao.prepareStatement(instrucao);
			
			declaracao.setString(1, disciplina.getDescricao());
			
			if (disciplina.getCodigo() != -1)
				declaracao.setInt(2, disciplina.getCodigo());
			
			declaracao.executeUpdate();
			
		}catch (SQLException e) {
			System.out.println(Erro.inserirBD("Disciplina"));
			
		}finally{
			Conexao.encerrarConexao(conexao, declaracao);
		}
	}
	
	/**
	 * Criação de uma instância da tabela Disciplina no BD, sem ter uma
	 * Disciplina jpa criada
	 * @param descricao Descrição da disciplina a ser criada e inserida no BD
	 */
	public static void inserir (String descricao){
		Disciplina disciplina = new Disciplina();
		
		disciplina.setDescricao(descricao);
		
		inserir(disciplina);
	}
	
	/**
	 * Leitura de toda a Tabela Disciplina no BD
	 * @return Todas as instâncias existentes no BD
	 */
	public static LinkedList<Disciplina> lerCompleto (){
		Connection conexao = Conexao.iniciarConexao();
		PreparedStatement declaracao = null;
		ResultSet resultado = null;
		LinkedList<Disciplina> disciplinas = new LinkedList<Disciplina>();
		String instrucao = "SELECT * FROM Disciplina";
		
		try {
			declaracao = conexao.prepareStatement(instrucao);
			resultado = declaracao.executeQuery();
			
			while (resultado.next()){
				Disciplina disciplina = new Disciplina();
				
				disciplina.setCodigo(resultado.getInt("codigo"));
				disciplina.setDescricao(resultado.getString("descricao"));
				
								
				disciplinas.add(disciplina);
			}
				
			
		}catch (SQLException e) {
			System.out.println(Erro.lerBD("Disciplina"));
		
		}finally {
			Conexao.encerrarConexao(conexao, declaracao, resultado);
			
		}
		
		return disciplinas;
	}
	
	/**
	 * Atualização de uma instância da tabela Disciplina no BD
	 * @param disciplina Instância a ser atualizada no BD
	 */
	public static void atualizar (Disciplina disciplina){
		Connection conexao = Conexao.iniciarConexao();
		PreparedStatement declaracao = null;
		String instrucao = "UPDATE Disciplina SET"
							+ "	descricao = ?"
							+ " WHERE codigo = ?";
		
		try{
			declaracao = conexao.prepareStatement(instrucao);
			
			declaracao.setString	(1, disciplina.getDescricao());
			declaracao.setInt		(2, disciplina.getCodigo());
			
			declaracao.executeUpdate();
			
		}catch (SQLException e) {
			System.out.println(Erro.atualizarBD("Disciplina"));
			
		}finally{
			Conexao.encerrarConexao(conexao, declaracao);
		}
	}
	
	/**
	 * Exclusão de uma instância da tabela Disciplina do BD
	 * @param disciplina Instância a ser excluída do BD
	 */
	public static void deletar (Disciplina disciplina){
		Connection conexao = Conexao.iniciarConexao();
		PreparedStatement declaracao = null;
		String instrucao = "DELETE FROM Disciplina WHERE codigo = ?";
		
		try{
			declaracao = conexao.prepareStatement(instrucao);
			
			declaracao.setInt		(1, disciplina.getCodigo());
			
			declaracao.executeUpdate();
			
		}catch (SQLException e) {
			System.out.println(Erro.deletarBD("Disciplina"));
			
		}finally{
			Conexao.encerrarConexao(conexao, declaracao);
		}
	}
	
	/**
	 * Verificação rápida se a lista de Disciplinas está vazia
	 * @return True, se estiver vazia; false, caso contrário
	 */
	public static boolean isEmpty (){
		return lerCompleto().isEmpty();
	}

	/**
	 * Liberando todas as instâncias registradas no BD
	 */
	public static void esvaziar (){
		if (!isEmpty()){
			LinkedList<Disciplina> lista = lerCompleto();
			
			for (int pos = 0; pos < lista.size(); pos++)
				deletar(lista.get(pos));
		}
	}
}
