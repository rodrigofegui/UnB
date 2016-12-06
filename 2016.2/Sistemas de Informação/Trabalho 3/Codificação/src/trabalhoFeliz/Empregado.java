package trabalhoFeliz;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.LinkedList;

import bancoDados.manipulacao.ProfissaoM;
import bancoDados.tabelas.Funcionario;
import bancoDados.tabelas.Profissao;
import utilitario.Autentificacao;
import utilitario.Erro;

/**
 * Classe responsável pela implementação de um Empregado
 * na empresa TrabalhoFeliz
 * @author	Rodrigo Guimarães
 * @version	1.0
 * @since	29/11/2016
 */
public class Empregado{
	private Funcionario func;
	private int grauAssiduo;
	private int faltas;
	private boolean reqFerias;
	private boolean req13Sal;
	
	
	
	/**
	 * Construção do Departamento, por maneira default
	 */
	public Empregado (){
		setFunc(new Funcionario());
		
		setGrauAssiduo(Integer.parseInt(Autentificacao.gerarSeqInt(1)));
		
		setFaltas(0);
		
		setReqFerias(false);
		
		setReq13Sal(false);
	}
	
	
	
	/**
	 * Valor atribuído ao funcionário corresponde no BD
	 * @return O funcionário corresponde no BD
	 */
	public Funcionario getFunc() {
		return func;
	}

	/**
	 * Atribuir valor ao funcionário corresponde no BD
	 * @param func O funcionário a ser atribuído
	 */
	public void setFunc(Funcionario func) {
		this.func = func;
	}

	/**
	 * Valor atribuído ao grau assiduidade
	 * @return O grau de assiduidade
	 */
	public int getGrauAssiduo() {
		return grauAssiduo;
	}

	/**
	 * Atribuir valor ao grau assiduidade
	 * @param grauAssiduo O grauAssiduo a ser atribuído
	 */
	public void setGrauAssiduo(int grauAssiduo) {
		this.grauAssiduo = grauAssiduo;
	}

	/**
	 * Valor atribuído às faltas
	 * @return As faltas do mês
	 */
	public int getFaltas() {
		return faltas;
	}

	/**
	 * Atribuir valor às faltas
	 * @param faltas As faltas a serem atribuídas
	 */
	public void setFaltas(int faltas) {
		this.faltas = faltas;
	}

	/**
	 * Valor atribuído à requisição de férias
	 * @return A requisição de férias
	 */
	public boolean isReqFerias() {
		return reqFerias;
	}

	/**
	 * Atribuir valor à requisição de férias
	 * @param reqFerias A requisição de férias a ser atribuída
	 */
	public void setReqFerias(boolean reqFerias) {
		this.reqFerias = reqFerias;
	}

	/**
	 * Valor atribuído à requisição do 13º salário
	 * @return A requisição do 13º Salário
	 */
	public boolean isReq13Sal() {
		return req13Sal;
	}

	/**
	 * Atribuir valor à requisição do 13º salário
	 * @param req13Sal A requisição a ser atribuída
	 */
	public void setReq13Sal(boolean req13Sal) {
		this.req13Sal = req13Sal;
	}
	
	

	/**
	 * Preenchimento dos dados pessoais do funcionário para a simulação
	 * @param leitura Arquivo que será lido os dados pessoais
	 * @param nomeArq Nome do arquivo a ser lido
	 * @return Funcionários com os dados preenchidos
	 */
	public static Funcionario preencherDados (BufferedReader leitura, String nomeArq){	
		Funcionario func = new Funcionario();
		
		try {
			String text = leitura.readLine();
			
			if (text.length() == 0){
				return null;
			}
			
			func.setCpf(Autentificacao.cpf(text));
			func.setNome(Autentificacao.nome(leitura.readLine()));
			func.setDataNasc(Autentificacao.data(leitura.readLine()));
			func.setTelefone(Autentificacao.telefone(leitura.readLine()));
			func.setEmail(leitura.readLine());
			preencherProfissao(leitura, func);
			func.setDataAdm(Autentificacao.data(leitura.readLine()));
			func.setQntValeTransp(Integer.parseInt(leitura.readLine()));
		} catch (IOException e) {
			System.out.println(Erro.acessarArq(nomeArq));
		}
		
		return func;
	}
	
	/**
	 * Preenchimento da profissão do funcionário para a simulação
	 * @param leitura Arquivo que será lido os dados pessoais
	 * @param func Funcionário a ser atribuído a profissão e os códigos
	 * da faixa do INSS e do IRRF
	 */
	private static void preencherProfissao (BufferedReader leitura, Funcionario func){
		LinkedList<Profissao> profissoes = ProfissaoM.lerCompleto();
		LinkedList<Integer> codigos = new LinkedList<Integer>();
		Profissao prof = new Profissao();
		
		try {
			String linha = leitura.readLine();
			for (int pos = 0; pos < profissoes.size(); pos++){
				prof = profissoes.get(pos);
				
				if (Integer.parseInt(linha) == prof.getCodigo())
					break;
			}
		
		} catch (NumberFormatException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		func.setCodProf(prof.getCodigo());
		func.setCodProfInss(prof.getInss_codigo());
		func.setCodProfIrrf(prof.getIrrf_codigo());
	}

	
	
	/**
	 * Simulação da ação de trabalhar
	 */
	public void trabalhar (){
		setGrauAssiduo(Integer.parseInt(Autentificacao.gerarSeqInt(9, 1)) + 1);
		
		setFaltas(Integer.parseInt(Autentificacao.gerarSeqInt(getGrauAssiduo(), 1)));
		
		setReqFerias(Boolean.parseBoolean(Autentificacao.gerarSeqInt(2, 1)));
		
		setReq13Sal(Boolean.parseBoolean(Autentificacao.gerarSeqInt(2, 1)));
	}
}

