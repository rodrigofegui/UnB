package bancoDados.manipulacao;

import java.sql.Connection;
import java.sql.Date;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.LinkedList;

import bancoDados.Conexao;
import bancoDados.tabelas.Disciplina;
import bancoDados.tabelas.Ferias;
import utilitario.Erro;

/**
 * Classe responsável pela mamipulação da tabela Ferias no Banco de Dados 
 * @author	Rodrigo Guimarães
 * @version	1.0
 * @since	29/11/2016
 */
public abstract class FeriasM {
	/**
	 * Criação de uma instância da tabela Ferias no BD
	 * @param ferias Instância a ser registrada no BD
	 */
	public static void inserir (Ferias ferias){
		Connection conexao = Conexao.iniciarConexao();
		PreparedStatement declaracao = null;
		String instrucao = "INSERT INTO Ferias (dataReferencia, Funcionario_matricula";
		String interrogacao = "";
		
		if (ferias.getCodigo() != -1){
			instrucao += ", codigo)";
			interrogacao = "?, ?, ?";
			
		}else{
			instrucao += ")";
			interrogacao = "?, ?";
		}
	
		instrucao += " VALUES (" + interrogacao + ")";
		
		try{
			declaracao = conexao.prepareStatement(instrucao);
			
			declaracao.setDate	(1, Date.valueOf(ferias.getDataRef()));
			declaracao.setInt	(2, ferias.getFuncMat());
			
			if (ferias.getCodigo() != -1)
				declaracao.setInt	(3, ferias.getCodigo());
			
			declaracao.executeUpdate();
			
		}catch (SQLException e) {
			System.out.println(Erro.inserirBD("Ferias"));
			
		}finally{
			Conexao.encerrarConexao(conexao, declaracao);
		}
	}
	
	/**
	 * Leitura de toda a Tabela Ferias no BD
	 * @return Todas as instâncias existentes no BD
	 */
	public static LinkedList<Ferias> lerCompleto (){
		Connection conexao = Conexao.iniciarConexao();
		PreparedStatement declaracao = null;
		ResultSet resultado = null;
		LinkedList<Ferias> listFerias = new LinkedList<Ferias>();
		String instrucao = "SELECT * FROM Ferias";
		
		try {
			declaracao = conexao.prepareStatement(instrucao);
			resultado = declaracao.executeQuery();
			
			while (resultado.next()){
				Ferias ferias = new Ferias();
				
				ferias.setCodigo(resultado.getInt("codigo"));
				ferias.setDataRef(resultado.getDate("dataReferencia").toString());
				ferias.setFuncMat(resultado.getInt("Funcionario_matricula"));
				
				listFerias.add(ferias);
			}
				
			
		}catch (SQLException e) {
			System.out.println(Erro.lerBD("Ferias"));
		
		}finally {
			Conexao.encerrarConexao(conexao, declaracao, resultado);
		}
		
		return listFerias;
	}
	
	/**
	 * Atualização de uma instância da tabela Ferias no BD
	 * @param ferias Instância a ser atualizada no BD
	 */
	public static void atualizar (Ferias ferias){
		Connection conexao = Conexao.iniciarConexao();
		PreparedStatement declaracao = null;
		String instrucao = "UPDATE Ferias SET"
							+ "	dataReferencia = ?, Funcionario_matricula = ?"
							+ " WHERE codigo = ?";
		
		try{
			declaracao = conexao.prepareStatement(instrucao);
			
			declaracao.setDate	(1, Date.valueOf(ferias.getDataRef()));
			declaracao.setInt	(2, ferias.getFuncMat());
			declaracao.setInt	(3, ferias.getCodigo());
			
			declaracao.executeUpdate();
			
		}catch (SQLException e) {
			System.out.println(Erro.atualizarBD("Ferias"));
			
		}finally{
			Conexao.encerrarConexao(conexao, declaracao);
		}
	}
	
	/**
	 * Exclusão de uma instância da tabela Ferias do BD
	 * @param ferias Instância a ser excluída do BD
	 */
	public static void deletar (Ferias ferias){
		Connection conexao = Conexao.iniciarConexao();
		PreparedStatement declaracao = null;
		String instrucao = "DELETE FROM Ferias WHERE codigo = ?";
		
		try{
			declaracao = conexao.prepareStatement(instrucao);
			
			declaracao.setInt		(1, ferias.getCodigo());
			
			declaracao.executeUpdate();
			
		}catch (SQLException e) {
			System.out.println(Erro.deletarBD("Ferias"));
			
		}finally{
			Conexao.encerrarConexao(conexao, declaracao);
		}
	}
	
	/**
	 * Verificação rápida se a lista de férias está vazia
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
			LinkedList<Ferias> lista = lerCompleto();
			
			for (int pos = 0; pos < lista.size(); pos++)
				deletar(lista.get(pos));
		}
	}
}
