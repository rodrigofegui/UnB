package bancoDados.manipulacao;

import java.sql.Connection;
import java.sql.Date;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.LinkedList;

import bancoDados.Conexao;
import bancoDados.tabelas.Funcionario;

/**
 * Classe responsável pela mamipulação da tabela Funcionário no Banco de Dados 
 * @author	Rodrigo Guimarães
 * @version	1.0
 * @since	29/11/2016
 */
public class FuncionárioM {
	/**
	 * Criação de uma instância da tabela Funcionario no BD
	 * @param func Instância a ser registrada no BD
	 */
	public void inserir (Funcionario func){
		Connection conexao = Conexao.iniciarConexao();
		PreparedStatement declaracao = null;
		String instrucao = "INSERT INTO Funcionario ("
							+ "cpf, nome, dataNascimento, telefone,"
							+ " email, dataAdmissao, valeTransporte_Dia, Profissao_codigo,"
							+ " Profissao_INSS_codigo, Profissao_IRRF_codigo) VALUES ("
							+ "?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
		
		try{
			declaracao = conexao.prepareStatement(instrucao);
			
			declaracao.setString 	(1, func.getCpf());
			declaracao.setString 	(2, func.getNome());
			declaracao.setDate		(3, Date.valueOf(func.getDataNasc()));
			declaracao.setString	(4, func.getTelefone());
			declaracao.setString 	(5, func.getEmail());
			declaracao.setDate		(6, Date.valueOf(func.getDataAdm()));
			declaracao.setInt		(7, func.getQntValeTransp());
			declaracao.setInt		(8, func.getCodProf());
			declaracao.setInt		(9, func.getCodProfInss());
			declaracao.setInt		(10, func.getCodProfIrrf());
			
			declaracao.executeUpdate();
			
		}catch (SQLException e) {
			e.printStackTrace();
			
		}finally{
			Conexao.encerrarConexao(conexao, declaracao);
		}
	}
	
	/**
	 * Leitura de toda a Tabela Funcionario no BD
	 * @return Todas as instâncias existentes no BD
	 */
	public LinkedList<Funcionario> lerCompleto (){
		Connection conexao = Conexao.iniciarConexao();
		PreparedStatement declaracao = null;
		ResultSet resultado = null;
		LinkedList<Funcionario> funcionarios = new LinkedList<Funcionario>();
		String instrucao = "SELECT * FROM IRRF";
		
		try {
			declaracao = conexao.prepareStatement(instrucao);
			resultado = declaracao.executeQuery();
			
			while (resultado.next()){
				Funcionario funcionario = new Funcionario();
				
				funcionario.setCpf(resultado.getString("cpf"));
				funcionario.setMatricula(resultado.getInt("matricula"));
				funcionario.setNome(resultado.getString("nome"));
				funcionario.setDataNasc(resultado.getDate("dataNascimento").toString());
				funcionario.setTelefone(resultado.getString("telefone"));
				funcionario.setEmail(resultado.getString("email"));
				funcionario.setDataAdm(resultado.getDate("dataAdmissao").toString());
				funcionario.setQntValeTransp(resultado.getInt("valeTransporte_Dia"));
				funcionario.setCodProf(resultado.getInt("Profissao_codigo"));
				funcionario.setCodProfInss(resultado.getInt("Profissao_INSS_codigo"));
				funcionario.setCodProfIrrf(resultado.getInt("Profissao_IRRF_codigo"));
				
				funcionarios.add(funcionario);
			}

		}catch (SQLException e) {
			e.printStackTrace();
		
		}finally {
			Conexao.encerrarConexao(conexao, declaracao, resultado);
		}
		
		return funcionarios;
	}
	
	/**
	 * Atualização de uma instância da tabela Funcionario no BD
	 * @param funcionario Instância a ser atualizada no BD
	 */
	public void atualizar (Funcionario funcionario){
		Connection conexao = Conexao.iniciarConexao();
		PreparedStatement declaracao = null;
		String instrucao = "UPDATE IRRF SET"
							+ " matricula = ?, nome = ?, dataNascimento = ?, telefone = ?,"
							+ " email = ?, dataAdmissao = ?, valeTransporte_Dia = ?, Profissao_codigo = ?,"
							+ " Profissao_INSS_codigo = ?, Profissao_IRRF_codigo = ?"
							+ " WHERE cpf = ?";
		
		try{
			declaracao = conexao.prepareStatement(instrucao);
			
			declaracao.setInt	 	(1, funcionario.getMatricula());
			declaracao.setString 	(2, funcionario.getNome());
			declaracao.setDate		(3, Date.valueOf(funcionario.getDataNasc()));
			declaracao.setString	(4, funcionario.getTelefone());
			declaracao.setString 	(5, funcionario.getEmail());
			declaracao.setDate		(6, Date.valueOf(funcionario.getDataAdm()));
			declaracao.setInt		(7, funcionario.getQntValeTransp());
			declaracao.setInt		(8, funcionario.getCodProf());
			declaracao.setInt		(9, funcionario.getCodProfInss());
			declaracao.setInt		(10, funcionario.getCodProfIrrf());
			declaracao.setString 	(11, funcionario.getCpf());
			
			declaracao.executeUpdate();
			
		}catch (SQLException e) {
			e.printStackTrace();
			
		}finally{
			Conexao.encerrarConexao(conexao, declaracao);
		}
	}
	
	/**
	 * Exclusão de uma instância da tabela Funcionario do BD
	 * @param funcionario Instância a ser excluída do BD
	 */
	public void deletar (Funcionario funcionario){
		Connection conexao = Conexao.iniciarConexao();
		PreparedStatement declaracao = null;
		String instrucao = "DELETE FROM IRRF WHERE codigo = ?";
		
		try{
			declaracao = conexao.prepareStatement(instrucao);
			
			declaracao.setString	(1, funcionario.getCpf());
			
			declaracao.executeUpdate();
			
		}catch (SQLException e) {
			e.printStackTrace();
			
		}finally{
			Conexao.encerrarConexao(conexao, declaracao);
		}
	}
}
