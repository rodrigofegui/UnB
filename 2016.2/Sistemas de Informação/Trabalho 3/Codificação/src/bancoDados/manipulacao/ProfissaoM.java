package bancoDados.manipulacao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.LinkedList;

import bancoDados.Conexao;
import bancoDados.tabelas.Profissao;
import utilitario.Erro;

/**
 * Classe responsável pela mamipulação da tabela Profissão no Banco de Dados 
 * @author	Rodrigo Guimarães
 * @version	1.0
 * @since	28/11/2016
 */
public class ProfissaoM {
	/**
	 * Criação de uma instância da tabela Profissão no BD
	 * @param profissao Instância a ser registrada no BD
	 */
	public void inserir (Profissao profissao){
		Connection conexao = Conexao.iniciarConexao();
		PreparedStatement declaracao = null;
		String instrucao = "INSERT INTO Profissao (descricao, salarioBase, INSS_codigo, IRRF_codigo";
		String interrogacao = "";
		
		if (profissao.getCodigo() != -1){
			instrucao += ", codigo)";
			interrogacao = "?, ?, ?, ?, ?";
			
		}else{
			instrucao += ")";
			interrogacao = "?, ?, ?, ?";
		}
	
		instrucao += " VALUES (" + interrogacao + ")";
		
		try{
			declaracao = conexao.prepareStatement(instrucao);
			
			declaracao.setString	(1, profissao.getDescricao());
			declaracao.setFloat		(2, profissao.getSalarioBase());
			declaracao.setInt		(3, profissao.getInss_codigo());
			declaracao.setInt		(4, profissao.getIrrf_codigo());
			
			if (profissao.getCodigo() != -1)
				declaracao.setInt		(5, profissao.getCodigo());
			
			declaracao.executeUpdate();
			
		}catch (SQLException e) {
			System.out.println(Erro.inserirBD("Profissao"));
			
		}finally{
			Conexao.encerrarConexao(conexao, declaracao);
		}
	}

	/**
	 * Leitura de toda a Tabela Profissão no BD
	 * @return Todas as instâncias existentes no BD
	 */
	public LinkedList<Profissao> lerCompleto (){
		Connection conexao = Conexao.iniciarConexao();
		PreparedStatement declaracao = null;
		ResultSet resultado = null;
		LinkedList<Profissao> profissoes = new LinkedList<Profissao>();
		String instrucao = "SELECT * FROM Profissao";
		
		try {
			declaracao = conexao.prepareStatement(instrucao);
			resultado = declaracao.executeQuery();
			
			while (resultado.next()){
				Profissao profissao = new Profissao();
				
				profissao.setCodigo(resultado.getInt("codigo"));
				profissao.setDescricao(resultado.getString("descricao"));
				profissao.setSalarioBase(resultado.getFloat("salarioBase"));
				profissao.setDisciplina_codigo(resultado.getInt("Disciplina_codigo"));
				profissao.setInss_codigo(resultado.getInt("INSS_codigo"));
				profissao.setIrrf_codigo(resultado.getInt("IRRF_codigo"));
								
				profissoes.add(profissao);
			}
				
			
		}catch (SQLException e) {
			e.printStackTrace();
		
		}finally {
			Conexao.encerrarConexao(conexao, declaracao, resultado);
		}
		
		return profissoes;
	}
	
	/**
	 * Atualização de uma instância da tabela Profissão no BD
	 * @param profissao Instância a ser atualizada no BD
	 */
	public void atualizar (Profissao profissao){
		Connection conexao = Conexao.iniciarConexao();
		PreparedStatement declaracao = null;
		String instrucao = "UPDATE Profissao SET"
							+ "	descricao = ?, salarioBase = ?, INSS_codigo = ?, IRRF_codigo = ?"
							+ " WHERE codigo = ?";
		
		try{
			declaracao = conexao.prepareStatement(instrucao);
			
			declaracao.setString	(1, profissao.getDescricao());
			declaracao.setFloat		(2, profissao.getSalarioBase());
			declaracao.setInt		(3, profissao.getInss_codigo());
			declaracao.setInt		(4, profissao.getIrrf_codigo());
			declaracao.setInt		(5, profissao.getCodigo());
			
			declaracao.executeUpdate();
			
		}catch (SQLException e) {
			e.printStackTrace();
			
		}finally{
			Conexao.encerrarConexao(conexao, declaracao);
		}
	}
	
	/**
	 * Exclusão de uma instância da tabela Profissão do BD
	 * @param profissao Instância a ser excluída do BD
	 */
	public void deletar (Profissao profissao){
		Connection conexao = Conexao.iniciarConexao();
		PreparedStatement declaracao = null;
		String instrucao = "DELETE FROM Profissao WHERE codigo = ?";
		
		try{
			declaracao = conexao.prepareStatement(instrucao);
			
			declaracao.setInt		(1, profissao.getCodigo());
			
			declaracao.executeUpdate();
			
		}catch (SQLException e) {
			e.printStackTrace();
			
		}finally{
			Conexao.encerrarConexao(conexao, declaracao);
		}
	}
}
