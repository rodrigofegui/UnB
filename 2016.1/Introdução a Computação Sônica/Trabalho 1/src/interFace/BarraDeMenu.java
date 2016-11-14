/*	Pacote ao qual pertence */
package interFace;

/*	Importando APIs necessárias */
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;

import javax.sound.midi.MidiUnavailableException;
import javax.swing.JMenuBar;
import javax.swing.JMenu;
import javax.swing.JMenuItem;
import javax.swing.KeyStroke;

public class BarraDeMenu implements ActionListener{
	JMenuBar barraDeMenu;
	JMenu menu;
	JMenuItem itensMenu;
	
	public JMenuBar criarBarraDeMenu (){
		/*	Criação da barra de menu */
		barraDeMenu = new JMenuBar();
		
		/*	Construção do Primeiro Menu */
		addMenuArquivo();
		
		/*	Construção do Segundo Menu */
		addMenuFerramenta();
		
		/*	Construção do Terceiro Menu */
		addMenuAjuda();
		
		return barraDeMenu; 
	}

	private void addMenuArquivo() {
		/*	Criação do Menu */
		menu = new JMenu("Arquivo");
		/*	Estabelecendo atalho para o menu: 'Alt + A' */
        menu.setMnemonic(KeyEvent.VK_A);
        /*	Descrição ao permanecer com o mouse */
        menu.setToolTipText("Manipula\u00e7\u00e3o de arquivos");
        /*	Adicionando menu à barra de menu */
        barraDeMenu.add(menu);
        
        /*	Criando os itens que estarão no menu */
        itensMenu = new JMenuItem ("Abrir...");
        /*	Estabelecendo atalho para este item: 'Ctrl + O' */
        itensMenu.setAccelerator (KeyStroke.getKeyStroke(KeyEvent.VK_O, ActionEvent.CTRL_MASK));
        /*	Identificação da Ação a ser tomada */
        itensMenu.setActionCommand("abrir");
        /*	Adicionando Ação ao item */
        itensMenu.addActionListener(this);
        /*	Adicionando ao menu */
        menu.add(itensMenu);
        
        /*	Separador de conteúdo */
        menu.addSeparator();
        
        itensMenu = new JMenuItem ("Conte\u00fado MIDI");
        /*	Estabelecendo atalho para este item: 'Ctrl + D' */
        itensMenu.setAccelerator (KeyStroke.getKeyStroke(KeyEvent.VK_D, ActionEvent.CTRL_MASK));
        /*	Identificação da Ação a ser tomada */
        itensMenu.setActionCommand("midi");
        /*	Adicionando Ação ao item */
        itensMenu.addActionListener(this);
        /*	Adicionando ao menu */
        menu.add(itensMenu);
        
        itensMenu = new JMenuItem ("Conte\u00fado Musical");
        /*	Estabelecendo atalho para este item: 'Ctrl + M' */
        itensMenu.setAccelerator (KeyStroke.getKeyStroke(KeyEvent.VK_M, ActionEvent.CTRL_MASK));
        /*	Identificação da Ação a ser tomada */
        itensMenu.setActionCommand("musical");
        /*	Adicionando Ação ao item */
        itensMenu.addActionListener(this);
        /*	Adicionando ao menu */
        menu.add(itensMenu);
        
        
        /*	Separador de conteúdo */
        menu.addSeparator();
        
        itensMenu = new JMenuItem ("Fechar");
        /*	Estabelecendo atalho para este item: 'Ctrl + X' */
        itensMenu.setAccelerator (KeyStroke.getKeyStroke(KeyEvent.VK_X, ActionEvent.CTRL_MASK));
        /*	Identificação da Ação a ser tomada */
        itensMenu.setActionCommand("fechar");
        /*	Adicionando Ação ao item */
        itensMenu.addActionListener(this);
        /*	Adicionando ao menu */
        menu.add(itensMenu);
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
		/*	Criação do Menu */
		menu = new JMenu("Ajuda");
		/*	Estabelecendo atalho para o menu: 'Alt + F' */
        menu.setMnemonic(KeyEvent.VK_H);
        /*	Descrição ao permanecer com o mouse */
        menu.setToolTipText("Exposi\u00e7\u00e3o a cerca do trabalho");
        /*	Adicionando menu à barra de menu */
        barraDeMenu.add(menu);
        
        /*	Criando novo item */
        itensMenu = new JMenuItem ("Sobre");
        /*	Estabelecendo atalho para este item: 'Ctrl + Espaço' */
        //itensMenu.setAccelerator (KeyStroke.getKeyStroke(KeyEvent.VK_SPACE, ActionEvent.CTRL_MASK));
        /*	Identificação da Ação a ser tomada */
        itensMenu.setActionCommand("sobre");
        /*	Adicionando Ação ao item */
        itensMenu.addActionListener(this);
        /*	Adicionando ao menu */
        menu.add(itensMenu);
	}
	
	public void actionPerformed(ActionEvent evento) {
		/*	Seleção de Comando */
		if ("abrir".equals(evento.getActionCommand()))
			try {
				Comandos.abrirArquivo();
			} catch (MidiUnavailableException e) {
				e.printStackTrace();
			}
		else if ("midi".equals(evento.getActionCommand()))
			Comandos.conteudoMidi();
		else if ("musical".equals(evento.getActionCommand()))
			Comandos.conteudoMusical();
		else if ("fechar".equals(evento.getActionCommand()))
			Comandos.fecharAplicacao();
		else if ("tocar".equals(evento.getActionCommand()))
			try {
				Comandos.tocarMusica();
			}catch (MidiUnavailableException e){
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
		else if ("aumentar".equals(evento.getActionCommand()))
			Comandos.aumentarVolume();
		else if ("diminuir".equals(evento.getActionCommand()))
			Comandos.diminuirVolume();
		else if ("sobre".equals(evento.getActionCommand()))
			Comandos.sobreAplicacao();
	}
}
