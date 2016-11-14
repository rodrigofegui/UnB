/*	Pacote ao qual pertence */
package principal;

import java.awt.Color;

import javax.swing.JSlider;
import javax.swing.JTextField;

import sintese.BancoDeInstrumentos;
import sintese.Dispositivo;
import sintese.Melodia;
import sintese.Som;
import sintese.Tema;

/** 
 * Constroi a aplicacao das acoes ocorridas na area grafica
 * garantindo a finalidade do programa
 * @author	Helio Santana
 * @author	Rodrigo Guimaraes
 * @version	1.0
 * @since	02/06/2016
 */
public class ControleComandos {
	/**
	 * Componentes requisitados para o desenvolvimento
	 */
	static Melodia melodiaEscolhida = null;
	static Dispositivo instrumentoEscolhido = null;
	static String nomeSomFormado = "sem_nome";
	static Som somFormado = null;
	/**
	 * Controles internos
	 */
	private static boolean melodiaSelecionada = false;
	private static boolean instrumentoSelecionado = false;
	private static int aSelecionar = 2;
	private static boolean invertida = false;
	static boolean editando = false;
	private static boolean deslizando = false;
	/**
	 * Itens descartáveis, mas utilizados por muitos
	 */
	private static float razao;
	private static int indiceEscolhido;
	private static int valorMaximo;
	private static int valorCorrente;
	private static String nome;

	
	
	/**
	 * Configuracao das acoes a serem tomadas ao se manipular
	 * o controle de selecao de melodias
	 */
	public static void escolherMelodias (){
		indiceEscolhido = InterfaceGrafica.escolherMelodias.getSelectedIndex();
				
		melodiaEscolhida = null;
		
		switch (indiceEscolhido){
			case 0:
				System.gc();
				break;
			case 1:
				melodiaEscolhida = Melodias.frozen();
				break;
			case 2:
				melodiaEscolhida = Melodias.gameOfThrones();
				break;
			case 3:
				melodiaEscolhida = Melodias.rainsOfCastamere();
				break;
			case 4:
				melodiaEscolhida = Tema.melodiasexta1();
				break;
			case 5:
				melodiaEscolhida = Tema.sonata_scarlatti();
				break;
			case 6:
				melodiaEscolhida = Tema.tema_aa_drawing_quintet_flauta();
				break;
			case 7:
				melodiaEscolhida = Tema.tema_aa_fuga1();
				break;
			case 8:
				melodiaEscolhida = Tema.tema_bwv775_invencao14_direita();
				break;
			case 9:
				melodiaEscolhida = Tema.tema_bwv775_invencao4_esquerda();
				break;
			case 10:
				melodiaEscolhida = Tema.tema_bwv988goldberg_v03_eq();
				break;
			case 11:
				melodiaEscolhida = Tema.tema_duda_no_frevo_eqYYY();
		}
		
		configurarInfosMelodias ();
		
		if (indiceEscolhido != 0 & !melodiaSelecionada)
			melodiaSelecionada = true;
		else if (indiceEscolhido != 0 & melodiaSelecionada)
			indiceEscolhido = -1;
		else if (indiceEscolhido == 0)
			melodiaSelecionada = false;
		
		analisarVisualizar (indiceEscolhido);
	}
	
	/**
	 * Configuracao das acoes a serem tomadas ao se manipular
	 * o controle de selecao de melodias
	 */
	public static void escolherInstrumentos (){
		indiceEscolhido = InterfaceGrafica.escolherInstrumentos.getSelectedIndex();
		
		instrumentoEscolhido = null;
		
		switch (indiceEscolhido){
			case 0:
				System.gc();
				break;
			case 1:
				instrumentoEscolhido = new IN1 ();
				break;
			case 2:
				instrumentoEscolhido = new IN2 ();
				break;
			case 3:
				instrumentoEscolhido = new IN3 ();
				break;
			case 4:
				instrumentoEscolhido = BancoDeInstrumentos.flauta_nao_harmonica_tonal();
				break;
			case 5:
				instrumentoEscolhido = BancoDeInstrumentos.gongo_aa_1994();
				break;
			case 6:
				instrumentoEscolhido = BancoDeInstrumentos.marimba_i51();
				break;
			case 7:
				instrumentoEscolhido = BancoDeInstrumentos.sompuro();
				break;
			case 8:
				instrumentoEscolhido = BancoDeInstrumentos.timbre_quasetonal();
				break;
			case 9:
				instrumentoEscolhido = BancoDeInstrumentos.timbreortogonal3();
				break;
			case 10:
				instrumentoEscolhido = BancoDeInstrumentos.trombone_naoharmonico();
				break;
			case 11:
				instrumentoEscolhido = BancoDeInstrumentos.trompete01();
		}
		
		
		configurarInfosInstrumento ();
		
		if (indiceEscolhido != 0 & !instrumentoSelecionado)
			instrumentoSelecionado = true;
		else if (indiceEscolhido != 0 & instrumentoSelecionado)
			indiceEscolhido = -1;
		else if (indiceEscolhido == 0)
			instrumentoSelecionado = false;
		
		analisarVisualizar (indiceEscolhido);
	}

	/**
	 * Salvar o som formado, com o nome
	 */
	public static void salvarSom (){
		formarSom();
		somFormado.salvawave ();
	}
	
	/**
	 * Configuracao do nome do som a ser salvo
	 */
	public static void configurarNomeSom (){
		nomeSomFormado = InterfaceGrafica.nomeWave.getText();
		
		if (nomeSomFormado.equals("nome do arquivo")
			|| nomeSomFormado.equals(""))
			nomeSomFormado = "sem_nome";
	}

	/**
	 * Tocar o som formado
	 */
	public static void tocarSom (){
		salvarSom();
		somFormado.tocawave();
	}

	/**
	 * Visualizar o espectro do som formado, sob a interface ja
	 * fornecida, e possibilitar a acao de tocar o som formado
	 */
	public static void visualizarSom (){
		formarSom();
		somFormado.visualiza();
	}

	/**
	 * Configuracoes relacionadas ao andamento da melodia
	 */
	public static void configurarAndamentoViaSlider (){
		deslizando = true;
		setRazaoViaSlider (InterfaceGrafica.controleAndamento);
		
		if (!editando)
			InterfaceGrafica.valorAndamento.setText ("" + razao);
		
		if (!InterfaceGrafica.controleAndamento.getValueIsAdjusting()
			& melodiaEscolhida != null){
				melodiaEscolhida.setAndamento (razao);
				System.out.println("Andamento foi para " + melodiaEscolhida.getAndamento());
			}
		
		deslizando = false;
	}
	
	/**
	 * Configuracoes relacionadas ao andamento da melodia
	 */
	public static void configurarAndamentoViaTexto (){
		if (!deslizando){
			editando = true;
			
			setRazaoViaTexto (InterfaceGrafica.valorAndamento);
			
			InterfaceGrafica.controleAndamento.setValue((int)(razao * 100));
			
			if (melodiaEscolhida != null){
				melodiaEscolhida.setAndamento(razao);
				System.out.println("Andamento foi para " + melodiaEscolhida.getAndamento());
			}
			
			editando = false;
		}
	}

	/**
	 * Configuracoes relacionadas a transposicao da melodia
	 */
	public static void configurarTransposicaoViaSlider (){
		deslizando = true;
		
		setRazaoViaSlider (InterfaceGrafica.controleTransposicao);

		if (!editando)
			InterfaceGrafica.valorTransposicao.setText ("" + razao);
		
		if (!InterfaceGrafica.controleTransposicao.getValueIsAdjusting()
			& melodiaEscolhida != null){
			melodiaEscolhida.transposicao(razao);
			System.out.println("A melodia foi transposta de " + razao);
		}
		
		deslizando = false;
	}
	
	/**
	 * Configuracoes relacionadas a transposicao da melodia
	 */
	public static void configurarTransposicaoViaTexto (){
		if (!deslizando){
			editando = true;
			
			setRazaoViaTexto (InterfaceGrafica.valorTransposicao);

			InterfaceGrafica.controleTransposicao.setValue((int)(razao * 100));
			
			if (melodiaEscolhida != null){
				melodiaEscolhida.transposicao (razao);
				System.out.println("A melodia foi transposta de " + razao);
			}
			
			editando = false;
		}
	}

	/**
	 * Configuracoes relacionadas ao fator de corte do instrumento
	 */
	public static void configurarFatordeCorteViaSlider (){
		deslizando = true;
		
		setRazaoViaSlider (InterfaceGrafica.controleFatordeCorte);
		
		if (!editando)
			InterfaceGrafica.valorFatordeCorte.setText ("" + razao);
		
		if (!InterfaceGrafica.controleFatordeCorte.getValueIsAdjusting()){
			switch(verificaInstrumento()){
				case 1:
					((IN1) instrumentoEscolhido).setFatorCorte (razao);
					System.out.println("Fator de corte foi para " + razao);
					break;
				case 2:
					((IN2) instrumentoEscolhido).setFatorCorte (razao);
					System.out.println("Fator de corte foi para " + razao);
					break;
				case 3:
					((IN3) instrumentoEscolhido).setFatorCorte (razao);
					System.out.println("Fator de corte foi para " + razao);
					break;
			}
		}
		
		deslizando = false;
	}
	
	/**
	 * Configuracoes relacionadas a transposicao da melodia
	 */
	public static void configurarFatordeCorteViaTexto (){
		if (!deslizando){
			editando = true;
			
			setRazaoViaTexto (InterfaceGrafica.valorFatordeCorte);
			
			InterfaceGrafica.controleFatordeCorte.setValue((int)(razao * 10000));
			
			switch(verificaInstrumento()){
				case 1:
					((IN1) instrumentoEscolhido).setFatorCorte (razao);
					System.out.println("Fator de corte foi para " + razao);
					break;
				case 2:
					((IN2) instrumentoEscolhido).setFatorCorte (razao);
					System.out.println("Fator de corte foi para " + razao);
					break;
				case 3:
					((IN3) instrumentoEscolhido).setFatorCorte (razao);
					System.out.println("Fator de corte foi para " + razao);
					break;
			}
			
			editando = false;
		}
	}
	
	/**
	 * Configuracoes relacionadas a fase do instrumento
	 */
	public static void configurarFaseViaSlider (){
		deslizando = true;
		
		razao = InterfaceGrafica.controleFase.getValue();
		
		if (!editando)
			InterfaceGrafica.valorFase.setText("" + razao);
		
		if (!InterfaceGrafica.controleFase.getValueIsAdjusting()){
			switch(verificaInstrumento()){
				case 1:
					((IN1) instrumentoEscolhido).setFase (razao);
					System.out.println("Fase foi para " + razao);
					break;
				case 2:
					((IN2) instrumentoEscolhido).setFase (razao);
					System.out.println("Fase foi para " + razao);
					break;
				case 3:
					((IN3) instrumentoEscolhido).setFase (razao);
					System.out.println("Fase foi para " + razao);
					break;
			}
		}
		
		deslizando = false;
	}
	
	/**
	 * Configuracoes relacionadas a fase do instrumento
	 */
	public static void configurarFaseViaTexto (){
		if (!deslizando){
			editando = true;
			
			setRazaoViaTexto (InterfaceGrafica.valorFase);
			
			InterfaceGrafica.controleFase.setValue((int)(razao));
			
			switch(verificaInstrumento()){
				case 1:
					((IN1) instrumentoEscolhido).setFase (razao);
					System.out.println("Fase foi para " + razao);
					break;
				case 2:
					((IN2) instrumentoEscolhido).setFase (razao);
					System.out.println("Fase foi para " + razao);
					break;
				case 3:
					((IN3) instrumentoEscolhido).setFase (razao);
					System.out.println("Fase foi para " + razao);
					break;
			}
			
			editando = false;
		}
	}
	
	/**
	 * Configuracoes relacionadas a estereofonia para a saida do instrumento
	 */
	public static void configurarLambdaViaSlider (){
		deslizando = true;
		
		setRazaoViaSlider (InterfaceGrafica.controleLambda);
		
		if (!editando)
			InterfaceGrafica.valorLambda.setText("" + razao );
		
		if (!InterfaceGrafica.controleLambda.getValueIsAdjusting()){
			switch(verificaInstrumento()){
				case 1:
					((IN1) instrumentoEscolhido).setLambda (razao);
					System.out.println("Esteriofonia na esquerda foi para " + razao);
					break;
				case 2:
					((IN2) instrumentoEscolhido).setLambda (razao);
					System.out.println("Esteriofonia na esquerda foi para " + razao);
					break;
				case 3:
					((IN3) instrumentoEscolhido).setLambda (razao);
					System.out.println("Esteriofonia na esquerda foi para " + razao);
					break;
			}
		}
		
		deslizando = false;
	}
	
	/**
	 * Configuracoes relacionadas a fase do instrumento
	 */
	public static void configurarLambdaViaTexto (){
		if (!deslizando){
			editando = true;
			
			setRazaoViaTexto (InterfaceGrafica.valorLambda);
			
			InterfaceGrafica.controleLambda.setValue((int)(razao * 100));
			
			switch(verificaInstrumento()){
				case 1:
					((IN1) instrumentoEscolhido).setLambda (razao);
					System.out.println("Esteriofonia na esquerda foi para " + razao);
					break;
				case 2:
					((IN2) instrumentoEscolhido).setLambda (razao);
					System.out.println("Esteriofonia na esquerda foi para " + razao);
					break;
				case 3:
					((IN3) instrumentoEscolhido).setLambda (razao);
					System.out.println("Esteriofonia na esquerda foi para " + razao);
					break;
			}
			
			editando = false;
		}
	}
	
	/**
	 * Configuracoes relacionadas a inversao da melodia
	 * @param acao Operacao realizada sobre a caixa de selecao,
	 * marcando positiva ou negativamente
	 */
	public static void configurarInversaoMelodia (int acao){
		if (acao == 0 & !invertida){
			melodiaEscolhida.inversao();
			invertida = true;
			System.out.println("A melodia foi invertida");
			
		}else if (acao == 1 & invertida){
			melodiaEscolhida.inversao();
			invertida = false;
			System.out.println("A melodia voltou ao sentido normal");
		}
	}
	
	/**
	 * Configuracoes relacionadas ao habilitar salvar a melodia
	 * @param acao Operacao realizada sobre a caixa de selecao,
	 * marcando positiva ou negativamente
	 */
	public static void configurarSalvarSom (int acao){
		editando = false;
		if (acao == 0){
			InterfaceGrafica.salvarSom.setEnabled(true);
			InterfaceGrafica.nomeWave.setText("nome do arquivo");
			InterfaceGrafica.nomeWave.setForeground(new Color (128, 128, 128));
			InterfaceGrafica.nomeWave.setVisible(true);
			
		}else{
			InterfaceGrafica.salvarSom.setEnabled(false);
			InterfaceGrafica.nomeWave.setVisible(false);
		}
	}
	
	/**
	 * Configuracoes relacionadas ao ganho de amplitude no instrumento
	 */
	public static void configurarGanhoInstrumento (){
		if (!editando){
			//System.out.println("tam -> " + InterfaceGrafica.valorGanhoInst.getText().length());
			
			setRazaoViaTexto (InterfaceGrafica.valorGanhoInst);
						
			//*
			switch(verificaInstrumento()){
				case 1:
					((IN1) instrumentoEscolhido).setGanho (razao);
					System.out.println("Foi feito um ganho de " + razao + " no instrumento");
					break;
				case 2:
					((IN2) instrumentoEscolhido).setGanho (razao);
					System.out.println("Foi feito um ganho de " + razao + " no instrumento");
					break;
				case 3:
					((IN3) instrumentoEscolhido).setGanho (razao);
					System.out.println("Foi feito um ganho de " + razao + " no instrumento");
					break;
				case 4:
					instrumentoEscolhido.setGanho(razao);
					System.out.println("Foi feito um ganho de " + razao + " no instrumento");
					break;
			}
		}
		//*/
	}

	/**
	 * Configuracoes relacionadas ao click do mouse sobre a caixa do
	 * nome do arquivo
	 */
	public static void configurarClickSalvar (){
		nome = InterfaceGrafica.nomeWave.getText();
		
		if ("nome do arquivo".equals(nome)){
			InterfaceGrafica.nomeWave.setText("");
			InterfaceGrafica.nomeWave.setForeground(new Color (0, 0, 0));
		}
	}
	
		
	
	
	/**
	 * Controle o status do "Visualizar", ativando quando se tem 
	 * melodia e instrumento escolhidos
	 * @param indiceEscolhido	Melodia ou Instrumento escolhido
	 */
	public static void analisarVisualizar (int indiceEscolhido) {
		
		if(indiceEscolhido > 0)
			aSelecionar--;
		else if (indiceEscolhido == 0)
			aSelecionar++;
		
		if (aSelecionar == 0){
			InterfaceGrafica.visualizarSom.setEnabled(true);
			InterfaceGrafica.tocarSom.setEnabled(true);
			InterfaceGrafica.controleSalvar.setEnabled(true);
			
		}else{
			InterfaceGrafica.visualizarSom.setEnabled(false);
			InterfaceGrafica.tocarSom.setEnabled(false);
			InterfaceGrafica.controleSalvar.setEnabled(false);
		}
	}

	/**
	 * Configuracao do valor a ser exibido na caixa de texto,
	 * referente ao slider modificado
	 * @param mestre Slider que sofreu alteracao de seu valor
	 */
	private static void setRazaoViaSlider (JSlider mestre) {
		valorMaximo = mestre.getMaximum();
		valorCorrente = mestre.getValue();
		
		razao = (float) Character.getNumericValue (Float.toString(valorMaximo).charAt(0));
		razao *= ((float)valorCorrente / valorMaximo);
	}
	
	/**
	 * Configuracao do valor a ser configurado no slider,
	 * referente a caixa de texto modificada
	 * @param mestre Caixa de texto que sofreu alteracao
	 */
	private static void setRazaoViaTexto (JTextField mestre) {
		if (mestre.getText().length() != 0)
			razao = Float.parseFloat (mestre.getText());
		else
			razao = 0;
	}
	
	/**
	 * Configuracao do som formado com as manipulacoes
	 */
	private static void formarSom (){
		somFormado = null;
		System.gc();
		
		if (!melodiaEscolhida.equals(null) & !instrumentoEscolhido.equals(null)){
			somFormado = melodiaEscolhida.getSom(instrumentoEscolhido);
		
			configurarNomeSom();
			somFormado.setNome(nomeSomFormado);
			
			System.out.println("");
		}
	}

	/**
	 * Configuracao dos parametros da interface em relacao a melodia escolhida
	 */
	private static void configurarInfosMelodias () {
		if (melodiaEscolhida != null){
			razao = melodiaEscolhida.getAndamento();
			
			InterfaceGrafica.controleAndamento.setValue((int)(razao * 100));
			
			InterfaceGrafica.controleInverterMel.setEnabled(true);
			
			configurarAndamentoViaSlider ();
		
		}else
			InterfaceGrafica.controleInverterMel.setEnabled(false);
	}
	
	/**
	 * Configuracao dos parametros da interface em relacao ao instrumento escolhido
	 */
	private static void configurarInfosInstrumento () {
		if (instrumentoEscolhido != null){
			switch(verificaInstrumento()){
				case 1:
					valorMaximo = InterfaceGrafica.controleFatordeCorte.getMaximum();
					razao = ((IN1) instrumentoEscolhido).getFatorCorte ();
					InterfaceGrafica.controleFatordeCorte.setValue((int)(razao * valorMaximo));
					
					valorMaximo = InterfaceGrafica.controleFase.getMaximum();
					razao = ((IN1) instrumentoEscolhido).getFase();
					InterfaceGrafica.controleFase.setValue((int)(razao * valorMaximo));
					
					valorMaximo = InterfaceGrafica.controleLambda.getMaximum();
					razao = ((IN1) instrumentoEscolhido).getLambda();
					InterfaceGrafica.controleLambda.setValue((int)(razao * valorMaximo));
					
					editando = true;
					razao = ((IN1) instrumentoEscolhido).getGanho();
					InterfaceGrafica.valorGanhoInst.setText("" + razao);
					editando = false;
					break;
				case 2:
					valorMaximo = InterfaceGrafica.controleFatordeCorte.getMaximum();
					razao = ((IN2) instrumentoEscolhido).getFatorCorte ();
					InterfaceGrafica.controleFatordeCorte.setValue((int)(razao * valorMaximo));
					
					valorMaximo = InterfaceGrafica.controleFase.getMaximum();
					razao = ((IN2) instrumentoEscolhido).getFase();
					InterfaceGrafica.controleFase.setValue((int)(razao * valorMaximo));
					
					valorMaximo = InterfaceGrafica.controleLambda.getMaximum();
					razao = ((IN2) instrumentoEscolhido).getLambda();
					InterfaceGrafica.controleLambda.setValue((int)(razao * valorMaximo));
					
					editando = true;
					razao = ((IN2) instrumentoEscolhido).getGanho();
					InterfaceGrafica.valorGanhoInst.setText("" + razao);
					editando = false;
					break;
				case 3:
					valorMaximo = InterfaceGrafica.controleFatordeCorte.getMaximum();
					razao = ((IN3) instrumentoEscolhido).getFatorCorte ();
					InterfaceGrafica.controleFatordeCorte.setValue((int)(razao * valorMaximo));
					
					valorMaximo = InterfaceGrafica.controleFase.getMaximum();
					razao = ((IN3) instrumentoEscolhido).getFase();
					InterfaceGrafica.controleFase.setValue((int)(razao * valorMaximo));
					
					valorMaximo = InterfaceGrafica.controleLambda.getMaximum();
					razao = ((IN3) instrumentoEscolhido).getLambda();
					InterfaceGrafica.controleLambda.setValue((int)(razao * valorMaximo));
					
					editando = true;
					razao = ((IN3) instrumentoEscolhido).getGanho();
					InterfaceGrafica.valorGanhoInst.setText("" + razao);
					editando = false;
					break;
			}
			
			configurarFatordeCorteViaSlider();
			configurarFaseViaSlider ();
			configurarLambdaViaSlider();
		}
	}
	
	/**
	 * Verificacao do tipo efetivo do instrumento a ser manipulado
	 */
	private static int verificaInstrumento (){
		if (instrumentoEscolhido != null){
			if (instrumentoEscolhido.getClass().equals(IN1.class))
				return 1;
			else if (instrumentoEscolhido.getClass().equals(IN2.class))
				return 2;
			else if (instrumentoEscolhido.getClass().equals(IN3.class))
				return 3;
			else
				return 4;
		}
		return 0;
	}
}
