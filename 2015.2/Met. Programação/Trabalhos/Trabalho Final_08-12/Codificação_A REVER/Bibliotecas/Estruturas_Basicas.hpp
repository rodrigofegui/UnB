typedef struct ger{
	// oke precisar;
}
Gerador;

typedef struct h_ger{
	Geradores *inicio;
	int qnt_tot;
	int energia_tot;
}
Header_ger;

typedef struct ct{
	// oke precisar;
}
City;

typedef struct h_ct{
	City *inicio;
	int qnt_tot;
	int energia_tot;
	int ct_insuf;
	int t_s_recurso;
	int menos_30_recurso;
	int t_m_30_rec;
}
Header_city;

typedef strut inter{
    char tipo;// indica que e interconexao
    char *nome;// vai guardar o nome da conexao
    int linha_inicio,coluna_inicio;// linha = pos_x e coluna = pos_y
    int linha_fim, coluna_fim;
    int capacidade;
    float falha;
    int tempo_cons, custo_cons; // custo e tempo de conserto
    struct inter *proximo;    
}
Conexao;

typedef struct h_inter{
	Conexao *inicio;
	int qnt_tot;
}
Header_conex;

typedef strut adp{
	//	oke precisar;
}
Adaptador;

typedef struct h_inter{
	Adaptador *inicio;
	int qnt_tot;
}
Header_adap;


typedef struct rede{
	Head_ger *in_ger;
	Head_adap *in_adap;
	Head_city *in_city;
	Head_conex *in_conex;
}
Rede;
