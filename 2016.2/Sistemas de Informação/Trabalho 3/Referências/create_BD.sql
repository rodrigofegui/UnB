-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL,ALLOW_INVALID_DATES';

-- -----------------------------------------------------
-- Schema t3_si
-- -----------------------------------------------------
DROP SCHEMA IF EXISTS `t3_si` ;

-- -----------------------------------------------------
-- Schema t3_si
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `t3_si` DEFAULT CHARACTER SET utf8 ;
USE `t3_si` ;

-- -----------------------------------------------------
-- Table `t3_si`.`Disciplina`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `t3_si`.`Disciplina` ;

CREATE TABLE IF NOT EXISTS `t3_si`.`Disciplina` (
  `codigo` INT NOT NULL AUTO_INCREMENT,
  `descricao` VARCHAR(100) NOT NULL,
  PRIMARY KEY (`codigo`, `descricao`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `t3_si`.`INSS`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `t3_si`.`INSS` ;

CREATE TABLE IF NOT EXISTS `t3_si`.`INSS` (
  `codigo` INT NOT NULL AUTO_INCREMENT,
  `limiteSuperior` FLOAT NOT NULL,
  `aliquota` FLOAT NULL,
  PRIMARY KEY (`limiteSuperior`),
  UNIQUE INDEX `codigo_UNIQUE` (`codigo` ASC))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `t3_si`.`IRRF`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `t3_si`.`IRRF` ;

CREATE TABLE IF NOT EXISTS `t3_si`.`IRRF` (
  `codigo` INT NOT NULL AUTO_INCREMENT,
  `limiteSuperior` FLOAT NOT NULL,
  `aliquota` FLOAT NULL,
  `desconto` FLOAT NULL,
  PRIMARY KEY (`limiteSuperior`),
  UNIQUE INDEX `codigo_UNIQUE` (`codigo` ASC))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `t3_si`.`Profissao`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `t3_si`.`Profissao` ;

CREATE TABLE IF NOT EXISTS `t3_si`.`Profissao` (
  `codigo` INT NOT NULL AUTO_INCREMENT,
  `descricao` VARCHAR(100) NOT NULL,
  `salarioBase` FLOAT NOT NULL,
  `Disciplina_codigo` INT NOT NULL,
  `INSS_codigo` INT NOT NULL,
  `IRRF_codigo` INT NOT NULL,
  PRIMARY KEY (`codigo`, `INSS_codigo`, `IRRF_codigo`),
  INDEX `fk_Profissao_Disciplina1_idx` (`Disciplina_codigo` ASC),
  INDEX `fk_Profissao_INSS1_idx` (`INSS_codigo` ASC),
  INDEX `fk_Profissao_IRRF1_idx` (`IRRF_codigo` ASC),
  CONSTRAINT `fk_Profissao_Disciplina1`
    FOREIGN KEY (`Disciplina_codigo`)
    REFERENCES `t3_si`.`Disciplina` (`codigo`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Profissao_INSS1`
    FOREIGN KEY (`INSS_codigo`)
    REFERENCES `t3_si`.`INSS` (`codigo`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Profissao_IRRF1`
    FOREIGN KEY (`IRRF_codigo`)
    REFERENCES `t3_si`.`IRRF` (`codigo`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
AUTO_INCREMENT = 0
PACK_KEYS = DEFAULT;


-- -----------------------------------------------------
-- Table `t3_si`.`Funcionario`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `t3_si`.`Funcionario` ;

CREATE TABLE IF NOT EXISTS `t3_si`.`Funcionario` (
  `cpf` VARCHAR(14) NOT NULL,
  `matricula` INT NOT NULL AUTO_INCREMENT,
  `nome` VARCHAR(100) NOT NULL,
  `dataNascimento` DATE NOT NULL,
  `empregado` TINYINT(1) NOT NULL,
  `dataAdmissao` DATE NOT NULL,
  `telefone` VARCHAR(15) NULL,
  `email` VARCHAR(100) NULL,
  `valeTransporte_Dia` INT NULL,
  `Profissao_codigo` INT NOT NULL,
  `Profissao_INSS_codigo` INT NOT NULL,
  `Profissao_IRRF_codigo` INT NOT NULL,
  PRIMARY KEY (`cpf`, `Profissao_codigo`, `Profissao_INSS_codigo`, `Profissao_IRRF_codigo`),
  UNIQUE INDEX `cpf_UNIQUE` (`cpf` ASC),
  INDEX `fk_Funcionario_Profissao1_idx` (`Profissao_codigo` ASC, `Profissao_INSS_codigo` ASC, `Profissao_IRRF_codigo` ASC),
  UNIQUE INDEX `matricula_UNIQUE` (`matricula` ASC),
  CONSTRAINT `fk_Funcionario_Profissao1`
    FOREIGN KEY (`Profissao_codigo` , `Profissao_INSS_codigo` , `Profissao_IRRF_codigo`)
    REFERENCES `t3_si`.`Profissao` (`codigo` , `INSS_codigo` , `IRRF_codigo`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
AUTO_INCREMENT = 1
PACK_KEYS = DEFAULT;


-- -----------------------------------------------------
-- Table `t3_si`.`Ferias`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `t3_si`.`Ferias` ;

CREATE TABLE IF NOT EXISTS `t3_si`.`Ferias` (
  `dataReferencia` DATE NOT NULL,
  `Funcionario_matricula` INT NOT NULL,
  `codigo` INT NOT NULL AUTO_INCREMENT,
  PRIMARY KEY (`dataReferencia`, `Funcionario_matricula`),
  INDEX `fk_Ferias_Funcionario_idx` (`Funcionario_matricula` ASC),
  UNIQUE INDEX `codigo_UNIQUE` (`codigo` ASC),
  CONSTRAINT `fk_Ferias_Funcionario`
    FOREIGN KEY (`Funcionario_matricula`)
    REFERENCES `t3_si`.`Funcionario` (`matricula`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `t3_si`.`DecimoTerceiro`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `t3_si`.`DecimoTerceiro` ;

CREATE TABLE IF NOT EXISTS `t3_si`.`DecimoTerceiro` (
  `requisicao` TINYINT(1) NOT NULL,
  `parcelaAcumulada` FLOAT NOT NULL,
  `codigo` INT NOT NULL AUTO_INCREMENT,
  `parcelaContador` INT NULL DEFAULT 0,
  `Funcionario_matricula` INT NOT NULL,
  PRIMARY KEY (`requisicao`, `parcelaAcumulada`, `Funcionario_matricula`),
  INDEX `fk_DecimoTerceiro_Funcionario1_idx` (`Funcionario_matricula` ASC),
  UNIQUE INDEX `codigo_UNIQUE` (`codigo` ASC),
  CONSTRAINT `fk_DecimoTerceiro_Funcionario1`
    FOREIGN KEY (`Funcionario_matricula`)
    REFERENCES `t3_si`.`Funcionario` (`matricula`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `t3_si`.`Holerite`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `t3_si`.`Holerite` ;

CREATE TABLE IF NOT EXISTS `t3_si`.`Holerite` (
  `dataReferencia` DATE NOT NULL,
  `salarioLiquido` FLOAT NOT NULL,
  `codigo` INT NOT NULL AUTO_INCREMENT,
  `Funcionario_matricula` INT NOT NULL,
  `inss` FLOAT NOT NULL DEFAULT 0,
  `irrf` FLOAT NOT NULL DEFAULT 0,
  `ferias` FLOAT NOT NULL DEFAULT 0,
  `decTerceiro` FLOAT NOT NULL DEFAULT 0,
  `faltas` FLOAT NOT NULL DEFAULT 0,
  `valeTransporte` FLOAT NOT NULL DEFAULT 0,
  PRIMARY KEY (`dataReferencia`, `salarioLiquido`, `Funcionario_matricula`),
  INDEX `fk_Holerite_Funcionario1_idx` (`Funcionario_matricula` ASC),
  UNIQUE INDEX `codigo_UNIQUE` (`codigo` ASC),
  CONSTRAINT `fk_Holerite_Funcionario1`
    FOREIGN KEY (`Funcionario_matricula`)
    REFERENCES `t3_si`.`Funcionario` (`matricula`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
