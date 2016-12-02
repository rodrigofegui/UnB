package utilitario;

/**
 * Classe responsável pela implementação de um controle de mensagens de erro
 * @author	Rodrigo Guimarães
 * @version	1.0
 * @since	01/12/2016
 */
public abstract class Erro{
	/**
	 * Mensagem de erro na tentativa de abrir comunicação com o BD
	 * @param classeError Distinção da origem do erro: true, para falha
	 * relacionada com o driver; false, para falha com o BD
	 * @return Mensagem desenvolvida
	 */
	public static String abrirConexao (boolean classeError){
		String mensagem = "\nNão foi possível abrir uma conexão com o BD.\n";
		
		if (classeError)
			mensagem += "Dica: Verifique o driver de comunicação.\n";
		else
			mensagem += "Dica: Verifique os dados do banco, como: usuário e senha.\n";
		
		mensagem += "Tente, novamente, mais tarde.\n";
		
		return mensagem;
	}
	
	/**
	 * Mensagem de erro na tentativa de encerrar comunicação com o BD
	 * @return Mensagem desenvolvida
	 */
	public static String encerrarConexao (){
		String mensagem = "\nNão foi possível encerrar a conexão com o BD.\n"
						+ "Tente, novamente, mais tarde.\n";
		
		return mensagem;
	}
	
	
	
	/**
	 * Mensagem de erro na tentativa de inserção de dados no BD
	 * @param tabela Tabela na qual foi tentada a inserção
	 * @return Mensagem desenvolvida
	 */
	public static String inserirBD (String tabela){
		String mensagem = "\nNão foi possível inserir na tabela '" + tabela + "'.\n"
						+ "Dica: Verifique chaves duplicadas ou dados incorretos.\n"
						+ "Tente, novamente, mais tarde.\n";
		
		return mensagem;
	}
	
	/**
	 * Mensagem de erro na tentativa de leitura de dados no BD
	 * @param tabela Tabela na qual foi tentada a leitura
	 * @return Mensagem desenvolvida
	 */
	public static String lerBD (String tabela){
		String mensagem = "\nNão foi possível ler a tabela '" + tabela + "'.\n"
						+ "Dica: Verifique se a tabela existe no BD.\n"
						+ "Tente, novamente, mais tarde.\n";

		return mensagem;
	}
	
	/**
	 * Mensagem de erro na tentativa de atualização de dados no BD
	 * @param tabela Tabela na qual foi tentada a atualização
	 * @return Mensagem desenvolvida
	 */
	public static String atualizarBD (String tabela){
		String mensagem = "\nNão foi possível atualizar na tabela '" + tabela + "'.\n"
						+ "Dica: Verifique se a instância realmente existe, com o código desejado.\n"
						+ "Tente, novamente, mais tarde.\n";

		return mensagem;
	}
	
	/**
	 * Mensagem de erro na tentativa de exclusão de dados no BD
	 * @param tabela Tabela na qual foi tentada a exclusão
	 * @return Mensagem desenvolvida
	 */
	public static String deletarBD (String tabela){
		String mensagem = "\nNão foi possível deletar na tabela '" + tabela + "'.\n"
						+ "Dica: Verifique se a instância realmente existe, com o código desejado.\n"
						+ "Tente, novamente, mais tarde.\n";
		
		return mensagem;
	}
	
	
	
	/**
	 * Mensagem de erro no nome fornecido
	 * @return Mensagem desenvolvida
	 */
	public static String nome (){
		String mensagem = "\nNome inválido!\n"
						+ "Dica: Deve haver caracteres inválidos, busque corrigir.\n"
						+ "Lembre-se: apenas letras de A-Z, sem acentuação.\n"
						+ "Digite, novamente.\n";
						
		return mensagem;
	}

	/**
	 * Mensagem de erro no CPF fornecido
	 * @return Mensagem desenvolvida
	 */
	public static String cpf (){
		String mensagem = "\nCPF inválido!\n"
						+ "Dica: Deve haver caracteres inválidos, busque corrigir.\n"
						+ "Lembre-se: apenas números de 0-9, totalizando 11 digitos.\n"
						+ "Digite, novamente.\n";
		
		return mensagem;
	}

	/**
	 * Mensagem de erro na data fornecida
	 * @param tipo Tipo da data que o erro está associada, podendo ser do 
	 * nascimento ou da admissão na empresa
	 * @return Mensagem desenvolvida
	 */
	public static String data (String tipo){
		String mensagem = "\nData de " + tipo + " inválida!\n"
						+ "Dica: Deve haver caracteres inválidos, busque corrigir.\n"
						+ "Lembre-se: apenas números de 0-9.\n"
						+ "Digite, novamente.\n";
		
		return mensagem;
	}

	/**
	 * Mensagem de erro no telefone fornecido
	 * @return Mensagem desenvolvida
	 */
	public static String telefone (){
		String mensagem = "\nTelefone inválido!\n"
						+ "Dica: Deve haver caracteres inválidos, busque corrigir.\n"
						+ "Lembre-se: apenas números de 0-9, totalizando 12 digitos.\n"
						+ "Digite, novamente.\n";
		
		return mensagem;
	}

	/**
	 * Mensagem de erro no e-mail fornecido
	 * @return Mensagem desenvolvida
	 */
	public static String email (){
		String mensagem = "\nE-mail inválido!\n"
						+ "Dica: Deve haver caracteres inválidos, busque corrigir.\n"
						+ "Lembre-se: deve estar no formato exemplo@exemplo.com.\n"
						+ "Digite, novamente.\n";
		
		return mensagem;
	}

	/**
	 * Mensagem de erro na profissão ou quantidade de vale fornecida
	 * @param tipo Tipo da mensagem de origem
	 * @param naoNumeral Destinção básica da causa do erro. True, pode
	 * ter sido fornecido um valor não numérico; false, não pertence 
	 * ao intervalo disponibilizado
	 * @return Mensagem desenvolvida
	 */
	public static String profissaoOuVale (String tipo, boolean naoNumeral){
		String mensagem = "\n" + tipo + " inválida!\n";
		
		if (naoNumeral)
			mensagem += "Dica: digite um valor numérico.\n";
		else
			mensagem += "Dica: digite um valor para os códigos oferecidos.\n";
		
		mensagem += "Digite, novamente.\n";
		
		return mensagem;
	}
}
