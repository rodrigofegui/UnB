package principal;

import bancoDados.manipulacao.INSSM;
import bancoDados.tabelas.INSS;

public class Principal {
	public static void main(String[] args){
		INSSM maniInss = new INSSM();
		INSS inss = new INSS();
		
		inss.setCodigo(1);
		
		maniInss.deletar(inss);
		
		System.out.println("Finalizou");
	}
}
