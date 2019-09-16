/*  Inclusão das bibliotecas requisitadas: */
#include "../Bibliotecas/Diretorios.hpp"

/*  Definições das funções a serem manipuladas por este arquivo: */
/*  Função 'arq_escreve_resize', escreve o aviso de redimensionamento */
void arq_escreve_resize (FILE *arq){
    /*  'arq' armazena o arquivo lógico a ser escrito o aviso */
    fprintf (arq, "Todas as imagens foram redimensionadas para %d x %d pixels, ", LIN_ALVO, COL_ALVO);
    fprintf (arq, "as medições abaixo obedecem esta proporção.\n\n");
}

/*	Função 'dir_ler', realiza a leitura de todos os diretórios a partir de um
**	diretório base, escrevendo num arquivo de escolha*/
void dir_ler (FILE *arq, FILE *arq1, char * dirbase, int ramificacao, FMeasure *estatistica){
	/*	'arq' armazena o arquivo a ser gravado as informações a medida que vai
	**	percorrendo os diretórios; 'dirbase' armazena o nome do diretório
	**	corrente a ser navegado; 'ramificacao' armazena o nivel de ramificacao
	**	dos diretórios; 'pasta' armazena as informações dos arquivos presentes
	**	no diretório; 'pdir' armazena o diretório lógico a ser navegado;
	**	'extensoes' armazena as extensões de arquivo, classificadas como imagem */
	Diretorios *pasta;
    DIR *pdir = dir_abre (dirbase);
    string hinweis[] = {"Categoria 1", "Categoria 2"};
    int contador = 0;

	/*	Analisando todos os arquivos do diretorio corrente */
    while((pasta = readdir(pdir))){

		/*	Escrita no arquivo desejado */
		dir_escreve_geral (arq, pasta, ramificacao);

        /*  Validação do diretório */
        if (dir_valido_geral(pasta) == VERDADE){

            /*  Configuração da classe que está sendo analisada */
            if (string_compara_n(pasta->d_name, hinweis[0], 0, 0, static_cast<int>(hinweis[0].size())) == VERDADE){
                estatistica->status = VERDADE;
            }else if (string_compara_n(pasta->d_name, hinweis[1], 0, 0, static_cast<int>(hinweis[1].size())) == VERDADE){
                estatistica->status = !VERDADE;
            }

            /*  Verificação se é outro diretório, caso positivo: */
            if(pasta->d_type == DIR_PASTA){
                /*  Configuração do nome do diretório,'nomedir', a ser lido */
                char nomedir[500];

                /*  Inicialização do nome do diretório */
                string_zera (nomedir, 0, 500);

                /*  Construção do nome do diretório filho */
                dir_constroi_nome (dirbase, pasta->d_name, nomedir);
                strcat (nomedir, DIR_DIVISAO);

                /*  Leitura do diretório formado */
                dir_ler (arq, arq1, nomedir, ramificacao + 1, estatistica);

            /*  Caso contrario e, além disso, sendo uma imagem  */
            }else if(dir_valido_imagem(pasta) == VERDADE){
                /*  Configuração do nome da imagem, 'nomeimg', a ser manipulada */
                char nomeimg[500];

                /*  Inicialização do nome do diretório */
                string_zera (nomeimg, 0, 500);

                /*  Construção do nome do diretório filho */
                dir_constroi_nome (dirbase, pasta->d_name, nomeimg);

                /*  Abertura da imagem para processamento */
                Mat teste = imread (nomeimg, CV_LOAD_IMAGE_COLOR);

                /*  Processamento sobre a imagem encontrada */
                if (!teste.empty()){
                    imagem_processa (arq1, teste, nomeimg, estatistica);
                    if (estatistica->classes.status == VERDADE){
                        contador++;
                    }
                }

                /*  Escrita no arquivo saida, o status sobre a imagem */
                dir_escreve_imagem (arq, nomeimg, ramificacao + 1, teste.empty());

                teste.release ();
            }
        }
    }

    if (estatistica->classes.status == VERDADE){
        /*  Levantamento das médias e desvios padrões para as classes */
        estatistica->classes.medias[estatistica->classes.classe] /= contador;
    }

    /*  Liberação de memória */
    if (pdir != NULL)
        closedir (pdir);
    return;
}

/*	Função 'dir_abre', realiza a abertura de um dado diretório,
**	verificando se é um diretorio válido */
DIR * dir_abre (char *nomedir){
	/*	'nomedir' armazena o nome do diretório a ser aberto; 'diretorio'
	**	armazena o diretório lógico a ser manipulado */
	DIR *diretorio = opendir (nomedir);

	/*	Validação do diretório lógico */
	if (diretorio == NULL){
		printf ("Falha ao abrir o diretorio %s!\n", nomedir);
	}

	return diretorio;
}

/*	Função 'dir_constroi_nome', realiza a construção do nome do diretorio,
**	pela concatenação de duas outras partes */
void dir_constroi_nome (char *parte1, char *parte2, char *destino){
	/*	'parte1' e 'parte2' armazenam as respectivas partes a serem concatenadas
	**	nessa ordem; 'destino' armazena o nome formado */

	/*	Concatenação das partes */
    strcpy (destino, parte1);
    strcat (destino, parte2);
}

/*	Função 'dir_escreve_geral', realiza a escrita do status de um arquivo do diretório
**	num arquivo de saída escolhido */
void dir_escreve_geral (FILE *arq, Diretorios *dir, int ramificacao){
	/*	'arq' armazena o arquivo lógico a ser escrito as informações do referente
	**	arquivo; 'dir' armazena o arquivo corrente; 'ramificacao' armazena o nível
	**	de ramificação do arquivo corrente */

	/*	Escrita com as ramificações */
	for (int vezes = 0; vezes < ramificacao; vezes++)
        fprintf (arq, "\t");

	/*	Escrita das informações */
    fprintf (arq, "Tipo =\t%d\t", dir->d_type);
    fprintf (arq, "Nome =\t%s\n", dir->d_name);
}

/*	Função 'dir_escreve_imagem', realiza a escrita do status de uma imagem do diretório
**	num arquivo de saída escolhido */
void dir_escreve_imagem (FILE *arq, char *nomeimg, int ramificacao, bool falha){
	/*	'arq' armazena o arquivo lógico a ser escrito as informações do referente
	**	arquivo; 'dir' armazena o arquivo corrente; 'ramificacao' armazena o nível
	**	de ramificação do arquivo corrente */

	/*	Escrita com as ramificações */
	for (int vezes = 0; vezes < ramificacao + 1; vezes++)
        fprintf (arq, "\t");

    /*  Não conseguindo abrir a imagem */
    if (falha == VERDADE){
        fprintf (arq, "Erro ao abrir a imagem %s\n\n", nomeimg);

    /*  Caso contrário */
    }else{
        fprintf (arq, "SUCESSO\n\n");
    }
}

/*	Função 'dir_valido_geral', realiza a validação de um diretório, ou seja, se é uma
**	pasta de arquivos e se é um nome diferente de '.' e '..' */
bool dir_valido_geral (Diretorios *dir){
	/*	'dir' armazena o diretório a ser analisado */

	/*	Validação do diretório */
	if ((strcmp(dir->d_name, ".") != IGUAL) && (strcmp(dir->d_name, "..") != IGUAL))
		return VERDADE;

	return !VERDADE;
}

/*  Função 'dir_valido_imagem', realiza a validação de um arquivo como imagem */
bool dir_valido_imagem (Diretorios *dir){
    /*  'dir' armazena o diretorio a ser avaliado como imagem ou não; 'referencia' armazena
    **  os criterios para que um diretório seja considerado como uma imagem */
    string referencia[] = {"jpg", "png"};

    /*  Valida o formato do diretório quanto um formato de imagem */
    /*  Busca dentre os formatos possíveis */
    for (int turn = 0; turn < QNT_FORMATOS; turn++){
        /*  Sendo VERDADE */
        if (string_compara_n (dir->d_name, referencia[turn], strlen(dir->d_name) - ARQ_EXTENSAO, 0, static_cast<int>(referencia[turn].length())) == VERDADE)
            return VERDADE;
    }

    /*  Não sendo uma imagem */
    return !VERDADE;
}

