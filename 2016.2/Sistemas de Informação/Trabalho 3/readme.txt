Responsável:
	Rodrigo Ferreira Guimarães

Matrícula:
	14/0170740

GitHub:
	https://github.com/rodrigofegui/UnB/tree/master/2016.2/Sistemas%20de%20Informa%C3%A7%C3%A3o/Trabalho%203

Linguagem Utilizada:
	Java

Plataforma necessária:
	Terminal com MV java instalada, ou seja: javac, java, jar e javadoc

Arquivos necessários:
	É preciso ter instalado a API de comunicação com o MySQL:
		- mysql-connector-java-5.1.40-bin.jar

Descritivo:
	Sistema de Processamento de Transação (SPT), em especial o Sistema de Folha de 
Pagamento para empresa  TrabalhoFeliz.

Descritivo do módulo:
	Sendo desenvolvido em Java, visando a implementação do padrão arquitetural MVC, foram
definidos os pacotes:
	- principal: controle da aplicação;
	- bancoDados: controle da comunicação com o banco de dados MySQL;
		* bancoDados.tabelas: tabelas definidas no MR;
		* bancoDados.manipulador: CRUD das tabelas;
	- gui: controle da interface com o usuário utilizada;
		* gui.terminal: implementação da interface pelo terminal;
	- trabalhoFeliz: agentes da empresa TrabalhoFeliz;
	- utilitario: validação das operações e emissão de mensagens de erro.

Descritivo dos diretórios básicos:
	Há os seguintes diretórios:
	- Javadoc: responsável por armazenar a documentação da aplicação;
	- src: responsável por armazenar os arquivos-fonte da aplicação desenvolvida;
	- Holerite: holerites geradas mensalmente. Os mesmos serão nomeados
como: <data>_<nomeEmpregado>.txt, de modo a evitar a sobreposição de arquivos;
	- Registro: relatórios mensais sobre as dispesas, proveniente do pagamentos
dos salários aos funcionários.
	* makefile: responsável pela abstração dos comandos essenciais à aplicação.

Descritivo do arquivo makefile:
	É preciso alterar de antemão o valor de DIR_BASE, pois este é o diretório atual que
contém todas as pastas necessárias; depende de cada computador e usuário.
	Executando o comando:
	@make
	Haverá uma simples explicação sobre cada regra possível.

