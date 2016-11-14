/*	Pacote ao qual pertence */
package interfaceGrafica;

import java.awt.Color;
import java.awt.Dimension;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.text.DecimalFormat;

import javax.sound.midi.InvalidMidiDataException;
import javax.sound.midi.MetaMessage;
import javax.sound.midi.MidiEvent;
import javax.sound.midi.MidiMessage;
import javax.sound.midi.MidiSystem;
import javax.sound.midi.Sequence;
import javax.sound.midi.Track;
import javax.swing.BorderFactory;
import javax.swing.BoxLayout;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JSlider;
import javax.swing.JTable;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.JTextPane;
import javax.swing.table.DefaultTableModel;

import sintese.BancoDeInstrumentos;
import sintese.Dispositivo;
import sintese.Melodia;
import sintese.Som;

/** 
 * Constroi a aplicacao das acoes ocorridas na area grafica
 * garantindo a finalidade do programa
 * @author	Helio Santana
 * @author	Rodrigo Guimaraes
 * @version	1.0
 * @since	16/06/2016
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
	private static String dirBase = "musicas/Wave/";
	static DecimalFormat formatoFloat = new DecimalFormat("0.00");
	/**
	 * Constantes necessarias
	 */
	static final int FORMULA_DE_COMPASSO = 0x58;
	static final int MENSAGEM_TONALIDADE = 0x59;
	static final int MENSAGEM_TEXTO = 0x01;
	private static long duracao = 0;
	private static int  resolucao = 0;
	private static long totaltiques = 0;
	private static float durtique = 0f;
	private static float durseminima = 0f;
	private static float bpm = 0f;
	private static int   totalseminimas = 0;
	private static Par formulaCompasso = null;
	private static String tonalidade = "";
	/**
	 * Itens descartáveis, mas utilizados por muitos
	 */
	private static float razao;
	private static int indiceEscolhido;
	private static int valorMaximo;
	private static int valorCorrente;
	private static String nome;



	/**
	 * Responsavel por armazenar dois valores, como coordenadas
	 * cartesianas no plano
	 * @author Arcela - ICS_UnB
	 *
	 */
	static private class Par{
		int x, y;
	    
	    Par (int x, int y){
	    	this.x = x;
	    	this.y = y;          
	    }
	  
	    int getX (){
	    	return x;
	    }
	    
	    int getY(){
	    	return y;
	    }
	}



	/**
	 * Selecao do arquivo midi externo
	 */
	public static void abrirMelodia (){
		JFileChooser seletorArquivo = new JFileChooser();
		
		seletorArquivo.setCurrentDirectory (new File("."));
		
		seletorArquivo.addChoosableFileFilter(new FiltroMidi());
		seletorArquivo.setAcceptAllFileFilterUsed(true);
		seletorArquivo.setFileFilter(new FiltroMidi());
		
        int returnVal = seletorArquivo.showOpenDialog(null);

        if (returnVal == JFileChooser.APPROVE_OPTION){
        	conversao.ConversorMidiJava.converterArquivo (seletorArquivo.getSelectedFile());
        	
        	adicionarMelodia (seletorArquivo.getSelectedFile());
        	
        	InterfaceGrafica.escolherMelodias.setSelectedIndex(InterfaceGrafica.escolherMelodias.getItemCount() - 1);
        }
	}
	
	/**
	 * Finaliza a aplicacao contruida com seguranca
	 */
	public static void fecharAplicacao (){
		conversao.ConversorMidiJava.registrarMelodias(conversao.ConversorMidiJava.melodiasRegistradasTratadas, false);
		
		conversao.ConversorMidiJava.registrarMelodias(conversao.ConversorMidiJava.melodiasRegistradasAbsolutas, false);
		
		interfaceGrafica.InterfaceGrafica.janelaPrincipal.dispose();
		
		System.gc();
		
		System.out.println("\nATIVIDADES ENCERRADAS!\n");
		
		System.exit(0);
	}
	
	/**
	 * Configuracao das acoes a serem tomadas ao se manipular
	 * o controle de selecao de melodias
	 */
	public static void escolherMelodias (){
		indiceEscolhido = InterfaceGrafica.escolherMelodias.getSelectedIndex();
		nome = (String) InterfaceGrafica.escolherMelodias.getItemAt(indiceEscolhido);
		
		melodiaEscolhida = null;
		
		if (indiceEscolhido == 0)
			System.gc();

		else if (indiceEscolhido < InterfaceGrafica.qntMelodiasIniciais)
			melodiaEscolhida = melodias.Melodias.gerenciadorDefault(nome);
		
		else{
			System.out.println("Abrindo melodia -> " + nome);
			melodiaEscolhida = melodias.BaseadoMidi.gerenciador(nome);
			if (melodiaEscolhida == null){
				System.out.println("não conseguiu abrir");
			}
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
				instrumentoEscolhido = new instrumentos.IN1 ();
				break;
			case 2:
				instrumentoEscolhido = new instrumentos.IN2 ();
				break;
			case 3:
				instrumentoEscolhido = new instrumentos.IN3 ();
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
		if (somFormado != null)
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
		
		nomeSomFormado = dirBase + nomeSomFormado;
	}

	/**
	 * Tocar o som formado
	 */
	public static void tocarSom (){
		salvarSom();
		if (somFormado != null)
			somFormado.tocawave();
	}

	/**
	 * Visualizar o espectro do som formado, sob a interface ja
	 * fornecida, e possibilitar a acao de tocar o som formado
	 */
	public static void visualizarSom (){
		formarSom();
		if (somFormado != null)
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
					((instrumentos.IN1) instrumentoEscolhido).setFatorCorte (razao);
					System.out.println("Fator de corte foi para " + razao);
					break;
				case 2:
					((instrumentos.IN2) instrumentoEscolhido).setFatorCorte (razao);
					System.out.println("Fator de corte foi para " + razao);
					break;
				case 3:
					((instrumentos.IN3) instrumentoEscolhido).setFatorCorte (razao);
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
					((instrumentos.IN1) instrumentoEscolhido).setFatorCorte (razao);
					System.out.println("Fator de corte foi para " + razao);
					break;
				case 2:
					((instrumentos.IN2) instrumentoEscolhido).setFatorCorte (razao);
					System.out.println("Fator de corte foi para " + razao);
					break;
				case 3:
					((instrumentos.IN3) instrumentoEscolhido).setFatorCorte (razao);
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
					((instrumentos.IN1) instrumentoEscolhido).setFase (razao);
					System.out.println("Fase foi para " + razao);
					break;
				case 2:
					((instrumentos.IN2) instrumentoEscolhido).setFase (razao);
					System.out.println("Fase foi para " + razao);
					break;
				case 3:
					((instrumentos.IN3) instrumentoEscolhido).setFase (razao);
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
					((instrumentos.IN1) instrumentoEscolhido).setFase (razao);
					System.out.println("Fase foi para " + razao);
					break;
				case 2:
					((instrumentos.IN2) instrumentoEscolhido).setFase (razao);
					System.out.println("Fase foi para " + razao);
					break;
				case 3:
					((instrumentos.IN3) instrumentoEscolhido).setFase (razao);
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
					((instrumentos.IN1) instrumentoEscolhido).setLambda (razao);
					System.out.println("Esteriofonia na esquerda foi para " + razao);
					break;
				case 2:
					((instrumentos.IN2) instrumentoEscolhido).setLambda (razao);
					System.out.println("Esteriofonia na esquerda foi para " + razao);
					break;
				case 3:
					((instrumentos.IN3) instrumentoEscolhido).setLambda (razao);
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
					((instrumentos.IN1) instrumentoEscolhido).setLambda (razao);
					System.out.println("Esteriofonia na esquerda foi para " + razao);
					break;
				case 2:
					((instrumentos.IN2) instrumentoEscolhido).setLambda (razao);
					System.out.println("Esteriofonia na esquerda foi para " + razao);
					break;
				case 3:
					((instrumentos.IN3) instrumentoEscolhido).setLambda (razao);
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
					((instrumentos.IN1) instrumentoEscolhido).setGanho (razao);
					System.out.println("Foi feito um ganho de " + razao + " no instrumento");
					break;
				case 2:
					((instrumentos.IN2) instrumentoEscolhido).setGanho (razao);
					System.out.println("Foi feito um ganho de " + razao + " no instrumento");
					break;
				case 3:
					((instrumentos.IN3) instrumentoEscolhido).setGanho (razao);
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
	 * Exibicao do conteudo midi numa tabela
	 */
	public static void conteudoMidi (){
		JFrame janelaDados = new JFrame("Conteúdo MIDI");
		janelaDados.setSize(new Dimension(1000, 400));
		janelaDados.setVisible (true);
		janelaDados.setResizable(false);
		janelaDados.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

		String[][] dados = {null}; 
		String cabecalho[] = {"Trilha", "Instante (tiques)",
							  "Instante (seg)", "Código",
							  "Operando 1", "Operando 2",
							  "Mensagem deco."};
		int tamanho[] = {50, 120, 100, 60, 90, 90};
		
		DefaultTableModel modeloTabelaDados = new DefaultTableModel(dados, cabecalho);
		JTable tabelaDados = new JTable(modeloTabelaDados);
		JScrollPane planoRolante = new JScrollPane(tabelaDados);
		
		for (int col = 0; col < tamanho.length; col++){
			tabelaDados.getColumnModel().getColumn(col).setMaxWidth(tamanho[col]);
			tabelaDados.getColumnModel().getColumn(col).setMinWidth(tamanho[col]);
			tabelaDados.getColumnModel().getColumn(col).setPreferredWidth(tamanho[col]);
			tabelaDados.getColumnModel().getColumn(col).setResizable(false);
		}
		
		tabelaDados.getTableHeader().setReorderingAllowed(false);
		
		indiceEscolhido = InterfaceGrafica.escolherMelodias.getSelectedIndex();
		
		if (indiceEscolhido >= InterfaceGrafica.qntMelodiasIniciais){
			nome = (String) InterfaceGrafica.escolherMelodias.getItemAt(indiceEscolhido);
			
			indiceEscolhido = conversao.ConversorMidiJava.melodiasRegistradasTratadas.indexOf(nome);
			nome = conversao.ConversorMidiJava.melodiasRegistradasAbsolutas.get(indiceEscolhido);
			
			System.out.println("pediu o arquivo -> " + nome);
			
			try{
				File arqmidi = new File(nome);
				Sequence sequencia = MidiSystem.getSequence(arqmidi);                            
			            
				inserirDados (modeloTabelaDados, sequencia); 
		
			}catch (InvalidMidiDataException e2){
				System.out.println("Erro2: "+"Erro nos dados midi.");
			}catch (IOException              e3){
				System.out.println("Erro3: "+"O arquivo midi não foi encontrado.");
				System.out.println("Sintaxe: "+"java TocadorMidi arquivo.mid"); 
			}
		
		}else{			
			modeloTabelaDados.insertRow (0, new Object[]{"testando", 0, 0, null, 0, 0, 0});
		}
		
		/*	Desativando a edição da tabela */
		tabelaDados.setEnabled(false);
		/*	Adicionando plano rolante à janela */
		janelaDados.add(planoRolante);
	}

	/**
	 * Exibicao do conteudo musical de um arquivo midi
	 */
	public static void conteudoMusical (){
		JFrame janelaMusical = new JFrame("Conteúdo Musical");
		janelaMusical.setSize(new Dimension(500, 400));
		janelaMusical.setResizable(false);
		janelaMusical.setVisible (true);
		janelaMusical.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		
		JPanel painelMusical = new JPanel();
		painelMusical.setLayout (new BoxLayout(painelMusical, BoxLayout.Y_AXIS));
        painelMusical.setOpaque (true);
        janelaMusical.add(painelMusical);
		
		JTextPane textoMusical = new JTextPane();
		textoMusical.setBackground (new Color(235, 235, 235));
		textoMusical.setBorder(BorderFactory.createEmptyBorder(0,5,10,10));
		textoMusical.setEditable(false);
		textoMusical.setContentType("text/html");
		
		String texto = "";
		
		indiceEscolhido = InterfaceGrafica.escolherMelodias.getSelectedIndex();
		
		if (indiceEscolhido >= InterfaceGrafica.qntMelodiasIniciais){
			nome = (String) InterfaceGrafica.escolherMelodias.getItemAt(indiceEscolhido);
			
			indiceEscolhido = conversao.ConversorMidiJava.melodiasRegistradasTratadas.indexOf(nome);
			nome = conversao.ConversorMidiJava.melodiasRegistradasAbsolutas.get(indiceEscolhido);
			
			try{
				File arqmidi = new File(nome);
				Sequence sequencia = MidiSystem.getSequence(arqmidi);                            
			            
				informacoesMusicais (sequencia);
				
				nome = conversao.ConversorMidiJava.tratarNome(nome);
				
				texto =	"<html>"
						+ "<br /> <font size=5> <b>" + nome + ": </b> </font> <br />"
						+ "<b>Armadura de Tonalidade: </b> <br />"
						+ "<font size=3>" + tonalidade + "</font>"
						+ "<br /><b>Fórmula de Compasso: </b><br />"
						+ "<font size=3>" + formulaCompasso.getX() + "/" + (int)(Math.pow(2, formulaCompasso.getY())) + "</font>"
						+ "<br /><b>Duração: </b><br />"
						+ "<font size=3>" + duracao + " s</font>"
						+ "<br /><b>Metro: </b><br />"
						+ "<font size=3>" + durseminima + " s</font>"
						+ "<br /><b>Quantidade de Seminimas: </b><br />"
						+ "<font size=3>" + totalseminimas + " uni</font>"
						+ "<br /><b>Andamento: </b><br />"
						+ "<font size=3>" + Math.round(bpm) + " bpm</font>"
						+ "<br /><b>Total de Tiques: </b><br />"
						+ "<font size=3>" + totaltiques + "</font>"
						+ "<br /><b>Duração de um Tique: </b><br />"
						+ "<font size=3>" + durtique + " s</font>"
						+ "<br /><b>Resolução: </b><br />"
						+ "<font size=3>" + resolucao + " tiques</font>"
						+ "<br /><br />"
						+ "</html>";
		
			}catch (InvalidMidiDataException e2){
				System.out.println("Erro2: "+"Erro nos dados midi.");
			}catch (IOException              e3){
				System.out.println("Erro3: "+"O arquivo midi não foi encontrado.");
				System.out.println("Sintaxe: "+"java TocadorMidi arquivo.mid"); 
			}
		
		}else{
			texto = "<html>"
					+ "<br /> Não foi possível a aquisição dos dados<br />"
					+ "</html>";
		}
		
		textoMusical.setText(texto);
		
		painelMusical.add(textoMusical);
		
	}
	
	/**
	 * Exibicao da classe Java extraida do arquivo midi
	 */
	public static void conteudoJava (){
		JFrame janelaJava = new JFrame("Conteúdo Java");
		janelaJava.setSize(new Dimension(InterfaceGrafica.comprimentoMaximo, 500));
		janelaJava.setVisible (true);
		janelaJava.setResizable(false);
		janelaJava.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		
		JPanel painelJava = new JPanel();
		painelJava.setLayout (new BoxLayout(painelJava, BoxLayout.Y_AXIS));
		painelJava.setBorder (BorderFactory.createTitledBorder("melodia.BaseadoMidi: "));
		painelJava.setOpaque (true);
		janelaJava.add(painelJava);
		
		JTextArea areaDocumento = new JTextArea();
		areaDocumento.setEditable(false);
		String documento = "";
		try {
		      FileReader arq = new FileReader(conversao.ConversorMidiJava.nomeClasseCriada);
		      
		      if (arq != null){
			      BufferedReader lerArq = new BufferedReader(arq);
			 
			      String linha = ""; 
			      
			      do{
			    	  linha = lerArq.readLine();
			    	  
			    	  if (linha != null)	documento += linha + "\n";
			    	  else 					break;
			    	  
			      }while (true);
			 
			      arq.close();
		      }
		      
	    } catch (IOException e) {
	        System.err.printf("Erro na abertura do arquivo: %s.\n", e.getMessage());
	    }
		
		areaDocumento.setText(documento);
		JScrollPane planoRolante = new JScrollPane(areaDocumento);
		
		painelJava.add(planoRolante);
	}
	
	/**
	 * Exibicao das informacoes gerais sobre a aplicacao construida
	 */
	public static void sobreAplicacao (){
		JFrame sobre = new JFrame("Sobre");
		sobre.setSize(new Dimension(500, 280));
		sobre.setResizable(false);
		sobre.setVisible (true);
		sobre.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		
		JTextPane textoSobre = new JTextPane();
		textoSobre.setBackground (new Color(235, 235, 235));
		textoSobre.setBorder(BorderFactory.createEmptyBorder(10,10,10,10));
		textoSobre.setEditable(false);
		textoSobre.setContentType("text/html");
		
		String texto = "<html>"
						+ "<b> Conversor Midi-Java</b><br /><br />"
						+ "<b> Desenvolvido por: </b><br />"
						+ "<i>Hélio Santana e Rodrigo Guimar\u00e3es</i><br /><br />"
						+ "<b> Finalidade: </b><br />"
						+ "Conversão de arquivos midi, principalmente a melodia desrita, "
						+ "para uma classe Java, de forma automática e direta, possibilitando: "
						+ "aplicações normais como nas melodias do pacote sintese fornecido; "
						+ "exibição do conteúdo midi do arquivo original; "
						+ "exibição das informações musicais e "
						+ "a exibição do documento criado pela conversão.<br />"
						+ "<b> Linguagem adotada: </b><br />"
						+ "A aplicaç\u00e3o foi desenvolvida em linguagem JAVA, tendo a GUI "
						+ "implementada por intermédio da SWING.<br /><br />"
						+ "</html>";
		
		textoSobre.setText(texto);

		sobre.add(textoSobre);
	}
	
	

	/**
	 * Adicao da melodia extraida do arquivo midi no escopo da execucao
	 * @param arq Arquivo midi
	 */
	public static void adicionarMelodia (File arq){
		nome = conversao.ConversorMidiJava.tratarNomeArqMidi (arq.getName(), false);
		
		if (InterfaceGrafica.melodiasDisponiveis.indexOf(nome) == -1){
			
			InterfaceGrafica.melodiasDisponiveis.add(nome);
			InterfaceGrafica.escolherMelodias.addItem(nome);
			
			conversao.ConversorMidiJava.melodiasRegistradasAbsolutas.add(arq.getAbsolutePath());
			
			conversao.ConversorMidiJava.registrarMelodias(conversao.ConversorMidiJava.melodiasRegistradasAbsolutas, true);
		}
	}
	
	/**
	 * Adicao da melodia extraida do arquivo midi no escopo da execucao
	 * @param nome Nome da melodia
	 */
	public static void adicionarMelodia (String nome){
		if (InterfaceGrafica.melodiasDisponiveis.indexOf(nome) == -1){
			
			InterfaceGrafica.melodiasDisponiveis.add(nome);
			InterfaceGrafica.escolherMelodias.addItem(nome);
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
		
		System.out.println("Melodia atual ->" + melodiaEscolhida);
		System.out.println("Intrumento atual ->" + instrumentoEscolhido);
		if (melodiaEscolhida != null & instrumentoEscolhido != null){
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
					razao = ((instrumentos.IN1) instrumentoEscolhido).getFatorCorte ();
					InterfaceGrafica.controleFatordeCorte.setValue((int)(razao * valorMaximo));
					
					valorMaximo = InterfaceGrafica.controleFase.getMaximum();
					razao = ((instrumentos.IN1) instrumentoEscolhido).getFase();
					InterfaceGrafica.controleFase.setValue((int)(razao * valorMaximo));
					
					valorMaximo = InterfaceGrafica.controleLambda.getMaximum();
					razao = ((instrumentos.IN1) instrumentoEscolhido).getLambda();
					InterfaceGrafica.controleLambda.setValue((int)(razao * valorMaximo));
					
					editando = true;
					razao = ((instrumentos.IN1) instrumentoEscolhido).getGanho();
					InterfaceGrafica.valorGanhoInst.setText("" + razao);
					editando = false;
					break;
				case 2:
					valorMaximo = InterfaceGrafica.controleFatordeCorte.getMaximum();
					razao = ((instrumentos.IN2) instrumentoEscolhido).getFatorCorte ();
					InterfaceGrafica.controleFatordeCorte.setValue((int)(razao * valorMaximo));
					
					valorMaximo = InterfaceGrafica.controleFase.getMaximum();
					razao = ((instrumentos.IN2) instrumentoEscolhido).getFase();
					InterfaceGrafica.controleFase.setValue((int)(razao * valorMaximo));
					
					valorMaximo = InterfaceGrafica.controleLambda.getMaximum();
					razao = ((instrumentos.IN2) instrumentoEscolhido).getLambda();
					InterfaceGrafica.controleLambda.setValue((int)(razao * valorMaximo));
					
					editando = true;
					razao = ((instrumentos.IN2) instrumentoEscolhido).getGanho();
					InterfaceGrafica.valorGanhoInst.setText("" + razao);
					editando = false;
					break;
				case 3:
					valorMaximo = InterfaceGrafica.controleFatordeCorte.getMaximum();
					razao = ((instrumentos.IN3) instrumentoEscolhido).getFatorCorte ();
					InterfaceGrafica.controleFatordeCorte.setValue((int)(razao * valorMaximo));
					
					valorMaximo = InterfaceGrafica.controleFase.getMaximum();
					razao = ((instrumentos.IN3) instrumentoEscolhido).getFase();
					InterfaceGrafica.controleFase.setValue((int)(razao * valorMaximo));
					
					valorMaximo = InterfaceGrafica.controleLambda.getMaximum();
					razao = ((instrumentos.IN3) instrumentoEscolhido).getLambda();
					InterfaceGrafica.controleLambda.setValue((int)(razao * valorMaximo));
					
					editando = true;
					razao = ((instrumentos.IN3) instrumentoEscolhido).getGanho();
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
			if (instrumentoEscolhido.getClass().equals(instrumentos.IN1.class))
				return 1;
			else if (instrumentoEscolhido.getClass().equals(instrumentos.IN2.class))
				return 2;
			else if (instrumentoEscolhido.getClass().equals(instrumentos.IN3.class))
				return 3;
			else
				return 4;
		}
		return 0;
	}

	/**
	 * Insercao dos dados de um arquivo midi e os escrevem na tabela
	 * @param tabela
	 * @param sequencia
	 */
	private static void inserirDados (DefaultTableModel tabela, Sequence sequencia){
		Track[] trilhas = sequencia.getTracks();
		
		for (int i = 0; i < trilhas.length; i++){
			Track trilha =  trilhas[i];
			
			for(int j = 0; j < trilha.size(); j++){
				MidiEvent   e          = trilha.get(j);
				MidiMessage mensagem   = e.getMessage();
				long        tique      = e.getTick();
		
				int n = mensagem.getStatus();
				byte[] dados = mensagem.getMessage();
				String nomecomando = "" + n;
		
				if ((128 <= n) & (n <= 143))
					nomecomando = montaNomeComando ("Note OFF", n, 128, dados);
				else if ((144 <= n) & (n <= 159))
					nomecomando = montaNomeComando ("Note ON", n, 144, dados);
				else if ((176 <= n) & (n <= 191))
					nomecomando = montaNomeComando ("Control Change", n, 176, dados);
				else if ((192 <= n) & (n <= 207))
					nomecomando = montaNomeComando ("Program Change", n, 192, dados);
				else if ((224 <= n) & (n <= 239))
					nomecomando = montaNomeComando ("Pitch Bend", n, 224, dados);
				else if ((240 <= n) & (n <= 255))
					nomecomando = "Mensagem Meta";
				
				switch (mensagem.getLength()) {
					case 2:
						tabela.addRow(new Object[]{	i, tique, formatoFloat.format((tique * durtique)),
								n, dados[1], null, nomecomando});
						break;
					case 3:
						tabela.addRow(new Object[]{	i, tique, formatoFloat.format((tique * durtique)),
								n, dados[1], dados[2], nomecomando});
						break;
				}
			}
			tabela.addRow(new Object[]{null, null, null, null, null, null, null, null,});
		}
	}

	/**
	 * Extracao das informacoes musicais de um arquivo midi
	 * @param sequencia Sequencia do arquivo midi
	 */
	private static void informacoesMusicais (Sequence sequencia) {
		duracao     = sequencia.getMicrosecondLength() / 1000000;
		resolucao   = sequencia.getResolution();
		totaltiques = sequencia.getTickLength();
	
		durtique       = (float)duracao/totaltiques;
		durseminima    = durtique * resolucao;
		bpm            = 60/durseminima;
		totalseminimas = (int)(duracao/durseminima);
		
		Track[] trilhas = sequencia.getTracks();
		
		formulaCompasso = getFormulaDeCompasso(trilhas[1]);
		
		try {
			tonalidade = getTonalidade(trilhas[1]);
		} catch (InvalidMidiDataException e1) {
			e1.printStackTrace();
		}
		
		if (tonalidade.length() == 0)
			tonalidade = "não possível determinar";
		
	}	

	/**
	 * Formula de compasso atribuida a uma trilha
	 * @param trilha Trilha base para a busca
	 * @return Formula de compasso especifica
	 */
	static Par getFormulaDeCompasso (Track trilha){
		int p = 1;
		int q = 1;
	
		for(int i = 0; i < trilha.size(); i++){
			MidiMessage m = trilha.get(i).getMessage();
	        
			if(m instanceof MetaMessage){
				if(((MetaMessage)m).getType() == FORMULA_DE_COMPASSO){
					MetaMessage mm = (MetaMessage)m;
					byte[] data = mm.getData();
					p = data[0];
					q = data[1];
					return new Par(p,q);
	          	}
			}
		}
		
		return new Par(p, q);
	}

	/**
	 * Tonalidade atribuida a uma trilha
	 * @param trilha Trilha base para a busca
	 * @return Tonalidade especificada a trilha
	 * @throws InvalidMidiDataException
	 */
	static String getTonalidade (Track trilha) throws InvalidMidiDataException{       
		String stonalidade = "";
	
		for (int i = 0; i < trilha.size(); i++){
			MidiMessage m = trilha.get(i).getMessage();
	
			if (m.getClass().equals(MetaMessage.class)){
				if (((MetaMessage) m).getType() == MENSAGEM_TONALIDADE){
					MetaMessage mm        = (MetaMessage) m;
					byte[]     data       = mm.getData();
					byte       tonalidade = data[0];
					byte       maior      = data[1];
		
					String          smaior = "Maior";
					if (maior == 1) smaior = "Menor";
		
					if (smaior.equalsIgnoreCase("Maior")){
						switch (tonalidade){
							case -7: stonalidade = "Dób Maior"; break;
							case -6: stonalidade = "Solb Maior"; break;
							case -5: stonalidade = "Réb Maior"; break;
							case -4: stonalidade = "Láb Maior"; break;
							case -3: stonalidade = "Mib Maior"; break;
							case -2: stonalidade = "Sib Maior"; break;
							case -1: stonalidade = "Fá Maior"; break;
							case  0: stonalidade = "Dó Maior"; break;
							case  1: stonalidade = "Sol Maior"; break;
							case  2: stonalidade = "Ré Maior"; break;
							case  3: stonalidade = "Lá Maior"; break;
							case  4: stonalidade = "Mi Maior"; break;
							case  5: stonalidade = "Si Maior"; break;
							case  6: stonalidade = "Fá# Maior"; break;
							case  7: stonalidade = "Dó# Maior"; break;
						}
					
					}else if (smaior.equalsIgnoreCase("Menor")){
						switch (tonalidade){
							case -7: stonalidade = "Láb Menor"; break;
							case -6: stonalidade = "Mib Menor"; break;
							case -5: stonalidade = "Sib Menor"; break;
							case -4: stonalidade = "Fá Menor"; break;
							case -3: stonalidade = "Dó Menor"; break;
							case -2: stonalidade = "Sol Menor"; break;
							case -1: stonalidade = "Ré Menor"; break;
							case  0: stonalidade = "Lá Menor"; break;
							case  1: stonalidade = "Mi Menor"; break;
							case  2: stonalidade = "Si Menor"; break;
							case  3: stonalidade = "Fá# Menor"; break;
							case  4: stonalidade = "Dó# Menor"; break;
							case  5: stonalidade = "Sol# Menor"; break;
							case  6: stonalidade = "Ré# Menor"; break;
							case  7: stonalidade = "Lá# Menor"; break;
						}
					}
				}
			}
		}
	    
		return stonalidade;
	}

	/**
	 * Texto atribuido a uma trilha
	 * @param trilha Trilha que se buscara o texto
	 * @return Texto espeficidado para a trilha
	 * @throws InvalidMidiDataException
	 */
	static String getTexto (Track trilha) throws InvalidMidiDataException{       
		String stexto = "";
	
		for(int i = 0; i < trilha.size(); i++){
			MidiMessage m = trilha.get(i).getMessage();
	            
			if (((MetaMessage)m).getType() == MENSAGEM_TEXTO){                
				MetaMessage mm  = (MetaMessage) m;
				byte[]     data = mm.getData();
	
				for (int j = 0; j < data.length; j++)
					stexto += (char) data[j];
			}
		}
	
		return stexto;
	}

	/**
	 * Construcao da identificacao do comando do arquivo midi
	 * @param base Identificacao previa do comando
	 * @param n Identificador bruto do comando
	 * @param minimo Menor indicador do comando
	 * @param dados Dados especificados para o comando
	 * @return Comando decodificado
	 */
	private static String montaNomeComando (String base, int n, int minimo, byte[] dados){
		String retorno = base + ", no canal " + (n - minimo) + ", ";
		
		if (base.equals("Note OFF")){
			float freq = (float)(conversao.NotasMidi.f_0 * Math.pow(2, (double)dados[1]/12));
			retorno += "na nota " + formatoFloat.format(freq) + " com decaimento de " + dados[2];

		}else if (base.equals("Note ON")){
			float freq = (float)(conversao.NotasMidi.f_0 * Math.pow(2, (double)dados[1]/12));
			retorno += "na nota " + formatoFloat.format(freq) + " com intensidade " + dados[2];

		}else if (base.equals("Program Change")){
			retorno += "mudando para o instrumento" + dados[1];

		}else if (base.equals("Control Change")){
			if ((dados[1] >= 120) & (dados[1] <= 127))
				retorno += "reservado para o channel mod";

			else{
				retorno += "alterando ";
				
				switch (dados[1]){
					case 0:
						retorno += "o banco de instrumento";
						break;
					case 7:
						retorno += "o volume";
						break;
					case 10:
						retorno += "a estereofonia";
						break;
					case 65:
						retorno += "o portamento On/Off";
						break;
					case 72:
						retorno += "o release time";
						break;
					case 73:
						retorno += "o attack time";
						break;
					case 74:
						retorno += "o brilho";
						break;
				}
			}
			retorno += " para o valor de controle " + dados[2];
		}
		
		return retorno;
	}
}