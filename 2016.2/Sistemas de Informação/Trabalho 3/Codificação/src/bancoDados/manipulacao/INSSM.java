package bancoDados.manipulacao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.LinkedList;

import bancoDados.Conexao;
import bancoDados.tabelas.INSS;
import bancoDados.tabelas.Profissao;

/**
 * Classe responsável pela mamipulação da tabela INSS no Banco de Dados 
 * @author	Rodrigo Guimarães
 * @version	1.0
 * @since	29/11/2016
 */
public class INSSM {
	/**
	 * Criação de uma instância da tabela INSS no BD
	 * @param inss Instância a ser registrada no BD
	 */
	public void inserir (INSS inss){
		Connection conexao = Conexao.iniciarConexao();
		PreparedStatement declaracao = null;
		String instrucao = "INSERT INTO INSS (limiteSuperior, aliquota) VALUES (?, ?)";
		
		try{
			declaracao = conexao.prepareStatement(instrucao);
			
			declaracao.setFloat	(1, inss.getLimSuperior());
			declaracao.setFloat	(2, inss.getAliquota());
			
			declaracao.executeUpdate();
			
		}catch (SQLException e) {
			e.printStackTrace();
			
		}finally{
			Conexao.encerrarConexao(conexao, declaracao);
		}
	}
	
	/**
	 * Leitura de toda a Tabela INSS no BD
	 * @return Todas as instâncias existentes no BD
	 */
	public LinkedList<INSS> lerCompleto (){
		Connection conexao = Conexao.iniciarConexao();
		PreparedStatement declaracao = null;
		ResultSet resultado = null;
		LinkedList<INSS> listInss = new LinkedList<INSS>();
		String instrucao = "SELECT * FROM INSS";
		
		try {
			declaracao = conexao.prepareStatement(instrucao);
			resultado = declaracao.executeQuery();
			
			while (resultado.next()){
				INSS inss = new INSS();
				
				inss.setCodigo(resultado.getInt("codigo"));
				inss.setLimSuperior(resultado.getFloat("limiteSuperior"));
				inss.setAliquota(resultado.getFloat("aliquota"));
				
				listInss.add(inss);
			}
				
			
		}catch (SQLException e) {
			e.printStackTrace();
		
		}finally {
			Conexao.encerrarConexao(conexao, declaracao, resultado);
		}
		
		return listInss;
	}
	
	/**
	 * Atualização de uma instância da tabela INSS no BD
	 * @param inss Instância a ser atualizada no BD
	 */
	public void atualizar (INSS inss){
		Connection conexao = Conexao.iniciarConexao();
		PreparedStatement declaracao = null;
		String instrucao = "UPDATE INSS SET"
							+ "	limiteSuperior = ?, aliquota = ?"
							+ " WHERE codigo = ?";
		
		try{
			declaracao = conexao.prepareStatement(instrucao);
			
			declaracao.setFloat	(1, inss.getLimSuperior());
			declaracao.setFloat	(2, inss.getAliquota());
			
			declaracao.executeUpdate();
			
		}catch (SQLException e) {
			e.printStackTrace();
			
		}finally{
			Conexao.encerrarConexao(conexao, declaracao);
		}
	}
	
	/**
	 * Exclusão de uma instância da tabela INSS do BD
	 * @param inss Instância a ser excluída do BD
	 */
	public void deletar (INSS inss){
		Connection conexao = Conexao.iniciarConexao();
		PreparedStatement declaracao = null;
		String instrucao = "DELETE FROM INSS WHERE codigo = ?";
		
		try{
			declaracao = conexao.prepareStatement(instrucao);
			
			declaracao.setInt		(1, inss.getCodigo());
			
			declaracao.executeUpdate();
			
		}catch (SQLException e) {
			e.printStackTrace();
			
		}finally{
			Conexao.encerrarConexao(conexao, declaracao);
		}
	}
}
