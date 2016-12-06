package bancoDados.manipulacao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.LinkedList;

import bancoDados.Conexao;
import bancoDados.tabelas.Holerite;
import bancoDados.tabelas.IRRF;
import utilitario.Erro;

/**
 * Classe responsável pela mamipulação da tabela IRRF no Banco de Dados 
 * @author	Rodrigo Guimarães
 * @version	1.0
 * @since	29/11/2016
 */
public abstract class IRRFM {
	/**
	 * Criação de uma instância da tabela IRRF no BD
	 * @param irrf Instância a ser registrada no BD
	 */
	public static void inserir (IRRF irrf){
		Connection conexao = Conexao.iniciarConexao();
		PreparedStatement declaracao = null;
		String instrucao = "INSERT INTO IRRF (limiteSuperior, aliquota, desconto";
		String interrogacao = "";
		
		if (irrf.getCodigo() != -1){
			instrucao += ", codigo)";
			interrogacao = "?, ?, ?, ?";
			
		}else{
			instrucao += ")";
			interrogacao = "?, ?, ?";
		}
	
		instrucao += " VALUES (" + interrogacao + ")";
		
		try{
			declaracao = conexao.prepareStatement(instrucao);
			
			declaracao.setFloat	(1, irrf.getLimSuperior());
			declaracao.setFloat	(2, irrf.getAliquota());
			declaracao.setFloat	(3, irrf.getDesconto());
			
			if (irrf.getCodigo() != -1)
				declaracao.setInt(4, irrf.getCodigo());
			
			declaracao.executeUpdate();
			
		}catch (SQLException e) {
			System.out.println(Erro.inserirBD("IRRF"));
			
		}finally{
			Conexao.encerrarConexao(conexao, declaracao);
		}
	}
	
	/**
	 * Leitura de toda a Tabela IRRF no BD
	 * @return Todas as instâncias existentes no BD
	 */
	public static LinkedList<IRRF> lerCompleto (){
		Connection conexao = Conexao.iniciarConexao();
		PreparedStatement declaracao = null;
		ResultSet resultado = null;
		LinkedList<IRRF> listirrf = new LinkedList<IRRF>();
		String instrucao = "SELECT * FROM IRRF";
		
		try {
			declaracao = conexao.prepareStatement(instrucao);
			resultado = declaracao.executeQuery();
			
			while (resultado.next()){
				IRRF irrf = new IRRF();
				
				irrf.setCodigo(resultado.getInt("codigo"));
				irrf.setLimSuperior(resultado.getFloat("limiteSuperior"));
				irrf.setAliquota(resultado.getFloat("aliquota"));
				irrf.setDesconto(resultado.getFloat("desconto"));
				
				listirrf.add(irrf);
			}
				
			
		}catch (SQLException e) {
			System.out.println(Erro.lerBD("IRRF"));
		
		}finally {
			Conexao.encerrarConexao(conexao, declaracao, resultado);
		}
		
		return listirrf;
	}
	
	/**
	 * Atualização de uma instância da tabela IRRF no BD
	 * @param irrf Instância a ser atualizada no BD
	 */
	public static void atualizar (IRRF irrf){
		Connection conexao = Conexao.iniciarConexao();
		PreparedStatement declaracao = null;
		String instrucao = "UPDATE IRRF SET"
							+ "	limiteSuperior = ?, aliquota = ?, desconto = ?"
							+ " WHERE codigo = ?";
		
		try{
			declaracao = conexao.prepareStatement(instrucao);
			
			declaracao.setFloat	(1, irrf.getLimSuperior());
			declaracao.setFloat	(2, irrf.getAliquota());
			declaracao.setFloat	(3, irrf.getDesconto());
			declaracao.setInt	(4, irrf.getCodigo());
			
			declaracao.executeUpdate();
			
		}catch (SQLException e) {
			System.out.println(Erro.atualizarBD("IRRF"));
			
		}finally{
			Conexao.encerrarConexao(conexao, declaracao);
		}
	}
	
	/**
	 * Exclusão de uma instância da tabela IRRF do BD
	 * @param irrf Instância a ser excluída do BD
	 */
	public static void deletar (IRRF irrf){
		Connection conexao = Conexao.iniciarConexao();
		PreparedStatement declaracao = null;
		String instrucao = "DELETE FROM IRRF WHERE codigo = ?";
		
		try{
			declaracao = conexao.prepareStatement(instrucao);
			
			declaracao.setInt		(1, irrf.getCodigo());
			
			declaracao.executeUpdate();
			
		}catch (SQLException e) {
			System.out.println(Erro.deletarBD("IRRF"));
			
		}finally{
			Conexao.encerrarConexao(conexao, declaracao);
		}
	}
	
	/**
	 * Verificação rápida se a lista de faixas do IRRF está vazia
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
			LinkedList<IRRF> lista = lerCompleto();
			
			for (int pos = 0; pos < lista.size(); pos++)
				deletar(lista.get(pos));
		}
	}
}
