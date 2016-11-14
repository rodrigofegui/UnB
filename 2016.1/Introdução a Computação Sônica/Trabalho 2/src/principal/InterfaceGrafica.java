/*	Pacote ao qual pertence */
package principal;

import java.awt.Color;

/*	Importando Classes necessárias */

import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.FocusEvent;
import java.awt.event.FocusListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.Hashtable;

import javax.swing.BorderFactory;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JSlider;
import javax.swing.JTextField;
import javax.swing.border.Border;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;


/** 
 * Gerencia a interface grafica da aplicacao, gerenciando todas as classes necessarias,
 * tendo como resultado a
 * <a href="https://www.dropbox.com/s/o8mvqmh5d8q8vgc/Interface_T2.png?dl=0"> imagem</a><br>
 * @author	Helio Santana
 * @author	Rodrigo Guimaraes
 * @version	1.0
 * @since	02/06/2016
 */
public class InterfaceGrafica implements	ActionListener, ChangeListener, ItemListener,
											DocumentListener, MouseListener, FocusListener {
	/**
	 * Janela que sera abrigada a GUI criada, nas dimensões definidas
	 */
	static JFrame		janelaPrincipal		= null;
	static final int	comprimentoMaximo	= 670;
	static final int	alturaMaxima		= 320;
	/**
	 * Contem todos os paineis formados
	 */
	public JPanel painelPrincipal		= null;
	/**
	 * Abriga os paineis "Abrir" e "Som"
	 */
	public JPanel painelGrupoEsquerda	= null;
	/**
	 * Controla as melodias e os instrumentos que serao utilizados
	 */
	public JPanel painelAbrir			= null;
	/**
	 * Abriga as configuracoes basicas sobre a melodia e sobre os instrumentos
	 */
	public JPanel painelConfiguracoes	= null;
	/**
	 * Abriga os 3 aspectos basicos sobre o som: salvar, ouvir e visualizar o
	 * espectro
	 */
	public JPanel painelSons			= null;
	/**
	 * Opcoes do painel "Abrir"
	 */
	static JComboBox<Object> escolherMelodias		= null;
	static JComboBox<Object> escolherInstrumentos	= null;
	/**
	 * Opcoes do painel "Configurar/Melodias"
	 */
	static JSlider		controleAndamento		= null;
	static JTextField	valorAndamento			= null;
	static JSlider		controleTransposicao	= null;
	static JTextField	valorTransposicao		= null;
	static JCheckBox	controleInverterMel		= null;
	/**
	 * Opcoes do painel "Configurar/Instrumentos"
	 */
	static JSlider		controleFatordeCorte	= null;
	static JTextField	valorFatordeCorte		= null;
	static JSlider		controleFase			= null;
	static JTextField	valorFase				= null;
	static JSlider		controleLambda			= null;
	static JTextField	valorLambda				= null;
	static JTextField	valorGanhoInst			= null;
	/**
	 * Opcoes do painel "Som"
	 */
	static JCheckBox	controleSalvar	= null;
	static JTextField	nomeWave		= null;
	static JButton		salvarSom		= null;
	static JButton		visualizarSom	= null;
	static JButton		tocarSom		= null;
	static JButton		pararSom		= null;
	/**
	 * Itens descartáveis, mas utilizados por muitos
	 */
	private JPanel painelAvulso;
	private JButton botaoAvulso;
	private Dimension padrao;

	
	
	/**
	 * Criacao da interface grafica
	 */
	public InterfaceGrafica (){
		new FormatacaoPadrao();
		
		
		janelaPrincipal = new JFrame("Trabalho 2 - H\u0026R");
		
		janelaPrincipal.setContentPane (this.getPainelPrincipal());
		
		janelaPrincipal.setSize (new Dimension (comprimentoMaximo, alturaMaxima));
		
		janelaPrincipal.setResizable (false);
		
		janelaPrincipal.setVisible (true);
		
		janelaPrincipal.setDefaultCloseOperation (JFrame.EXIT_ON_CLOSE);
		
		/*
		janelaPrincipal.setResizable (true);
		for (int i = 0; ;i++)
			System.out.println("" + janelaPrincipal.getSize());
		//*/
	}

	/**
	 * Configuracao da area grafica
	 * @return Area grafica ja criada
	 */
	public JPanel getPainelPrincipal () {
		prepararPainelPrincipal ();
		
		constroiGrupoEsquerda();
		
		painelPrincipal.add(painelGrupoEsquerda);
		
		constroiConfiguracoes ();
		
		painelPrincipal.add(painelConfiguracoes);
		
		return painelPrincipal;
	}

	/**
	 * Configuracao inicial do painel para receber os recursos
	 */
	private void prepararPainelPrincipal (){
		painelPrincipal = new JPanel ();
		
		//painelPrincipal.setLayout (new GridLayout(1, 2));
		//painelPrincipal.setLayout (new BoxLayout(painelPrincipal, BoxLayout.Y_AXIS));
		painelPrincipal.setLayout (new BoxLayout(painelPrincipal, BoxLayout.X_AXIS));
		
		painelPrincipal.setOpaque (true);
        
        Border caixaPrincipal = BorderFactory.createEmptyBorder (10, 10, 10, 10);
        painelPrincipal.setBorder (caixaPrincipal);
	}
	
	/**
	 * Configuracao inicial do painel "Abrir"
	 */
	private void prepararPainelAbrir (){
		padrao = new Dimension (comprimentoMaximo + 50, 105);
		
		painelAbrir = new JPanel ();
		
		painelAbrir.setLayout (new GridLayout(2, 1, 1, 2));
		
		painelAbrir.setBorder (BorderFactory.createTitledBorder("Abrir: "));
		
		painelAbrir.setMaximumSize (padrao);
		painelAbrir.setMinimumSize (padrao);
		painelAbrir.setPreferredSize (padrao);
	}
	
	/**
	 * Configuracao inicial do painel "Configurar"
	 */
	private void prepararPainelConfigurar (){
		padrao = new Dimension (400, alturaMaxima);
		
		painelConfiguracoes = new JPanel ();
		
		painelConfiguracoes.setLayout (new GridLayout (1, 2, 1, 1));
		
		painelConfiguracoes.setBorder (BorderFactory.createTitledBorder ("Configurar: "));
		
		painelConfiguracoes.setMaximumSize (padrao);
		painelConfiguracoes.setMinimumSize (padrao);
		painelConfiguracoes.setPreferredSize (padrao);
	}
	
	/**
	 * Configuracao inicial do painel "Som"
	 */
	private void prepararPainelSons (){
		painelSons = new JPanel ();
		
		painelSons.setLayout (new GridLayout (5, 1, 1, 1));
		
		painelSons.setBorder (BorderFactory.createTitledBorder ("Som: "));
	}
	
	/**
	 * Configuracao inicial do painel que abrigara os paineis:
	 * "Abrir" e "Som"
	 */
	private void prepararPainelGrupoEsquerda  (){
		painelGrupoEsquerda = new JPanel ();
		padrao = new Dimension(250, alturaMaxima);
		
		painelGrupoEsquerda.setLayout (new GridLayout(2, 1));
        
		painelGrupoEsquerda.setMaximumSize(padrao);
		painelGrupoEsquerda.setMinimumSize(padrao);
		painelGrupoEsquerda.setPreferredSize(padrao);
		
		painelGrupoEsquerda.setOpaque (true);
        
        Border caixaPrincipal = BorderFactory.createEmptyBorder (5, 5, 5, 5);
        painelGrupoEsquerda.setBorder (caixaPrincipal);
	}
	
	/**
	 * Construcao do painel que abriga os componentes de 
	 * "Abrir" e "Salvar"
	 */
	private void constroiGrupoEsquerda () {
		prepararPainelGrupoEsquerda ();
		
		constroiAbrir ();
		
		painelGrupoEsquerda.add(painelAbrir);
		
		constroiSons ();
		
		painelGrupoEsquerda.add(painelSons);
	}
	
	/**
	 * Construcao do ambiente "Abrir"	
	 */
	private void constroiAbrir () {
		prepararPainelAbrir ();
		
		constroiAbMelodias();
		
		constroiAbIntrumentos();
	}
	
	/**
	 * Construcao do ambiente "Configuracoes"	
	 */
	private void constroiConfiguracoes () {
		prepararPainelConfigurar ();
		
		constroiConfMelodias ();
						
		constroiConfInstrumentos ();
	}
	
	/**
	 * Construcao do ambiente "Som"	
	 */
	private void constroiSons () {
		prepararPainelSons ();
		
		painelAvulso = new JPanel ();
		painelAvulso.setLayout(new BoxLayout(painelAvulso, BoxLayout.X_AXIS));
		
		botaoAvulso = criarIdentificacao("Salvar:", true);
		controleSalvar = criarCheckBox();
		controleSalvar.setToolTipText("Salvar do áudio gerado, no diretório atual");
		botaoAvulso.setToolTipText("Salvar do áudio gerado, no diretório atual");
		painelAvulso.add (botaoAvulso);
		painelAvulso.add (controleSalvar);
		painelSons.add(painelAvulso);
		
		nomeWave = criarTextField ("nomeWave", "nome do arquivo", false);
		nomeWave.setForeground(new Color (128, 128, 128));
		nomeWave.getDocument().addDocumentListener(this);
		nomeWave.getDocument().putProperty("owner", nomeWave);
		nomeWave.addFocusListener(this);
		nomeWave.setVisible(false);
		painelSons.add(nomeWave);
		
		salvarSom = criarBotao("salvar", "Salvar");
		salvarSom.setToolTipText("Efetuar registro do áudio em HD");
		painelSons.add(salvarSom);
		
		painelAvulso = new JPanel ();
		painelAvulso.setLayout(new BoxLayout(painelAvulso, BoxLayout.X_AXIS));
		tocarSom = criarBotao("tocar", "Tocar musica inteira");
		tocarSom.setToolTipText("Tocar o som formado, limitado: sem pausa");
		painelSons.add(tocarSom);
		
		visualizarSom = criarBotao("visualizar", "Visualizar");
		visualizarSom.setToolTipText("Visualizar espectro formado");
		painelSons.add(visualizarSom);		
	}
	
	/**
	 * Construcao das opcoes de melodias, no painel "Abrir"
	 */
	private void constroiAbMelodias (){
			painelAvulso = new JPanel ();
			painelAvulso.setLayout(new GridLayout(2, 1));
						
			botaoAvulso = criarIdentificacao("Melodias:", false);
			botaoAvulso.setToolTipText("Melodias disponíveis");
			painelAvulso.add(botaoAvulso);
			
			String melodias[] = {"", "Frozen", "Game of Thrones", "The Rains of Castamere",
								"Melodia Sexta1", "Sonata de Scarlatti", "Drawing Quintet Flauta",
								"Fuga 01, Arcela", "BWV 775, Invenção no. 14 dir.", "BWV 775, Invenção no. 4 esq.",
								"BWV 988, variação goldberg_v03", "Duda no Frevo"};
			
			escolherMelodias = new JComboBox<Object>(melodias);
			escolherMelodias.setToolTipText("Melodias disponíveis");
			
			escolherMelodias.setActionCommand("escolheMel");
			escolherMelodias.addActionListener(this);
			
			painelAvulso.add(escolherMelodias);
			painelAbrir.add(painelAvulso);
	}
	
	/**
	 * Construcao das opcoes de instrumentos, no painel "Abrir"
	 */
	private void constroiAbIntrumentos (){
		painelAvulso = new JPanel ();
		painelAvulso.setLayout(new GridLayout(2, 1));
		
		botaoAvulso= criarIdentificacao("Instrumentos:", false);
		botaoAvulso.setToolTipText("Intrumentos disponíveis");
		painelAvulso.add(botaoAvulso);
		
		String instrumentos[] = {"", "H&R 1", "H&R 2", "H&R 3",
								"Flauta não Harmonica", "Gongo Arcela 1994",
								"Marimba_i51", "Som puro", "Timbre quase Tonal",
								"Timbre Ortogonal", "Trombone não Harmonico", "Trompete"};
		
		escolherInstrumentos = new JComboBox<Object>(instrumentos);
		escolherInstrumentos.setToolTipText("Intrumentos disponíveis");
		
		escolherInstrumentos.setActionCommand("escolheInst");
		escolherInstrumentos.addActionListener(this);
		
		painelAvulso.add(escolherInstrumentos);
		painelAbrir.add(painelAvulso);
	}
	
	/**
	 * Construcao das opcoes de melodias, no painel "Configurar"
	 */
	private void constroiConfMelodias () {
		JPanel painelMelodias = new JPanel (new GridLayout(6, 1));
		painelMelodias.setSize(new Dimension (comprimentoMaximo - 30, 80));
		painelMelodias.setBorder(BorderFactory.createTitledBorder("  Melodias: "));

		
		painelAvulso = new JPanel ();
		painelAvulso.setLayout(new BoxLayout(painelAvulso, BoxLayout.X_AXIS));
		botaoAvulso = criarIdentificacao ("Andamento:", true);
		controleAndamento = criarSlider("Andamento", 0, 500, 100, true);
		valorAndamento = criarTextField (controleAndamento, "andamentoMelodia", true);
		valorAndamento.getDocument().putProperty ("owner", valorAndamento);
		valorAndamento.setToolTipText ("O quão rápido a música deve ir, em relação ao default da melodia");
		botaoAvulso.setToolTipText ("O quão rápido a música deve ir, em relação ao default da melodia");
		controleAndamento.setToolTipText ("O quão rápido a música deve ir, em relação ao default da melodia");
		painelAvulso.add (botaoAvulso);
		painelAvulso.add (valorAndamento);
		painelMelodias.add (painelAvulso);
		painelMelodias.add (controleAndamento);
		
		
		painelAvulso = new JPanel ();
		painelAvulso.setLayout(new BoxLayout(painelAvulso, BoxLayout.X_AXIS));
		botaoAvulso = criarIdentificacao ("Transposição:", true);
		controleTransposicao = criarSlider("Transposição", 0, 200, 100, true); 
		valorTransposicao = criarTextField (controleTransposicao, "transposicaoMelodia", true);
		valorTransposicao.getDocument().putProperty ("owner", valorTransposicao);
		valorTransposicao.setToolTipText("Controle do tom da melodia, de oitava abaixo a uma oitava acima");
		controleTransposicao.setToolTipText("Controle do tom da melodia, de oitava abaixo a uma oitava acima");
		botaoAvulso.setToolTipText ("Controle do tom da melodia, de oitava abaixo a uma oitava acima");
		painelAvulso.add (botaoAvulso);
		painelAvulso.add (valorTransposicao);
		painelMelodias.add (painelAvulso);
		painelMelodias.add(controleTransposicao);
		
		
		painelAvulso = new JPanel ();
		painelAvulso.setLayout(new BoxLayout(painelAvulso, BoxLayout.X_AXIS));
		botaoAvulso = criarIdentificacao("Inverter:", true);
		controleInverterMel = criarCheckBox();
		controleInverterMel.setToolTipText("Inversão melódica");
		botaoAvulso.setToolTipText("Inversão melódica");
		painelAvulso.add (botaoAvulso);
		painelAvulso.add (controleInverterMel);
		painelMelodias.add(painelAvulso);
		
		painelConfiguracoes.add(painelMelodias);
	}
	
	/**
	 * Construcao das opcoes de instrumentos, no painel "Configurar"
	 */
	private void constroiConfInstrumentos () {
		JPanel painelInstrumentos = new JPanel (new GridLayout(7, 1));
		painelInstrumentos.setSize(new Dimension (comprimentoMaximo - 30, 80));
		painelInstrumentos.setBorder(BorderFactory.createTitledBorder("  Instrumentos: "));

		
		painelAvulso = new JPanel ();
		painelAvulso.setLayout(new BoxLayout(painelAvulso, BoxLayout.X_AXIS));
		botaoAvulso = criarIdentificacao("Fator de Corte:", true);
		controleFatordeCorte = criarSlider("Fator de Corte", 0, 10000, 10000, true);
		valorFatordeCorte = criarTextField (controleFatordeCorte, "fatorcorteInstrumento", true);
		valorFatordeCorte.getDocument().putProperty("owner", valorFatordeCorte);
		valorFatordeCorte.setToolTipText("Largura de banda do filtro passa-baixa");
		controleFatordeCorte.setToolTipText("Largura de banda do filtro passa-baixa");
		botaoAvulso.setToolTipText("Largura de banda do filtro passa-baixa");
		painelAvulso.add (botaoAvulso);
		painelAvulso.add(valorFatordeCorte);
		painelInstrumentos.add(painelAvulso);
		painelInstrumentos.add(controleFatordeCorte);
		
		
		painelAvulso = new JPanel ();
		painelAvulso.setLayout (new BoxLayout(painelAvulso, BoxLayout.X_AXIS));
		botaoAvulso = criarIdentificacao ("Fase:", true);
		controleFase = criarSlider("Fase", 0, 360, 0, false);
		valorFase = criarTextField (controleFase, "faseInstrumento", true);
		valorFase.getDocument().putProperty ("owner", valorFase);
		valorFase.setToolTipText ("Ângulo de fase, inteiro");
		controleFase.setToolTipText ("Ângulo de fase, inteiro");
		botaoAvulso.setToolTipText ("Ângulo de fase, inteiro");
		painelAvulso.add (botaoAvulso);
		painelAvulso.add (valorFase);
		painelInstrumentos.add (painelAvulso);
		painelInstrumentos.add (controleFase);
		
		
		
		painelAvulso = new JPanel ();
		painelAvulso.setLayout (new BoxLayout(painelAvulso, BoxLayout.X_AXIS));
		botaoAvulso = criarIdentificacao ("Esteriofonia:", true);
		controleLambda = criarSlider("Esteriofonia", 0, 100, 50, true);
		valorLambda = criarTextField (controleLambda, "lambdaInstrumento", true);
		valorLambda.getDocument().putProperty ("owner", valorLambda);
		valorLambda.setToolTipText ("Medida da saida de áudio no canal esquerdo, no direito é o complementar");
		controleLambda.setToolTipText ("Medida da saida de áudio no canal esquerdo, no direito é o complementar");
		botaoAvulso.setToolTipText ("Medida da saida de áudio no canal esquerdo, no direito é o complementar");
		painelAvulso.add (botaoAvulso);
		painelAvulso.add (valorLambda);
		painelInstrumentos.add (painelAvulso);
		painelInstrumentos.add (controleLambda);
		

		
		painelAvulso = new JPanel ();
		painelAvulso.setLayout(new BoxLayout(painelAvulso, BoxLayout.X_AXIS));
		botaoAvulso = criarIdentificacao("Ganho:", true);
		valorGanhoInst = criarTextField ("ganhoInstrumento", "1.0", true);
		valorGanhoInst.getDocument().putProperty("owner", valorGanhoInst);
		valorGanhoInst.setToolTipText("Controle grosso do volume, quanto maior o valor maior o volume");
		botaoAvulso.setToolTipText("Controle grosso do volume, quanto maior o valor maior o volume");
		painelAvulso.add (botaoAvulso);
		painelAvulso.add(valorGanhoInst);
		painelInstrumentos.add(painelAvulso);
		
		painelConfiguracoes.add(painelInstrumentos);
	}
	
	
	
	/**
	 * Criacao de um botao padrao
	 * @param descricao Identificacao do botao no tratamento de acoes
	 * @param texto		Texto a ser posto como inicial
	 * @return			Botao ja criado
	 */
	public JButton criarBotao (String descricao, String texto){
		JButton novo = new JButton();
		
		novo.setText(texto);
		
		novo.setEnabled(false);
		
		novo.setActionCommand(descricao);
		novo.addActionListener(this);
		
		return novo;
	}
	
	/**
	 * Criacao botoes especiais para a identificacao, título, dos
	 * demais componentes
	 * @param descricao	Texto a ser posto como inicial 
	 * @param checkBox	Sinaliza se e um botao de identificacao de checkBox
	 * @return 			O botao criado, respeitando os parametros
	 */
	public JButton criarIdentificacao (String descricao, boolean checkBox){
		JButton novo = new JButton();
		
		if (!checkBox)
			padrao = new Dimension(85, 30);
		else
			padrao = new Dimension(120, 30);
		
		novo.setText(descricao);
		novo.setHorizontalAlignment(JButton.CENTER);
				
		novo.setBorderPainted(false);
		novo.setContentAreaFilled(false);
		
		novo.setMaximumSize (padrao);
		novo.setMinimumSize (padrao);
		novo.setPreferredSize (padrao);
		
		return novo;
	}

	/**
	 * Criacao de um slider padrao
	 * @param nome			Nome a ser atribuido ao slider
	 * @param minimo		Valor minimo da escala
	 * @param maximo		Valor maximo da escala
	 * @param inicio		Valor inicial
	 * @param transforma	Sinaliza se o valor deve sofrer alteracao para exibicao
	 * @return				O slider ja construido
	 */
	public JSlider criarSlider (String nome, int minimo, int maximo, int inicio, boolean transforma){
		JSlider novo = new JSlider(JSlider.HORIZONTAL, minimo, maximo, inicio);
	
		novo.setSize(new Dimension(100, 45));
		
		novo.setPaintLabels(true);
		
		int razao = Character.getNumericValue(Float.toString(maximo).charAt(0));
		float valor;
		Integer inteiro;
		JLabel legenda;
		
		Hashtable<Object, Object> labelTable = new Hashtable<Object, Object>();
		for (int vezes = 0; vezes < 5; vezes++){
			valor = (maximo * (float)vezes / 4);
			inteiro = new Integer((int)valor);
			
			if (transforma){
				valor /= (maximo - minimo);
				valor *= razao;
				legenda = new JLabel(Float.toString(valor));
			}else{
				legenda = new JLabel(Integer.toString((int)valor));
			}				
			
			labelTable.put (inteiro, legenda);
		}
		
		novo.setLabelTable( labelTable );
		
		novo.setName(nome);
		
		novo.addChangeListener(this);
		
		return novo;
	}
	
	/**
	 * Criacao de um botao especial para exibicao do valor de um slider mestre
	 * @param mestre	Slider que tera o valor exibido
	 * @return			Botao construido
	 */
	public JButton criarValorSlider (JSlider mestre){
		padrao = new Dimension(100, 20);
		JButton novo = new JButton();
		float razao;
		
		razao = (float) Character.getNumericValue(Float.toString(mestre.getMaximum()).charAt(0));
		razao *= ((float)mestre.getValue() / mestre.getMaximum());
		
		novo.setText(mestre.getName() + ": " + razao);
		
		novo.setBorder (null);
		novo.setBorderPainted(false);
		novo.setContentAreaFilled(false);
				
		novo.setHorizontalAlignment(JButton.CENTER);
		novo.setVerticalAlignment(JButton.BOTTOM);
				
		novo.setMaximumSize		(padrao);
		novo.setMinimumSize		(padrao);
		novo.setPreferredSize	(padrao);
		
		return novo;
	}
	
	/**
	 * Criacao de uma caixa de marcacao padrao
	 * @return	Caixa construida
	 */
	public JCheckBox criarCheckBox (){
		JCheckBox novo = new JCheckBox ();
		
		novo.setSelected(false);
		
		novo.setEnabled(false);
		
		novo.addItemListener(this);
		
		return novo;
	}
	
	/**
	 * Criacao de uma area de texto padrao
	 * @param nome			Nome a ser atribuido a area de texto
	 * @param textoInicial	Texto iniciado de maneira defautl
	 * @param executavel	Sinaliza se sera construido uma area de texto executavel ou
	 * nao
	 * @return				Area de texto construida
	 */
	public JTextField criarTextField (String nome, String textoInicial, boolean executavel){
		padrao = new Dimension (60, 20);
		JTextField novo = new JTextField();
		
		novo.setText (textoInicial);
		novo.setName (nome);

		if (executavel)
			novo.getDocument().addDocumentListener(this);
		else{
			
			novo.addMouseListener(this);
		}
		
		novo.setMinimumSize (padrao);
		novo.setMaximumSize (padrao);
		novo.setPreferredSize (padrao);
				
		return novo;
	}
	
	/**
	 * Criacao de uma area de texto para expressar valor de um slider
	 * @param mestre		Slider que tera o valor exibido
	 * @param nome			Nome a ser atribuido a area de texto
	 * @param executavel	Sinaliza se sera construido uma area de texto executavel ou
	 * nao
	 * @return				Area de texto construida
	 */
	public JTextField criarTextField (JSlider mestre, String nome, boolean executavel){
		padrao = new Dimension (60, 20);
		JTextField novo = new JTextField();
		float razao;
		
		razao = (float) Character.getNumericValue(Float.toString(mestre.getMaximum()).charAt(0));
		razao *= ((float)mestre.getValue() / mestre.getMaximum());
		
		novo.setText("" + razao);
		
		novo.setName (nome);

		if (executavel)
			novo.getDocument().addDocumentListener(this);
		else{
			novo.addMouseListener(this);
		}
		
		novo.setMinimumSize (padrao);
		novo.setMaximumSize (padrao);
		novo.setPreferredSize (padrao);
				
		return novo;
	}
	
	
	
	/**
	 * Controle das acoes dos ambientes graficos, para as
	 * comboBox e os botoes executaveis
	 * @param evento Qual o componente que foi ativado
	 */
	public void actionPerformed(ActionEvent evento) {
		if ("escolheMel".equals(evento.getActionCommand())){
			ControleComandos.escolherMelodias ();
		
		}else if ("escolheInst".equals(evento.getActionCommand())){
			ControleComandos.escolherInstrumentos ();
		
		}else if ("salvar".equals(evento.getActionCommand())){
			ControleComandos.salvarSom();
		
		}else if ("visualizar".equals(evento.getActionCommand())){
			ControleComandos.visualizarSom();
		
		}else if ("tocar".equals(evento.getActionCommand())){
			ControleComandos.tocarSom();
		}
	}
		
	/**
	 * Controle das acoes dos ambientes graficos, para
	 * os slider
	 * @param fonte Fonte da acao
	 */
	public void stateChanged(ChangeEvent fonte) {
		JSlider origem = (JSlider) fonte.getSource(); 
		
		if (origem.equals(controleAndamento)){
			ControleComandos.configurarAndamentoViaSlider ();

		}else if (origem.equals(controleTransposicao)){
			ControleComandos.configurarTransposicaoViaSlider();

		}else if (origem.equals(controleFatordeCorte)){
			ControleComandos.configurarFatordeCorteViaSlider();

		}else if (origem.equals(controleFase)){
			ControleComandos.configurarFaseViaSlider();

		}else if (origem.equals(controleLambda)){
			ControleComandos.configurarLambdaViaSlider();

		}
	}

	/**
	 * Controle das acoes dos ambientes graficos, para
	 * as caixas de selecao
	 * @param fonte	Fonte da acao
	 */
	public void itemStateChanged(ItemEvent fonte) {
		Object origem = fonte.getItemSelectable();
		int acao = (fonte.getStateChange() - 1);
				
		if (origem.equals(controleInverterMel)){
			ControleComandos.configurarInversaoMelodia(acao);
			
		}else if (origem.equals(controleSalvar)){
			ControleComandos.configurarSalvarSom(acao);
			
		}
	}

	/**
	 * Controle das acoes dos ambientes graficos, para
	 * a insercao de caracteres nos campos de texto
	 * @param evento Evento registrado
	 */
	public void insertUpdate(DocumentEvent evento) {
		atualizacaoTexto (evento);
	}

	/**
	 * Controle das acoes dos ambientes graficos, para
	 * a remocao de caracteres nos campos de texto
	 * @param evento Evento registrado
	 */
	public void removeUpdate(DocumentEvent evento) {
		atualizacaoTexto (evento);
	}

	/**
	 * Dispensavel para este trabalho, mas obrigatorio
	 * de declarar
	 */
	public void changedUpdate(DocumentEvent e) {
		
	}
	
	/**
	 * Controle das acoes dos ambientes graficos, para
	 * os campos de texto
	 * @param event Evento registrado
	 */
	private void atualizacaoTexto (DocumentEvent evento){
		Object fonte = evento.getDocument().getProperty("owner");
		
		if (fonte.equals(valorGanhoInst)){
			ControleComandos.configurarGanhoInstrumento ();
			
		}else if (fonte.equals(valorAndamento)){
			ControleComandos.configurarAndamentoViaTexto ();
			
		}else if (fonte.equals(valorTransposicao)){
			ControleComandos.configurarTransposicaoViaTexto ();
			
		}else if (fonte.equals(valorFatordeCorte)){
			ControleComandos.configurarFatordeCorteViaTexto ();
			
		}else if (fonte.equals(valorFase)){
			ControleComandos.configurarFaseViaTexto ();
			
		}else if (fonte.equals(valorLambda)){
			ControleComandos.configurarLambdaViaTexto();
			
		}else if (fonte.equals(nomeWave)){
			ControleComandos.configurarNomeSom();
			
		}
	}

	/**
	 * Controle das acoes dos ambientes graficos, para
	 * o campo salvar, ao primeiro click do mouse sobre
	 * o mesmmo
	 * @param evento Evento registrado
	 */
	public void mouseClicked(MouseEvent evento) {
		ControleComandos.configurarClickSalvar ();		
	}

	/**
	 * Dispensavel para este trabalho, mas obrigatorio
	 * de declarar
	 */
	public void mousePressed(MouseEvent e) {
	}

	/**
	 * Dispensavel para este trabalho, mas obrigatorio
	 * de declarar
	 */
	public void mouseReleased(MouseEvent e) {
	}

	/**
	 * Dispensavel para este trabalho, mas obrigatorio
	 * de declarar
	 */
	public void mouseEntered(MouseEvent e) {
	}

	/**
	 * Dispensavel para este trabalho, mas obrigatorio
	 * de declarar
	 */
	public void mouseExited(MouseEvent e) {
	}

	/**
	 * Dispensavel para este trabalho, mas obrigatorio
	 * de declarar
	 */
	public void focusGained(FocusEvent e) {
		// TODO Auto-generated method stub
		
	}

	/**
	 * Controle da configuracao do nome, apos clicar em 
	 * qualquer outro componente
	 * @param evento Evento registrado
	 */
	public void focusLost(FocusEvent evento) {
		ControleComandos.editando = true;
		ControleComandos.configurarNomeSom();
		ControleComandos.editando = false;
	}
}
