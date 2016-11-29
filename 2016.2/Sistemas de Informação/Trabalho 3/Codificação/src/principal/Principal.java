package principal;

import java.sql.Date;

import bancoDados.manipulacao.INSSM;
import bancoDados.tabelas.INSS;

public class Principal {
	public static void main(String[] args){
		/*
		INSSM maniInss = new INSSM();
		INSS inss = new INSS();
		
		inss.setCodigo(1);
		
		maniInss.deletar(inss);
		//*/
		
		System.out.println("Date -> " + Date.valueOf("24/12/1994"));
		
		System.out.println("Finalizou");
	}
}
