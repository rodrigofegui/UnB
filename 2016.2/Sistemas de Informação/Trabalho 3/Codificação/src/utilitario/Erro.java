package utilitario;

/**
 * Classe responsável pela implementação de um controle de mensagens de erro
 * @author	Rodrigo Guimarães
 * @version	1.0
 * @since	01/12/2016
 */
public abstract class Erro{
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
		String mensagem = "Nome inválido!\n"
						+ "Deve haver caracteres inválidos, busque corrigir.\n"
						+ "Lembre-se: apenas letras de A-Z, sem acentuação."
						+ "Digite, novamente.";
						
		return mensagem;
	}

	/**
	 * Mensagem de erro no CPF fornecido
	 * @return Mensagem desenvolvida
	 */
	public static String cpf (){
		String mensagem = "CPF inválido!\n"
						+ "Deve haver caracteres inválidos, busque corrigir.\n"
						+ "Lembre-se: apenas números de 0-9.\n"
						+ "Digite, novamente.";
		
		return mensagem;
	}
}
