package bancoDados.manipulacao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.LinkedList;

import bancoDados.Conexao;
import bancoDados.tabelas.Holerite;
import bancoDados.tabelas.INSS;
import utilitario.Erro;

/**
 * Classe responsável pela mamipulação da tabela INSS no Banco de Dados 
 * @author	Rodrigo Guimarães
 * @version	1.0
 * @since	29/11/2016
 */
public abstract class INSSM {
	/**
	 * Criação de uma instância da tabela INSS no BD
	 * @param inss Instância a ser registrada no BD
	 */
	public static void inserir (INSS inss){
		Connection conexao = Conexao.iniciarConexao();
		PreparedStatement declaracao = null;
		String instrucao = "INSERT INTO INSS (limiteSuperior, aliquota";
		String interrogacao = "";
		
		if (inss.getCodigo() != -1){
			instrucao += ", codigo)";
			interrogacao = "?, ?, ?";
			
		}else{
			instrucao += ")";
			interrogacao = "?, ?";
		}
	
		instrucao += " VALUES (" + interrogacao + ")";
		
		try{
			declaracao = conexao.prepareStatement(instrucao);
			
			declaracao.setFloat	(1, inss.getLimSuperior());
			declaracao.setFloat	(2, inss.getAliquota());
			
			if (inss.getCodigo() != -1)
				declaracao.setInt(3, inss.getCodigo());
			
			declaracao.executeUpdate();
			
		}catch (SQLException e) {
			System.out.println(Erro.inserirBD("INSS"));
			
		}finally{
			Conexao.encerrarConexao(conexao, declaracao);
		}
	}
	
	/**
	 * Leitura de toda a Tabela INSS no BD
	 * @return Todas as instâncias existentes no BD
	 */
	public static LinkedList<INSS> lerCompleto (){
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
			System.out.println(Erro.lerBD("INSS"));
		
		}finally {
			Conexao.encerrarConexao(conexao, declaracao, resultado);
		}
		
		return listInss;
	}
	
	/**
	 * Atualização de uma instância da tabela INSS no BD
	 * @param inss Instância a ser atualizada no BD
	 */
	public static void atualizar (INSS inss){
		Connection conexao = Conexao.iniciarConexao();
		PreparedStatement declaracao = null;
		String instrucao = "UPDATE INSS SET"
							+ "	limiteSuperior = ?, aliquota = ?"
							+ " WHERE codigo = ?";
		
		try{
			declaracao = conexao.prepareStatement(instrucao);
			
			declaracao.setFloat	(1, inss.getLimSuperior());
			declaracao.setFloat	(2, inss.getAliquota());
			declaracao.setInt	(3, inss.getCodigo());
			
			declaracao.executeUpdate();
			
		}catch (SQLException e) {
			System.out.println(Erro.atualizarBD("INSS"));
			
		}finally{
			Conexao.encerrarConexao(conexao, declaracao);
		}
	}
	
	/**
	 * Exclusão de uma instância da tabela INSS do BD
	 * @param inss Instância a ser excluída do BD
	 */
	public static void deletar (INSS inss){
		Connection conexao = Conexao.iniciarConexao();
		PreparedStatement declaracao = null;
		String instrucao = "DELETE FROM INSS WHERE codigo = ?";
		
		try{
			declaracao = conexao.prepareStatement(instrucao);
			
			declaracao.setInt		(1, inss.getCodigo());
			
			declaracao.executeUpdate();
			
		}catch (SQLException e) {
			System.out.println(Erro.deletarBD("INSS"));
			
		}finally{
			Conexao.encerrarConexao(conexao, declaracao);
		}
	}
	
	/**
	 * Verificação rápida se a lista de faixas do INSS está vazia
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
			LinkedList<INSS> lista = lerCompleto();
			
			for (int pos = 0; pos < lista.size(); pos++)
				deletar(lista.get(pos));
		}
	}
}
