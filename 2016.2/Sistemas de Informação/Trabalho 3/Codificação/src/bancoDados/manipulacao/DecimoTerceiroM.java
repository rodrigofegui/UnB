package bancoDados.manipulacao;

import java.sql.Connection;
import java.sql.Date;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.LinkedList;

import bancoDados.Conexao;
import bancoDados.tabelas.DecimoTerceiro;
import bancoDados.tabelas.Ferias;

/**
 * Classe responsável pela mamipulação da tabela DecimoTerceiro no Banco de Dados 
 * @author	Rodrigo Guimarães
 * @version	1.0
 * @since	29/11/2016
 */
public class DecimoTerceiroM {
	/**
	 * Criação de uma instância da tabela DecimoTerceiro no BD
	 * @param decTer Instância a ser registrada no BD
	 */
	public void inserir (DecimoTerceiro decTer){
		Connection conexao = Conexao.iniciarConexao();
		PreparedStatement declaracao = null;
		String instrucao = "INSERT INTO DecimoTerceiro ("
							+ "requisicao, parcelaAcumulada, parcelaContador, Funcionario_matricula)"
							+ " VALUES (?, ?)";
		
		try{
			declaracao = conexao.prepareStatement(instrucao);
			
			declaracao.setBoolean	(1, decTer.isRequisitado());
			declaracao.setFloat	(2, decTer.getParcelaAcumulada());
			declaracao.setInt	(1, decTer.getContParcela());
			declaracao.setInt	(1, decTer.getFuncMat());
			
			declaracao.executeUpdate();
			
		}catch (SQLException e) {
			e.printStackTrace();
			
		}finally{
			Conexao.encerrarConexao(conexao, declaracao);
		}
	}
	
	/**
	 * Leitura de toda a Tabela Ferias no BD
	 * @return Todas as instâncias existentes no BD
	 */
	public LinkedList<DecimoTerceiro> lerCompleto (){
		Connection conexao = Conexao.iniciarConexao();
		PreparedStatement declaracao = null;
		ResultSet resultado = null;
		LinkedList<DecimoTerceiro> listDecTer = new LinkedList<DecimoTerceiro>();
		String instrucao = "SELECT * FROM DecimoTerceiro";
		
		try {
			declaracao = conexao.prepareStatement(instrucao);
			resultado = declaracao.executeQuery();
			
			while (resultado.next()){
				DecimoTerceiro decTer = new DecimoTerceiro();
				
				decTer.setCodigo(resultado.getInt("codigo"));
				decTer.setRequisicao(resultado.getBoolean("requisicao"));
				decTer.setParcelaAcumulada(resultado.getFloat("parcelaAcumulada"));
				decTer.setContParcela(resultado.getInt("parcelaContador"));
				decTer.setFuncMat(resultado.getInt("Funcionario_matricula"));
				
				listDecTer.add(decTer);
			}
				
			
		}catch (SQLException e) {
			e.printStackTrace();
		
		}finally {
			Conexao.encerrarConexao(conexao, declaracao, resultado);
		}
		
		return listDecTer;
	}
	
	/**
	 * Atualização de uma instância da tabela DecimoTerceiro no BD
	 * @param decTer Instância a ser atualizada no BD
	 */
	public void atualizar (DecimoTerceiro decTer){
		Connection conexao = Conexao.iniciarConexao();
		PreparedStatement declaracao = null;
		String instrucao = "UPDATE DecimoTerceiro SET"
							+ " requisicao = ?, parcelaAcumulada = ?, parcelaContador = ?, Funcionario_matricula = ?"
							+ " WHERE codigo = ?";
		
		try{
			declaracao = conexao.prepareStatement(instrucao);
			
			declaracao.setBoolean	(1, decTer.isRequisitado());
			declaracao.setFloat	(2, decTer.getParcelaAcumulada());
			declaracao.setInt	(1, decTer.getContParcela());
			declaracao.setInt	(1, decTer.getFuncMat());
			declaracao.setInt	(1, decTer.getCodigo());
			
			declaracao.executeUpdate();
			
		}catch (SQLException e) {
			e.printStackTrace();
			
		}finally{
			Conexao.encerrarConexao(conexao, declaracao);
		}
	}
	
	/**
	 * Exclusão de uma instância da tabela DecimoTerceiro do BD
	 * @param decTer Instância a ser excluída do BD
	 */
	public void deletar (DecimoTerceiro decTer){
		Connection conexao = Conexao.iniciarConexao();
		PreparedStatement declaracao = null;
		String instrucao = "DELETE FROM DecimoTerceiro WHERE codigo = ?";
		
		try{
			declaracao = conexao.prepareStatement(instrucao);
			
			declaracao.setInt		(1, decTer.getCodigo());
			
			declaracao.executeUpdate();
			
		}catch (SQLException e) {
			e.printStackTrace();
			
		}finally{
			Conexao.encerrarConexao(conexao, declaracao);
		}
	}
}
