/*	Pacote ao qual pertence */
package principal;


/** 
 * Constroi os intervalos musicais basicos, para ser implementados na
 * construcao de melodias
 * @author	Helio Santana
 * @author	Rodrigo Guimaraes
 * @version	1.0
 * @since	28/05/2016
 */
public class IntervalosMusicais {
	/**
	 * Nota DO 1, referencia para a localizacao dos demais
	 */

	public static final float C1 = 65.4f;
	public static final float C2 = oitavaAcima (C1);
	public static final float C3 = oitavaAcima (C2);
	public static final float C4 = oitavaAcima (C3);
	public static final float C5 = oitavaAcima (C4);

	
	
	/**
	 * Constroi o intervalo musical correspondente a segunda menor
	 * @param doBase Representa o C da escala em que o C# sera
	 * aplicado
	 * @return Segunda-menor em relacao ao doBase
	 */
	public static float Csust (float doBase){
		return (float)(doBase * Math.pow(2, (double)1/12));
	}
	
	/**
	 * Constroi o intervalo musical correspondente a segunda maior
	 * @param doBase Representa o C da escala em que o D sera
	 * aplicado
	 * @return Segunda-maior em relacao ao doBase
	 */
	public static float D (float doBase){
		return (float)(doBase * Math.pow(2, (double)2/12));
	}
	
	/**
	 * Constroi o intervalo musical correspondente a terca menor
	 * @param doBase Representa o C da escala em que o D# sera
	 * aplicado
	 * @return Terca-menor em relacao ao doBase
	 */
	public static float Dsust (float doBase){
		return (float)(doBase * Math.pow(2, (double)3/12));
	}
	
	/**
	 * Constroi o intervalo musical correspondente a terca maior
	 * @param doBase Representa o C da escala em que o E sera
	 * aplicado
	 * @return Terca-maior em relacao ao doBase
	 */
	public static float E (float doBase){
		return (float)(doBase * Math.pow(2, (double)4/12));
	}
	
	/**
	 * Constroi o intervalo musical correspondente a quarta justa
	 * @param doBase Representa o C da escala em que o F sera
	 * aplicado
	 * @return Quarta-justa em relacao ao doBase
	 */
	public static float F (float doBase){
		return (float)(doBase * Math.pow(2, (double)5/12));
	}
	
	/**
	 * Constroi o intervalo musical correspondente a quarta aumentada
	 * @param doBase Representa o C da escala em que o F# sera
	 * aplicado
	 * @return Quarta-aumentada em relacao ao doBase
	 */
	public static float Fsust (float doBase){
		return (float)(doBase * Math.pow(2, (double)6/12));
	}

	/**
	 * Constroi o intervalo musical correspondente a quinta justa
	 * @param doBase Representa o C da escala em que o G sera
	 * aplicado
	 * @return Quinta-justa em relacao ao doBase
	 */
	public static float G (float doBase){
		return (float)(doBase * Math.pow(2, (double)7/12));
	}
	
	/**
	 * Constroi o intervalo musical correspondente a sexta menor
	 * @param doBase Representa o C da escala em que o G# sera
	 * aplicado
	 * @return Sexta-menor em relacao ao doBase
	 */
	public static float Gsust (float doBase){
		return (float)(doBase * Math.pow(2, (double)8/12));
	}
	
	/**
	 * Constroi o intervalo musical correspondente a sexta maior
	 * @param doBase Representa o C da escala em que o A sera
	 * aplicado
	 * @return Sexta-maior em relacao ao doBase
	 */
	public static float A (float doBase){
		return (float)(doBase * Math.pow(2, (double)9/12));
	}
	
	/**
	 * Constroi o intervalo musical correspondente a setima menor
	 * @param doBase Representa o C da escala em que o A# sera
	 * aplicado
	 * @return Setima-menor em relacao ao doBase
	 */
	public static float Asust (float doBase){
		return (float)(doBase * Math.pow(2, (double)10/12));
	}
	
	/**
	 * Constroi o intervalo musical correspondente a setima maior
	 * @param doBase Representa o C da escala em que o B sera
	 * aplicado
	 * @return Setima-maior em relacao ao doBase
	 */
	public static float B (float doBase){
		return (float)(doBase * Math.pow(2, (double)11/12));
	}
	
	/**
	 * Constroi o intervalo musical correspondente a oitava ascendente
	 * @param doBase Representa o doBase da escala em que a oitava sera
	 * aplicada
	 * @return Oitava ascendente em relacao ao doBase
	 */
	public static float oitavaAcima (float doBase){
		return (doBase * 2f);
	}
	
	/**
	 * Constroi o intervalo musical correspondente a oitava descendente
	 * @param doBase Representa o doBase da escala em que a oitava sera
	 * aplicada
	 * @return Oitava descendente em relacao ao doBase
	 */
	public static float oitavaAbaixo (float doBase){
		return (doBase * .5f);
	}

	
	
	/**
	 * Constroi a duracao da semibreve proporcional em relacao a
	 * seminima ja definida pela melodia
	 * @return Valor da semibreve ajustado
	 */
	public static float semibreve (){
		return 4f * Melodias.melodiaPrincipal.getSeminima ();
	}
	
	/**
	 * Constroi a duracao da minima proporcional em relacao a
	 * seminima ja definida pela melodia
	 * @return Valor da minima ajustado
	 */
	public static float minima (){
		return 2f * Melodias.melodiaPrincipal.getSeminima();
	}
	
	/**
	 * Constroi a duracao da seminima proporcional em relacao a
	 * seminima ja definida pela melodia
	 * @return Valor da seminima ajustado
	 */
	public static float seminima (){
		return Melodias.melodiaPrincipal.getSeminima();
	}
	
	/**
	 * Constroi a duracao da colcheia proporcional em relacao a
	 * seminima ja definida pela melodia
	 * @return Valor da colcheia ajustado
	 */
	public static float colcheia (){
		return .5f  * Melodias.melodiaPrincipal.getSeminima();
	}
	
	/**
	 * Constroi a duracao da semicolcheia proporcional em relacao a
	 * seminima ja definida pela melodia
	 * @return Valor da semicolcheia ajustado
	 */
	public static float semicolcheia (){
		return .25f * Melodias.melodiaPrincipal.getSeminima();
	}
	
	/**
	 * Constroi a duracao da fusa proporcional em relacao a
	 * seminima ja definida pela melodia
	 * @return Valor da fusa ajustado
	 */
	public static float fusa (){
		return .125f * Melodias.melodiaPrincipal.getSeminima();
	}
	
	/**
	 * Constroi a duracao da semifusa proporcional em relacao a
	 * seminima ja definida pela melodia
	 * @return Valor da semifusa ajustado
	 */
	public static float semifusa (){
		return .0625f * Melodias.melodiaPrincipal.getSeminima();
	}
}
