package bancoDados.manipulacao;

import java.sql.Connection;
import java.sql.Date;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.LinkedList;

import bancoDados.Conexao;
import bancoDados.tabelas.Holerite;
import utilitario.Erro;

/**
 * Classe responsável pela mamipulação da tabela Holerite no Banco de Dados 
 * @author	Rodrigo Guimarães
 * @version	1.0
 * @since	29/11/2016
 */
public abstract class HoleriteM {
	/**
	 * Criação de uma instância da tabela Holerite no BD
	 * @param holerite Instância a ser registrada no BD
	 */
	public static void inserir (Holerite holerite){
		Connection conexao = Conexao.iniciarConexao();
		PreparedStatement declaracao = null;
		String instrucao = "INSERT INTO Holerite ("
							+ "dataReferencia, salarioLiquido, faltas, Funcionario_matricula";
		String interrogacao = "";
		
		if (holerite.getCodigo() != -1){
			instrucao += ", codigo)";
			interrogacao = "?, ?, ?, ?, ?";
			
		}else{
			instrucao += ")";
			interrogacao = "?, ?, ?, ?";
		}
	
		instrucao += " VALUES (" + interrogacao + ")";
		
		try{
			declaracao = conexao.prepareStatement(instrucao);
			
			declaracao.setDate	(1, Date.valueOf(holerite.getDataRef()));
			declaracao.setFloat	(2, holerite.getSalLiq());
			declaracao.setInt	(3, holerite.getFaltas());
			declaracao.setInt	(4, holerite.getFuncMat());
			
			if (holerite.getCodigo() != -1)
				declaracao.setInt	(5, holerite.getCodigo());
				
			declaracao.executeUpdate();
			
		}catch (SQLException e) {
			System.out.println(Erro.inserirBD("Holerite"));
			
		}finally{
			Conexao.encerrarConexao(conexao, declaracao);
		}
	}
	
	/**
	 * Leitura de toda a Tabela Holerite no BD
	 * @return Todas as instâncias existentes no BD
	 */
	public static LinkedList<Holerite> lerCompleto (){
		Connection conexao = Conexao.iniciarConexao();
		PreparedStatement declaracao = null;
		ResultSet resultado = null;
		LinkedList<Holerite> holerites = new LinkedList<Holerite>();
		String instrucao = "SELECT * FROM Holerite";
		
		try {
			declaracao = conexao.prepareStatement(instrucao);
			resultado = declaracao.executeQuery();
			
			while (resultado.next()){
				Holerite holerite = new Holerite();
				
				holerite.setCodigo(resultado.getInt("codigo"));
				holerite.setDataRef(resultado.getDate("dataReferencia").toString());
				holerite.setSalLiq(resultado.getFloat("salarioLiquido"));
				holerite.setFaltas(resultado.getInt("faltas"));
				holerite.setFuncMat(resultado.getInt("Funcionario_matricula"));
				
				holerites.add(holerite);
			}
				
			
		}catch (SQLException e) {
			System.out.println(Erro.lerBD("Holerite"));
		
		}finally {
			Conexao.encerrarConexao(conexao, declaracao, resultado);
		}
		
		return holerites;
	}
	
	/**
	 * Atualização de uma instância da tabela Holerite no BD
	 * @param holerite Instância a ser atualizada no BD
	 */
	public static void atualizar (Holerite holerite){
		Connection conexao = Conexao.iniciarConexao();
		PreparedStatement declaracao = null;
		String instrucao = "UPDATE Holerite SET"
							+ " dataReferencia = ?, salarioLiquido = ?, faltas = ?, Funcionario_matricula = ?"
							+ " WHERE codigo = ?";
		
		try{
			declaracao = conexao.prepareStatement(instrucao);
			
			declaracao.setDate	(1, Date.valueOf(holerite.getDataRef()));
			declaracao.setFloat	(2, holerite.getSalLiq());
			declaracao.setInt	(3, holerite.getFaltas());
			declaracao.setInt	(4, holerite.getFuncMat());
			declaracao.setInt	(4, holerite.getCodigo());
			
			declaracao.executeUpdate();
			
		}catch (SQLException e) {
			System.out.println(Erro.atualizarBD("Holerite"));
			
		}finally{
			Conexao.encerrarConexao(conexao, declaracao);
		}
	}
	
	/**
	 * Exclusão de uma instância da tabela Holerite do BD
	 * @param holerite Instância a ser excluída do BD
	 */
	public static void deletar (Holerite holerite){
		Connection conexao = Conexao.iniciarConexao();
		PreparedStatement declaracao = null;
		String instrucao = "DELETE FROM Holerite WHERE codigo = ?";
		
		try{
			declaracao = conexao.prepareStatement(instrucao);
			
			declaracao.setInt		(1, holerite.getCodigo());
			
			declaracao.executeUpdate();
			
		}catch (SQLException e) {
			System.out.println(Erro.deletarBD("Holerite"));
			
		}finally{
			Conexao.encerrarConexao(conexao, declaracao);
		}
	}
}
