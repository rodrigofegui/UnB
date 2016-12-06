package bancoDados.manipulacao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.LinkedList;

import bancoDados.Conexao;
import bancoDados.tabelas.Funcionario;
import bancoDados.tabelas.Holerite;
import utilitario.Autentificacao;
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
							+ "dataReferencia, salarioLiquido, faltas, Funcionario_matricula, "
							+ "inss, irrf, ferias, decTerceiro, valeTransporte";
		String interrogacao = "";
		
		if (holerite.getCodigo() != -1){
			instrucao += ", codigo)";
			interrogacao = "?, ?, ?, ?, ?, ?, ?, ?, ?, ?";
			
		}else{
			instrucao += ")";
			interrogacao = "?, ?, ?, ?, ?, ?, ?, ?, ?";
		}
	
		instrucao += " VALUES (" + interrogacao + ")";
		
		try{
			declaracao = conexao.prepareStatement(instrucao);
			
			declaracao.setDate	(1, Autentificacao.dataSQL(holerite.getDataRef()));
			declaracao.setFloat	(2, holerite.getSalLiq());
			declaracao.setFloat	(3, holerite.getFaltas());
			declaracao.setInt	(4, holerite.getFuncMat());
			declaracao.setFloat (5, holerite.getInss());
			declaracao.setFloat (6, holerite.getIrrf());
			declaracao.setFloat (7, holerite.getFerias());
			declaracao.setFloat (8, holerite.getDecTerceiro());
			declaracao.setFloat (9, holerite.getValeTransporte());
			
			if (holerite.getCodigo() != -1)
				declaracao.setInt	(10, holerite.getCodigo());
				
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
				holerite.setFaltas(resultado.getFloat("faltas"));
				holerite.setFuncMat(resultado.getInt("Funcionario_matricula"));
				holerite.setInss(resultado.getFloat("inss"));
				holerite.setIrrf(resultado.getFloat("irrf"));
				holerite.setFerias(resultado.getFloat("ferias"));
				holerite.setDecTerceiro(resultado.getFloat("decTerceiro"));
				holerite.setValeTransporte(resultado.getFloat("valeTransporte"));
				
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
							+ " dataReferencia = ?, salarioLiquido = ?, faltas = ?, Funcionario_matricula = ?, "
							+ "inss = ?, irrf = ?, ferias = ?, decTerceiro = ?, valeTransporte = ?"
							+ " WHERE codigo = ?";
		
		try{
			declaracao = conexao.prepareStatement(instrucao);
			
			declaracao.setDate	(1, Autentificacao.dataSQL(holerite.getDataRef()));
			declaracao.setFloat	(2, holerite.getSalLiq());
			declaracao.setFloat	(3, holerite.getFaltas());
			declaracao.setInt	(4, holerite.getFuncMat());
			declaracao.setFloat (5, holerite.getInss());
			declaracao.setFloat (6, holerite.getIrrf());
			declaracao.setFloat (7, holerite.getFerias());
			declaracao.setFloat (8, holerite.getDecTerceiro());
			declaracao.setFloat (9, holerite.getValeTransporte());
			declaracao.setInt	(10, holerite.getCodigo());
			
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
	
	/**
	 * Verificação rápida se a lista de Holerites está vazia
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
			LinkedList<Holerite> lista = lerCompleto();
			
			for (int pos = 0; pos < lista.size(); pos++)
				deletar(lista.get(pos));
		}
	}
}
