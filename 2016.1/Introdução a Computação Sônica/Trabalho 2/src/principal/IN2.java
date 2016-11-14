package principal;

import sintese.Curva;
import sintese.Envoltoria;
import sintese.Oscilador;
import sintese.Ruido;
import sintese.Somador;

public class IN2 extends Instrumento {

	Envoltoria envoltoriaFreq = null;
	Envoltoria envoltoriaFreqRuido = null;
	Somador somador = null;
	
	Curva curvaDeEnvoltoria;
	
	public IN2(){
		super();
		this.fatorCorte = 0.015f;
	}
	
	public IN2 (float fc){
		super(fc);
	}
	
	public IN2 (Ruido ruido, Envoltoria envoltoria, float fc){	
		super(ruido, envoltoria, fc);
	}
	
	@Override
	public void reset() {
		curvaDeEnvoltoria = constroiCurvaDeEnvoltoria();
		this.envoltoria.setCURVA(curvaDeEnvoltoria);
    	this.envoltoria.setDuracao(this.duracao);    	
        this.envoltoria.reset();        
        
        
        envoltoriaFreq = new Envoltoria();
        this.envoltoriaFreq.setCURVA(constroiFuncaoFrequenciaRuido());
        this.envoltoriaFreq.setDuracao(this.duracao);
        this.envoltoriaFreq.reset();
        
        envoltoriaFreqRuido = new Envoltoria();
        this.envoltoriaFreqRuido.setCURVA(constroiFuncaoFrequenciaRuido());
        this.envoltoriaFreqRuido.setDuracao(this.duracao);
        this.envoltoriaFreqRuido.reset();        
        
        
        this.ruido = new Ruido(envoltoriaFreqRuido);   
        this.ruido.setFrequencia (this.frequencia * this.fatorCorte);        
        this.ruido.setFase (this.fase); 
        this.ruido.setDuracao (this.duracao);        
        this.ruido.reset();
        
        
        this.somador = new Somador(this.ruido, this.envoltoriaFreq );
        this.somador.setDuracao(this.duracao);
        this.somador.reset();
        
        this.oscilador = new Oscilador(this.envoltoria, this.somador);
        this.oscilador.setFase(this.fase);
        this.oscilador.setDuracao(this.duracao);
        this.oscilador.reset();
        
		
	}

	
}
