package trabalhoFeliz;

import bancoDados.tabelas.Disciplina;
import bancoDados.tabelas.INSS;
import bancoDados.tabelas.IRRF;
import bancoDados.tabelas.Profissao;

/**
 * Classe responsável pela implementação do Departamento de Recursos Humanos
 * na empresa TrabalhoFeliz
 * @author	Rodrigo Guimarães
 * @version	1.0
 * @since	29/11/2016
 */
public class DeptRH {
	
	/**
	 * Construção do Departamento, por maneira default
	 */
	public DeptRH (){
		Disciplina.povoar();
		
		INSS.povoar();
		
		IRRF.povoar();
		
		Profissao.povar();
	}
	
	/**
	 * Cadastramento de um novo funcionário na empresa TrabalhoFeliz;
	 * com o preenchimento dos dados pessoais e cadastramento no BD
	 */
	public void cadrastarFuncionario (){
		requisitarDados();
		
		Empregado.preencherDados();
	}
	
	/**
	 * Requisitando ao empregado o preenchimento dos dados pessoais, de forma
	 * a efetivá-lo na TrabalhoFeliz
	 */
	private void requisitarDados(){
		System.out.println("Bem-vindo a TrabalhoFeliz!");
		System.out.println("Para a oficialização da contratação é preciso saber");
		System.out.println("os seus dados pessoais.\n");
		
		System.out.println("Por favor, os preencham agora");
	}
}
