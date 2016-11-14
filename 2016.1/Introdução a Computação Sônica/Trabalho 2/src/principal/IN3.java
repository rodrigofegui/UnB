package principal;

import sintese.Curva;
import sintese.Envoltoria;
import sintese.Oscilador;
import sintese.Ruido;
import sintese.Somador;

public class IN3 extends Instrumento{
	
	Envoltoria envoltoriaFreq = null;
	Envoltoria envoltoriaFreqRuido = null;
	Somador somador = null;
	Oscilador oscilador1 = null;
	
	public IN3(){
		super();
	}
	
	public IN3 (float fc){
		super(fc);
	}
	
	public IN3 (Ruido ruido, Envoltoria envoltoria, float fc){	
		super(ruido, envoltoria, fc);
	}
	
	
	public void reset(){
		this.envoltoria.setCURVA(constroiCurvaDeEnvoltoria());
    	this.envoltoria.setDuracao(this.duracao);    	
        this.envoltoria.reset();
        
       
        
        envoltoriaFreq = new Envoltoria();
        this.envoltoriaFreq.setCURVA(funcaoFrequencia());
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
        
        this.oscilador1= new Oscilador(0.5f, 270, 90);
        this.oscilador1.setFase(this.fase);
        this.oscilador1.setDuracao(this.duracao);
        this.oscilador1.reset();
        
        
        this.somador = new Somador(this.somador, this.oscilador1 );
        this.somador.setDuracao(this.duracao);
        this.somador.reset();
        
        
        this.oscilador = new Oscilador(this.envoltoria, this.somador);
        this.oscilador.setFase(this.fase);
        this.oscilador.setDuracao(this.duracao);
        this.oscilador.reset();
	}

	private Curva funcaoFrequencia(){
		Curva funcaoFrequenciaRuido = new Curva(720);
		funcaoFrequenciaRuido.addPonto(0f, this.frequencia);        
        funcaoFrequenciaRuido.addPonto(720f, this.frequencia);
        
        return funcaoFrequenciaRuido;
	}
	
	
}
