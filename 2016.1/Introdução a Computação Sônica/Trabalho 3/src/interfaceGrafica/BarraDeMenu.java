/*	Pacote ao qual pertence */
package interfaceGrafica;

/*	Importando APIs necessárias */
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;

import javax.swing.JMenuBar;
import javax.swing.JMenu;
import javax.swing.JMenuItem;
import javax.swing.KeyStroke;

/**
 * Responsavel por criar a barra de menu da interface grafica
 * @author	Helio Santana
 * @author	Rodrigo Guimaraes
 * @version	1.0
 * @since	16/06/2016
 */
public class BarraDeMenu implements ActionListener{
	static JMenuBar barraDeMenu = null;
	private JMenu menu;
	private JMenuItem itensMenu;
	
	/**
	 * Criacao da barra de menu de maneira default
	 */
	public BarraDeMenu (){
		barraDeMenu = new JMenuBar();
		
		addMenuArquivo();
		
		addMenuExibir();
		
		//addMenuFerramenta();
		
		addMenuAjuda();
	}
	
	/**
	 * Criacao da barra de menu para componentes externos,
	 * de maneira estatica
	 * @return Barra de menu criada
	 */
	public static JMenuBar criarBarraDeMenu (){
		new BarraDeMenu();
		
		return barraDeMenu; 
	}

	/**
	 * Criacao do menu "Arquivo" da barra da menu
	 */
	private void addMenuArquivo() {
		menu = new JMenu("Arquivo");
		menu.setMnemonic(KeyEvent.VK_A);
        menu.setToolTipText("Manipula\u00e7\u00e3o de arquivos");
        
        itensMenu = new JMenuItem ("Abrir...");
        itensMenu.setToolTipText("Abrir melodia a partir de um arquivo midi");
        itensMenu.setAccelerator (KeyStroke.getKeyStroke(KeyEvent.VK_O, ActionEvent.CTRL_MASK));
        itensMenu.setActionCommand("abrir");
        itensMenu.addActionListener(this);
        menu.add(itensMenu);
        
        /*	Separador de conteúdo */
        menu.addSeparator();
        
        itensMenu = new JMenuItem ("Fechar");
        itensMenu.setToolTipText("Fechar a aplica\u00e7\u00e3o");
        itensMenu.setAccelerator (KeyStroke.getKeyStroke(KeyEvent.VK_X, ActionEvent.CTRL_MASK));
        itensMenu.setActionCommand("fechar");
        itensMenu.addActionListener(this);
        menu.add(itensMenu);
        
        barraDeMenu.add(menu);
	}
	
	/**
	 * Criacao do menu "Exibir" da barra da menu
	 */
	private void addMenuExibir (){
		menu = new JMenu("Exibir");
		menu.setMnemonic(KeyEvent.VK_E);
        menu.setToolTipText("Exibi\u00e7\u00e3o de informa\u00e7\u00f5es importantes");
        
        itensMenu = new JMenuItem ("Conte\u00fado MIDI");
        itensMenu.setToolTipText("Conteúdo bruto do arquivo base");
        itensMenu.setAccelerator (KeyStroke.getKeyStroke(KeyEvent.VK_D, ActionEvent.CTRL_MASK));
        itensMenu.setActionCommand("midi");
        itensMenu.addActionListener(this);
        menu.add(itensMenu);
        
        itensMenu = new JMenuItem ("Conte\u00fado Musical");
        itensMenu.setToolTipText("Conteúdo musical do arquivo base");
        itensMenu.setAccelerator (KeyStroke.getKeyStroke(KeyEvent.VK_M, ActionEvent.CTRL_MASK));
        itensMenu.setActionCommand("musical");
        itensMenu.addActionListener(this);
        menu.add(itensMenu);
        
        itensMenu = new JMenuItem ("Classe Java");
        itensMenu.setToolTipText("Classe java no estado atual, sem poder editar");
        itensMenu.setAccelerator (KeyStroke.getKeyStroke(KeyEvent.VK_J, ActionEvent.CTRL_MASK));
        itensMenu.setActionCommand("java");
        itensMenu.addActionListener(this);
        menu.add(itensMenu);
        
        barraDeMenu.add(menu);
	}
	
	private void addMenuFerramenta() {
		/*	Criação do Menu */
		menu = new JMenu("Ferramentas");
		/*	Estabelecendo atalho para o menu: 'Alt + F' */
        menu.setMnemonic(KeyEvent.VK_F);
        /*	Descrição ao permanecer com o mouse */
        menu.setToolTipText("Manipula\u00e7\u00e3o do áudio");
        /*	Adicionando menu à barra de menu */
        barraDeMenu.add(menu);
        
        /*	Criando novo item */
        itensMenu = new JMenuItem ("Tocar");
        /*	Estabelecendo atalho para este item: 'Ctrl + Espaço' */
        itensMenu.setAccelerator (KeyStroke.getKeyStroke(KeyEvent.VK_SPACE, ActionEvent.CTRL_MASK));
        /*	Identificação da Ação a ser tomada */
        itensMenu.setActionCommand("tocar");
        /*	Adicionando Ação ao item */
        itensMenu.addActionListener(this);
        /*	Adicionando ao menu */
        menu.add(itensMenu);
        
        /*	Criando novo item */
        itensMenu = new JMenuItem ("Pausar");
        /*	Estabelecendo atalho para este item: 'Ctrl + P' */
        itensMenu.setAccelerator (KeyStroke.getKeyStroke(KeyEvent.VK_P, ActionEvent.CTRL_MASK));
        /*	Identificação da Ação a ser tomada */
        itensMenu.setActionCommand("pausar");
        /*	Adicionando Ação ao item */
        itensMenu.addActionListener(this);
        menu.add(itensMenu);
        
        /*	Criando novo item */
        itensMenu = new JMenuItem ("Parar");
        /*	Estabelecendo atalho para este item: 'Ctrl + S' */
        itensMenu.setAccelerator (KeyStroke.getKeyStroke(KeyEvent.VK_S, ActionEvent.CTRL_MASK));
        /*	Identificação da Ação a ser tomada */
        itensMenu.setActionCommand("parar");
        /*	Adicionando Ação ao item */
        itensMenu.addActionListener(this);
        menu.add(itensMenu);
        
        /*	Separador de itens */
        menu.addSeparator();
        
        /*	Criando novo item */
        itensMenu = new JMenuItem ("Voltar");
        /*	Estabelecendo atalho para este item: 'Ctrl + [' */
        itensMenu.setAccelerator (KeyStroke.getKeyStroke(KeyEvent.VK_COMMA, ActionEvent.CTRL_MASK));
        /*	Identificação da Ação a ser tomada */
        itensMenu.setActionCommand("voltar");
        /*	Adicionando Ação ao item */
        itensMenu.addActionListener(this);
        menu.add(itensMenu);
        
        /*	Criando novo item */
        itensMenu = new JMenuItem ("Avan\u00e7ar");
        /*	Estabelecendo atalho para este item: 'Ctrl + ]' */
        itensMenu.setAccelerator (KeyStroke.getKeyStroke(KeyEvent.VK_PERIOD, ActionEvent.CTRL_MASK));
        /*	Identificação da Ação a ser tomada */
        itensMenu.setActionCommand("avancar");
        /*	Adicionando Ação ao item */
        itensMenu.addActionListener(this);
        menu.add(itensMenu);
        
        /*	Separador de itens */
        menu.addSeparator();
        
        /*	Criando novo item */
        itensMenu = new JMenuItem ("Aumentar");
        /*	Estabelecendo atalho para este item: 'Ctrl + +' */
        itensMenu.setAccelerator (KeyStroke.getKeyStroke(KeyEvent.VK_ADD, ActionEvent.CTRL_MASK));
        /*	Identificação da Ação a ser tomada */
        itensMenu.setActionCommand("aumentar");
        /*	Adicionando Ação ao item */
        itensMenu.addActionListener(this);
        menu.add(itensMenu);
        
        /*	Criando novo item */
        itensMenu = new JMenuItem ("Diminuir");
        /*	Estabelecendo atalho para este item: 'Ctrl + -' */
        itensMenu.setAccelerator (KeyStroke.getKeyStroke(KeyEvent.VK_SUBTRACT, ActionEvent.CTRL_MASK));
        /*	Identificação da Ação a ser tomada */
        itensMenu.setActionCommand("diminuir");
        /*	Adicionando Ação ao item */
        itensMenu.addActionListener(this);
        menu.add(itensMenu);
	}
	
	private void addMenuAjuda() {
		menu = new JMenu("Ajuda");
		menu.setMnemonic(KeyEvent.VK_H);
        menu.setToolTipText("Exposi\u00e7\u00e3o a cerca do trabalho");
        barraDeMenu.add(menu);
        
        itensMenu = new JMenuItem ("Sobre");
        itensMenu.setToolTipText("Exposição a cerca do trabalho");
        itensMenu.setAccelerator (KeyStroke.getKeyStroke(KeyEvent.VK_H, ActionEvent.CTRL_MASK));
        itensMenu.setActionCommand("sobre");
        itensMenu.addActionListener(this);
        menu.add(itensMenu);
	}
	
	
	/**
	 * Controle das acoes da barra de menu
	 * @param evento Qual o componente que foi ativado
	 */
	public void actionPerformed (ActionEvent evento) {
		if ("abrir".equals(evento.getActionCommand()))
			ControleComandos.abrirMelodia();
		
		else if ("fechar".equals(evento.getActionCommand()))
			ControleComandos.fecharAplicacao();
		else if ("midi".equals(evento.getActionCommand()))
			ControleComandos.conteudoMidi();
		else if ("musical".equals(evento.getActionCommand()))
			ControleComandos.conteudoMusical();
		else if ("java".equals(evento.getActionCommand()))
			ControleComandos.conteudoJava();
		else if ("sobre".equals(evento.getActionCommand()))
			ControleComandos.sobreAplicacao();
	}
}
