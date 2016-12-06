package bancoDados.manipulacao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.LinkedList;

import bancoDados.Conexao;
import bancoDados.tabelas.Ferias;
import bancoDados.tabelas.Funcionario;
import utilitario.Autentificacao;
import utilitario.Erro;

/**
 * Classe responsável pela mamipulação da tabela Funcionário no Banco de Dados 
 * @author	Rodrigo Guimarães
 * @version	1.0
 * @since	29/11/2016
 */
public abstract class FuncionarioM {
	/**
	 * Criação de uma instância da tabela Funcionario no BD
	 * @param func Instância a ser registrada no BD
	 */
	public static void inserir (Funcionario func){
		Connection conexao = Conexao.iniciarConexao();
		PreparedStatement declaracao = null;
		String instrucao = "INSERT INTO Funcionario ("
							+ "cpf, nome, dataNascimento, telefone,"
							+ " email, dataAdmissao, valeTransporte_Dia, Profissao_codigo,"
							+ " Profissao_INSS_codigo, Profissao_IRRF_codigo, empregado";
		String interrogacao = "";
		
		if (func.getMatricula() != -1){
			instrucao += ", matricula)";
			interrogacao = "?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?";
			
		}else{
			instrucao += ")";
			interrogacao = "?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?";
		}
	
		instrucao += " VALUES (" + interrogacao + ")";
		
		try{
			declaracao = conexao.prepareStatement(instrucao);
			
			declaracao.setString 	(1, func.getCpf());
			declaracao.setString 	(2, func.getNome());
			declaracao.setDate		(3, Autentificacao.dataSQL(func.getDataNasc()));
			declaracao.setString	(4, func.getTelefone());
			declaracao.setString 	(5, func.getEmail());
			declaracao.setDate		(6, Autentificacao.dataSQL(func.getDataAdm()));
			declaracao.setInt		(7, func.getQntValeTransp());
			declaracao.setInt		(8, func.getCodProf());
			declaracao.setInt		(9, func.getCodProfInss());
			declaracao.setInt		(10, func.getCodProfIrrf());
			declaracao.setBoolean	(11, func.isEmpregado());
			
			if (func.getMatricula() != -1)
				declaracao.setInt	(12, func.getMatricula());
			
			declaracao.executeUpdate();
			
		}catch (SQLException e) {
			System.out.println(Erro.inserirBD("Funcionario"));
			//e.printStackTrace();
			
		}finally{
			Conexao.encerrarConexao(conexao, declaracao);
		}
	}
	
	/**
	 * Leitura de toda a Tabela Funcionario no BD
	 * @return Todas as instâncias existentes no BD
	 */
	public static LinkedList<Funcionario> lerCompleto (){
		Connection conexao = Conexao.iniciarConexao();
		PreparedStatement declaracao = null;
		ResultSet resultado = null;
		LinkedList<Funcionario> funcionarios = new LinkedList<Funcionario>();
		String instrucao = "SELECT * FROM Funcionario";
		
		try {
			declaracao = conexao.prepareStatement(instrucao);
			resultado = declaracao.executeQuery();
			
			while (resultado.next()){
				Funcionario funcionario = new Funcionario();
				
				funcionario.setCpf(resultado.getString("cpf"));
				funcionario.setMatricula(resultado.getInt("matricula"));
				funcionario.setNome(resultado.getString("nome"));
				funcionario.setDataNasc(resultado.getDate("dataNascimento").toString());
				funcionario.setEmpregado(resultado.getBoolean("empregado"));
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
			System.out.println(Erro.lerBD("Funcionario"));
			//e.printStackTrace();
		
		}finally {
			Conexao.encerrarConexao(conexao, declaracao, resultado);
		}
		
		return funcionarios;
	}
	
	/**
	 * Atualização de uma instância da tabela Funcionario no BD
	 * @param funcionario Instância a ser atualizada no BD
	 */
	public static void atualizar (Funcionario funcionario){
		Connection conexao = Conexao.iniciarConexao();
		PreparedStatement declaracao = null;
		String instrucao = "UPDATE Funcionario SET"
							+ " matricula = ?, nome = ?, dataNascimento = ?, telefone = ?,"
							+ " email = ?, dataAdmissao = ?, valeTransporte_Dia = ?, Profissao_codigo = ?,"
							+ " Profissao_INSS_codigo = ?, Profissao_IRRF_codigo = ?, empregado = ?"
							+ " WHERE cpf = ?";
		
		try{
			declaracao = conexao.prepareStatement(instrucao);
			
			declaracao.setInt	 	(1, funcionario.getMatricula());
			declaracao.setString 	(2, funcionario.getNome());
			declaracao.setDate		(3, Autentificacao.dataSQL(funcionario.getDataNasc()));
			declaracao.setString	(4, funcionario.getTelefone());
			declaracao.setString 	(5, funcionario.getEmail());
			declaracao.setDate		(6, Autentificacao.dataSQL(funcionario.getDataNasc()));
			declaracao.setInt		(7, funcionario.getQntValeTransp());
			declaracao.setInt		(8, funcionario.getCodProf());
			declaracao.setInt		(9, funcionario.getCodProfInss());
			declaracao.setInt		(10, funcionario.getCodProfIrrf());
			declaracao.setBoolean	(11, funcionario.isEmpregado());
			declaracao.setString 	(12, funcionario.getCpf());
			
			
			declaracao.executeUpdate();
			
		}catch (SQLException e) {
			System.out.println(Erro.atualizarBD("Funcionario"));
			
		}finally{
			Conexao.encerrarConexao(conexao, declaracao);
		}
	}
	
	/**
	 * Exclusão de uma instância da tabela Funcionario do BD
	 * @param funcionario Instância a ser excluída do BD
	 */
	public static void deletar (Funcionario funcionario){
		Connection conexao = Conexao.iniciarConexao();
		PreparedStatement declaracao = null;
		String instrucao = "DELETE FROM Funcionario WHERE codigo = ?";
		
		try{
			declaracao = conexao.prepareStatement(instrucao);
			
			declaracao.setString	(1, funcionario.getCpf());
			
			declaracao.executeUpdate();
			
		}catch (SQLException e) {
			System.out.println(Erro.deletarBD("Funcionario"));
			
		}finally{
			Conexao.encerrarConexao(conexao, declaracao);
		}
	}
	
	/**
	 * Verificação rápida se a lista de Funcionários está vazia
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
			LinkedList<Funcionario> lista = lerCompleto();
			
			for (int pos = 0; pos < lista.size(); pos++)
				deletar(lista.get(pos));
		}
	}
}
