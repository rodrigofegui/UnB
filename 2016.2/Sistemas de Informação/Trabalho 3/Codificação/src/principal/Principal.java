package principal;

import bancoDados.manipulacao.INSSM;
import bancoDados.tabelas.INSS;

public class Principal {
	public static void main(String[] args){
		INSSM maniInss = new INSSM();
		INSS inss = new INSS();
		
		inss.setLimSuperior(1556.94f);
		inss.setAliquota(8f);
		
		maniInss.inserir(inss);
		
		System.out.println("Finalizou");
	}
}
