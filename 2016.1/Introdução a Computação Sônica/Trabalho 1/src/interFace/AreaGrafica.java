/*	Pacote ao qual pertence */
package interFace;

/*	Importando APIs necessárias */
import java.awt.Color;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

import javax.sound.midi.MidiUnavailableException;
import javax.swing.BorderFactory;
import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JPanel;
import javax.swing.JProgressBar;
import javax.swing.JSlider;
import javax.swing.JTextArea;
import javax.swing.SwingConstants;
import javax.swing.border.Border;
import javax.swing.border.EtchedBorder;
import javax.swing.border.TitledBorder;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

public class AreaGrafica implements ActionListener, ChangeListener{
	JPanel painelPrincipal;
	JPanel painelProgresso;
	JPanel painelBotoes;
	ImageIcon icone;
	final static int volumeInicial = 64;
	public static int posicaoBarraProgresso = 0;
	static JTextArea textoNomeArquivo = null;
	static JProgressBar barraDeProgresso = null;
	static JTextArea textoBarraDeProgresso = null;
	static JButton botaoTocar = null, botaoPausar = null, botaoParar = null;
	static JButton botaoVoltar = null, botaoAvancar = null, botaoVolume = null;
	static JButton textoVolume = null;
	static JSlider controleVolume = null;
	
	public JPanel criarPlanoDeConteudo() {
		/*	Preparaç\u00e3o para o incremento das informações gráficas */
		preparaPainelPrincipal();
		
		/*	Adicionando nome do arquivo */
		addCaixaArquivo();
		
		/*	Preparando a barra de progresso */
		preparaPainelProgresso ();
		
		/*	Adicionando a barra de progresso */
		addBarraProgresso ();
		
		/*	Preparando os botoes */
		preparaPainelBotes();
		
		/*	Adicionando os botoes */
		addBotoes();
		
		return painelPrincipal;
	}

	private void preparaPainelPrincipal() {
		/*	Criando o painel de conteúdo principal */
		painelPrincipal = new JPanel ();
		/*	Configuraç\u00e3o do layout para "crescer" no eixo Y */
        painelPrincipal.setLayout (new BoxLayout(painelPrincipal, BoxLayout.Y_AXIS));
        painelPrincipal.setOpaque (true);
        
        /*	Criando e configurando caixa principal */
        Border caixaPrincipal = BorderFactory.createEmptyBorder (2,10,10,10);
        painelPrincipal.setBorder (caixaPrincipal);
	}
	
	private void addCaixaArquivo(){
		/*	Criando caixa em baixo relevo */
		Border caixaArquivo = BorderFactory.createEtchedBorder(EtchedBorder.LOWERED);
		/*	Criando título da caixa */
		TitledBorder tituloCaixaArquivo = BorderFactory.createTitledBorder(caixaArquivo, "Nome do Arquivo:");
        /*	Adicionando a caixa com título */
        addCompABorda (tituloCaixaArquivo, "", painelPrincipal);
        
        /*	Adicionaod espaçamento para o próximo painel */
        painelPrincipal.add(Box.createRigidArea(new Dimension(0, 10)));
	}

	private void preparaPainelProgresso(){
		/*	Criando painel para a barra de progresso */
		painelProgresso = new JPanel ();
		/*	Configuraç\u00e3o do layout para "crescer" no eixo Y */
		painelProgresso.setLayout(new BoxLayout(painelProgresso, BoxLayout.Y_AXIS));
		painelProgresso.setOpaque (true);
		
		/*	Configurando o tamanho máximo */
		painelProgresso.setMaximumSize(new Dimension(550, 30));
		
		/*	Adicionando ao painel principal */
		painelPrincipal.add(painelProgresso);
	}
	
	private void addBarraProgresso() {
		barraDeProgresso = new JProgressBar(0, 100);
		barraDeProgresso.setPreferredSize(new Dimension(400,10));
		barraDeProgresso.setFocusable(false);
		barraDeProgresso.setStringPainted(false);
		
		textoBarraDeProgresso = new JTextArea ();
		textoBarraDeProgresso.setBackground (new Color(235, 235, 235));
		textoBarraDeProgresso.setEditable(false);
		
		painelProgresso.add(barraDeProgresso);
		painelProgresso.add(textoBarraDeProgresso);
		painelProgresso.add(Box.createRigidArea(new Dimension(0, 5)));
	}
	
	private void preparaPainelBotes() {
		painelBotoes = new JPanel (new FlowLayout());
		Border caixaPrincipal = BorderFactory.createEmptyBorder(1,1,1,1);
		
		painelBotoes.setBorder(caixaPrincipal);
		painelBotoes.setBackground(new Color(235, 235, 235));
		painelBotoes.setMaximumSize(new Dimension(550, 55));
		painelPrincipal.add(painelBotoes);        
	}
	
	private void addBotoes(){
		botaoVoltar = criarBotao ("voltar", true, false);
		
		botaoPausar = criarBotao ("pausar", true, false);
		botaoPausar.setVisible(false);

		botaoTocar = criarBotao ("tocar", true, false);
		
		botaoAvancar = criarBotao ("avancar", true, false);

		botaoParar = criarBotao ("parar", true, false);
		
		addEspacoVazio (90);
		
		botaoVolume = criarVolume ("volume_médio");
		
		controleVolume = sliderVolume (0, 127, volumeInicial);
		
		textoVolume = criarTextoVolume ();
		
		Comandos.controleVolume();
	}
	
	
	void addCompABorda(Border borda, String descricao, Container destino){
        /*	Criando Caixa */
		JPanel caixa = new JPanel (new GridLayout (1, 1), false);
       
		/*	Configuraç\u00e3o da área de texto */
		textoNomeArquivo = new JTextArea();
		textoNomeArquivo.setBackground(new Color(235, 235, 235));
		textoNomeArquivo.setText(descricao);
		textoNomeArquivo.setEditable(false);
        caixa.add(textoNomeArquivo);
        caixa.setBorder(borda);
        
        caixa.setMaximumSize (new Dimension(550, 40));
        destino.add(Box.createRigidArea(new Dimension(0, 10)));
        destino.add(caixa);
    }
	
	private void addEspacoVazio(int largura) {
		painelBotoes.add(Box.createRigidArea(new Dimension(largura, 50)));
	}
		
	public static ImageIcon criarIcone (String diretorio){
        ImageIcon imagem = new ImageIcon (diretorio);
        return imagem;
    }
	
	
	private JButton criarBotao (String descricao, boolean acao, boolean ativacao){
		String nomeIcone;
		if (Principal.EXECUTANDO_ECLIPSE)
			nomeIcone = "Icones/" + descricao + ".png";
		else
			nomeIcone = "../Icones/" + descricao + ".png";
		
		/*	Aquisiç\u00e3o do icone */
		icone = criarIcone(nomeIcone);
		/*	Criando Bot\u00e3o de Tocar */
		JButton novo = new JButton(icone);
		/*	Redimensioar bot\u00e3o */
		if (descricao.equals("tocar") || descricao.equals("pausar"))
			novo.setPreferredSize(new Dimension(43, 43));
		else
			novo.setPreferredSize(new Dimension(32, 32));
		/*	Tirar borda */
		novo.setBorderPainted(false);
		/*	Tirar area pintada */
		novo.setContentAreaFilled(false);
		/*	Tirar destaque ao clicar */
		//novo.setFocusPainted(false);
		
		if (acao){
			/*	Identificaç\u00e3o da Aç\u00e3o a ser tomada */
	        novo.setActionCommand(descricao);
	        /*	Adicionando Aç\u00e3o ao botao */
			novo.addActionListener(this);
		}
		
		/*	Desativado */
		novo.setEnabled(ativacao);
		/*	Adicionando ao painel */
		painelBotoes.add(novo);
		
		return novo;
	}
	
	private JButton criarVolume (String descricao){
		String nomeIcone;
		if (Principal.EXECUTANDO_ECLIPSE)
			nomeIcone = "Icones/" + descricao + ".png";
		else
			nomeIcone = "../Icones/" + descricao + ".png";
		
		/*	Aquisiç\u00e3o do icone */
		icone = criarIcone(nomeIcone);
		/*	Criando Bot\u00e3o de Tocar */
		JButton novo = new JButton(icone);
		/*	Redimensioar bot\u00e3o */
		novo.setPreferredSize(new Dimension(32, 32));
		/*	Tirar borda */
		novo.setBorderPainted(false);
		/*	Tirar area pintada */
		novo.setContentAreaFilled(false);
		/*	Tirar destaque ao clicar */
		//novo.setFocusPainted(false);
		/*	Adicionando ao painel */
		painelBotoes.add(novo);
		
		return novo;
	}
	
	private JSlider sliderVolume (int min, int max, int inicio){
		/*	Criando Controle de volume por Slider */
		JSlider novo = new JSlider(JSlider.HORIZONTAL, min, max, inicio);
		/*	Configurando o tamanho */
		novo.setSize(new Dimension(110, 45));
		/*	Configurando Traços de intervalos menores */
		novo.setMinorTickSpacing(21);
		/*	Configurando Traços de intervalos maiores */
		novo.setMajorTickSpacing(42);
		/*	Marcando os traços */
		novo.setPaintTicks(true);
		/*	Mostrando Identificações */
		novo.setPaintLabels(true);
		/*	Criando Identificações */
		novo.setLabelTable(novo.createStandardLabels(42));
		/*	Adicionando aç\u00e3o */
		novo.addChangeListener(this);
		/*	Adicionando ao painel */
		painelBotoes.add(novo);
		
		return novo;
	}
	
	private JButton criarTextoVolume (){
		JButton nova = new JButton();
		
		/*	Redimensioar area do texto */
		nova.setPreferredSize (new Dimension(25, 45));
		/*	Tirar borda */
		nova.setBorderPainted(false);
		/*	Tirar area pintada */
		nova.setContentAreaFilled(false);
		/*	Configuraç\u00e3o do alinhamento do texto */
		nova.setHorizontalAlignment(SwingConstants.LEFT);
		/*	Configuraç\u00e3o do tamanho da fonte */
		nova.setFont(nova.getFont().deriveFont(10));
		/*	Retirando borda interna */
		nova.setBorder (null);
		/*	Adicionando ao painel */
		painelBotoes.add(nova);
		
		return nova;
	}
	
	public void actionPerformed(ActionEvent evento){
		if ("tocar".equals(evento.getActionCommand()))
			try {
				Comandos.tocarMusica();
			} catch (MidiUnavailableException e) {
				e.printStackTrace();
			}
		else if ("pausar".equals(evento.getActionCommand()))
			Comandos.pausarMusica();
		else if ("parar".equals(evento.getActionCommand()))
			Comandos.pararMusica();
		else if ("voltar".equals(evento.getActionCommand()))
			Comandos.voltarMusica();
		else if ("avancar".equals(evento.getActionCommand()))
			Comandos.avancarMusica();
	}
	
	public void stateChanged(ChangeEvent event){
		int atual = controleVolume.getValue();
		String nomeIcone;
		if (Principal.EXECUTANDO_ECLIPSE)
			nomeIcone = "Icones/";
		else
			nomeIcone = "../Icones/";
		
		if (atual == 0)
			nomeIcone += "volume_mudo.png";			
		else if (atual < 42)
			nomeIcone += "volume_baixo.png";
		else if (atual < 84)
			nomeIcone += "volume_médio.png";
		else
			nomeIcone += "volume_alto.png";
		
		/*	Abrindo o ícone */
		icone = criarIcone(nomeIcone);
		
		/*	Configurando o ícone do bot\u00e3o */
		botaoVolume.setIcon(icone);
		
		Comandos.controleVolume();
    }
}
