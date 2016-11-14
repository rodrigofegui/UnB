package conversao;

/**
 * Responsavel por armazenar as notas lidas no arquivo midi,
 * antes de passa-las a uma classe Java
 * @author Helio Santana
 * @author Rodrigo Guimaraes
 * @version	1.0
 * @since	14/06/2016
 */
public class NotasMidi {
	/**
	 * Frequencia base para as notas, obdecendo a afinacao igualmente temperada
	 */
	public static final float f_0 = 8.175f;
	/**
	 * Controle de amplitude da nota
	 * Frequencia da nota, em Hz
	 * Instantes limítrofes da nota
	 * Duração da nota
	 */
	int amplitude;
	float frequencia;
	float instanteInicial, instanteFinal;
	float duracao;

	
	
	
	/**
	 * Construcao da nota de maneira default
	 */
	public NotasMidi (){
		this.amplitude = 0;
		this.frequencia = 0f;
		this.instanteFinal = 0f;
		this.instanteInicial = 0f;
		this.duracao = 0f;
	}
	
	/**
	 * Atribui valor a amplitude da nota
	 * @param amplitude Valor a ser atribuido 
	 */
	public void setAmplitude (int amplitude){
		this.amplitude = amplitude;
	}
	
	/**
	 * Valor atribuido a amplitude da nota
	 * @return O valor da amplitude
	 */
	public int getAmplitude (){
		return this.amplitude;
	}
	
	
	/**
	 * Atribui valor a frequencia da nota, sabendo o valor exato
	 * @param frequencia Valor a ser atribuido
	 */
	public void setFrequencia (float frequencia){
		this.frequencia = frequencia;
	}
	
	/**
	 * Atribui valor a frequencia da nota,
	 * sabendo o indice da afinacao igualmente temperada
	 * @param indice Expoente da afinacao igualmente temperada
	 */
	public void setFrequencia (int indice){
		this.frequencia = (float)(f_0 * Math.pow(2, (double)indice/12));
	}
	
	/**
	 * Valor atribuido a frequencia da nota
	 * @return Valor da frequencia
	 */
	public float getFrequencia (){
		return this.frequencia;
	}
	
	
	/**
	 * Atribui valor ao instante inicial da nota,
	 * conhecendo-se o valor exato
	 * @param instanteInicial Valor do instante inicial
	 */
	public void setInstanteInical (float instanteInicial){
		this.instanteInicial = instanteInicial;
	}
	
	/**
	 * Atribui valor ao instante inicial da nota,
	 * conhecendo-se o instante final e a duracao
	 * @param instanteFinal Valor do instante final
	 * @param duracao Valor da duracao
	 */
	public void setInstanteInicial (float instanteFinal, float duracao){
		this.instanteInicial = instanteFinal - duracao;
	}
	
	/**
	 * Valor atribuido ao instante inicial
	 * @return Valor do instante inicial
	 */
	public float getInstanteInicial (){
		return this.instanteInicial;
	}
	
	
	/**
	 * Atribui valor ao instante final da nota,
	 * conhecendo-se o valor exato
	 * @param instanteFinal Valor do instante final
	 */
	public void setInstanteFinal (float instanteFinal){
		this.instanteFinal = instanteFinal;
	}
	
	/**
	 * Atribui valor ao instante final da nota,
	 * conhecendo-se o instante inicial e a duracao
	 * @param instanteInicial Valor do instante inicial
	 * @param duracao Valor da duracao
	 */
	public void setInstanteFinal (float instanteInicial, float duracao){
		this.instanteFinal = instanteInicial + duracao;
	}
	
	/**
	 * Valor atribuido ao instante final
	 * @return Valor do instante final
	 */
	public float getInstanteFinal (){
		return this.instanteFinal;
	}
	
	
	/**
	 * Atribui valor a duracao da nota,
	 * considera-se que os instantes inicial e final
	 * ja estejam configurados
	 */
	public void setDuracao (){
		this.duracao = this.instanteFinal - this.instanteInicial;
	}
	
	/**
	 * Atribui valor a duracao da nota,
	 * conhecendo-se o valor exato
	 * @param duracao Valor da duracao
	 */
	public void setDuracao (float duracao){
		this.duracao = duracao;
	}
	
	/**
	 * Atribui valor aduracao da nota,
	 * conhecendo-se os instantes inicial e final
	 * @param instanteInicial Valor do instante inicial
	 * @param instanteFinal Valor do instante final
	 */
	public void setDuracao (float instanteInicial, float instanteFinal){
		this.duracao = instanteFinal - instanteInicial;
	}
	
	/**
	 * Valor atribuido a duracao
	 * @return Valor da duracao
	 */
	public float getDuracao (){
		return this.duracao;
	}

	
	/**
	 * Retorna uma String que representa a saida do objeto NotasMidi
	 * @return Descricao montada
	 */
	public String toString (){
		String descricao = "Nota formada:\n";
		
		descricao += "\tFreq = " + this.getFrequencia() + "\n";
		
		descricao += "\tAmpli = " + this.getAmplitude() + "\n";
		
		descricao += "\tDuracao = " + this.getDuracao() + "\n";
		
		descricao += "\tInst. Inicial = " + this.getInstanteInicial() + "\n";
		
		descricao += "\tInst. Final = " + this.getInstanteFinal() + "\n\n";
		
		return descricao;
	}
}
