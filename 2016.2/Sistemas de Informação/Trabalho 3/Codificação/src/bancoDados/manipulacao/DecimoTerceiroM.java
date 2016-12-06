package bancoDados.manipulacao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.LinkedList;

import bancoDados.Conexao;
import bancoDados.tabelas.DecimoTerceiro;
import utilitario.Erro;

/**
 * Classe responsável pela mamipulação da tabela DecimoTerceiro no Banco de Dados 
 * @author	Rodrigo Guimarães
 * @version	1.0
 * @since	29/11/2016
 */
public abstract class DecimoTerceiroM {
	/**
	 * Criação de uma instância da tabela DecimoTerceiro no BD
	 * @param decTer Instância a ser registrada no BD
	 */
	public static void inserir (DecimoTerceiro decTer){
		Connection conexao = Conexao.iniciarConexao();
		PreparedStatement declaracao = null;
		String instrucao = "INSERT INTO DecimoTerceiro ("
							+ "requisicao, parcelaAcumulada, parcelaContador, Funcionario_matricula";
		String interrogacao = "";
		
		if (decTer.getCodigo() != -1){
			instrucao += ", codigo)";
			interrogacao = "?, ?, ?, ?, ?";
			
		}else{
			instrucao += ")";
			interrogacao = "?, ?, ?, ?";
		}
			
		instrucao += " VALUES (" + interrogacao + ")";		
		
		try{
			declaracao = conexao.prepareStatement(instrucao);
			
			declaracao.setBoolean	(1, decTer.isRequisitado());
			declaracao.setFloat		(2, decTer.getParcelaAcumulada());
			declaracao.setInt		(3, decTer.getContParcela());
			declaracao.setInt		(4, decTer.getFuncMat());
			
			if (decTer.getCodigo() != -1)
				declaracao.setInt		(5, decTer.getCodigo());
			
			declaracao.executeUpdate();
			
		}catch (SQLException e) {
			System.out.println(Erro.inserirBD("DecimoTerceiro"));
			e.printStackTrace();
			
		}finally{
			Conexao.encerrarConexao(conexao, declaracao);
		}
	}
	
	/**
	 * Leitura de toda a Tabela Ferias no BD
	 * @return Todas as instâncias existentes no BD
	 */
	public static LinkedList<DecimoTerceiro> lerCompleto (){
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
			System.out.println(Erro.lerBD("DecimoTerceiro"));
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
	public static void atualizar (DecimoTerceiro decTer){
		Connection conexao = Conexao.iniciarConexao();
		PreparedStatement declaracao = null;
		String instrucao = "UPDATE DecimoTerceiro SET"
							+ " requisicao = ?, parcelaAcumulada = ?, parcelaContador = ?, Funcionario_matricula = ?"
							+ " WHERE codigo = ?";
		
		try{
			declaracao = conexao.prepareStatement(instrucao);
			
			declaracao.setBoolean	(1, decTer.isRequisitado());
			declaracao.setFloat	(2, decTer.getParcelaAcumulada());
			declaracao.setInt	(3, decTer.getContParcela());
			declaracao.setInt	(4, decTer.getFuncMat());
			declaracao.setInt	(5, decTer.getCodigo());
			
			declaracao.executeUpdate();
			
		}catch (SQLException e) {
			System.out.println(Erro.atualizarBD("DecimoTerceiro"));
			e.printStackTrace();
			
		}finally{
			Conexao.encerrarConexao(conexao, declaracao);
		}
	}
	
	/**
	 * Exclusão de uma instância da tabela DecimoTerceiro do BD
	 * @param decTer Instância a ser excluída do BD
	 */
	public static void deletar (DecimoTerceiro decTer){
		Connection conexao = Conexao.iniciarConexao();
		PreparedStatement declaracao = null;
		String instrucao = "DELETE FROM DecimoTerceiro WHERE codigo = ?";
		
		try{
			declaracao = conexao.prepareStatement(instrucao);
			
			declaracao.setInt		(1, decTer.getCodigo());
			
			declaracao.executeUpdate();
			
		}catch (SQLException e) {
			System.out.println(Erro.deletarBD("DecimoTerceiro"));
			e.printStackTrace();
			
		}finally{
			Conexao.encerrarConexao(conexao, declaracao);
		}
	}
	
	/**
	 * Verificação rápida se a lista de 13º's está vazia
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
			LinkedList<DecimoTerceiro> decTers = lerCompleto();
			
			for (int pos = 0; pos < decTers.size(); pos++)
				deletar(decTers.get(pos));
		}
	}
}
