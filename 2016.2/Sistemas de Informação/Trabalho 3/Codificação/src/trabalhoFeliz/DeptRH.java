package trabalhoFeliz;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.LinkedList;
import java.util.Scanner;

import bancoDados.manipulacao.DecimoTerceiroM;
import bancoDados.manipulacao.DisciplinaM;
import bancoDados.manipulacao.FeriasM;
import bancoDados.manipulacao.FuncionarioM;
import bancoDados.manipulacao.HoleriteM;
import bancoDados.manipulacao.INSSM;
import bancoDados.manipulacao.IRRFM;
import bancoDados.manipulacao.ProfissaoM;
import bancoDados.tabelas.DecimoTerceiro;
import bancoDados.tabelas.Disciplina;
import bancoDados.tabelas.Ferias;
import bancoDados.tabelas.Funcionario;
import bancoDados.tabelas.Holerite;
import bancoDados.tabelas.INSS;
import bancoDados.tabelas.IRRF;
import bancoDados.tabelas.Profissao;
import gui.Mensagem;
import gui.terminal.Textual;
import principal.Principal;
import utilitario.Autentificacao;
import utilitario.Erro;


/**
 * Classe responsável pela implementação do Departamento de Recursos Humanos
 * na empresa TrabalhoFeliz
 * @author	Rodrigo Guimarães
 * @version	1.0
 * @since	29/11/2016
 */
public class DeptRH {
	public static final int DIAS_COMERCIAIS = 30;
	private LinkedList<Empregado> empregados;
	private GregorianCalendar dataCorrente;
	private int mesesSimulacao;
	private int porte;
	
	/**
	 * Construção do Departamento, por maneira default
	 */
	public DeptRH (){
		setEmpregados(new LinkedList<Empregado> ());
		
		setDataCorrente(new GregorianCalendar(2016, 0, 1));
		
		setPorte(1);
	}
	
	
	
	/**
	 * Valor atribuído os empregados
	 * @return Os empregados da empresa
	 */
	public LinkedList<Empregado> getEmpregados (){
		return empregados;
	}
	
	/**
	 * Atribuir valor aos empregados
	 * @param empregados Os empregados a serem atribuídos
	 */
	public void setEmpregados (LinkedList<Empregado> empregados){
		this.empregados = empregados;
	}
	
	/**
	 * Valor atribuído à data corrente
	 * @return A dataCorrente
	 */
	public GregorianCalendar getDataCorrente() {
		return dataCorrente;
	}
	
	/**
	 * Atribuir valor à data corrente
	 * @param dataCorrente A dataCorrente a ser atribuída
	 */
	public void setDataCorrente(GregorianCalendar dataCorrente) {
		this.dataCorrente = dataCorrente;
	}
	
	/**
	 * Valor atribuído ao porte da empresa
	 * @return O porte da empresa
	 */
	public int getPorte() {
		return porte;
	}
	
	/**
	 * Atribuir valor ao porte da empresa
	 * @param porte O porte a ser atribuído
	 */
	public void setPorte(int porte) {
		this.porte = porte;
	}
	
	/**
	 * Valor atribuído aos meses de simulação
	 * @return Os meses de simulacao
	 */
	public int getMesesSimulacao() {
		return mesesSimulacao;
	}
	



	/**
	 * Atribuir valor aos meses de simulação
	 * @param mesesSimulacao Os meses de simulacao a serem atribuídos
	 */
	public void setMesesSimulacao(int mesesSimulacao){
		this.mesesSimulacao = mesesSimulacao;
	}
	
	
	



	/**
	 * Povoando as tabelas base para o desenvolvimento da aplicação,
	 * considerando as que estiverem vazias
	 */
	public static void povoarBase (){
		System.out.println(Mensagem.aguarde("Povoar tabelas base"));

		if (DisciplinaM.isEmpty())
			Disciplina.povoar();
		
		if (INSSM.isEmpty())
			INSS.povoar();
		
		if (IRRFM.isEmpty())
			IRRF.povoar();
		
		if (ProfissaoM.isEmpty())
			Profissao.povoar();

		System.out.println(Mensagem.sucesso("Povoar tabelas base"));
	}
	
	/**
	 * Exclusão de todas as instâncias de todas
	 * as tabelas existentes no BD
	 */
	public static void esvaziarTudo (){
		DecimoTerceiroM.esvaziar();
		
		DisciplinaM.esvaziar();
		
		FeriasM.esvaziar();
		
		FuncionarioM.esvaziar();
		
		HoleriteM.esvaziar();
		
		INSSM.esvaziar();
		
		IRRFM.esvaziar();
		
		ProfissaoM.esvaziar();
	}
	
	
	
	/**
	 * Simulação do sistema
	 * @param entradaDados Entrada de dados via terminal
	 * @param mesesSimulacao A quantidade de meses a serem considerados
	 * para a simulação
	 */
	public void simular (Scanner entradaDados, int mesesSimulacao){
		setMesesSimulacao(mesesSimulacao);
		setPorte(gerarPorte());
		
		cadastrar ();
		
		for (int mes = 0; mes < mesesSimulacao; mes++){
			trabalhar();
			
			gerenciarPagamento();
			
			System.out.println(Mensagem.sucesso("Simular período: " + Autentificacao.data(getDataCorrente())));
			
			Autentificacao.avancarMes(getDataCorrente(), 1);
			Textual.aguardeTecla(entradaDados);
			
			if (getDataCorrente().get(Calendar.MONTH) == 0)
				reiniciarDecTer ();
		}
		
		
		Textual.aguardeTecla(entradaDados);
	}
	
	/**
	 * Gerar porte da empresa para a simulação
	 * @return Por ter uma base de 25 nomes, foram dividos 5 níveis para o
	 * porte, retornando valores entre 1 e 4
	 */
	private static int gerarPorte (){
		return (Integer.parseInt(Autentificacao.gerarSeqInt(4, 1)) + 1);
	}
	
	/**
	 * Cadastramento dos funcionários na empresa
	 */
	private void cadastrar (){
		//*
		System.out.println(Mensagem.aguarde("Cadastrar Homens"));
		cadastrar("Inicialização/Homens.txt");			
		System.out.println(Mensagem.sucesso("Cadastrar Homens"));
		
		System.out.println(Mensagem.aguarde("Cadastrar Mulheres"));
		cadastrar("Inicialização/Mulheres.txt");			
		System.out.println(Mensagem.sucesso("Cadastrar Mulheres"));
		//*/
		
		atribuirEmpregados ();
	}
	
	/**
	 * Cadastrar empregados, com base num arquivo .txt, para
	 * a simulação
	 * @param nomeArq Nome do arquivo que contém a base para a
	 * simulação
	 */
	private void cadastrar (String nomeArq){
		try{
			BufferedReader leitura = new BufferedReader(new FileReader(nomeArq));
						
			while(leitura.ready()){
				for (int qnt = 0; qnt < (getPorte() * 5); qnt++){
					Funcionario func = Empregado.preencherDados(leitura, nomeArq);
					
					if (func != null)
						FuncionarioM.inserir(func);
				}
				break;
			}
	         
	        leitura.close();
      	}catch(IOException excessao){
      		System.out.println(Erro.acessarArq(nomeArq));
	    }
	}
	
	/**
	 * Atribuir os funcionários do BD aos empregados da empresa 
	 */
	private void atribuirEmpregados (){
		LinkedList<Funcionario> funcionarios = FuncionarioM.lerCompleto();
		
		for (int pos = 0; pos < funcionarios.size(); pos++){
			Empregado empregado = new Empregado();
			empregado.setFunc(funcionarios.get(pos));
			
			getEmpregados().add(empregado);
		}
	}
	
	/**
	 * Proporcionar a ação de trabalhar a todos os empregados
	 */
	private void trabalhar (){
		for (int pos = 0; pos < getEmpregados().size(); pos++)
			getEmpregados().get(pos).trabalhar();
	}
	
	/**
	 * Gerenciamento de todas as holerites
	 */
	public void gerenciarPagamento (){
		DeptFinan deptFinan = new DeptFinan();

		System.out.println ("Gerenciando...");
		
		for (int pos = 0; pos < getEmpregados().size(); pos++){
			Empregado empregado = getEmpregados().get(pos);
			Holerite holerite = new Holerite();
			
			holerite.setDataRef(Autentificacao.data(getDataCorrente()));
			holerite.setFuncMat(empregado.getFunc().getMatricula());
			
			float salBase = resgatarSalBase(empregado);
			
			float salLiq = controleINSS(empregado, salBase);
			holerite.setInss(salLiq);
			holerite.setIrrf(controleIRRF(empregado, salLiq));
			holerite.setFaltas(controleFaltas(empregado, salBase));
			holerite.setFerias(controleFerias(empregado, salBase));
			holerite.setDecTerceiro(controle13Sal(empregado, salBase));
			holerite.setValeTransporte(controleValeTransporte(empregado, salBase));
			
			holerite.setSalLiq();
			holerite.setSalLiq(holerite.getSalLiq() + salBase);
			
			holerite.gerar(empregado, salBase);
			DecimoTerceiro.atualizar(holerite);
			
			System.out.println(Mensagem.aguarde("Emissão da holerite"));
			if(!emitirHolerite(holerite, empregado)){
				Principal.executar("mkdir Holerite/");
				emitirHolerite(holerite, empregado);
			}
			
			deptFinan.pagar(holerite, empregado);
		}
		
		if(!deptFinan.registrarMes(getDataCorrente())){
			Principal.executar("mkdir Registro/");
			deptFinan.registrarMes(getDataCorrente());
		}
	}
	
	/**
	 * Operação de resgate do salário base do trabalhador;
	 * @param empregado Empregado a ser avaliado no controle
	 * @return Salário base referente ap cargo do usuário
	 */
	public float resgatarSalBase (Empregado empregado){
		LinkedList<Profissao> profissoes = ProfissaoM.lerCompleto();
		float salBase = 0f;
		
		for (int pos = 0; pos < profissoes.size(); pos++)
			if (profissoes.get(pos).getCodigo() == empregado.getFunc().getCodProf()){
				salBase = profissoes.get(pos).getSalarioBase();
				break;
			}
		
		return salBase;
	}
	
	/**
	 * Controle das férias.
	 * Caso haja uma requisição do empregado, será avaliado a disponibilidade de liberação
	 * do pagamento; caso contrário, será acrescentado 0
	 * @param empregado Empregado a ser avaliado no controle
	 * @param salBase Salário base do empregado
	 * @return Férias a serem creditadas
	 */
	public float controleFerias (Empregado empregado, float salBase){
		if (empregado.isReqFerias()){
			if (FeriasM.isEmpty())
				return determinarFerias(empregado, salBase);
				
			else{
				LinkedList<Ferias> listFerias = FeriasM.lerCompleto();
				
				for (int pos = 0; pos < listFerias.size(); pos++)
					if (listFerias.get(pos).getFuncMat() == empregado.getFunc().getMatricula()){
						String data = listFerias.get(pos).getDataRef();
						GregorianCalendar dataFerias = new GregorianCalendar(
								Autentificacao.ano(data), Autentificacao.mes(data),
								Autentificacao.dia(data));
						
						if (Autentificacao.diffDataMes(getDataCorrente(), dataFerias) >= 12)
							return determinarFerias(empregado, salBase);
					}
			}
		}
		
		return 0;
	}
	
	/**
	 * Controle do pagamento do 13º Salário
	 * @param empregado Empregado a ser avaliado no controle
	 * @param salBase Salário base do empregado
	 * @return Parcela a ser considerada
	 */
	public float controle13Sal (Empregado empregado, float salBase){
		float valor = 0f;
		
		if (empregado.isReq13Sal()){
			return determinar13Sal(empregado, salBase);
			
		}else{
			int mesAtual = getDataCorrente().get(Calendar.MONTH);
			//System.out.println("Mes atual -> " + mesAtual);
			//Textual.aguardeTecla(Principal.entradaDados);
			
			if ((mesAtual == DecimoTerceiro.MES_LIM_1)
				|| (mesAtual == DecimoTerceiro.MES_LIM_2))
				return determinar13Sal(empregado, salBase);
		}
		
		return valor;
	}
	
	/**
	 * Controle das faltas por conta do Empregado
	 * @param empregado Funcionário a ser analisado as faltas
	 * @param salBase Salário base para a determinação da dedução
	 * @return Dedução correspondente às faltas
	 */
	public float controleFaltas (Empregado empregado, float salBase){
		float deducao = ((float) empregado.getFaltas() / DIAS_COMERCIAIS) * salBase;
		
		/*
		System.out.println("Faltas -> " + empregado.getFaltas());
		System.out.println("Salário base -> " + salBase);
		System.out.println("Deduçao -> " + deducao);
		//*/
		
		return -deducao;
	}
	
	/**
	 * Controle da dedução da parcela do INSS
	 * @param empregado Funcionário a ser analisado as faltas
	 * @param salBase Salário base para a determinação da dedução
	 * @return Salário deduzido
	 */
	public float controleINSS (Empregado empregado, float salBase){
		return INSS.reducao(empregado.getFunc().getCodProfInss(), salBase);
	}
	
	/**
	 * Controle da dedução da parcela do IRFF
	 * @param empregado Funcionário a ser analisado as faltas
	 * @param salBase Salário base para a determinação da dedução
	 * @return Salário deduzido
	 */
	public float controleIRRF (Empregado empregado, float salBase){
		return IRRF.reducao(empregado.getFunc().getCodProfIrrf(), salBase);
	}
	
	/**
	 * Controle do vale transporte
	 * @param empregado Funcionário a ser analisado as faltas
	 * @param salBase Salário base para a determinação da dedução
	 * @return Desconto do vale transporte
	 */
	public float controleValeTransporte (Empregado empregado, float salBase){
		if (empregado.getFunc().getQntValeTransp() == 1)
			return -(salBase * .06f);
		
		return 0;
	}
	
	
	
	/**
	 * Determinar, efetivamente, o valor a ser acrescido
	 * pelas férias
	 * @param empregado Funcionário a ser analisado as f´erias
	 * @param salBase Salário base para a determinação do valor
	 * @return Valor das férias
	 */
	private float determinarFerias(Empregado empregado, float salBase){
		LinkedList<Holerite> holerites = HoleriteM.lerCompleto();
		Ferias ferias = new Ferias();
		float valor = 0f;
		
		for (int pos = holerites.size() - 1; pos >= 0; pos--){
			Holerite holerite = holerites.get(pos);
			if (holerite.getFuncMat() == empregado.getFunc().getMatricula()){
				float salario = INSS.deduzirAliquota(salBase);
				salario = IRRF.deduzirAliquota(empregado.getFunc().getCodProfIrrf(), salario);
				valor = holerite.getSalLiq() + (salario / 3f);
				
				break;
			}
		}
		
		ferias.setDataRef(Autentificacao.data(getDataCorrente()));
		ferias.setFuncMat(empregado.getFunc().getMatricula());
		FeriasM.inserir(ferias);
		
		return valor;
	}
	
	/**
	 * Determinar, efetivamente, o valor a ser acrescido
	 * pela parcela do 13º salário
	 * @param empregado Funcionário a ser analisado as faltas
	 * @param salBase Salário base para a determinação da dedução
	 * @return Valor da parcela
	 */
	private float determinar13Sal (Empregado empregado, float salBase){
		LinkedList<DecimoTerceiro> list13Sal = DecimoTerceiroM.lerCompleto();
		float valor = 0f;
		
		for (int pos = 0; pos < list13Sal.size(); pos++){
			DecimoTerceiro decTer = list13Sal.get(pos);
			
			if (decTer.getFuncMat() == empregado.getFunc().getMatricula())
				if (decTer.getContParcela() < DecimoTerceiro.LIM_PARCELAS){
					/*
					System.out.println("Concedeu 13º:");
					System.out.println("Em: " + Autentificacao.data(getDataCorrente()));
					System.out.println("A: " + empregado.getFunc().getNome());
					//*/
					
					valor = decTer.getParcelaAcumulada();
					
					decTer.setContParcela(decTer.getContParcela() + 1);
					decTer.setParcelaAcumulada(0f);
					decTer.setRequisicao(true);
					
					DecimoTerceiroM.atualizar(decTer);
					
					Textual.aguardeTecla(Principal.entradaDados);
					break;
				}
		}
		
		return valor;
	}
	
	
	
	/**
	 * Cadastramento de um novo funcionário na empresa TrabalhoFeliz;
	 * com o preenchimento dos dados pessoais e cadastramento no BD
	 */
	public void cadrastarFuncionario (){
		requisitarDados();
		
		//FuncionarioM.inserir(Empregado.preencherDados());
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

	
	
	/**
	 * Emissão da holerite gerada
	 * @param holerite Folha de pagamento a ser emitida
	 * @param empregado Funcionário a ser analisado as faltas
	 * @return True, se o processo ocorreu bem; false, caso contrário, sendo
	 * provavelmente por falta de diretório certo
	 */
	public boolean emitirHolerite (Holerite holerite, Empregado empregado){
		String caminho = "Holerite/" + holerite.getDataRef().replaceAll("/", "-")
						+ "_" + empregado.getFunc().getNome() + ".txt";
		
		try{			
			BufferedWriter gravarArq = new BufferedWriter(new FileWriter (caminho));
			
			gravarArq.append(holerite.getHolerite() + "\n");
			
			gravarArq.close();

			System.out.println(Mensagem.sucesso("Salvar '" + caminho + "'"));
			
			return true;
		}catch (IOException e) {
			System.out.println(Erro.acessarArq(caminho));
			
			return false;
		}
	}
	
	/**
	 * Reinício de todas os Décimos Terceiros, devido ao início do ano
	 */
	private void reiniciarDecTer (){
		if (!DecimoTerceiroM.isEmpty()){
			LinkedList<DecimoTerceiro> decTers = DecimoTerceiroM.lerCompleto();
			
			for (int pos = 0; pos < decTers.size(); pos++){
				DecimoTerceiro decTer = decTers.get(pos);
				
				decTer.setRequisicao(false);
				decTer.setContParcela(0);
				decTer.setParcelaAcumulada(0f);
				
				DecimoTerceiroM.atualizar(decTer);
			}
		}
	}
}
