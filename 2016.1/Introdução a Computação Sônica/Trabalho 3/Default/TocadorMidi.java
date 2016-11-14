import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.text.DecimalFormat;

import javax.sound.midi.InvalidMidiDataException;
import javax.sound.midi.MetaMessage;
import javax.sound.midi.MidiEvent;
import javax.sound.midi.MidiMessage;
import javax.sound.midi.MidiSystem;
import javax.sound.midi.MidiUnavailableException;
import javax.sound.midi.Sequence;
import javax.sound.midi.Sequencer;
import javax.sound.midi.Track;

public class TocadorMidi {
	// Dó Central (C3) = indice 60
	static final int FORMULA_DE_COMPASSO = 0x58;
	static final int MENSAGEM_TONALIDADE = 0x59;
	static final int MENSAGEM_TEXTO = 0x01;
	static DecimalFormat formatoFloat = new DecimalFormat("0.00000");

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

	public static void main (String args[]) throws MidiUnavailableException{
		String nomearq = "../Musicas/Midi/mvioloncelo1.mid";
		//String nomearq = "musicas/bwv772.mid";
		//String nomearq = "musicas/Ainda bem - Mariza Monte.mid";
		//String nomearq = "musicas/The Rains of Castamere.mid";
		//String nomearq = "musicas/Super_Mario_Bros_-_Overworld_Theme_by_BlueSCD.mid";
		//String nomearq = "musicas/Let It Go.mid";
		
		File      arqmidi = new File(nomearq);
		Sequence  sequencia;
			
		try{ 
			sequencia = MidiSystem.getSequence(arqmidi);                            
		            
			exibirDados (sequencia, nomearq);
			
			//escreverDados (sequencia, nomearq);
			
			//tocarSequencia (sequencia); 
	
		}catch (InvalidMidiDataException e2){
			System.out.println("Erro2: "+"Erro nos dados midi.");
		}catch (IOException              e3){
			System.out.println("Erro3: "+"O arquivo midi não foi encontrado.");
			System.out.println("Sintaxe: "+"java TocadorMidi arquivo.mid"); 
		}
	
		System.out.println("");
		System.out.println("* * * \n");
	}

	static void retardo (int miliseg){  
		try{
			Thread.sleep(miliseg);
		}catch(InterruptedException e){}
	}

	static void exibirDados (Sequence sequencia, String nome){
		long duracao     = sequencia.getMicrosecondLength() / 1000000;
		int  resolucao   = sequencia.getResolution();
		long totaltiques = sequencia.getTickLength();
	
		float durtique       = (float)duracao/totaltiques;
		float durseminima    = durtique*resolucao;
		float bpm            = 60/durseminima;
		int   totalseminimas = (int)(duracao/durseminima);
	
		System.out.println("");
		System.out.println("------------------------------------------");
		System.out.println("--- Arquivo Midi: " + nome);
		System.out.println("------------------------------------------");
		System.out.println("resolução            = "+resolucao+" tiques   (número de divisões da semínima)");
		System.out.println("duração              = "+duracao+" s");
		System.out.println("número de tiques     = "+totaltiques+" ");
		System.out.println("duração do tique     = "+durtique+" s");
		System.out.println("duração da semínima  = "+durseminima+" s");
		System.out.println("total de seminimas   = "+totalseminimas);
		System.out.println("andamento            = "+Math.round(bpm)+ " bpm");
		System.out.println("------------------------------------------");
	
		System.out.println("\n");
		System.out.println("------------------------------------------");
		System.out.println("--- Conteúdo da sequência:");
		System.out.println("------------------------------------------");
	  
		Track[] trilhas = sequencia.getTracks();
	
		for (int i = 0; i < trilhas.length; i++){
			System.out.println("\n------------------------------------------");
			System.out.println("--- Início da trilha nº " + i);
			System.out.println("------------------------------------------");
			Track trilha =  trilhas[i];
		  
			Par    fc  =  null;
			String st  = "--";
			String stx = "--";
		  
		  	if(i == 0)
				fc = getFormulaDeCompasso(trilha);
		
			if(i == 0)
			try{
				st =  getTonalidade(trilha);
			}catch(Exception e){}
		  
			try{
				stx =  getTexto(trilha);
			}catch(Exception e){}
		  
			if(fc != null)
				System.out.println("Fórmula de Compasso: " + fc.getX() +":"+ (int)(Math.pow(2, fc.getY())) );
		
			System.out.println("Tonalidade         : " + st);
			System.out.println("Texto              : " + stx);
			System.out.println("------------------------------------------");
		  
			for(int j = 0; j < trilha.size(); j++){
				System.out.println("Trilha nº " + i );
				System.out.println("Evento nº " + j);
		
				MidiEvent   e          = trilha.get(j);
				MidiMessage mensagem   = e.getMessage();
				long        tique      = e.getTick();
		
				int n = mensagem.getStatus();
				String nomecomando = "" + n;
		
				if ((128 <= n) & (n <= 143))
					nomecomando = montaNomeComando ("Note OFF", n, 128);
				else if ((144 <= n) & (n <= 159))
					nomecomando = montaNomeComando ("Note ON", n, 144);
				else if ((176 <= n) & (n <= 191))
					nomecomando = montaNomeComando ("Control Change", n, 176);
				else if ((192 <= n) & (n <= 207))
					nomecomando = montaNomeComando ("Program Change", n, 192);
				else if ((224 <= n) & (n <= 239))
					nomecomando = montaNomeComando ("Pitch Bend", n, 224);
				else if ((240 <= n) & (n <= 255))
					nomecomando = "Mensagem Meta";
		
				System.out.println("       Mensagem: " + nomecomando );
				byte[] dados = mensagem.getMessage();
		
				for (int ind = 1; ind < mensagem.getLength(); ind++)
					System.out.println("              Byte " + ind + " => " + dados[ind]);
				System.out.println("       Instante: " + formatoFloat.format((float)(tique * durtique)) + " s" );
				System.out.println("------------------------------------------");                                    
			}
		}                            
	}

	static void escreverDados (Sequence sequencia, String nome) throws IOException{
		FileWriter arq = new FileWriter(nome + "_teste.txt");
	    PrintWriter gravarArq = new PrintWriter(arq);

	    long duracao     = sequencia.getMicrosecondLength() / 1000000;
		int  resolucao   = sequencia.getResolution();
		long totaltiques = sequencia.getTickLength();
	
		float durtique       = (float)duracao/totaltiques;
		float durseminima    = durtique*resolucao;
		float bpm            = 60/durseminima;
		int   totalseminimas = (int)(duracao/durseminima);
	
		gravarArq.println("------------------------------------------");
		gravarArq.println("--- Arquivo Midi: " + nome);
		gravarArq.println("------------------------------------------");
		gravarArq.println("resolução            = " + resolucao + " tiques   (número de divisões da semínima)");
		gravarArq.println("duração              = " + duracao + " s");
		gravarArq.println("número de tiques     = " + totaltiques);
		gravarArq.println("duração do tique     = " + durtique + " s");
		gravarArq.println("duração da semínima  = " + durseminima + " s");
		gravarArq.println("total de seminimas   = " + totalseminimas);
		gravarArq.println("andamento            = " + Math.round(bpm) + " bpm");
		gravarArq.println("------------------------------------------");
	
		gravarArq.println("\n");
		gravarArq.println("------------------------------------------");
		gravarArq.println("--- Conteúdo da sequência:");
		gravarArq.println("------------------------------------------");
	  
		Track[] trilhas = sequencia.getTracks();
	
		for (int i = 0; i < trilhas.length; i++){
			gravarArq.println("\n------------------------------------------");
			gravarArq.println("--- Início da trilha nº " + i);
			gravarArq.println("------------------------------------------");
			Track trilha =  trilhas[i];
		  
			Par    fc  =  null;
			String st  = "--";
			String stx = "--";
		  
		  	if(i == 0)
				fc = getFormulaDeCompasso(trilha);
		
			if(i == 0)
			try{
				st =  getTonalidade(trilha);
			}catch(Exception e){}
		  
			try{
				stx =  getTexto(trilha);
			}catch(Exception e){}
		  
			if(fc != null)
				gravarArq.println("Fórmula de Compasso: " + fc.getX() +":"+ (int)(Math.pow(2, fc.getY())) );
		
			gravarArq.println("Tonalidade         : " + st);
			gravarArq.println("Texto              : " + stx);
			gravarArq.println("------------------------------------------");
		  
			for(int j = 0; j < trilha.size(); j++){
				gravarArq.println("Trilha nº " + i );
				gravarArq.println("Evento nº " + j);
		
				MidiEvent   e          = trilha.get(j);
				MidiMessage mensagem   = e.getMessage();
				long        tique      = e.getTick();
		
				int n = mensagem.getStatus();
				String nomecomando = "" + n;
		
				if ((128 <= n) & (n <= 143))
					nomecomando = montaNomeComando ("Note OFF", n, 128);
				else if ((144 <= n) & (n <= 159))
					nomecomando = montaNomeComando ("Note ON", n, 144);
				else if ((176 <= n) & (n <= 191))
					nomecomando = montaNomeComando ("Control Change", n, 176);
				else if ((192 <= n) & (n <= 207))
					nomecomando = montaNomeComando ("Program Change", n, 192);
				else if ((224 <= n) & (n <= 239))
					nomecomando = montaNomeComando ("Pitch Bend", n, 224);
				else if ((240 <= n) & (n <= 255))
					nomecomando = "Mensagem Meta";
		
				gravarArq.println("\tMensagem: " + nomecomando );
				byte[] dados = mensagem.getMessage();
		
				for (int ind = 1; ind < mensagem.getLength(); ind++)
					gravarArq.println("\t\tByte " + ind + " => " + dados[ind]);
				gravarArq.println("\tInstante: " + formatoFloat.format((float)(tique * durtique)) + " s" );
				gravarArq.println("------------------------------------------");                                    
			}
		}               
	    
	    arq.close();
	    System.out.println("Acabou de escrever o arquivo");
	}
	
	private static void tocarSequencia (Sequence sequencia) throws MidiUnavailableException, InvalidMidiDataException {
		//---preparar o sequenciador com o banco: ------
		Sequencer sequenciador = MidiSystem.getSequencer();
		sequenciador.open();
		sequenciador.setSequence(sequencia);
		sequenciador.start();  //--aqui começa a tocar.
		
		int i = 0;
		System.out.println("Instante em segundos: ");

		while(true){
			if(sequenciador.isRunning()){
				retardo(1000);
		      
				//----exibir o instante real em segundos:---------
				long  posicao = sequenciador.getMicrosecondPosition();
				int   seg     = Math.round(posicao*0.000001f);
				System.out.print(seg + " ");
				i++;
				if(i == 20){
					System.out.println("");
					i = 0;
				}
		    }
		    else break;        
		}
		  
		System.out.println("");
		System.out.println("* * * \n");

		retardo(1000); 
		sequenciador.stop();
		sequenciador.close();
	}
	
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

	static String getTonalidade (Track trilha) throws InvalidMidiDataException{       
		String stonalidade = "";
	
		for (int i = 0; i < trilha.size(); i++){
			MidiMessage m = trilha.get(i).getMessage();
	
			if (((MetaMessage)m).getType() == MENSAGEM_TONALIDADE){
				MetaMessage mm        = (MetaMessage)m;
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
	    
		return stonalidade;
	}

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

	private static String montaNomeComando (String base, int n, int minimo){
		return (base + ", canal " + (n - minimo));
	}
}
