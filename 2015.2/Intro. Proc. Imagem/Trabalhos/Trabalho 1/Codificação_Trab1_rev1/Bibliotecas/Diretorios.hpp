#include "Imagens.hpp"


/*  Protótipos das funções da biblioteca */
/*  Função 'arq_escreve_resize', escreve o aviso de redimensionamento */
void arq_escreve_resize (FILE *);

/*  Função 'dir_ler', navega nos diretórios */
void dir_ler (FILE *, FILE *, char *, int, FMeasure *);

/*  Função 'dir_abre', abri o diretório lógico para examinação */
DIR * dir_abre (char *);

/*  Função 'dir_constroi_nome', concatena as partes do diretório,
**  a antiga e a atual */
void dir_constroi_nome (char *, char *, char *);

/*  Função 'dir_escreve_geral', escreve os status de um arquivo
**  de qualquer natureza */
void dir_escreve_geral (FILE *, Diretorios *, int);

/*  Função 'dir_escreve_geral', escreve os status de um arquivo
**  que seja uma imagem */
void dir_escreve_imagem (FILE *, char *, int, bool);

/*  Função 'dir_valido_geral', verifica a validade quanto ao nome
**  do arquivo */
bool dir_valido_geral (Diretorios *);

/*  Função 'dir_valido_imagem', verifica a validade quanto ao formato
**  do arquivo */
bool dir_valido_imagem (Diretorios *);


