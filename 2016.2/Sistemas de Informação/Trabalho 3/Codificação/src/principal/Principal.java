package principal;

import bancoDados.BancoDados;

public class Principal {
	public static void main(String[] args) {
		BancoDados bd = new BancoDados();
		
		bd.getStatus();
		
		bd.inicializacaoEspecifica();
		
		bd.iniciarConexao();
		
		bd.getStatus();
		
		bd.encerrarConexao();
	}
}
