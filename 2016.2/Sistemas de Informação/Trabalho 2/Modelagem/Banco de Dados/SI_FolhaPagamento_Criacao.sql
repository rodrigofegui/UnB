-- Database generated with pgModeler (PostgreSQL Database Modeler).
-- pgModeler  version: 0.8.1
-- PostgreSQL version: 9.4
-- Project Site: pgmodeler.com.br
-- Model Author: ---


-- Database creation must be done outside an multicommand file.
-- These commands were put in this file only for convenience.
-- -- object: novo_banco_de_dados | type: DATABASE --
-- -- DROP DATABASE IF EXISTS novo_banco_de_dados;
-- CREATE DATABASE novo_banco_de_dados
-- ;
-- -- ddl-end --
-- 

-- object: public."Funcionario" | type: TABLE --
-- DROP TABLE IF EXISTS public."Funcionario" CASCADE;
CREATE TABLE public."Funcionario"(
	matricula decimal(8) NOT NULL,
	cpf decimal(11) NOT NULL,
	nome varchar(100) NOT NULL,
	"dataNascimento" date NOT NULL,
	telefone decimal(13),
	email varchar(100),
	"dataAdmissao" date,
	"codigo_Profissoes" decimal,
	"valeTransporte_Dia" decimal,
	CONSTRAINT "ID_Fun" PRIMARY KEY (matricula)

);
-- ddl-end --
ALTER TABLE public."Funcionario" OWNER TO postgres;
-- ddl-end --

-- object: public."Profissoes" | type: TABLE --
-- DROP TABLE IF EXISTS public."Profissoes" CASCADE;
CREATE TABLE public."Profissoes"(
	codigo decimal NOT NULL,
	descricao varchar(100) NOT NULL,
	"codigo_Disciplina" decimal,
	"codigo_INSS" decimal NOT NULL,
	"codigo_IRRF" decimal NOT NULL,
	"salarioBase" money NOT NULL,
	CONSTRAINT "ID_Prof" PRIMARY KEY (codigo)

);
-- ddl-end --
ALTER TABLE public."Profissoes" OWNER TO postgres;
-- ddl-end --

-- object: public."INSS" | type: TABLE --
-- DROP TABLE IF EXISTS public."INSS" CASCADE;
CREATE TABLE public."INSS"(
	codigo decimal NOT NULL,
	"limiteSuperior" money NOT NULL,
	aliquota decimal(2),
	CONSTRAINT "ID_IN" PRIMARY KEY (codigo)

);
-- ddl-end --
ALTER TABLE public."INSS" OWNER TO postgres;
-- ddl-end --

-- object: "Profissoes_fk" | type: CONSTRAINT --
-- ALTER TABLE public."Funcionario" DROP CONSTRAINT IF EXISTS "Profissoes_fk" CASCADE;
ALTER TABLE public."Funcionario" ADD CONSTRAINT "Profissoes_fk" FOREIGN KEY ("codigo_Profissoes")
REFERENCES public."Profissoes" (codigo) MATCH FULL
ON DELETE SET NULL ON UPDATE CASCADE;
-- ddl-end --

-- object: "INSS_fk" | type: CONSTRAINT --
-- ALTER TABLE public."Profissoes" DROP CONSTRAINT IF EXISTS "INSS_fk" CASCADE;
ALTER TABLE public."Profissoes" ADD CONSTRAINT "INSS_fk" FOREIGN KEY ("codigo_INSS")
REFERENCES public."INSS" (codigo) MATCH FULL
ON DELETE RESTRICT ON UPDATE CASCADE;
-- ddl-end --

-- object: public."IRRF" | type: TABLE --
-- DROP TABLE IF EXISTS public."IRRF" CASCADE;
CREATE TABLE public."IRRF"(
	codigo decimal NOT NULL,
	"limiteSuperior" money NOT NULL,
	aliquota decimal(2) NOT NULL,
	desconto money NOT NULL,
	CONSTRAINT "ID_IR" PRIMARY KEY (codigo)

);
-- ddl-end --
ALTER TABLE public."IRRF" OWNER TO postgres;
-- ddl-end --

-- object: "IRRF_fk" | type: CONSTRAINT --
-- ALTER TABLE public."Profissoes" DROP CONSTRAINT IF EXISTS "IRRF_fk" CASCADE;
ALTER TABLE public."Profissoes" ADD CONSTRAINT "IRRF_fk" FOREIGN KEY ("codigo_IRRF")
REFERENCES public."IRRF" (codigo) MATCH FULL
ON DELETE RESTRICT ON UPDATE CASCADE;
-- ddl-end --

-- object: public."Disciplina" | type: TABLE --
-- DROP TABLE IF EXISTS public."Disciplina" CASCADE;
CREATE TABLE public."Disciplina"(
	codigo decimal NOT NULL,
	descricao varchar(100) NOT NULL,
	CONSTRAINT "ID_Dis" PRIMARY KEY (codigo)

);
-- ddl-end --
ALTER TABLE public."Disciplina" OWNER TO postgres;
-- ddl-end --

-- object: "Disciplina_fk" | type: CONSTRAINT --
-- ALTER TABLE public."Profissoes" DROP CONSTRAINT IF EXISTS "Disciplina_fk" CASCADE;
ALTER TABLE public."Profissoes" ADD CONSTRAINT "Disciplina_fk" FOREIGN KEY ("codigo_Disciplina")
REFERENCES public."Disciplina" (codigo) MATCH FULL
ON DELETE SET NULL ON UPDATE CASCADE;
-- ddl-end --

-- object: public."Holerite" | type: TABLE --
-- DROP TABLE IF EXISTS public."Holerite" CASCADE;
CREATE TABLE public."Holerite"(
	"matricula_Funcionario" decimal(8) NOT NULL,
	"salarioLiquido" smallint NOT NULL,
	"mesReferencia" date NOT NULL,
	"anoReferencia" smallint NOT NULL,
	faltas decimal(2),
	CONSTRAINT "ID_FP" PRIMARY KEY ("salarioLiquido","mesReferencia","anoReferencia")

);
-- ddl-end --
ALTER TABLE public."Holerite" OWNER TO postgres;
-- ddl-end --

-- object: "Funcionario_fk" | type: CONSTRAINT --
-- ALTER TABLE public."Holerite" DROP CONSTRAINT IF EXISTS "Funcionario_fk" CASCADE;
ALTER TABLE public."Holerite" ADD CONSTRAINT "Funcionario_fk" FOREIGN KEY ("matricula_Funcionario")
REFERENCES public."Funcionario" (matricula) MATCH FULL
ON DELETE RESTRICT ON UPDATE CASCADE;
-- ddl-end --

-- object: "Holerite_uq" | type: CONSTRAINT --
-- ALTER TABLE public."Holerite" DROP CONSTRAINT IF EXISTS "Holerite_uq" CASCADE;
ALTER TABLE public."Holerite" ADD CONSTRAINT "Holerite_uq" UNIQUE ("matricula_Funcionario");
-- ddl-end --

-- object: public."Ferias" | type: TABLE --
-- DROP TABLE IF EXISTS public."Ferias" CASCADE;
CREATE TABLE public."Ferias"(
	"matricula_Funcionario" decimal(8) NOT NULL,
	"mesReferencia" date NOT NULL,
	"anoReferencia" date NOT NULL,
	CONSTRAINT "ID_Ferias" PRIMARY KEY ("mesReferencia","anoReferencia")

);
-- ddl-end --
ALTER TABLE public."Ferias" OWNER TO postgres;
-- ddl-end --

-- object: "Funcionario_fk" | type: CONSTRAINT --
-- ALTER TABLE public."Ferias" DROP CONSTRAINT IF EXISTS "Funcionario_fk" CASCADE;
ALTER TABLE public."Ferias" ADD CONSTRAINT "Funcionario_fk" FOREIGN KEY ("matricula_Funcionario")
REFERENCES public."Funcionario" (matricula) MATCH FULL
ON DELETE RESTRICT ON UPDATE CASCADE;
-- ddl-end --

-- object: public."DecimoTerceiro" | type: TABLE --
-- DROP TABLE IF EXISTS public."DecimoTerceiro" CASCADE;
CREATE TABLE public."DecimoTerceiro"(
	"matricula_Funcionario" decimal(8) NOT NULL,
	requisicao boolean NOT NULL,
	"parcelaAcumulada" money NOT NULL,
	"parcelaContador" decimal NOT NULL,
	CONSTRAINT "ID_Sal13" PRIMARY KEY (requisicao,"parcelaAcumulada")

);
-- ddl-end --
ALTER TABLE public."DecimoTerceiro" OWNER TO postgres;
-- ddl-end --

-- object: "Funcionario_fk" | type: CONSTRAINT --
-- ALTER TABLE public."DecimoTerceiro" DROP CONSTRAINT IF EXISTS "Funcionario_fk" CASCADE;
ALTER TABLE public."DecimoTerceiro" ADD CONSTRAINT "Funcionario_fk" FOREIGN KEY ("matricula_Funcionario")
REFERENCES public."Funcionario" (matricula) MATCH FULL
ON DELETE RESTRICT ON UPDATE CASCADE;
-- ddl-end --

-- object: "DecimoTerceiro_uq" | type: CONSTRAINT --
-- ALTER TABLE public."DecimoTerceiro" DROP CONSTRAINT IF EXISTS "DecimoTerceiro_uq" CASCADE;
ALTER TABLE public."DecimoTerceiro" ADD CONSTRAINT "DecimoTerceiro_uq" UNIQUE ("matricula_Funcionario");
-- ddl-end --


